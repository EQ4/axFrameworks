#include "main.h"
#include "axWindowManager.h"
#include "axWindowTree.h"
#include "axSlider.h"

NumberScroll::NumberScroll(ax::Window* parent, const ax::Rect& rect, const int& num):
axKnob(parent,
       rect,
       axKnob::Events(),
       axKnob::Info(ax::Color(0.6),
                    ax::Color(0.6),
                    ax::Color(0.6),
                    num,
                    ax::Size(20, 20),
                    "", "")),
_font(0)
{
    _font.SetFontSize(50);
}

void NumberScroll::OnPaint()
{
    ax::GC gc;

    gc.SetColor(ax::Color(1.0, 0.6));
    
    std::string num = m_nCurrentImg > 9 ? std::to_string(m_nCurrentImg) : "0" + std::to_string(m_nCurrentImg);
    gc.DrawString(_font, num, ax::Point(0, 0));
}




AMPMScroll::AMPMScroll(ax::Window* parent, const ax::Rect& rect):
axKnob(parent, rect, axKnob::Events(),
       axKnob::Info(ax::Color(0.6), ax::Color(0.6), ax::Color(0.6),
                    2, ax::Size(20, 20), "", "")),
_font(0)
{
    _font.SetFontSize(50);
}

void AMPMScroll::OnPaint()
{
    ax::GC gc;
    ax::Rect rect(GetDrawingRect());
    
    //gc.SetColor(ax::Color(0.6, 1.0));
    //gc.DrawRectangle(ax::Rect(0, 0, rect.size.x + 1, rect.size.y + 1));
    
    gc.SetColor(ax::Color(1.0, 0.6));
    
    std::string num = m_nCurrentImg ? "PM" : "AM";
    gc.DrawString(_font, num, ax::Point(0, 0));
    
    //ax::Print(m_nCurrentImg);
}




Alarm::AlarmSet::AlarmSet(ax::Window* parent, const ax::Rect& rect):
ax::Window(parent, rect),
_font(0)
{
    _font.SetFontSize(50);
    
    _tog_on = new ax::Image("toggle_on.png");
    
    ax::Button::Info info(ax::Color(0.8, 0.9),
                          ax::Color(0.8, 0.9),
                          ax::Color(0.8, 0.9),
                          ax::Color(0.8, 0.9),
                          ax::Color(0.8, 0.9),
                          ax::Color(0.8, 0.9),
                          0);
    
    NumberScroll* hours = new NumberScroll(this, ax::Rect(10, 5, 55, 55), 12);
    
    NumberScroll* mins = new NumberScroll(this, ax::Rect(78, 5, 55, 55), 60);
    
    AMPMScroll* am_pm = new AMPMScroll(this, ax::Rect(138, 5, 75, 55));
}

void Alarm::AlarmSet::OnPaint()
{
    ax::GC gc;
    ax::Rect rect(GetDrawingRect());
    
    gc.SetColor(ax::Color(0.6, 0.3));
    gc.DrawRectangle(ax::Rect(0, 0, rect.size.x + 1, rect.size.y + 1));
    
    gc.SetColor(ax::Color(1.0, 0.6));
    gc.DrawString(_font, ":", ax::Point(63, 2));
    
    gc.DrawImage(_tog_on, ax::Point(rect.size.x - 100, 13));
    
    gc.SetColor(ax::Color(0.8, 0.3));
    gc.DrawRectangleContour(ax::Rect(0, 0, rect.size.x + 1, rect.size.y + 1));
}




Alarm::Alarm(ax::Window* parent, const ax::Rect& rect):
ax::Window(parent, rect),
_font(0)
{
    _font.SetFontSize(20);
    
    _bg_img = new ax::Image("bg0.png");

    ax::Button::Info info(ax::Color(0.8, 0.0),
                          ax::Color(0.8, 0.0),
                          ax::Color(0.8, 0.0),
                          ax::Color(0.8, 0.0),
                          ax::Color(0.8, 0.0),
                          ax::Color(0.8, 0.0),
                          0);
    
    ax::Event::Function exit_fct([=](ax::Event::Msg* msg){ Hide(); });
    
    ax::Button* btn = new ax::Button(this, ax::Rect(5, 0, 30, 30),
                                     exit_fct, info, "back.png", "",
                                     ax::Button::Flags::SINGLE_IMG);
    
    AlarmSet* a0 = new AlarmSet(this, ax::Rect(0, 30, rect.size.x, 70));
    AlarmSet* a1 = new AlarmSet(this, ax::Rect(0, 30 + 70, rect.size.x, 70));
    AlarmSet* a2 = new AlarmSet(this, ax::Rect(0, 30 + 2 * 70, rect.size.x, 70));
}

void Alarm::OnPaint()
{
    ax::GC gc;
    ax::Rect rect(GetDrawingRect());
    
    gc.DrawImage(_bg_img, ax::Point(0, 0));
    
    
    gc.SetColor(ax::Color(1.0));
    gc.DrawString(_font, "08:43", ax::Point(45, 4));

    gc.DrawString(_font, "Monday 21/09/2015", ax::Point(rect.size.x - 195, 4));
}



Settings::Settings(ax::Window* parent, const ax::Rect& rect):
ax::Window(parent, rect),
_font(0)
{
    _font.SetFontSize(20);
    
    _bg_img = new ax::Image("bg0.png");
    
    ax::Button::Info info(ax::Color(0.8, 0.0),
                          ax::Color(0.8, 0.0),
                          ax::Color(0.8, 0.0),
                          ax::Color(0.8, 0.0),
                          ax::Color(0.8, 0.0),
                          ax::Color(0.8, 0.0),
                          0);
    
    ax::Event::Function exit_fct([=](ax::Event::Msg* msg){ Hide(); });
    
    ax::Button* btn = new ax::Button(this, ax::Rect(5, 0, 30, 30),
                                     exit_fct, info, "back.png", "",
                                     ax::Button::Flags::SINGLE_IMG);
    
    axSliderInfo sld_info("SliderButton.png",
                          ax::Size(42, 43),
                          ax::Color(1.0, 0.0),
                          ax::Color(1.0, 0.0),
                          ax::Color(1.0, 0.0),
                          ax::Color(1.0, 0.0, 0.0),
                          ax::Color(1.0, 0.0),
                          ax::Color(1.0, 0.0),
                          ax::Color(1.0, 0.0),
                          ax::Color(0.0, 1.0),
                          ax::Color(1.0, 0.0),
                          ax::Color(1.0, 0.0),
                          20,
                          0);
    
    axSlider* sld = new axSlider(this, ax::Rect(20, 50, 200, 42), axSliderEvents(), sld_info);
}

void Settings::OnPaint()
{
    ax::GC gc;
    ax::Rect rect(GetDrawingRect());
    
    gc.DrawImage(_bg_img, ax::Point(0, 0));
    
    
    gc.SetColor(ax::Color(1.0));
    gc.DrawString(_font, "08:43", ax::Point(45, 4));
    
    gc.DrawString(_font, "Monday 21/09/2015", ax::Point(rect.size.x - 195, 4));
}




AlarmClock::AlarmClock(ax::App* app, const ax::Rect& rect):
ax::Window(app, rect),
_font(0),
_font_clock("alarm_clock.ttf")
{
    _font.SetFontSize(20);
    _font_clock.SetFontSize(110);
    
    _bg_img = new ax::Image("bg0.png");
    
    ax::Button::Info info(ax::Color(0.8, 0.1),
                          ax::Color(0.8, 0.1),
                          ax::Color(0.8, 0.1),
                          ax::Color(0.8, 0.1),
                          ax::Color(0.8, 0.1),
                          ax::Color(0.8, 0.1),
                          0);
    
    int delta = 10;
    ax::Size btn_size(92, 92);
    ax::Point btn_pos(delta + 2, rect.size.y - btn_size.y - delta);
    ax::StringVector imgs = {"set5.png", "show6.png", "settings49.png"};
    ax::Event::Function evts[] = { GetOnAlarmPanel(), GetOnAppsPanel(), GetOnSettingsPanel() };
    
    
    for(int i = 0; i < 3; i++)
    {
        ax::Button* btn = new ax::Button(this, ax::Rect(btn_pos, btn_size),
                                         evts[i], info, imgs[i], "",
                                         ax::Button::Flags::SINGLE_IMG);
        
        btn_pos = btn->GetRect().GetNextPosRight(delta);
        
    }
    
    _alarm = new Alarm(this, rect);
    _alarm->Hide();
    
    _settings = new Settings(this, rect);
    _settings->Hide();
    
    axWindowTree* tree = GetApp()->GetWindowManager()->GetWindowTree();
    axWindowNode* node = tree->Get(this);
    
}

void AlarmClock::OnAlarmPanel(const ax::Button::Msg& msg)
{
    _alarm->Show();
}

void AlarmClock::OnAppsPanel(const ax::Button::Msg& msg)
{
    
}

void AlarmClock::OnSettingsPanel(const ax::Button::Msg& msg)
{
    _settings->Show();
}

void AlarmClock::OnPaint()
{
    ax::GC gc;
    ax::Rect rect(GetDrawingRect());
    
    gc.SetColor(ax::Color(0.84));
    gc.DrawRectangle(ax::Rect(0, 0, rect.size.x + 1, rect.size.y + 1));
    
    // Draw background.
    gc.DrawImage(_bg_img, ax::Point(0, 0));
    
    // Draw date.
    gc.SetColor(ax::Color(1.0));
    gc.DrawString(_font, "Monday 21/09/2015", ax::Point(rect.size.x - 195, 4));
    
    // Draw time.
    gc.SetColor(ax::Color(1.0));
    gc.DrawString(_font_clock, "08:43", ax::Point(20, 12));
    
}



int main()
{
    ax::App app;
    
    app.AddMainEntry([&app]()
    {
        app.SetFrameSize(ax::Size(320, 240));
                         
        // Create editor.
        //app.SetEditorInterface(new ax::Editor::Core(&app));
                         
        AlarmClock* panel = new AlarmClock(&app, ax::Rect(0, 0, 320, 240));
        //        panel->AddProperty("AcceptWidget");
    });
    
    app.MainLoop();
    
    return 0;
}
