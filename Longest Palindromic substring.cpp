#include<iostream>
using namespace std;
// DP approach
string fun(string s)
{
    int n = s.size(),x=0,y=0;  
    vector< vector<int> > arr(n,vector<int>(n));
    for(int k = 0;k<n;k++)
      arr[k][k] = 1;
    for(int j = 1; j < n;j++)
    {
        for(int i = 0;i<n-j;i++)
        {
            if(s[i] == s[i+j] && j==1)
            {
                arr[i][i+j] = 1;
                x = i;
                y = i+j;
                continue;
            }
            
            if(s[i] == s[i+j] && j>1 && arr[i+1][i+j-1])
            {
                arr[i][i+j] = 1;
                x = i;
                y = i+j;
            }
        }
    }
    
    return s.substr(x,y-x+1);
}
//************************************************************************************************************************************

// O(1) space complexity O(n^2) time complexity
string LongPal(string s)
{
    int start = 0,end = 0;
    for(int i = 0;i<s.size(); i++)
    {
        int len = max( expand(s,i,i), expand(s,i,i+1) );
        if(len > (end-start + 1))
        {
            start = i - (len-1)/2;
            end = i + (len)/2;   
        }
    }
    
    return s.substr(start,end-start + 1);
}

int expand(string s,int l,int r)
{
    while(l>=0 && r<s.size() && s[l]==s[r])
    {
        l--;
        r++;
    }
    return r-l-1;
}
