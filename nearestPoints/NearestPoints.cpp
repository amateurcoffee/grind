#include "NearestPoints.h"
#include <glog/logging.h>

void printPoints(std::vector<Point> points) {
  LOG(INFO) << points.size() << " points are below:";
  for (auto &p : points) {
    LOG(INFO) << "[" << p.x << ", " <<  p.y << "]";
  }
}

struct PointComparator { 
  Point target;
  bool operator() (Point a, Point b) {
    return target.distanceTo(a) < target.distanceTo(b);  
  }
};

std::vector<Point> nNearest(std::vector<Point> points, Point target) {
  std::vector<Point> result;
  std::copy(points.begin(), points.end(), std::back_inserter(result));
  PointComparator comparator {target};
  std::sort(result.begin(), result.end(), comparator);
  LOG(INFO) << "N nearest points to target in sorted order";
  printPoints(result); 
  return result;
}

std::vector<Point> nNearest(std::vector<Point> points, Point target, double threshold) {
  LOG(INFO) << "N nearest points to target within max threshold distance in sorted order";
  std::vector<Point> sorted;
  sorted.insert(sorted.end(), points.begin(), points.end());
  PointComparator comparator {target};
  std::vector<Point> result;
  std::sort(result.begin(), result.end(), comparator);
  std::copy_if(sorted.cbegin(), sorted.cend(), std::back_inserter(result), 
      [&](Point p){return target.distanceTo(p) <= threshold;});
  printPoints(result);
  return result;
}

int main () {
  Point p1 {1, 2};
  Point p2 {3, 4};
  Point p3 {2, 1};
  Point p4 {4, 3};
  Point p {3, 2};
  double threshold = 1.5;
  std::vector<Point> points = {p1, p2, p3, p4};
  nNearest(points, p);
  nNearest(points, p, threshold);
  return 0;
}
