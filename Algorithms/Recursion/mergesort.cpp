#include<iostream>
#include<string>
#include<algorithm>
template<class T>
void merge(T array[],int start,int mid,int end)
{
    int left = mid-start+1;
    int right = end-mid;
    T *left_array = new T[left];
    T *right_array = new T[right];
    
    for(int i=0;i<left;i++)
        left_array[i] = array[i+start];
    for(int j =0;j<right;j++)
        right_array[j]=array[mid+1+j];
    int k = start,j=0,i=0;

    while (i<left &&j<right)
    {
       if(left_array[i]<=right_array[j])
       {
           array[k]=left_array[i];
           i++;
       }
       else
       {
           array[k]=right_array[j];
           j++;
       }
        k++;
    }
    while(i<left)
    {
        array[k] = left_array[i];
        k++;
        i++;
    }
    while(j<right)
    {
        array[k]=right_array[j];
        k++;
        j++;
    }
    delete[]left_array;
    delete[]right_array;
}
template<class T>
void mergeSort(T array[], int start,int end)
{
    int mid = start + (end - start)/2;
    if(start<end)
    {
        mergeSort(array,start,mid);
        mergeSort(array,mid+1,end);
        merge(array,start,mid,end);
    }
}

template<class T>
void print(T data)
{
    std::cout<<data<<"\t";
}
int main()
{
    std::string digits[] = {"2346135843","8249004533","0954476756","7381033606",
        "5633680329","4091753471","7534156282","8788896255","2077980173","3732183423"};
    
    int numbers[10] = {91,81,98,92,58,34,79,59,86,47};
    std::cout<<"the given numbers are:\n";
    for(int i=0;i<10;i++)
        print(numbers[i]);
    std::cout<<std::endl;
    mergeSort(numbers,0,9);
    
    std::cout<<"the sorted numbers are:\n";
    for(int i=0;i<10;i++)
        print(numbers[i]);
    std::cout<<std::endl;

    std::cout<<"the given digits are:\n";
    for(int i=0;i<10;i++)
        print(digits[i]);
    std::cout<<std::endl;
    
    std::cout<<"the sorted digits are:\n";
        mergeSort(digits,0,9);
    for(int i=0;i<10;i++)
        print(digits[i]);
    std::cout<<std::endl;
    return 0;
}
