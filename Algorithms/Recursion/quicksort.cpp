#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>

template<class T>
void swap(T& val1,T& val2)
{
    T temp = val1;
    val1 = val2;
    val2 = temp;
}

template<class T>
int partition(std::vector<T>&vec,int start,int end)
{
    T pivot = vec[end];
    int partIndex = start;
    for(int i = start;i<end;i++)
    {
        if(vec[i]<=pivot)
        {
            swap(vec[i],vec[partIndex]);
            partIndex++;
        }
    }
    swap(vec[partIndex],vec[end]);
    return partIndex;
}
template<class T>
void qsort(std::vector<T>&vec,int start,int end)
{
    if(end<start)
        return;
    
    int partIndex = partition(vec,start,end);
    qsort(vec,start,partIndex-1);
    qsort(vec,partIndex+1,end);

}

int main()
{
    std::vector<int> data = { 5,12,45,2,67,8 };
    int n = data.size()-1;
    qsort(data, 0, n);

    std::vector<std::string> names = { "Joseph","Nichol","Anand","Lisa","Matt","Dave" };
    n = names.size()-1;
    
    qsort(names, 0, n);
    std::copy(std::begin(data), std::end(data), std::ostream_iterator<int>(std::cout, "\t"));
    std::cout << "\n";

    std::copy(std::begin(names), std::end(names), std::ostream_iterator<std::string>(std::cout, "\t"));
    std::cout << "\n";
    return 0;
}
