//
//  EqGUI.h
//  axVstSynth
//
//  Created by Alexandre Arsenault on 2015-03-02.
//  Copyright (c) 2015 Alexandre Arsenault. All rights reserved.
//

#ifndef __axVstSynth__EqGUI__
#define __axVstSynth__EqGUI__

#include "axLib.h"
#include "FilterParametric.h"
#include "axToggle.h"
#include "axKnob.h"

class axParametricEq : public axPanel
{
public:
    axParametricEq(axWindow* parent, const ax::Rect& rect);
    
    void Resize(const ax::Size& size);
    
private:
    FilterParametric* _filter;
    
    axEVENT_ACCESSOR(axToggle::Msg, OnToggleF1);
    void OnToggleF1(const axToggle::Msg& msg);

    axEVENT_ACCESSOR(axKnob::Msg, OnP1FreqChange);
    void OnP1FreqChange(const axKnob::Msg& msg);
    
    axEVENT_ACCESSOR(axKnob::Msg, OnP1QChange);
    void OnP1QChange(const axKnob::Msg& msg);
    
    axEVENT_ACCESSOR(axKnob::Msg, OnP1AmpChange);
    void OnP1AmpChange(const axKnob::Msg& msg);

    virtual void OnPaint();
};


#endif /* defined(__axVstSynth__EqGUI__) */
