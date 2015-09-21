#include "axLib.h"
#include "axButton.h"
#include "axEditor.h"

class MainPanel : public ax::Window
{
public:
    MainPanel(ax::App* app, const ax::Rect& rect):
    ax::Window(app, rect)
    {
        ax::Button::Info info(ax::Color(0.8, 1.0),
                              ax::Color(0.8, 1.0),
                              ax::Color(0.8, 1.0),
                              ax::Color(0.8, 1.0),
                              ax::Color(0.8, 1.0),
                              ax::Color(0.8, 1.0),
                              0);
        
        ax::Button* btn1 = new ax::Button(this, ax::Rect(90, 10, 105, 105),
                                          ax::Button::Events(), info, "", "",
                                          ax::Button::Flags::SINGLE_IMG);
    }
    
private:
    
    virtual void OnPaint()
    {
        ax::GC gc;
        ax::Rect rect(GetDrawingRect());
        
        gc.SetColor(ax::Color(0.84));
        gc.DrawRectangle(ax::Rect(0, 0, rect.size.x + 1, rect.size.y + 1));
        
    }
};


int main()
{
    ax::App app;
    
    app.AddMainEntry([&app]()
    {
        app.SetFrameSize(ax::Size(400, 400));
        
        // Create editor.
        app.SetEditorInterface(new ax::Editor::Core(&app));
        
        MainPanel* panel = new MainPanel(&app, ax::Rect(0, 0, 400, 400));
        panel->AddProperty("AcceptWidget");
    });
    
    app.MainLoop();
    
    return 0;
}
