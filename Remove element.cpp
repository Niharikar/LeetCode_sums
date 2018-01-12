#include<iostream>
using namespace std;

int fun(vector<int>& nums,int val)
{
    int i = 0;,j = nums.size()-1;
    
    while(i<=j)
    {
        if(val==nums[i])
        {
            swap(num[i],nums[j]);
            j--;
            continue;
        }
        
        else
            i++;
    }
    
    return i;
}


// Take two pointers, one from start(first pointer) and other from end(second pointer). if an element matches with val, swap it with 2nd pointer position and decrement it
// otherwise increment first pointer
