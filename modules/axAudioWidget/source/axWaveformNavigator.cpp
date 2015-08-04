//
//  axWaveformNavigator.cpp
//  MidiSequencer
//
//  Created by Alexandre Arsenault on 2014-11-15.
//  Copyright (c) 2014 Alexandre Arsenault. All rights reserved.
//

#include "axWaveformNavigator.h"
#include "axAudioBuffer.h"

axWaveformNavigator::axWaveformNavigator(axWindow* parent,
                                         const ax::Rect& rect):
axPanel(parent, rect),
_audioBuffer(nullptr)
{
    _leftBorder = 0.0;
    _rightBorder = 1.0;
    _fillAlpha = 0.0;
    
    _playingPos = 0.0;
    
//    if(events.slider_value_change)
//    {
//        axObject::AddConnection(events.VALUE_CHANGE,
//                                events.slider_value_change);
//    }
}

void axWaveformNavigator::SetAudioBuffer(ax::Audio::Buffer* buffer)
{
    _audioBuffer = buffer;
    FillWaveformDrawingData();
    Update();
}

void axWaveformNavigator::SetPlayingPos(const double& playing_pos)
{
    _playingPos = ax::Utils::Clamp<double>(playing_pos, 0.0, 1.0);
    Update();
}

void axWaveformNavigator::OnPlayingPositionChange(const double& playing_pos)
{
    _playingPos = ax::Utils::Clamp<double>(playing_pos, 0.0, 1.0);
//    std::cout << "Pos change : " << _playingPos << std::endl;
    Update();
}

void axWaveformNavigator::FillWaveformDrawingData()
{
    if(_audioBuffer != nullptr)
    {
        ax::Rect rect(GetRect());
        
        //    std::cout << "RECT : " << (rect.size.x-3) * 4 << std::endl;

        int data_vector_index = 0;
        axBufferInfo b_info = _audioBuffer->GetBufferInfo();
        
        bool need_to_push_back = false;
        
        if(b_info.frames < 2 * rect.size.x)
        {
            _waveformDrawingData.clear();
            need_to_push_back = true;
        }
        else
        {
            // Doesnt work if buffer is smaller than number of pixel.
            int size_of_data_vector = (rect.size.x-3) * 4;
            _waveformDrawingData.resize(size_of_data_vector);
        }

            float* buffer = _audioBuffer->GetBuffer();
            int middle_y = rect.size.y * 0.5;
            
            //        std::cout << "BSIZE : " << b_info.frames << std::endl;
            
            double nSamplesToProcess = double(b_info.frames);
            int index = 1 ;
            int nSamplePerPixel = 0;
            
            double min_value_pixel = 1000.0;
            double max_value_pixel = -1000.0;
            
            // Ratio of number of pixel over number of sample to draw.
            double r = double(rect.size.x-2) / nSamplesToProcess;
            
            for(int i = 1; i < ceil(nSamplesToProcess); i++, index++)
            {
                // Pixel position.
                double x_pos_left = double(i-1) * r;
                double x_pos_right = double(i) * r;
                
                double l_value = buffer[index - 1];
                double r_value = buffer[index];
                
                if(l_value < min_value_pixel) min_value_pixel = l_value;
                if(l_value > max_value_pixel) max_value_pixel = l_value;
                if(r_value < min_value_pixel) min_value_pixel = r_value;
                if(r_value > max_value_pixel) max_value_pixel = r_value;
                
                // Increment sample at each iteration.
                nSamplePerPixel++;
                
                // If pixel has change.
                if(int(x_pos_left) != int(x_pos_right))
                {
                    if(nSamplePerPixel > 1)
                    {
                        // Pixel value.
                        
                        double height = 0.9 * middle_y;
                        int y_pixel_left = middle_y - min_value_pixel * height;
                        int y_pixel_right = middle_y - max_value_pixel * height;
                        
                        // Draw min to max line on the left pixel.
                        if(need_to_push_back)
                        {
                            ax::Point left(x_pos_left, y_pixel_left);
                            ax::Point right(x_pos_left, y_pixel_right);
                            _waveformDrawingData.push_back(left);
                            _waveformDrawingData.push_back(right);
                        }
                        else
                        {
                            ax::Point left(x_pos_left, y_pixel_left);
                            ax::Point right(x_pos_left, y_pixel_right);
                            _waveformDrawingData[data_vector_index++] = left;
                            _waveformDrawingData[data_vector_index++] = right;
                        }
  
                        // Draw last value of left pixel and first value of
                        // right pixel. This is to make sure that horizontal
                        // lines will be drawn if necessary. A liason between
                        // each vertical lines.
                        y_pixel_left = middle_y - l_value * 0.9 * middle_y;
                        y_pixel_right = middle_y - r_value * 0.9 * middle_y;
                        
                        if(need_to_push_back)
                        {
                            ax::Point left(x_pos_left, y_pixel_left);
                            ax::Point right(x_pos_right, y_pixel_right);
                            _waveformDrawingData.push_back(left);
                            _waveformDrawingData.push_back(right);
                        }
                        else
                        {
                            ax::Point left(x_pos_left, y_pixel_left);
                            ax::Point right(x_pos_right, y_pixel_right);
                            _waveformDrawingData[data_vector_index++] = left;
                            _waveformDrawingData[data_vector_index++] = right;
                        }
    
                    }
                    // One sample or less per pixel.
                    else
                    {
                        // Pixel value.
                        double height = 0.9 * middle_y;
                        int y_pixel_left = middle_y - l_value * height;
                        int y_pixel_right = middle_y - r_value * height;
                        
                        if(need_to_push_back)
                        {
                            ax::Point left(x_pos_left, y_pixel_left);
                            ax::Point right(x_pos_right, y_pixel_right);
                            _waveformDrawingData.push_back(left);
                            _waveformDrawingData.push_back(right);
                        }
                        else
                        {
                            ax::Point left(x_pos_left, y_pixel_left);
                            ax::Point right(x_pos_right, y_pixel_right);
                            _waveformDrawingData[data_vector_index++] = left;
                            _waveformDrawingData[data_vector_index++] = right;
                        }
                    }
                    
                    nSamplePerPixel = 0;
                    min_value_pixel = 1000.0;
                    max_value_pixel = -1000.0;
                }
            }
//        }
    }
    
//    std::cout << "Waveform lines size = " << _waveformDrawingData.size() << std::endl;
}


//void axWaveformNavigator::SetValueChangeEvt(axEvtFunction(double) fct)
//{
//    _value_change_evt = fct;
//}

void axWaveformNavigator::SetLeftBorder(const double& pos)
{
    
}

void axWaveformNavigator::SetRightBorder(const double& pos)
{
    
}

void axWaveformNavigator::SetBorders(const double& left, const double& right)
{
    _leftBorder = ax::Utils::Clamp<double>(left, 0.0, 1.0);
    _rightBorder = ax::Utils::Clamp<double>(right, _leftBorder, 1.0);
    Update();
}

void axWaveformNavigator::SetBorders(const ax::FloatRange& borders)
{
    _leftBorder = ax::Utils::Clamp<double>(borders.left, 0.0, 1.0);
    _rightBorder = ax::Utils::Clamp<double>(borders.right, _leftBorder, 1.0);
    Update();
}

// PRIVATE.

ax::Rect axWaveformNavigator::GetBorderRect() const
{
    ax::Rect rect = GetRect();
    ax::Point border_pos(1 + _leftBorder * (rect.size.x-2), 1);
    ax::Size border_size(ceil((_rightBorder - _leftBorder) * (rect.size.x-2)), rect.size.y-2);
    return ax::Rect(border_pos, border_size);
}

ax::FloatRange axWaveformNavigator::GetBorderRangeFromRect(const ax::Rect& border_rect) const
{
    ax::Rect rect(GetRect());
    double left = double(border_rect.position.x - 1) / double(rect.size.x - 2);
    double right = border_rect.size.x / double(rect.size.x - 2) + left;
    return ax::FloatRange(left, right);
}

void axWaveformNavigator::OnMouseLeftDown(const ax::Point& mousePos)
{
    ax::Rect borderRect(GetBorderRect());
    ax::Point pos = mousePos - GetAbsoluteRect().position;
    
    if(borderRect.IsPointInside(pos))
    {
        _fillAlpha = 0.3;
        _click_pos_delta_x = pos.x - borderRect.position.x;
        GrabMouse();
    }
    else
    {
        _fillAlpha = 0.0;
    }
}

void axWaveformNavigator::OnMouseLeftDragging(const ax::Point& mousePos)
{
    ax::Point pos = mousePos - GetAbsoluteRect().position;
    
    ax::Rect borderRect(GetBorderRect());
    int x = (pos.x - _click_pos_delta_x);
    
    if (x < 1)
    {
        x = 1;
    }
    
    if(x + borderRect.size.x >= (GetRect().size.x - 1))
    {
        x = (GetRect().size.x - 1) - borderRect.size.x;
    }

    borderRect.position.x = x;
    SetBorders(GetBorderRangeFromRect(borderRect));
    
//    if(_value_change_evt)
//    {
//        _value_change_evt(_leftBorder);
//    }
    
//    axObject::PushEvent(axSliderEvents::VALUE_CHANGE,
//                        new axSliderMsg(_leftBorder));
    
    PushEvent(0, new Msg(_leftBorder));
    
    Update();
}

void axWaveformNavigator::OnMouseLeftUp(const ax::Point& pos)
{
    if(IsGrabbed())
    {
        UnGrabMouse();
    }
    if(_fillAlpha != 0.0)
    {
        _fillAlpha = 0.0;
        Update();
    }
}

void axWaveformNavigator::OnMouseEnter()
{
    
}

void axWaveformNavigator::OnMouseLeave()
{
    _fillAlpha = 0.0;
}

void axWaveformNavigator::OnPaint()
{
    ax::GC gc;
    ax::Rect rect(GetDrawingRect());
//    ax::Rect rect(GetRect());
//    ax::Rect rect0(ax::Point(0, 0), rect.size);
    
    // Draw background.
    gc.SetColor(ax::Color(0.5, 0.5, 0.5), 0.01);
    gc.DrawRectangle(rect);
    
    // Draw waveform.
    gc.SetColor(ax::Color(0.5, 0.5, 0.5), 1.0);
    gc.DrawLines(_waveformDrawingData);
    
    // Draw middle line.
    int middle_y = rect.size.y * 0.5;
    gc.SetColor(ax::Color(0.5, 0.5, 0.5), 0.4);
    gc.DrawLine(ax::Point(1, middle_y), ax::Point(rect.size.x - 2, middle_y));
    
    // Draw navigator borders.
    ax::Rect borderRect(GetBorderRect());
    borderRect.position.y += 1;
    borderRect.size.y -= 1;
    borderRect.position.x += 1;
    borderRect.size.x -= 1;
    
    gc.SetColor(ax::Color(0.9, 0.4, 0.0, _fillAlpha));
    gc.DrawRectangle(borderRect);
    
    // Draw navigator borders contour.
    gc.SetColor(ax::Color(0.9, 0.4, 0.0, 0.8));
    gc.DrawRectangleContour(borderRect);
    
    // Draw playing cursor.
    if(_playingPos != 0.0 && _playingPos < 1.0)
    {
        gc.SetColor(ax::Color(0.0, 0.1, 1.0), 0.7);
        int x_pos = 1 + _playingPos * (rect.size.x - 2);
        gc.DrawLine(ax::Point(x_pos, 1), ax::Point(x_pos, rect.size.y - 2));
    }

    // Draw background contour.
    gc.SetColor(ax::Color(0.4));
    gc.DrawRectangleContour(rect);
}