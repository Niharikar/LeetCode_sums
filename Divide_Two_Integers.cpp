
int divide(int dividend,int divisor)
{
    if(dividend ==INT_MIN && divisor == -1)
        return -1;
        
    int ans = 0;
    long D = labs(dividend),d = labs(divisor);
    
    int sign = (dividend<0) ^ (divisor<0) ? -1:1
    
    while(D >= d)
    {
        long temp = d;int q = 1; 
        while( (temp << 1) <= D )
        {
            temp <<= 1;
            q <<= 1;
        }
        
        D = D-temp;
        ans += q;
        
    }    
    
    return sign*(ans);
}
