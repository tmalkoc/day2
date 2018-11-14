#pragma once

class color
{
public:
  inline static const double min_value = 0.0;
  inline static const double max_value = 1.0;

  inline static const double rgb_color_depth = 256.;
  
  inline static const double luminance_red = 0.2126;
  inline static const double luminance_green = 0.7152;
  inline static const double luminance_blue = 0.0722;
  
  color(double red = 0.0, double green = 0.0, double blue = 0.0);
  color(const color&) = default;
  ~color() = default;

  double get_red() const;
  double get_green() const;
  double get_blue() const;

  void set_red(double red);
  void set_green(double green);
  void set_blue(double blue);

  COLORREF get_color_ref() const;
  double get_luminance() const;

private:
  double red_;
  double green_;
  double blue_;
};

bool operator==(const color& c1, const color& c2);

