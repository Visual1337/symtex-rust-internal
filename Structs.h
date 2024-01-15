#pragma once


class Rect {
public:
	float x; // 0x10
	float y; // 0x14
	float wid; // 0x18
	float hei; // 0x1C
	Rect(float x, float y/*top left*/, float x_rightsize, float y_downsize) {
		this->x = x;
		this->y = y;
		wid = x_rightsize;
		hei = y_downsize;
	}
	Rect() {
		this->x = 0;
		this->y = 0;
		wid = 0;
		hei = 0;
	}
	bool Contains(Vector2 point)
	{
		return point.x >= x && point.x < (x + wid) && point.y >= y && point.y < (y + hei);
	}
};

Color RGBA(float speed = 0.0008f)
{
	static int cases = 0;
	static float r = 1.00f, g = 0.00f, b = 1.00f;
	switch (cases) {
	case 0: { r -= speed; if (r <= 0) cases += 1; break; }
	case 1: { g += speed; b -= speed; if (g >= 1) cases += 1; break; }
	case 2: { r += speed; if (r >= 1) cases += 1; break; }
	case 3: { b += speed; g -= speed; if (b >= 1) cases = 0; break; }
	default: { r = 1.00f; g = 0.00f; b = 1.00f; break; }
	}

	return Color(r * 255, g * 255, b * 255, 255);
}

enum class EventType : int {
	MouseDown = 0,
	MouseUp = 1,
	MouseDrag = 3,
	KeyDown = 4,
	KeyUp = 5,
	Repaint = 7
};


//inline short MyGetAsyncKeyState(int vKey)
//{
//	return Unity::GetKeyInt(vKey);
//}





