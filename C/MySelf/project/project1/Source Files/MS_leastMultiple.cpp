// File: MS_leastMutiple

int  Multiple(int m, int n)
{
    int min = m<n ? m : n;
    for(int i = min; i <= m*n ;i++)
        if(i%m == 0 && i%n == 0)
            return i;
}
