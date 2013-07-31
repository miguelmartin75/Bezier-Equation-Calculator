#ifndef __POINT2D_H__
#define __POINT2D_H__

#include <ostream>

struct point2d
{
	
	float x, y;
	
	point2d() : x(0), y(0) {}
	point2d(float X, float Y) : x(X), y(Y) {}
	
	bool operator==(const point2d& point) const
	{ return x == point.x && y == point.y; }
	bool operator!=(const point2d& point) const
	{ return !operator ==(point); }
	
	point2d& operator=(const point2d& point)
	{
		x = point.x;
		y = point.y;
		
		return *this;
	}
	
	friend std::ostream& operator<<(std::ostream&, const point2d&);
	friend std::istream& operator>>(std::istream&, point2d&);
};


#endif // __POINT2D_H__