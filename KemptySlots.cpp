
// O(N) time complexity, O(N) space complexity
int KEmptySlots(vector<int>& flowers,int k)
{
    vector<int> days(flowers.size());
    for(int i = 0;i<flowers.size();i++)
        days[flowers[i]-1] = i+1; 
    int left = 0,right = k+1;
    int ans = INT_MAX;
    
   search: 
    while(right < days.size())
    {
        for(int i = left+1;i<right;i++)
        {
            if(days[[i]<days[left] || days[i]<days[right])
            {
                left = i+1;
                right = left+k+1;
                continue search;
            }
        }
        
        ans = min(ans,max(days[left],days[right]));
        left = right;
        right = left+k+1;
    }
    
    return ans < INT_MAX ? ans:-1;
    
}
