#include<iostream>
using namespace std;

double Median(vector<int>& nums1, vector<int>& nums2)
{
     int m = nums1.size(),n = nums2.size();
     if(m>n)
       return Median(nums2,nums1);
       
    int i = 0;    
    while(1)
    {
        int j = (m+n+1)/2 - i;
        if(  (i==0 || j==n || nums1[i-1] <= nums2[j])  && (i==m || j==0 || nums2[j-1] <= nums1[i])  )
          break;
         
         if(nums2[j-1] > nums1[i])
          i++;
         else if(nums1[i-1] > nums2[j])
          i--;
    }
    
    double MaxL,MaxR;
    if(i==0)
      MaxL = nums2[j-1];
    else if(j==0)
      MaxL = nums1[i-1];
    else
      MaxL = max(nums1[i-1],nums2[j-1]);
     
     if((m+n)%2==1)
      return MaxL;
      
     if(i==m)
        MaxR = nums2[j];
     else if(j==n)
        MaxR = nums1[i];
     else
        MaxR = min(nums1[i],nums2[j]);
       
     return (MaxL + MaxR)/2;
      
    
}
