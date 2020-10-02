#include <iostream>
#include <vector>
#include <limits>

int poor_bruteForce(int arr[],int size)
{
  int ans = std::numeric_limits<int>::min();
  for(int sub_arr_size =1;sub_arr_size<=size;sub_arr_size++)
    {
      for(int start_index=0;start_index<size;start_index++)
	{
	  if(start_index+sub_arr_size > size)
	    break;
	  int sum =0;
	  for(int i =start_index;i<(start_index+sub_arr_size);i++)
	    {
	      sum+=arr[i];
	      ans = std::max(ans,sum);
	    }
	}
    }
  return ans;
}

int brute_force(int arr[],int size)
{
  int ans = std::numeric_limits<int>::min();
  for(int start_index =0;start_index<=size;start_index++)
    {
      int sum = 0;
      for(int sub_array_size =1;sub_array_size<=size;sub_array_size++)
	{
	  if(start_index+ sub_array_size>size)
	    break;
	  sum+= arr[sub_array_size+start_index -1];
	  ans = std::max(ans,sum);
	}
    }
  return ans;
}
int div_and_conquer(int arr[], int size)
{
  if(size ==1 )
    return arr[0];
  int mid = size/2;
  int left_min = div_and_conquer(arr,mid);
  int right_min = div_and_conquer(arr+mid,size-mid);
  int left_sum = std::numeric_limits<int>::min();
  int right_sum = std::numeric_limits<int>::min();
  int sum = 0;
  for(int i = mid;i<size;i++)
    {
      sum=arr[i];
      right_sum = std::max(sum,right_sum);
    }
  sum =0;
  for(int i = mid-1;i>=0;i--)
    {
      sum+=arr[i];
      left_sum = std::max(left_sum,sum);
    }
  int ans = std::max(left_min,right_min);
  return std::max(ans,left_sum+right_sum);
  
}

int main()
{
  int array[8] = {-2,4,2,-1,3,-4,5,-2};
  int size = sizeof(array)/sizeof(int);

  std::cout<<"The sum of the maximum sub array from the poor brute force is: "<<poor_bruteForce(array,size)<<std::endl;
  std::cout<<"The sum of the maximum sub array from the better brute force is: "<<brute_force(array,size)<<std::endl;
  std::cout<<"The sum of the maximum sub array from the divide and conquer algorithm is: "<<div_and_conquer(array,size)<<std::endl;
    
  return 0;
}
