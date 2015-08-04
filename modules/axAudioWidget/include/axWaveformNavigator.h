//
//  axWaveformNavigator.h
//  MidiSequencer
//
//  Created by Alexandre Arsenault on 2014-11-15.
//  Copyright (c) 2014 Alexandre Arsenault. All rights reserved.
//

#ifndef __MidiSequencer__axWaveformNavigator__
#define __MidiSequencer__axWaveformNavigator__

#include "axLib.h"
#include "axEvent.h"
#include "axWidget.h"
#include "axUtils.h"
#include "axConfig.h"
#include "axWidgetBuilder.h"

namespace ax
{
    namespace Audio
    {
        class Buffer;
    }
}

/// @todo Format as a standard axWidget.
class axWaveformNavigator : public axPanel
{
public:
    
    typedef ax::Event::SimpleMsg<double> Msg;
    
    axWaveformNavigator(axWindow* parent,
                        const ax::Rect& rect);
    
    void SetAudioBuffer(ax::Audio::Buffer* buffer);
    
//    void SetZoom(const double& zoom);
//
    void SetBorders(const double& left, const double& right);
    void SetBorders(const ax::FloatRange& borders);
    void SetLeftBorder(const double& pos);
    void SetRightBorder(const double& pos);
    void SetPlayingPos(const double& playing_pos);
    
//    void SetValueChangeEvt(axEvtFunction(double) fct);
    
//    axEVENT(double, OnPlayingPositionChange);
    
private:
    ax::Audio::Buffer* _audioBuffer;
    
    double _leftBorder, _rightBorder;
    double _fillAlpha;
    double _playingPos;
    
    int _click_pos_delta_x;
    
    std::vector<ax::Point> _waveformDrawingData;
    
    void FillWaveformDrawingData();
    ax::Rect GetBorderRect() const;
    ax::FloatRange GetBorderRangeFromRect(const ax::Rect& rect) const;
    
//    axEvtFunction(double) _value_change_evt;
    
    // Events.
    virtual void OnPaint();
    virtual void OnMouseLeftDragging(const ax::Point& pos);
    virtual void OnMouseLeftDown(const ax::Point& pos);
    virtual void OnMouseLeftUp(const ax::Point& pos);
    virtual void OnMouseEnter();
    virtual void OnMouseLeave();
    
    void OnPlayingPositionChange(const double& playing_pos);
};

#endif /* defined(__MidiSequencer__axWaveformNavigator__) */
