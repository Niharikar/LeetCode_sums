

int fun(string s,int k)
{
    int num = 0,i = 0,ans = -1;
    vector<int> count(256,0);
    for(int j = 0;j<s.size();j++)
    {
        if(count[s[i]]++ == 0)
            num++;
         if(num > k)
         {  
            while(--count[s[i++]] > 0);
              num--;
         }
         
         ans = max(ans,j-i+1);
    }
    
    return ans;
}
