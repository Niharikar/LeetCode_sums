
string numberToWords(int n)
{
    if(n == 0)
      return "zero";
    else
       return int_string(n).substr(1);
}

char* below_20[] = {"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
"Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};

char* below_100[] = {"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

string int_string(int n)
{
    if(n >= 1e9)
    {
        return int_string(n/1e9) + " Billion" + int_string(n%(1e9));
    }
    
    if(n >= 1e6)
    {
        return int_string(n/1e6) + " Million" + int_string(n%(1e6));
    }
    
    if(n>= 1000)
    {
        return int_string(n/1000) + " Thousand" + int_string(n%(1000));
    }
    
    if(n >= 100)
    {
        return int_string(n/100) + " Hundred" + int_string(n%100); 
    }
    
    if(n>= 20)
    {
        return " " + below_100[n/10 -2] + " " + int_string(n%10);
    }
    
    if(n >= 1)
    {
        return " " + below_20[n-1];
    }
    
    else
      return "";
    
}
