#include<iostream>
using namespace std;

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
            
            if(s[i] == s[i+j] && j>1 && a[i+1][i+j-1])
            {
                arr[i][i+j] = 1;
                x = i;
                y = i+j;
            }
        }
    }
    
    return s.substr(x,y-x+1);
}
