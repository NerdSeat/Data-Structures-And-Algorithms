#include<iostream>
#include<vector>
#include<string>

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
void quickSort(std::vector<T>&vec,int start,int end)
{
    if(start<end)
    {
        int partIndex = partition(vec,start,end);
        quickSort(vec,start,partIndex-1);
        quickSort(vec,partIndex+1,end);
    }
}

template<class T>
void print(const std::vector<T> vec)
{
    for(auto v:vec)
        std::cout<<v<<"\t";
    std::cout<<std::endl;
}

int main()
{
    std::vector<std::string> digits = {"2346135843","8249004533","0954476756","7381033606",
        "5633680329","4091753471","7534156282","8788896255","2077980173","3732183423"};
    
    std::vector<int> numbers = {91,81,98,92,58,34,79,59,86,47};
    std::cout<<"the given numbers are:\n";
    print(numbers);
    quickSort(numbers,0,numbers.size()-1);
    
    std::cout<<"the sorted numbers are:\n";
    print(numbers);


    std::cout<<"the given digits are:\n";
    print(digits);
    
    std::cout<<"the sorted digits are:\n";
    quickSort(digits,0,digits.size()-1);
    print(digits);

    return 0;
}
