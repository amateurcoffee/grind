#pragma once

#include <vector>
#include <cmath>

struct Point {
  double x;
  double y;
  
  double distanceTo(const Point& another) {
    return std::sqrt((x - another.x) * (x - another.x) + (y - another.y) * (y - another.y)); 
  }
};

