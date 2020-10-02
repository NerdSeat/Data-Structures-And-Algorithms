#ifndef RANGE_H
#define RANGE_H
#include <iostream>
#include <vector>


class Range
{
 private:
  int min,current,max;
  Range* iterator;
  Range(Range* iterator,int curr);
public:
  Range(unsigned int y);
  Range(int min, int max);
  int* begin();
  int* end();
  bool operator!=(const Range& rhs);
  int operator*(const Range& rhs);
  Range& operator++();
};
#endif
