#include "main.h"

class CPanel : public ax::Window::Backbone
{
public:
	CPanel(const ax::Rect& rect)
	{
		ax::Window::Ptr win = ax::Window::Create(rect);
		
		win->event.OnPaint = ax::WBind<ax::GC>(this, &CPanel::OnPaint);
		
		win->event.OnMouseLeftDown = ax::WFunc<ax::Point>([](ax::Point pt) {
			ax::Print("Window click");
		});
		
		win->node.Add(ax::Button::Create(ax::Point(10, 10),
			ax::Event::Bind(this, &CPanel::OnButtonClick), "Button"));
		
		AssignWindow(win);
	}
	
	void OnButtonClick(ax::Event::Msg* msg)
	{
		ax::Print("Button click");
	}
	
	void OnPaint(ax::GC gc)
	{
		ax::Print("Paint");
		ax::Rect rect(GetWindow()->dimension.GetDrawingRect());
		
		ax::Print("rect ", rect.size.x);
		
		gc.SetColor(ax::Color(0.9f, 0.6f, 0.3f));
		gc.DrawRectangle(rect);
	}
};

int main()
{
    ax::App& app = ax::App::GetInstance();
	
    app.AddMainEntry([&app]()
    {
		app.SetFrameSize(ax::Size(500, 500));
		
		ax::Window::Ptr win(ax::Window::Create(ax::Rect(0, 0, 500, 500)));
		app.AddTopLevel(win);
		
		win->event.OnPaint = ax::WFunc<ax::GC>([win](ax::GC gc) {
			ax::Rect rect(win->dimension.GetDrawingRect());
			
			gc.SetColor(ax::Color(0.98));
			gc.DrawRectangle(rect);
		});
		
		std::shared_ptr<CPanel> cpanel(new CPanel(ax::Rect(100, 100, 100, 100)));
		win->node.Add(cpanel);
		
		ax::Window::Ptr w2 = ax::Window::Create(ax::Rect(20, 20, 20, 20));

		ax::Window::Ptr w1 =
			win->node.Add(ax::Window::Create(ax::Rect(20, 20, 20, 20)));
		
		w1->event.OnPaint = ax::WFunc<ax::GC>([=](ax::GC gc){
			ax::Rect rect(w1->dimension.GetDrawingRect());
			gc.SetColor(ax::Color(0.9f, 0.1f, 0.3f));
			gc.DrawRectangle(rect);

		});

    });
	
    app.MainLoop();
	
    return 0;
}







