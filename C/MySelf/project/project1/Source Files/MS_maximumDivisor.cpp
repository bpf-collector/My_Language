// File: MS_maximumDivisor

int  Dividor(int m, int n)
{
    int max = m>n ? m : n;
    for(int i = max; i>0 ;i--)
        if(m%i == 0 && n%i == 0)
            return i;
}
