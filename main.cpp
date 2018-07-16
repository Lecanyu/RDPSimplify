/***
 * This is an Ramer¨CDouglas¨CPeucker algorithm implementation (2d version). https://en.wikipedia.org/wiki/Ramer%E2%80%93Douglas%E2%80%93Peucker_algorithm
 * Given a curve composed of line segments to find a similar curve with fewer points. 
 * 
 * Recursive implementation, might stack overflow when the curve is complicate.
 */


#include "DouglasPeucker.h"
#include <iostream>

int main()
{
	std::vector<RDP::Point2d> vertices1;
	vertices1.push_back(RDP::Point2d(1, 1));
	vertices1.push_back(RDP::Point2d(1.2, 0.4));
	vertices1.push_back(RDP::Point2d(2, 0.2));
	vertices1.push_back(RDP::Point2d(3, 0.6));
	vertices1.push_back(RDP::Point2d(4, 3));

	std::vector<RDP::Point2d> result = RDP::DouglasPeucker::Simplify(vertices1, 1.2);
	for (auto p:result)
		std::cout << p.x_ << " " << p.y_ << "\n";
	
	return 0;
}
