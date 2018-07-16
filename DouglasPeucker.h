#pragma once

#include <vector>
#include "Utils.h"

namespace RDP
{
	class DouglasPeucker
	{
	public:
		static std::vector<Point2d> Simplify(std::vector<Point2d>& pointList, float epsilon);
	private:
		static float perpendicularDistance(const Point2d& p, const Point2d& line_p1, const Point2d& line_p2);
	};
}
