#pragma once

class color
{
public:
  color(double r = 0.0, double g = 0.0, double b = 0.0);

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

bool operator ==(const color& c1, const color& c2);

