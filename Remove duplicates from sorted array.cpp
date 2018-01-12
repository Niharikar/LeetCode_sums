#include<iostream>
using namespace std;

int fun(vector<int>& nums)
{
    int i = 0;
    for(int j = 1;j<nums.size();j++)
    {
        if(nums[j]!=nums[i])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    
    return i+1;
}

//  Idea is to use two pointers slow and fast, incrementing the slow pointer only when we do not encounter a duplicate in array 
//  then updating array so as to remove duplicate. 
