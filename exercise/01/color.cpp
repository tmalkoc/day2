#include "stdafx.h"
#include "color.h"

namespace {
  double to_allowed_color_range(double d)
  {
    return d < 0.0 ? 0.0 : 1.0 < d ? 1.0 : d;
  }

  int to_char_range(double d)
  {
    return static_cast<int>(255.0 * to_allowed_color_range(d));
  }
}

color::color(double r, double g, double b)
  : red_(to_allowed_color_range(r)), green_(to_allowed_color_range(g)), blue_(to_allowed_color_range(b))
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
  return 0.2126*red_ + 0.7152*green_ + 0.0722*blue_;
}

bool operator==(const color& c1, const color& c2)
{
  const auto precision = 1. / 256.;
  return
    (std::fabs(c1.get_red() - c2.get_red()) < precision) &&
    (std::fabs(c1.get_green() - c2.get_green()) < precision) &&
    (std::fabs(c1.get_blue() - c2.get_blue()) < precision);
}
