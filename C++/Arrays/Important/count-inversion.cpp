/*                    Count Inversion
                   
https://practice.geeksforgeeks.org/problems/inversion-of-array/0
Given an array of integers. Find the Inversion Count in the array. 
Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
Example 1:
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).
Example 2:
Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already 
sorted so there is no inversion count.
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    //BRUTE FORCE
    // long long int inversionCount(long long arr[], long long N)
    // {
    //     long long int count=0;
    //     for(long long int i=0;i<N-1;i++)
    //     {
    //         for(int j=i+1;j<N;j++)
    //         {
    //             if(arr[i]>arr[j])
    //             {
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }
    
    //OPTIMIZATION USING MERGE SORT
long long int mergeIt(long long arr[], long long temp[], long long left, long long mid, long long right)
{

      long long inv_count=0;
      long long i=left;
      long long j =mid;
      long long k =left;

      while((i<=mid-1) && (j<=right))
      {
         if(arr[i]<=arr[j])

          {

              temp[k++]=arr[i++];

          }

          else{

              temp[k++]=arr[j++];

              inv_count += mid-i;

          }

      }

      while(i <= mid - 1)

        temp[k++] = arr[i++];

 

        while(j <= right)

            temp[k++] = arr[j++];

    

        for(i = left ; i <= right ; i++)

            arr[i] = temp[i];

        

    return inv_count;

  }

  

  long long int merge_sort(long long arr[],long long temp[],long long left , long long right)

  {

      long long mid,inv_count=0;

      if(right>left)

      {

          mid = (left+right)/2;

          inv_count += merge_sort(arr,temp,left,mid);
          inv_count += merge_sort(arr,temp,mid+1,right);
  
          inv_count += mergeIt(arr,temp,left,mid+1,right);

      }

      return inv_count;

  }

    long long int inversionCount(long long arr[], long long N)

    {

        long long temp[N];

        long long ans = merge_sort(arr,temp,0,N-1);

        return ans;
    }

};
