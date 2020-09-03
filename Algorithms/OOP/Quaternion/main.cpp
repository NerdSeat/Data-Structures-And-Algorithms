#include "Quaternion.h"
#include "Quaternion.cpp"

int main()
{
    Quaternion<double> quat(2, 3, 1, 6);
    Quaternion<double> quat1(4, 2, 8, 7);

    std::cout << quat + quat1 << std::endl;
    std::cout << quat * quat1 << std::endl;
    return 0;
}