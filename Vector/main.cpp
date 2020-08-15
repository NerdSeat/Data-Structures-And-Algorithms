#include "Vector.cpp"

int main()
{
    Vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(8);
    vec.push_back(2);
    vec.push_back(9);
    Vector<int> vec2(vec);
    for (auto x : vec)
        std::cout << x << std::endl;

    std::cout << "The size of the vector is \n";
    std::cout << vec.size() << std::endl;

    vec2.push_back(23);
    vec2.push_back(15);
    vec2.push_back(11);
    vec2.push_back(18);
    vec2.push_back(12);
    std::cout << "The capacity vector two is: ";
    std::cout << vec2.capacity() << std::endl;
    std::cout << "And the vector is :\n";
    for (int i = 0; i < vec2.size(); i++)
        std::cout << vec2[i] << " ";
    std::cout << std::endl;
    return 0;
}