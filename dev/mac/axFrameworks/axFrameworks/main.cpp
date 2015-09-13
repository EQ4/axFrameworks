#include "axLib.h"

int main()
{
    ax::App app(ax::Size(500, 500));
    
    app.AddMainEntry([&app]()
    {
        axPanel* panel = new axPanel(&app, ax::Rect(0, 0, 500, 500));
    });
    
    app.MainLoop();
    
    return 0;
}
