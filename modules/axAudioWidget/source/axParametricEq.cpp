//
//  EqGUI.cpp
//  AudioApp
//
//  Created by Alexandre Arsenault on 2015-02-27.
//  Copyright (c) 2015 Alexandre Arsenault. All rights reserved.
//

#include "axParametricEq.h"
#include "axAudioUtils.h"
#include "axToggle.h"
#include "axLabel.h"
#include "axKnob.h"


struct BandControl
{
    BandControl()
    {
    }
    BandControl(const int& n, const bool& as_amp_,
                const ax::Event::Function& f_evt,
                const ax::Event::Function& q_evt,
                const ax::Event::Function& a_evt,
                const ax::Event::Function& active):
    freq(f_evt), q(q_evt), amp(a_evt), on(active), num(n), as_amp(as_amp_)
    {
        
    }
    ax::Event::Function freq, q, amp, on;
    int num;
    bool as_amp;
};

ax::Point CreateFilterBandControls(axWindow* parent,
                                 const ax::Point& pos,
                                 const BandControl& ctrl_info,
                                 const ax::Size& knobSize,
                                 const axKnob::Info& knob_info,
                                 const axToggle::Info& togInfoOnOff,
                                 const ax::Size& toggleSizeOnOff,
                                 const axLabel::Info& labelInfo,
                                 const ax::Size& labelSize)
{
    std::string msg = std::to_string(ctrl_info.num);
    
    axKnob* p1_freq = new axKnob(parent, ax::Rect(pos, knobSize),
                                 axKnob::Events(ctrl_info.freq),
                                 knob_info, 0, 0.0, msg);
    
    p1_freq->SetValue(ctrl_info.num / 8.0);
    
    axToggle* tog = new axToggle(parent,
                                 ax::Rect(p1_freq->GetRect().GetNextPosUp(40) + ax::Point(3, 0),
                                        toggleSizeOnOff),
                                 axToggle::Events(ctrl_info.on),
                                 togInfoOnOff, "",
                                 std::to_string(ctrl_info.num), 0,
                                 std::to_string(ctrl_info.num));
    
    tog->SetSelected(true);
    
    
    new axLabel(parent,
                ax::Rect(p1_freq->GetRect().GetNextPosUp(20), labelSize),
                labelInfo, "Freq");
    
    axKnob* p1_q = new axKnob(parent,
                              ax::Rect(p1_freq->GetRect().GetNextPosDown(20), knobSize),
                              axKnob::Events(ctrl_info.q),
                              knob_info, 0, 0.0, msg);
    
    ax::FloatRange qRange(0.1, 5.0);
    p1_q->SetValue(qRange.GetZeroToOneValue(0.707));
    
    new axLabel(parent, ax::Rect(p1_q->GetRect().GetNextPosUp(20), labelSize),
                labelInfo, "Q");
    
    if(ctrl_info.as_amp)
    {
        axKnob* p1_amp = new axKnob(parent,
                                    ax::Rect(p1_q->GetRect().GetNextPosDown(20), knobSize),
                                    axKnob::Events(ctrl_info.amp),
                                    knob_info, 0, 0.0, msg);
        
        p1_amp->SetValue(0.5);
        
        new axLabel(parent, ax::Rect(p1_amp->GetRect().GetNextPosUp(20), labelSize),
                    labelInfo, "Gain");
    }
    
    
    return p1_freq->GetRect().GetNextPosRight(25);
}

axParametricEq::axParametricEq(axWindow* parent, const ax::Rect& rect):
axPanel(parent, rect)
{
    
    _filter = new FilterParametric(this,
                                   ax::Rect(ax::Point(10, 10), ax::Size(rect.size.x, 200)));
                                          
    
    axLabel::Info labelInfo;
    labelInfo.normal = ax::Color(0.0, 0.0);
    labelInfo.contour = ax::Color(0.0, 0.0);
    labelInfo.font_size = 12;
    labelInfo.font_color = ax::Color(0.4);
    labelInfo.font_name = "";
    labelInfo._alignement = ax::Utils::axALIGN_CENTER;
    
    axToggle::Info togInfoOnOff;
    togInfoOnOff.normal = ax::Color(0.6);
    togInfoOnOff.hover = ax::Color(0.7);
    togInfoOnOff.clicking = ax::Color(0.65);
    togInfoOnOff.selected = ax::Color(0.9, 0.4, 0.0);
    togInfoOnOff.selected_hover = ax::Color(0.95, 0.4, 0.0);
    togInfoOnOff.selected_clicking = ax::Color(0.85, 0.4, 0.0);
    togInfoOnOff.contour = ax::Color(0.0);
    togInfoOnOff.img = "";
    togInfoOnOff.single_img = false;
    togInfoOnOff.font_color = ax::Color(0.0);
    togInfoOnOff.selected_font_color = ax::Color(1.0);
    togInfoOnOff.font_size = 10;
    
    ax::Size toggleSizeOnOff(30, 14);
    ax::Size knobSize(36, 36);
    ax::Size labelSize(36, 20);
    
    axKnob::Info knob_info(ax::Color(0.0, 0.0),
                           ax::Color(0.0, 0.0),
                           ax::Color(0.0, 0.0),
                           128,
                           knobSize,
                           std::string("greyKnob.png"),
                           std::string("greyKnob.png"));
    
    // Create all 8 bands.
    BandControl band_ctrl(0, false, GetOnP1FreqChange(),
                          GetOnP1QChange(),
                          GetOnP1AmpChange(),
                          GetOnToggleF1());
    
    ax::Point next_pos(ax::Point(18, 270));
    for(int i = 0; i < 8; i++)
    {
        if(i > 0 && i < 7)
        {
            band_ctrl.as_amp = true;
        }
        else
        {
            band_ctrl.as_amp = false;
        }
        
        band_ctrl.num = i + 1;
        next_pos = CreateFilterBandControls(this,
                                            next_pos,
                                            band_ctrl, knobSize, knob_info,
                                            togInfoOnOff, toggleSizeOnOff,
                                            labelInfo, labelSize);
    }
}

void axParametricEq::Resize(const ax::Size& size)
{
    _filter->SetSize(ax::Size(size.x - 20, 200));
}

void axParametricEq::OnToggleF1(const axToggle::Msg& msg)
{
    int index = stoi(msg.GetMsg()) - 1;
    _filter->SetActive(index, msg.GetSelected());
    
//    Audio* audio = GetApp()->GetResourceManager()->GetResource("Audio");
//    audio->SetActive(index, msg.GetSelected());
}

void axParametricEq::OnP1FreqChange(const axKnob::Msg& msg)
{
    ax::Print("Freq value change");
    double f = ax::Audio::LogarithmicInterpole<double>(20.0,
                                                       20000.0,
                                                       msg.GetValue());
    
    int index = stoi(msg.GetMsg()) - 1;
    _filter->SetFrequency(index, f);
    
//    Audio* audio = GetApp()->GetResourceManager()->GetResource("Audio");
//    audio->SetFreq(index, f);
}

void axParametricEq::OnP1QChange(const axKnob::Msg& msg)
{
    double q = ax::Audio::LineairInterpole(0.1, 5.0, msg.GetValue());
    
    int index = stoi(msg.GetMsg()) - 1;
    _filter->SetQ(index, q);
    
//    Audio* audio = GetApp()->GetResourceManager()->GetResource("Audio");
//    audio->SetQ(index, q);
}

void axParametricEq::OnP1AmpChange(const axKnob::Msg& msg)
{
    double amp = ax::Audio::LineairInterpole(0.1, 1.9, msg.GetValue());
    
    int index = stoi(msg.GetMsg()) - 1;
    _filter->SetAmp(index, amp);
    
//    Audio* audio = GetApp()->GetResourceManager()->GetResource("Audio");
//    audio->SetAmp(index, amp);
}

void axParametricEq::OnPaint()
{
    ax::GC gc;
    ax::Rect rect(GetDrawingRect());
    
    gc.DrawRectangleColorFade(rect, ax::Color(0.8), ax::Color(0.9));
    
//    gc.SetColor(ax::Color(0.45));
//    gc.DrawRectangle(ax::Rect(0, 0, rect.size.x, 30));
}
