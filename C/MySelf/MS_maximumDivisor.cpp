/*
 * @Author: bpf
 * @Date: 2019-09-13 15:49:56
 * @LastEditTime: 2019-09-27 20:40:33
 * @Description: get the MAX dividor of two numbers(求最大公约数)
 */
int  Dividor(int m, int n)
{
    int max = m>n ? m : n;
    for(int i = max; i>0 ;i--)
        if(m%i == 0 && n%i == 0)
            return i;
    return 0;
}
