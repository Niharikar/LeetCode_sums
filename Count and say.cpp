#include<iostream>
using namespace std;

string fun(int n)
{
    string res = "1";
    
    while(--n)
    {
        string cur = "";
        
        for(int i = 0 ;i<res.size();i++)
        {
            int count = 1;
            while(res[i] == res[i+1] && i+1 < res.size() )
            {
                count++;
                i++;
            }
            cur += to_string(count) + res[i];
        }
        res = cur;
    }
    
    return res;
}


//As for each number input the result depends on the result of previous number, we need to find the string for every input from 1 
// to the given number
// we know that first ans is "1", then we count the repitions of the numbers in the string.
