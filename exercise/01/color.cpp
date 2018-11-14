#include "stdafx.h"
#include "color.h"

namespace {
  double to_allowed_color_range(double d)
  {
    return 
      d < color::min_value ? color::min_value :
      color::max_value < d ? color::max_value :
      d;
  }

  int to_char_range(double d)
  {
    return static_cast<int>((color::rgb_color_depth - 1) * to_allowed_color_range(d));
  }
}

color::color(double red, double green, double blue) : 
  red_(to_allowed_color_range(red)), 
  green_(to_allowed_color_range(green)), 
  blue_(to_allowed_color_range(blue))
{  }

double color::get_red() const
{
  return red_;
}

double color::get_green() const
{
  return green_;
}

double color::get_blue() const
{
  return blue_;
}

void color::set_red(double red)
{
  red_ = to_allowed_color_range(red);
}

void color::set_green(double green)
{
  green_ = to_allowed_color_range(green);
}

void color::set_blue(double blue)
{
  blue_ = to_allowed_color_range(blue);
}

COLORREF color::get_color_ref() const
{
  return RGB(to_char_range(red_), to_char_range(green_), to_char_range(blue_));
}

double color::get_luminance() const
{
  return 
    luminance_red * red_ +
    luminance_green * green_ + 
    luminance_blue * blue_;
}

bool operator==(const color& c1, const color& c2)
{
  const auto precision = 1. / color::rgb_color_depth;
  return
    std::fabs(c1.get_red() - c2.get_red()) < precision &&
    std::fabs(c1.get_green() - c2.get_green()) < precision &&
    std::fabs(c1.get_blue() - c2.get_blue()) < precision;
}
