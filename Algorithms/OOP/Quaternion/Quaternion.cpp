#include "Quaternion.h"

template <typename _Tp>
Quaternion<_Tp>::Quaternion()
{
}
template <typename _Tp>
Quaternion<_Tp>::Quaternion(_Tp r, _Tp i, _Tp j, _Tp k)
{
    quat.push_back(r);
    quat.push_back(i);
    quat.push_back(j);
    quat.push_back(k);
}
template <typename _Tp>
Quaternion<_Tp> &Quaternion<_Tp>::operator+(const Quaternion &q)
{
    this->quat[0] += q.quat[0];
    this->quat[1] += q.quat[1];
    this->quat[2] += q.quat[2];
    this->quat[3] += q.quat[3];

    return *this;
}
template <typename _Tp>
Quaternion<_Tp> &Quaternion<_Tp>::operator*(const Quaternion &q)
{
    this->quat[0] = this->quat[0] * q.quat[0] - this->quat[1] * q.quat[1] -
                    this->quat[2] * q.quat[2] - this->quat[3] * q.quat[3];

    this->quat[1] = this->quat[0] * q.quat[1] + this->quat[1] * q.quat[0] +
                    this->quat[2] * q.quat[3] - this->quat[3] * q.quat[2];

    this->quat[2] = this->quat[0] * q.quat[2] + this->quat[2] * q.quat[0] +
                    this->quat[3] * q.quat[1] - this->quat[1] * q.quat[3];

    this->quat[3] = this->quat[0] * q.quat[3] + this->quat[3] * q.quat[0] +
                    this->quat[1] * q.quat[2] - this->quat[2] * q.quat[1];

    return *this;
}
template <typename _Tp>
std::ostream &operator<<(std::ostream &out, const Quaternion<_Tp> &q)
{

    std::vector<char> sign;
    for (auto x : q.quat)
    {
        sign.push_back(std::signbit(x) ? '-' : '+');
    }

    out << q.quat[0] << " " << sign[1] << " " << abs(q.quat[1]) << "i " << sign[2] << " "
        << abs(q.quat[2]) << "j " << sign[3] << " " << abs(q.quat[3]) << "k";

    return out;
}
template <typename _Tp>
std::istream &operator>>(std::istream &read, Quaternion<_Tp> &q)
{
    _Tp w, x, y, z;
    std::cout << "Enter real number: ";
    read >> w;
    std::cout << "Enter i component: ";
    read >> x;
    std::cout << "Enter j component: ";
    read >> y;
    std::cout << "Enter k component: ";
    read >> z;

    q.quat.push_back(w);
    q.quat.push_back(x);
    q.quat.push_back(y);
    q.quat.push_back(z);

    return read;
}