#pragma once

// do not use standard container as member or base class

class array
{
public:
  array(int size = 0, double value = 0.0);
  array(const array&);
  array(array&&) noexcept;
  ~array();

  int size() const;
  double at(int i) const;
  array& operator=(const array&);

private:
  double* ptr_;
  int size_;
};
