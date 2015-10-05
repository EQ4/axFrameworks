#ifndef axFrameworks_main_h
#define axFrameworks_main_h

#include "axLib.h"
#include "axButton.h"
#include "axEditor.h"
#include "axKnob.h"

class NumberScroll : public axKnob
{
public:
    NumberScroll(ax::Window* parent, const ax::Rect& rect, const int& num);
    
private:
    ax::Font _font;
    
    virtual void OnPaint();
};

class AMPMScroll : public axKnob
{
public:
    AMPMScroll(ax::Window* parent, const ax::Rect& rect);
    
private:
    ax::Font _font;
    
    virtual void OnPaint();
};

class Alarm : public ax::Window
{
public:
    class AlarmSet : public ax::Window
    {
    public:
        AlarmSet(ax::Window* parent, const ax::Rect& rect);
        
    private:
        ax::Font _font;
        ax::Image* _tog_on;
        virtual void OnPaint();
    };
    
    
    Alarm(ax::Window* parent, const ax::Rect& rect);
    
private:
    ax::Font _font;
    ax::Image* _bg_img;
    
    
    virtual void OnPaint();
};

class Settings : public ax::Window
{
public:
    Settings(ax::Window* parent, const ax::Rect& rect);
    
private:
    ax::Image* _bg_img;
    ax::Font _font;
    
    virtual void OnPaint();
};



class AlarmClock : public ax::Window
{
public:
//    AlarmClock(ax::Window* parent, const ax::Rect& rect);
    AlarmClock(ax::App* app, const ax::Rect& rect);
    
private:
    ax::Font _font, _font_clock;
    ax::Image* _bg_img;
    ax::Image* _img_test;
    
    Alarm* _alarm;
    Settings* _settings;
    
    axEVENT_ACCESSOR(ax::Button::Msg, OnAlarmPanel);
    void OnAlarmPanel(const ax::Button::Msg& msg);
    
    axEVENT_ACCESSOR(ax::Button::Msg, OnAppsPanel);
    void OnAppsPanel(const ax::Button::Msg& msg);
    
    axEVENT_ACCESSOR(ax::Button::Msg, OnSettingsPanel);
    void OnSettingsPanel(const ax::Button::Msg& msg);
    
    virtual void OnPaint();
};

#endif
