#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>

template<typename it>
void merge(std::vector<it>& data, int  begin, int midpoint, int end)
{
    std::vector<it> left(midpoint - begin+1);
    std::vector<it> right(end - midpoint);
    
    //populate the left vector
    for (int j = 0; j < left.size(); ++j)
        left[j] = data[j+begin];

    //populate the right vector
    for (int j = 0; j < right.size(); ++j)
        right[j] = data[j + midpoint+1];

    int k = begin, i = 0, r = 0;
    while (i < left.size() && r < right.size())
    {
        data[k++] = left[i] < right[r] ? left[i++] : right[r++];
    }

//copy left left-overs to the main vector
    while (i < left.size())
        data[k++] = left[i++];
        
//copy right left-overs to the main vector;
    while (r < right.size())
        data[k++] = right[r++];
}

template<typename it>
void mergesort(std::vector<it>& data, int start, int end)
{
    if (end-start<2)
        return;
    int mid = start + (end - start) / 2;

    mergesort(data, start, mid);
    mergesort(data, mid+1, end);
    merge(data, start, mid, end);
}

int main()
{
    std::vector<int> data = { 5,12,45,2,67,8 };
    int n = data.size()-1;
    mergesort(data, 0, n);

    std::vector<std::string> names = { "Joseph","Nichol","Anand","Lisa","Matt","Dave" };
    n = names.size()-1;
    
    mergesort(names, 0, n);
    std::copy(std::begin(data), std::end(data), std::ostream_iterator<int>(std::cout, "\t"));
    std::cout << "\n";

    std::copy(std::begin(names), std::end(names), std::ostream_iterator<std::string>(std::cout, "\t"));
    std::cout << "\n";
    return 0;
}
