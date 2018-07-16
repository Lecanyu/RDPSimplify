#include "DouglasPeucker.h"


std::vector<RDP::Point2d> RDP::DouglasPeucker::Simplify(std::vector<Point2d>& pointList, float epsilon)
{
	std::vector<Point2d> resultList;

	// Find the point with the maximum distance
	float dmax = 0;
	int index = 0;
	for (int i = 1; i < pointList.size() - 1; ++i)
	{
		float d = perpendicularDistance(pointList[i], pointList[0], pointList[pointList.size() - 1]);
		if (d > dmax) {
			index = i;
			dmax = d;
		}
	}
	// If max distance is greater than epsilon, recursively simplify
	if (dmax > epsilon)
	{
		std::vector<Point2d> pre_part, next_part;
		for (int i = 0; i <= index; ++i)	pre_part.push_back(pointList[i]);
		for (int i = index; i < pointList.size(); ++i)	next_part.push_back(pointList[i]);
		// Recursive call
		std::vector<Point2d> resultList1 = Simplify(pre_part, epsilon);
		std::vector<Point2d> resultList2 = Simplify(next_part, epsilon);

		// combine
		resultList.insert(resultList.end(), resultList1.begin(), resultList1.end());
		resultList.insert(resultList.end(), resultList2.begin()+1, resultList2.end());
	}
	else
	{
		resultList.push_back(pointList[0]);
		resultList.push_back(pointList[pointList.size() - 1]);
	}
		
	return resultList;
}

float RDP::DouglasPeucker::perpendicularDistance(const Point2d& p, const Point2d& line_p1, const Point2d& line_p2)
{
	Point2d vec1 = Point2d(p.x_ - line_p1.x_, p.y_ - line_p1.y_);
	Point2d vec2 = Point2d(line_p2.x_ - line_p1.x_, line_p2.y_ - line_p1.y_);
	float d_vec2 = sqrt(vec2.x_*vec2.x_ + vec2.y_*vec2.y_);
	float cross_product = vec1.x_*vec2.y_ - vec2.x_*vec1.y_;
	float d = abs(cross_product / d_vec2);
	return d;
}
