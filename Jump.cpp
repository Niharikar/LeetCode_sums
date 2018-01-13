#include<iostream>
using namespace std;

int fun(vector<int>& nums)
{
    int start = 0,end = 0,maxend = 0,n = nums.size(),step = 0;
    
    while(end < n-1)
    {
        step++;
        for(int i = start;i<=end;i++)
        {
            if(i+nums[i] >= n-1)
                return step;
            maxend = max(maxend,i+nums[i]);
        }
        start = end+1;
        end = maxend;
    }
    
    return step;
    
}

