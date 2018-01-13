#include<iostream>
using namespace std;

string fun(string a,string b)
{
    string ans(a.size() + b.size(),'0');
    
    for(int i = a.size()-1;i>=0;i--)
    {
        int carry = 0;
        for(int j = b.size()-1;j>=0;j--)
        {
            int temp =  (ans[i+j+1]-'0') + (b[j]-'0')*(a[i]-'0') + carry;
            ans[i+j+1] = temp%10 + '0';
            carry = temp/10;
        }
        ans[i] += carry
    }
    
    size_t startpos = sum.find_first_not_of("0");
    if(string::npos != startpos)
        return ans.substr(startpos);
     
     return "0";
    
}

// the result will have size of sum of bot sizes, 
