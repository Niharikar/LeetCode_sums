#include<iostream>
using namespace std;


string StringSort(string s)
{
    vector<int> count(26,0);
    for(int i = 0;i<s.size();i++) 
      count[s[i]-'a']++;
    
    string a(s.size(),'a');
    int p = 0;
    for(int j = 0;j<26;j++)
      for(int k = 0;k<count[j];k++)
        a[p++] += j;
      
      return a;
}

vector< vector<string> > fun(vector<string>& list)
{
    map<string, vector<string>> m;
    
    for(int i = 0;i<list.size();i++)
        m[StringSort(list[i])].push_back(list[i]);
    
    vector< vector<string> > ans;
    
    for(auto x : m)
    {
        vector<string> b(x.begin(),x.end());
        ans.push_back(b);
    }
    
    return ans;
    
    
    
}
