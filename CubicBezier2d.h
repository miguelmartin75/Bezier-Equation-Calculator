#ifndef __CUBICBEZIER2D_H__
#define __CUBICBEZIER2D_H__

#include <cmath>

#include "point2d.h"

class CubicBezier2d
{
public:
	
	CubicBezier2d()
	{
	}
	
	CubicBezier2d(const point2d& start, const point2d& controlPoint1, const point2d controlPoint2, const point2d& end)
		: _start(start),
		_end(end),
		_controlPoint1(controlPoint1),
		_controlPoint2(controlPoint2)
	{
	}
	
	point2d& getStart() { return _start; }
	point2d& getEnd() { return _end; }
	const point2d& getStart() const { return _start; }
	const point2d& getEnd() const { return _end; }
	
	point2d& getControlPoint1() { return _controlPoint1; }
	point2d& getControlPoint2() { return _controlPoint2; }
	const point2d& getControlPoint1() const { return _controlPoint1; }
	const point2d& getControlPoint2() const { return _controlPoint2; }
	
	point2d getPoint(double t) const
	{ return point2d(getX(t), getY(t)); }
	
	double getDx() const
	{
		return _start.x;
	}
	double getCx() const
	{
		return 3 * (_controlPoint1.x -_start.x);
	}
	double getBx() const
	{
		return 3 * (_start.x - 2 * _controlPoint1.x + _controlPoint2.x);
	}
	double getAx() const
	{
		return (_end.x + 3 * (_controlPoint1.x - _controlPoint2.x) - _start.x);
	}
	
	double getDy() const
	{
		return _start.y;
	}
	double getCy() const
	{
		return 3 * (_controlPoint1.y -_start.y);
	}
	double getBy() const
	{
		return 3 * (_start.y - 2 * _controlPoint1.y + _controlPoint2.y);
	}
	double getAy() const
	{
		return (_end.y + 3 * (_controlPoint1.y - _controlPoint2.y) - _start.y);
	}
	
	
	double getX(double t) const
	{ return std::pow(t, 3) * (_end.x + 3 * (_controlPoint1.x - _controlPoint2.x) - _start.x) + 3 * std::pow(t, 2) * (_start.x - 2 * _controlPoint1.x + _controlPoint2.x) + 3 * t * (_controlPoint1.x -_start.x) + _start.x; }
	
	double getY(double t) const
	{ return std::pow(t, 3) * (_end.y + 3 * (_controlPoint1.y - _controlPoint2.y) - _start.y) + 3 * std::pow(t, 2) * (_start.y - 2 * _controlPoint1.y + _controlPoint2.y) + 3 * t * (_controlPoint1.y - _start.y) + _start.y; }

	bool operator==(const CubicBezier2d& bezier) const
	{ return _start == bezier._start && _end == bezier._end && _controlPoint1 == bezier._controlPoint1 && _controlPoint2 == bezier._controlPoint2; }

	bool operator!=(const CubicBezier2d& bezier) const
	{ return !operator==(bezier); }

	CubicBezier2d& operator=(const CubicBezier2d& bezier)
	{
		_start = bezier._start;
		_end = bezier._end;
		_controlPoint1 = bezier._controlPoint1;
		_controlPoint2 = bezier._controlPoint2;
		return *this;
	}
	
private:
	
	point2d _start;
	point2d _end;
	point2d _controlPoint1, _controlPoint2;
	
	
	
	friend std::ostream& operator<<(std::ostream&, const CubicBezier2d&);
	friend std::istream& operator>>(std::istream&, CubicBezier2d&);
};


#endif // __CUBICBEZIER2D_H__
