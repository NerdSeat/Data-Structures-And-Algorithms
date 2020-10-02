#include "Range.hpp"

Range::Range(Range* iter, int pos)
{
  this->iterator = iter;
  this->current = pos;
}

Range::Range(int min,int max)
{
  this->min = min;
  this->max = max;
}
Range::Range(unsigned int max)
{
  this-> min = 0;
  this->max = max;
}
int* Range::begin()
{
  Range(this,min);
  return &this->min;
}
int* Range::end()
{
  Range(this,max);
  return &this->max;
}
bool Range::operator!=(const Range& rhs)
{
  return this->current!=rhs.current;
}

int Range::operator*(const Range& rhs)
{
  return rhs.current;
}
Range& Range::operator++()
{
  this->current++;
  return *this;
}
