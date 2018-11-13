#include "array.h"
#include <stdexcept>
#include <string>

array::array(int size, double value) :
  ptr_(new double[size]),
  size_(size)
{
  for (int i = 0; i < size; i++)
    ptr_[i] = value;
}

array::array(const array& source) :
  ptr_(new double[source.size_]),
  size_(source.size_)
{
  for (int i = 0; i < size_; i++)
    ptr_[i] = source.ptr_[i];
}

array::array(array&& source) noexcept :
  ptr_(source.ptr_),
  size_(source.size_)
{
  source.size_ = 0;
  source.ptr_ = nullptr;
}

array::~array()
{
  delete[] ptr_;
  ptr_ = nullptr;
  size_ = 0;
}

int array::size() const
{
  return size_;
}

double array::at(const int i) const
{
  if (i < 0 || size_ < i)
    throw std::out_of_range("array::at(idx) - index is out of range. idx == " + std::to_string(i));
  return ptr_[i];
}

array& array::operator=(const array& other)
{
  size_ = other.size_;
  delete[] ptr_;
  ptr_ = new double[size_];
  for (int i = 0; i < size_; i++)
    ptr_[i] = other.ptr_[i];
  return *this;
}
