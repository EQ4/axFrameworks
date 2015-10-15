#include "main.h"
#include "axNumberBox.h"

//class Topbar : public ax::Window::Backbone
//{
//public:
//	Topbar()
//	{
//		
//	}
//};

//class CPanel : public ax::Window::Backbone
//{
//public:
//	CPanel(const ax::Rect& rect)
//	{
//		ax::Window::Ptr win = ax::Window::Create(rect);
//		
//		win->event.OnPaint = ax::WBind<ax::GC>(this, &CPanel::OnPaint);
//		
//		win->event.OnMouseLeftDown = ax::WFunc<ax::Point>([](ax::Point pt) {
//			ax::Print("Window click");
//		});
//		
//		win->node.Add(ax::Button::Create(ax::Point(10, 10),
//			ax::Event::Bind(this, &CPanel::OnButtonClick), "Button"));
//		
//		win->node.Add(ax::NumberBox::Create(ax::Point(10, 40),
//			ax::NumberBox::Events()));
//
//		AssignWindow(win);
//	}
//	
//	void OnButtonClick(ax::Event::Msg* msg)
//	{
//		ax::Print("Button click");
//	}
//	
//	void OnPaint(ax::GC gc)
//	{
//		ax::Print("Paint");
//		ax::Rect rect(GetWindow()->dimension.GetDrawingRect());
//		
//		ax::Print("rect ", rect.size.x);
//		
//		gc.SetColor(ax::Color(0.9f, 0.6f, 0.3f));
//		gc.DrawRectangle(rect);
//		
//		gc.SetColor(ax::Color(1.0f, 0.6f, 0.4f));
//		gc.DrawRectangleContour(rect);
//	}
//};

class CPanel : public ax::Window::Backbone
{
public:
	CPanel(const ax::Rect& rect)
	{
		win = ax::Window::Create(rect);
		
		win->event.OnPaint = ax::WBind<ax::GC>(this, &CPanel::OnPaint);
		
		int x_init = 20;
		int delta_x = (rect.size.x - 2 * 20) / 18;
		int delta_y = (rect.size.y - 2 * 20) / 16;
		
		int reste_add_x = 18 / ((rect.size.x - 2 * 20) - 18 * delta_x);
		int reste_add_y = 16 / ((rect.size.y - 2 * 20) - 16 * delta_y);
		
		int x = x_init;
		for(int i = 0; i < 19; i++) {

			_points_width.push_back(x);
			
			if(i % reste_add_x == 0) {
				x++;
			}
			x += delta_x;
		}
		
		int y = x_init;
		for(int i = 0; i < 17; i++) {
			
			if(i == 16) {
				y -= 3;
			}
			
			_points_height.push_back(y);
			
			if(i % reste_add_y == 0) {
				y++;
			}
			
			
			y += delta_y;
		}
		
		
		
		
		
		for(int i = 0; i < 16; i++) {
			for(int j = 0; j < 18; j++) {
				_values[i][j] = 0.0;
			}
		}
		
		_values[0][0] = 130;
		_values[1][0] = 130;
		_values[2][0] = 130;
		
		_values[0][15] = -130;
		_values[1][15] = -130;
		_values[2][15] = -130;
		
		_values[5][5] = 1.0;
		
		
		
		
		for(int k = 0; k < 20; k++) {
			for(int i = 1; i < 14; i++) {
				for(int j = 1; j < 16; j++) {
					ax::Point index(i, j);
					
					if(index.x == 0 || index.y == 0 ||
					   index.x == 15 || index.y == 17) {
						break;
					}
					
					if(index == ax::Point(0, 0) || index == ax::Point(1, 0) ||
					   index == ax::Point(2, 0)) {
						break;
					}
					
					_values[i][j] = (_values[i+1][j] - _values[i-1][j]) * 0.5 +
							(_values[i][j-1] - _values[i][j+1]) * 0.5;
				}
			}
		}
		
		
	}
	
	void OnButtonClick(ax::Event::Msg* msg)
	{
		ax::Print("Button click");
	}
	
	ax::Rect GetRectFromIndex(int w, int h)
	{
		return ax::Rect(_points_width[w], _points_height[h],
				_points_width[w + 1] - _points_width[w],
				_points_height[h + 1] - _points_height[h]);
	}
	
	void OnPaint(ax::GC gc)
	{
		ax::Print("Paint");
		ax::Rect rect(GetWindow()->dimension.GetDrawingRect());
		
		ax::Print("rect ", rect.size.x);
		
		gc.SetColor(ax::Color(1.0f));
		gc.DrawRectangle(rect);
		
		
		
	
		// Draw values
		for(int i = 0; i < 16; i++) {
			for(int j = 0; j < 18; j++) {
				
				double v = _values[i][j];
				
				if(v > 0.0) {
					gc.SetColor(ax::Color(1.0f, 0.0f, 0.0f, v / 130.0));
					gc.DrawRectangle(GetRectFromIndex(j + 1, i + 1));
				} else {
					gc.SetColor(ax::Color(0.0f, 0.0f, 1.0f, v / -130.0));
					gc.DrawRectangle(GetRectFromIndex(j + 1, i + 1));
				}
				
				
			}
		}
		
		
		
		
		
		
		
		
		
		
		gc.SetColor(ax::Color(0.0f, 0.0f, 0.9f, 0.4f));
		
		// Left air border.
		for(int i = 0; i < _points_height.size() - 1; i++) {
			gc.DrawRectangle(GetRectFromIndex(0, i));
		}
		
		// Right air border.
		for(int i = 0; i < _points_height.size() - 1; i++) {
			gc.DrawRectangle(GetRectFromIndex((int)_points_height.size(), i));
		}
		
		// Top air border.
		for(int i = 1; i < _points_width.size() - 2; i++) {
			gc.DrawRectangle(GetRectFromIndex(i, 0));
		}
		
		// Bottom air border.
		for(int i = 1; i < _points_width.size() - 2; i++) {
			gc.DrawRectangle(GetRectFromIndex(i, (int)_points_height.size() - 2));
		}
		
		// Source.
		gc.SetColor(ax::Color(0.5f, 0.4f));
		gc.DrawRectangle(GetRectFromIndex(1, 1));
		gc.DrawRectangle(GetRectFromIndex(1, 2));
		gc.DrawRectangle(GetRectFromIndex(1, 3));
		
		// Drain.
		gc.DrawRectangle(GetRectFromIndex(16, 1));
		gc.DrawRectangle(GetRectFromIndex(16, 2));
		gc.DrawRectangle(GetRectFromIndex(16, 3));
		
		// Yellow.
		gc.SetColor(ax::Color(1.0f, 1.0f, 0.0f, 0.4f));
		for(int i = 0; i < 8; i++) {
			gc.DrawRectangle(GetRectFromIndex(5 + i, 1));
			gc.DrawRectangle(GetRectFromIndex(5 + i, 2));
			gc.DrawRectangle(GetRectFromIndex(5 + i, 3));
		}
		
		for(int i = 0; i < 8; i++) {
			gc.DrawRectangle(GetRectFromIndex(5 + i, 12));
			gc.DrawRectangle(GetRectFromIndex(5 + i, 13));
			gc.DrawRectangle(GetRectFromIndex(5 + i, 14));
		}
		
		
		
		
		
		

		
		
		
		
		
		gc.SetColor(ax::Color(0.0));
		
		for(int i = 0; i < _points_width.size(); i++) {
			gc.DrawLine(ax::Point(_points_width[i], 20),
						ax::Point(_points_width[i], rect.size.y - 19));
		}
		
		for(int i = 0; i < _points_height.size(); i++) {
			gc.DrawLine(ax::Point(19, _points_height[i]),
						ax::Point(rect.size.x - 11, _points_height[i]));
		}

//		int x_init = 20;
//		int delta_x = (rect.size.x - 2 * 20) / 18;
//		int delta_y = (rect.size.y - 2 * 20) / 16;
//		
//		int reste_add_x = 18 / ((rect.size.x - 2 * 20) - 18 * delta_x);
//		int reste_add_y = 16 / ((rect.size.y - 2 * 20) - 16 * delta_y);
//		
//		int x = x_init;
//		for(int i = 0; i < 19; i++) {
//			gc.DrawLine(ax::Point(x, 20), ax::Point(x, rect.size.y - 19));
//			
//			if(i % reste_add_x == 0) {
//				x++;
//			}
//			x += delta_x;
//		}
//		
//		int y = x_init;
//		for(int i = 0; i < 17; i++) {
//		
//			if(i == 16) {
//				y -= 3;
//			}
//			gc.DrawLine(ax::Point(19, y), ax::Point(rect.size.x - 20, y));
//			
//			if(i % reste_add_y == 0) {
//				y++;
//			}
//			
//			y += delta_y;
//		}
		
		gc.SetColor(ax::Color(1.0f));
		gc.DrawRectangleContour(rect);
	}
	
private:
	std::vector<int> _points_width, _points_height;
	double _values[16][18];
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
		
		std::shared_ptr<CPanel> cpanel(new CPanel(ax::Rect(0, 0, 500, 500)));
		win->node.Add(cpanel);
//		
//		ax::Window::Ptr w2 = ax::Window::Create(ax::Rect(20, 20, 20, 20));
//
//		ax::Window::Ptr w1 =
//			win->node.Add(ax::Window::Create(ax::Rect(20, 20, 20, 20)));
//		
//		w1->event.OnPaint = ax::WFunc<ax::GC>([=](ax::GC gc) {
//			ax::Rect rect(w1->dimension.GetDrawingRect());
//			gc.SetColor(ax::Color(0.9f, 0.1f, 0.3f));
//			gc.DrawRectangle(rect);
//		});
	});
	
	app.MainLoop();
	
	return 0;
}







