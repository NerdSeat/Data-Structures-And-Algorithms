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
    for (auto it = vec.begin();it!=vec.end();++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    Vector<int> data(5,4);
    for(auto a:data)
        std::cout<<a<<"\t";
    std::cout<<"\n";
    return 0;
}
