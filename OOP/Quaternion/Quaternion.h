#ifndef QUARTENION_H
#define QUARTENION_H
#include<string>
#include<iostream>
#include<vector>
#include<cmath>
template<typename _Tp>
class Quaternion
{
private:
    std::vector<_Tp> quat;
public:
    Quaternion();
    Quaternion(_Tp r,_Tp i,_Tp j, _Tp k);
    //int square(char im);
    Quaternion& operator+(const Quaternion& q);
    Quaternion& operator*(const Quaternion& q);
    template<class T>
    friend std::ostream& operator<<(std::ostream& out,const Quaternion<T>& q);
    template<class T>
    friend std::istream& operator>>(std::istream& input,Quaternion<T> &q);

};
#endif