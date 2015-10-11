#include "main.h"
#include "axWindowManager.h"
#include "axWindowTree.h"
#include "axSlider.h"
#include "axNumberBox.h"
#include "axTextBox.h"
#include "axKnob.h"

#include "axMathVector.h"
#include "axFrameBuffer.h"
//
//NumberScroll::NumberScroll(ax::Window* parent, const ax::Rect& rect, const int& num):
//ax::Knob(parent,
//       rect,
//         ax::Knob::Events(),
//         ax::Knob::Info(ax::Color(0.6),
//                    ax::Color(0.6),
//                    ax::Color(0.6),
//                    num,
//                    ax::Size(20, 20),
//                    "", "")),
//_font(0)
//{
//    _font.SetFontSize(50);
//}
//
//void NumberScroll::OnPaint()
//{
//    ax::GC gc;
//    gc.SetColor(ax::Color(1.0, 0.6));
//    
//    std::string num = m_nCurrentImg > 9 ? std::to_string(m_nCurrentImg) : "0" + std::to_string(m_nCurrentImg);
//    gc.DrawString(_font, num, ax::Point(0, 0));
//}
//
//
//
//
//AMPMScroll::AMPMScroll(ax::Window* parent, const ax::Rect& rect):
//ax::Knob(parent, rect, ax::Knob::Events(),
//         ax::Knob::Info(ax::Color(0.6), ax::Color(0.6), ax::Color(0.6),
//                    2, ax::Size(20, 20), "", "")),
//_font(0)
//{
//    _font.SetFontSize(50);
//}
//
//void AMPMScroll::OnPaint()
//{
//    ax::GC gc;
//    ax::Rect rect(GetDrawingRect());
//    
//    //gc.SetColor(ax::Color(0.6, 1.0));
//    //gc.DrawRectangle(ax::Rect(0, 0, rect.size.x + 1, rect.size.y + 1));
//    
//    gc.SetColor(ax::Color(1.0, 0.6));
//    
//    std::string num = m_nCurrentImg ? "PM" : "AM";
//    gc.DrawString(_font, num, ax::Point(0, 0));
//    
//    //ax::Print(m_nCurrentImg);
//}
//
//
//
//
//Alarm::AlarmSet::AlarmSet(ax::Window* parent, const ax::Rect& rect):
//ax::Window(parent, rect),
//_font(0)
//{
//    _font.SetFontSize(50);
//    
//    _tog_on = new ax::Image("toggle_on.png");
//    
//    ax::Button::Info info(ax::Color(0.8, 0.9),
//                          ax::Color(0.8, 0.9),
//                          ax::Color(0.8, 0.9),
//                          ax::Color(0.8, 0.9),
//                          ax::Color(0.8, 0.9),
//                          ax::Color(0.8, 0.9),
//                          0);
//    
//    NumberScroll* hours = new NumberScroll(this, ax::Rect(10, 5, 55, 55), 12);
//    
//    NumberScroll* mins = new NumberScroll(this, ax::Rect(78, 5, 55, 55), 60);
//    
//    AMPMScroll* am_pm = new AMPMScroll(this, ax::Rect(138, 5, 75, 55));
//}
//
//void Alarm::AlarmSet::OnPaint()
//{
//    ax::GC gc;
//    ax::Rect rect(GetDrawingRect());
//    
//    gc.SetColor(ax::Color(0.6, 0.3));
//    gc.DrawRectangle(ax::Rect(0, 0, rect.size.x + 1, rect.size.y + 1));
//    
//    gc.SetColor(ax::Color(1.0, 0.6));
//    gc.DrawString(_font, ":", ax::Point(63, 2));
//    
//    gc.DrawImage(_tog_on, ax::Point(rect.size.x - 100, 13));
//    
//    gc.SetColor(ax::Color(0.8, 0.3));
//    gc.DrawRectangleContour(ax::Rect(0, 0, rect.size.x + 1, rect.size.y + 1));
//}
//
//
//
//
//Alarm::Alarm(ax::Window* parent, const ax::Rect& rect):
//ax::Window(parent, rect),
//_font(0)
//{
//    _font.SetFontSize(20);
//    
//    _bg_img = new ax::Image("bg0.png");
//
//    ax::Button::Info info(ax::Color(0.8, 0.0),
//                          ax::Color(0.8, 0.0),
//                          ax::Color(0.8, 0.0),
//                          ax::Color(0.8, 0.0),
//                          ax::Color(0.8, 0.0),
//                          ax::Color(0.8, 0.0),
//                          0);
//    
//    ax::Event::Function exit_fct([=](ax::Event::Msg* msg){ Hide(); });
//    
//    ax::Button* btn = new ax::Button(this, ax::Rect(5, 0, 30, 30),
//                                     exit_fct, info, "back.png", "",
//                                     ax::Button::Flags::SINGLE_IMG);
//    
//    AlarmSet* a0 = new AlarmSet(this, ax::Rect(0, 30, rect.size.x, 70));
//    AlarmSet* a1 = new AlarmSet(this, ax::Rect(0, 30 + 70, rect.size.x, 70));
//    AlarmSet* a2 = new AlarmSet(this, ax::Rect(0, 30 + 2 * 70, rect.size.x, 70));
//}
//
//void Alarm::OnPaint()
//{
//    ax::GC gc;
//    ax::Rect rect(GetDrawingRect());
//    
//    gc.DrawImage(_bg_img, ax::Point(0, 0));
//    
//    
//    gc.SetColor(ax::Color(1.0));
//    gc.DrawString(_font, "08:43", ax::Point(45, 4));
//
//    gc.DrawString(_font, "Monday 21/09/2015", ax::Point(rect.size.x - 195, 4));
//}
//
//
//
//Settings::Settings(ax::Window* parent, const ax::Rect& rect):
//ax::Window(parent, rect),
//_font(0)
//{
//    _font.SetFontSize(20);
//    
//    _bg_img = new ax::Image("bg0.png");
//    
//    ax::Button::Info info(ax::Color(0.8, 0.0),
//                          ax::Color(0.8, 0.0),
//                          ax::Color(0.8, 0.0),
//                          ax::Color(0.8, 0.0),
//                          ax::Color(0.8, 0.0),
//                          ax::Color(0.8, 0.0),
//                          0);
//    
//    ax::Event::Function exit_fct([=](ax::Event::Msg* msg){ Hide(); });
//    
//    ax::Button* btn = new ax::Button(this, ax::Rect(5, 0, 30, 30),
//                                     exit_fct, info, "back.png", "",
//                                     ax::Button::Flags::SINGLE_IMG);
//    
//    axSliderInfo sld_info("SliderButton.png",
//                          ax::Size(42, 43),
//                          ax::Color(1.0, 0.0),
//                          ax::Color(1.0, 0.0),
//                          ax::Color(1.0, 0.0),
//                          ax::Color(1.0, 0.0, 0.0),
//                          ax::Color(1.0, 0.0),
//                          ax::Color(1.0, 0.0),
//                          ax::Color(1.0, 0.0),
//                          ax::Color(0.0, 1.0),
//                          ax::Color(1.0, 0.0),
//                          ax::Color(1.0, 0.0),
//                          20,
//                          0);
//    
//    ax::Slider* sld = new ax::Slider(this, ax::Rect(20, 50, 200, 42), axSliderEvents(), sld_info);
//}
//
//void Settings::OnPaint()
//{
//    ax::GC gc;
//    ax::Rect rect(GetDrawingRect());
//    
//    gc.DrawImage(_bg_img, ax::Point(0, 0));
//    
//    
//    gc.SetColor(ax::Color(1.0));
//    gc.DrawString(_font, "08:43", ax::Point(45, 4));
//    
//    gc.DrawString(_font, "Monday 21/09/2015", ax::Point(rect.size.x - 195, 4));
//}
//
//
//
//
//AlarmClock::AlarmClock(ax::App* app, const ax::Rect& rect):
////AlarmClock::AlarmClock(ax::Window* parent, const ax::Rect& rect):
//
//ax::Window(app, rect),
//_font(0),
//_font_clock("alarm_clock.ttf")
//{
//    _font.SetFontSize(20);
//    _font_clock.SetFontSize(110);
//    
//    _bg_img = new ax::Image("bg0.png");
//    _img_test = new ax::Image("toggle_on.png");
//    
//    ax::Button::Info info(ax::Color(0.8, 0.1),
//                          ax::Color(0.8, 0.1),
//                          ax::Color(0.8, 0.1),
//                          ax::Color(0.8, 0.1),
//                          ax::Color(0.8, 0.1),
//                          ax::Color(0.8, 0.1),
//                          0);
//    
//    int delta = 10;
//    ax::Size btn_size(92, 92);
//    ax::Point btn_pos(delta + 2, rect.size.y - btn_size.y - delta);
//    ax::StringVector imgs = {"set5.png", "show6.png", "settings49.png"};
//    ax::Event::Function evts[] = { GetOnAlarmPanel(), GetOnAppsPanel(), GetOnSettingsPanel() };
//    
//    
//    for(int i = 0; i < 3; i++)
//    {
//        ax::Button* btn = new ax::Button(this, ax::Rect(btn_pos, btn_size),
//                                         evts[i], info, imgs[i], "",
//                                         ax::Button::Flags::SINGLE_IMG);
//        
//        btn_pos = btn->GetRect().GetNextPosRight(delta);
//        
//    }
//    
//    _alarm = new Alarm(this, rect);
//    _alarm->Hide();
//    
//    _settings = new Settings(this, rect);
//    _settings->Hide();
//    
////    axWindowTree* tree = GetApp()->GetWindowManager()->GetWindowTree();
////    axWindowNode* node = tree->Get(this);
//    
//}
//
//void AlarmClock::OnAlarmPanel(const ax::Button::Msg& msg)
//{
//    _alarm->Show();
//}
//
//void AlarmClock::OnAppsPanel(const ax::Button::Msg& msg)
//{
//    
//}
//
//void AlarmClock::OnSettingsPanel(const ax::Button::Msg& msg)
//{
//    _settings->Show();
//}
//
//void AlarmClock::OnPaint()
//{
//    ax::GC gc;
//    ax::Rect rect(GetDrawingRect());
//    
//    gc.SetColor(ax::Color(0.84));
//    gc.DrawRectangle(ax::Rect(0, 0, rect.size.x + 1, rect.size.y + 1));
//    
//    // Draw background.
//    gc.DrawImage(_bg_img, ax::Point(0, 0));
//    
//    
//    
//    // Draw date.
//    gc.SetColor(ax::Color(1.0));
//    gc.DrawString(_font, "Monday 21/09/2015", ax::Point(rect.size.x - 195, 4));
//    
//    // Draw time.
//    gc.SetColor(ax::Color(1.0));
//    gc.DrawString(_font_clock, "08:43", ax::Point(20, 12));
//    
//    gc.DrawImage(_img_test, ax::Point(50, 50), 0.2);
//    
//}
//
//
//
//class MyPanel : public ax::Panel3D
//{
//public:
//    MyPanel(ax::Window* parent,const ax::Rect& rect, AlarmClock* alarm):
//    ax::Panel3D(parent, rect),
//    _alarm(alarm)
//    {
//        
//    }
//    
//private:
//    AlarmClock* _alarm;
//    
//    
//    void DrawQuad(ax::Math::Vec3<double>* vecs,
//                  ax::Color* colors = nullptr,
//                  ax::Math::Vec3<double>* texs = nullptr,
//                  unsigned int tex_id = 0)
//    {
//        glEnableClientState(GL_VERTEX_ARRAY);
//        glVertexPointer(3, GL_DOUBLE, 0, vecs);
//        
//        if(texs != nullptr)
//        {
//            glEnable(GL_TEXTURE_2D);
//            glBindTexture(GL_TEXTURE_2D, tex_id);
//            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//            
//            double tex_coord[8] = {0.0, 0.0,  1.0, 0.0,  1.0, 1.0,  0.0, 1.0 };
//            glTexCoordPointer(2, GL_DOUBLE, 0, tex_coord);
//            
//           
//        }
//        
//        if(colors != nullptr)
//        {
//            glEnableClientState(GL_COLOR_ARRAY);
//            glColorPointer(4, GL_DOUBLE, 0, colors);
//        }
//        
//        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
//    
//        glDisableClientState(GL_COLOR_ARRAY);
//        glDisableClientState(GL_VERTEX_ARRAY);
//        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//
//    }
//    
//    virtual void OnPaint3D()
//    {
//        glTranslated(0.0, 0.0, -2.5);
////        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
//        
//        ax::GC gc;
//        glEnable(GL_LINE_SMOOTH);       glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
//        glEnable(GL_POLYGON_SMOOTH);    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
//        
//        using Vec3 = ax::Math::Vec3<double>;
//        
//        Vec3 quad[4] = { Vec3(0.00,  0.00,  0.00),
//                         Vec3(0.75,  0.00, -2.00),
//                         Vec3(0.75,  0.75, -2.00),
//                         Vec3(0.00,  0.75,  0.00) };
//        
//        Vec3 tex[4] = { Vec3(0.0, 0.0, 0.0),
//            Vec3(1.0, 0.0, 0.0),
//            Vec3(1.0, 1.0, 0.0),
//            Vec3(0.0, 1.0, 0.0) };
//        
//        ax::Color colors[4] = { ax::Color(1.0, 0.0, 0.0),
//                                ax::Color(0.0, 1.0, 0.0),
//                                ax::Color(0.0, 0.0, 1.0),
//                                ax::Color(1.0, 1.0, 0.0) };
//        
//        Vec3 quad2[4] = { Vec3(-1.00,  0.00,  0.00),
//                          Vec3( 0.00,  0.00,  0.00),
//                          Vec3( 0.00,  0.75,  0.00),
//                          Vec3(-1.00,  0.75,  0.00) };
//        
//        glLineWidth(2);
//        gc.SetColor(ax::Color(0.5));
//        
//        
//        DrawQuad(quad2, nullptr, tex, _alarm->GetFrameBuffer()->GetFrameBufferTexture());
//        DrawQuad(quad, nullptr, tex, _alarm->GetFrameBuffer()->GetFrameBufferTexture());
//        
//        glDisableClientState(GL_COLOR_ARRAY);
//        glDisableClientState(GL_VERTEX_ARRAY);
//        
//        
//        
//        
//        glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
//        
//        glDisable(GL_LINE_SMOOTH);
//        glDisable(GL_POLYGON_SMOOTH);
//    }
//    
//    virtual void OnPaint()
//    {
//        ax::GC gc;
//        ax::Rect rect(GetDrawingRect());
//        
//        gc.SetColor(ax::Color(1.0));
//        gc.DrawRectangle(rect);
//        
//        gc.SetColor(ax::Color(0.0, 0.0, 0.0));
//        gc.DrawRectangleContour(rect);
//    }
//};
//
//
//
//
//




//int main()
//{
//    ax::App app;
//    
//    app.AddMainEntry([&app]()
//    {
////        
////        app.SetFrameSize(ax::Size(500, 500));
//        
////        axPanel* frame = new axPanel(&app, ax::Rect(0, 0, 500, 500));
////        AlarmClock* alarm = new AlarmClock(frame, ax::Rect(0, 0, 320, 240));
//////        alarm->Hide();
////        GLuint text_id = alarm->GetFrameBuffer()->GetFrameBufferTexture();
////        MyPanel* panel3d = new MyPanel(frame, ax::Rect(0, 0, 500, 500), alarm);
////
//        
//        app.SetFrameSize(ax::Size(320, 240));
//        
//        // Create editor.
////        app.SetEditorInterface(new ax::Editor::Core(&app));
//        
//        AlarmClock* panel = new AlarmClock(&app, ax::Rect(0, 0, 320, 240));
//                panel->AddProperty("AcceptWidget");
//    });
//    
//    app.MainLoop();
//    
//    return 0;
//}

//class CPanel : public ax::Window
//{
//public:
//    CPanel(ax::App* app, const ax::Rect& rect):
//    ax::Window(app, rect),
//    _font(0)
//    {
//        // Connect base events.
//        event.OnPaint = ax::WBind<ax::GC>(this, &CPanel::OnPaint);
//        event.OnMouseLeftDown = ax::WBind<ax::Point>(this, &CPanel::Shit);
//
//        
//        auto btn1 = node.Add(ax::Button::Create(shared_from_this(),
//                                                ax::Point(10, 50),
//                                                GetOnPush(), "Push"));
//        
//        node.Add(ax::Button::Create(shared_from_this(),
//                                    btn1->dimension.GetRect().GetNextPosRight(10),
//                                    GetOnPop(), "Pop"));
//        
//        
//        node.Add(_box1 = ax::NumberBox::Create(shared_from_this(),
//                                               ax::Point(10, 85)));
//        
//        node.Add(_box2 = ax::NumberBox::Create(shared_from_this(),
//                                               _box1->dimension.GetRect().GetNextPosDown(10)));
//
////        ax::TextBox::Events txt_evts;
////        txt_evts.enter_click = GetOnTextEnter();
////        _txt1 = new ax::TextBox(this, ax::Rect(200, 50, 200, 25), txt_evts);
////        
////        ax::Label* lab1 = new ax::Label(this, ax::Rect(10, 10, 50, 25), "Potato");
////        
////        ax::Knob* knob1 = new ax::Knob(this, ax::Point(80, 80));
////        
////        axGrid* grid = new axGrid(this,
////                                  ax::Rect(150, 100, 100, 55),
////                                  axGridEvents(),
////                                  axGridInfo(),
////                                  ax::Size(5, 2));
////        
////        ax::Slider* sld1 = new ax::Slider(this, ax::Rect(270, 100, 100, 15),
////                                          ax::Slider::Events(),
////                                          ax::Slider::Info(),
////                                          axSLIDER_FLAG_CLICK_ANYWHERE);
//    }
//    
//private:
//    ax::Font _font;
//    ax::StringVector _strs;
//    ax::NumberBox::Ptr _box1, _box2;
////    ax::NumberBox *_box1, *_box2;
////    ax::TextBox* _txt1;
////    
//    void Shit(const ax::Point& pt)
//    {
//        std::cout << "Mouse left down : " << pt.x << " " << pt.y << std::endl;
//        
//    }
////
////    std::string GenerateText()
////    {
////        std::string v1 = std::to_string(_box1->GetValue());
////        v1.resize(4);
////        
////        std::string v2 = std::to_string(_box2->GetValue());
////        v2.resize(4);
////        
////        return v1 + " " + v2 + " " +  _txt1->GetLabel();
////    }
////    
////    axEVENT_ACCESSOR(ax::TextBox::Msg, OnTextEnter);
////    void OnTextEnter(const ax::TextBox::Msg& msg)
////    {
////        ax::Print("Push");
////        _strs.push_back(GenerateText());
////        Update();
////    }
////    
//    axEVENT_ACCESSOR(ax::Button::Msg, OnPush);
//    void OnPush(const ax::Button::Msg& msg)
//    {
//        ax::Print("Push");
////        _strs.push_back(GenerateText());
//        Update();
//    }
//    
//    axEVENT_ACCESSOR(ax::Button::Msg, OnPop);
//    void OnPop(const ax::Button::Msg& msg)
//    {
//        ax::Print("Pop");
//        if(_strs.size())
//        {
//            _strs.pop_back();
//            Update();
//        }
//    }
//    
//    void OnPaint(ax::GC gc)
//    {
////        ax::GC gc;
//        ax::Rect rect(dimension.GetDrawingRect());
//        
//        gc.SetColor(ax::Color(0.98));
//        gc.DrawRectangle(rect);
//        
//        
//        ax::Point pos(0, 160);
//        
//        for(int i = 0; i < _strs.size(); i++)
//        {
//            if(i % 2)
//            {
//                gc.SetColor(ax::Color(0.95));
//            }
//            else
//            {
//                gc.SetColor(ax::Color(0.98));
//            }
//            
//            gc.DrawRectangle(ax::Rect(pos, ax::Size(rect.size.x, 20)));
//            gc.SetColor(ax::Color(0.4));
//            gc.DrawString(_font, _strs[i], pos + ax::Point(10, 0));
//            pos.y += 20;
//        }
//        
//        gc.SetColor(ax::Color(0.5));
//        gc.DrawRectangleContour(rect);
//    }
//};



int main()
{
    ax::App& app = ax::App::GetInstance();
    
    app.AddMainEntry([&app]()
    {
        app.SetFrameSize(ax::Size(500, 500));
		
		ax::Window::Ptr win(ax::Window::Create(ax::Rect(0, 0, 500, 500)));
		
        win->event.OnPaint = ax::WFunc<ax::GC>([win](ax::GC gc) {
            ax::Rect rect(win->dimension.GetDrawingRect());
			
			gc.SetColor(ax::Color(0.98));
            gc.DrawRectangle(rect);
        });
        
        ax::Event::Function btn_click([](ax::Event::Msg* msg) {
			ax::Print("Push event");
			});
        
        win->node.Add(ax::Button::Create(win, ax::Point(10, 50),
			btn_click, "Push"));
			
        win->node.Add(ax::NumberBox::Create(win, ax::Point(10, 85)));
        
        
//        std::shared_ptr<CPanel> panel = std::shared_ptr<CPanel>(new CPanel(&app, ax::Rect(0, 0, 500, 500)));
//        app.GetWindowManager()->GetWindowTree()->AddTopLevel(panel);
    });
    
    app.MainLoop();
    
    return 0;
}
