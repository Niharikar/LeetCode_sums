
int myAtoi(string str)
{
    int i = 0; 
    while(str[i] == ' ') {i++;}
    int sign = 1;
    if(str[i] == '+' || str[i] == '-')
    {
        sign = 1 - 2*(str[i++] == '-');
    }
    
    int base = 0;
    while(str[i] >= '0' && str[i] <= '9')
    {
        if(base > INT_MAX/10 || (base == INT_MAX/10 && str[i] > '7'))
        {
            if(sign == 1) 
              return INT_MAX;
            else
              return INT_MIN;
        }
        
        base = 10*base + str[i++] - '0';
    }
    
    return sign*base;
    
    
}
