#include "point.h"

point::point(int x, int y):
  x(x), y(y)
{ }

bool operator==(const point& p1, const point& p2)
{
  return p1.x == p2.x && p1.y == p2.y;
}

bool operator!=(const point& p1, const point& p2)
{
  return !(p1 == p2);
}

bool operator<(const point& p1, const point& p2)
{
  return
    p1.x != p2.x ?
    p1.x < p2.x :
    p1.y < p2.y;
}
