

double myPow(double x,int n)
{
    long m  = n;
    
    if(m<0)
    {
        m = -m;
        x = 1/x;
    }
    
    double a = 1;
    while(m>0)
    {
        if(m&1)
          a = a*x;
        x *= x;
        m >>=1;
    }
    
    return a;
}
