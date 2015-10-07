#include "axLib.h"
#include "axButton.h"
#include <iostream>

class MyPanel : public axPanel
{
public:
	MyPanel(ax::App* app, const ax::Rect& rect):
		axPanel(app, rect)
	{
		ax::Button* btn = new ax::Button(this, ax::Rect(100, 100, 50, 50),
										 ax::Button::Events(),
										 ax::Button::Info(ax::Color(0.3),
							                              ax::Color(0.4),
							                              ax::Color(0.5),
							                              ax::Color(0.3),
							                              ax::Color(0.0),
							                              ax::Color(1.0)), 
										 "", "Test");
	}

	virtual void OnPaint()
	{
		ax::Print("Draw mypanel.");
		ax::GC gc;
		ax::Rect rect(GetDrawingRect());

		gc.SetColor(ax::Color(0.0, 1.0, 0.0));
		gc.DrawRectangle(rect);

		gc.SetColor(ax::Color(0.0, 1.0, 1.0));
		gc.DrawRectangle(ax::Rect(20, 20, 50, 50));
	}
};

int main()
{
	ax::App app(ax::Size(500, 500));

	app.AddMainEntry([&app]()
	{
		MyPanel* frame = new MyPanel(&app, ax::Rect(0, 0, 500, 500));
	});

	app.MainLoop();
	return 0;
}