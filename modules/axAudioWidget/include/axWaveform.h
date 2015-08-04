//
//  axWaveform.h
//  MidiSequencer
//
//  Created by Alexandre Arsenault on 2014-11-14.
//  Copyright (c) 2014 Alexandre Arsenault. All rights reserved.
//

#ifndef __MidiSequencer__axWaveform__
#define __MidiSequencer__axWaveform__

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

/*******************************************************************************
 * axWaveform.
 ******************************************************************************/
class axWaveform : public axWidget
{
public:
    /***************************************************************************
     * axWaveform::Info.
     **************************************************************************/
    class Info : public axInfo
    {
    public:
        Info();
        
        Info(const std::string& path);
        
        Info(const ax::StringPairVector& attributes);
        
        Info(const ax::Color& bg_color,
             const ax::Color& waveform_color,
             const ax::Color& contour_color,
             const ax::Color& grid_main_line_color,
             const ax::Color& grid_second_line_color,
             const ax::Color& middle_line_color,
             const ax::Color& env_color);
        
        // Info needed for debug editor. Derived from axInfo.
        virtual ax::StringVector GetParamNameList() const;
        virtual std::string GetAttributeValue(const std::string& name);
        virtual void SetAttribute(const ax::StringPair& attribute);
        
        ax::Color bg_color;
        ax::Color waveform_color;
        ax::Color contour_color;
        ax::Color grid_main_line_color;
        ax::Color grid_second_line_color;
        ax::Color middle_line_color;
        ax::Color env_color;
    };
    
    /***************************************************************************
     * axWaveform::Builder.
     **************************************************************************/
    class Builder : public axWidgetBuilder
    {
    public:
        Builder(axWindow* parent);
        
        virtual axWidget* Create(const ax::StringPairVector& attributes);
        
    private:
        axWaveform::Info _info;
        ax::Size _size;
    };
    
    /***************************************************************************
     * axWaveform::axWaveform.
     **************************************************************************/
    axWaveform(axWindow* parent, const ax::Rect& rect,
               const axWaveform::Info& info);
    
    void SetAudioBuffer(ax::Audio::Buffer* buffer);
    
    void SetZoom(const double& zoom);
    
    void SetLeftPosition(const double& pos);
    
    void SetGain(const double& gain);
    
    ax::FloatRange GetBorders() const;
    
    std::vector<float>* _envBuffer;
    std::vector<ax::FloatPoint>* _envPoints;
    
    void ShowEnv(const bool& show);
    
private:
    ax::Audio::Buffer* _audioBuffer;
    
    double _zoom, _leftPos, _gain;
    bool _showEnv;
    
    // Events.
    virtual void OnPaint();
};

#endif /* defined(__MidiSequencer__axWaveform__) */
