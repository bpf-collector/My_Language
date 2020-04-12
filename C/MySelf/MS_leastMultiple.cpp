/*
 * @Author: bpf
 * @Date: 2019-09-13 15:49:56
 * @LastEditTime: 2019-09-27 20:40:21
 * @Description: Get the MIN multiple of two numbers(最小公倍数)
 */
int  Multiple(int m, int n)
{
    int min = m<n ? m : n, i = 0;
    for(i = min; i <= m*n ;i++)
        if(i%m == 0 && i%n == 0)
            return i;
    return 0;
}