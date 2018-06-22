#include<iostream>
using namespace std;

vector< vector<int> > threesum(vector<int>& nums)
{
     vector< vector<int> > ans;
    sort(nums.begin().nums.end());
    for(int i = 0;i<nums.size();i++)
    {
        int target = -nums[i];
        int front = i+1, back = nums.size()-1;
        
        while(front < back)
        {
            if( nums[front] + nums[back] > target )
              back--;
            else if( nums[front] + nums[back] < target )
              front++;
             else
             {
                  vector<int> t(3,0);
                  t[0] = nums[front];t[1] = nums[back];t[2] = -target;
                  ans.push_back(t);

                  while( t[0] == nums[front] && front!=back )
                    front++;
                   while( t[1] == nums[back] && front!=back)
                    back--;

             }
         }
         
         
         while( nums[i] == nums[i+1] && i+1 < nums.size() )
          i++;
        
    }
    
    return ans;
    
  
    
}
