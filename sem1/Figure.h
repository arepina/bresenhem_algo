#pragma once
namespace sem1 {
	enum class FigureType {
		Line,
		Circle,
		Ellipse,
		Rect
	};
	ref class Figure
	{
	private:
		FigureType figure_type;
	public:
		int x1, y1, x2, y2, rad_first, rad_second;
		void create_line(int x1, int y1, int x2, int y2);
		void create_circle(int x1, int y1, int rad);
		void create_ellipse(int x1, int y1, int rad_1, int rad_2);
		void create_rect(int x1, int y1, int x2, int y2);
		FigureType getFigureType();
	};
}

