#pragma once

class point
{

public:
  point(int x = 0, int y = 0);
  point(const point&) = default;
  ~point() = default;

  const int x;
  const int y;
};

bool operator==(const point& p1, const point& p2);
bool operator!=(const point& p1, const point& p2);
bool operator<(const point& p1, const point& p2);

