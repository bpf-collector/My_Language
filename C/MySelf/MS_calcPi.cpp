/*
 * @Author: bpf
 * @Date: 2019-09-13 15:49:56
 * @LastEditTime: 2019-09-27 20:29:08
 * @Description: º∆À„Pi
 *  Pi/4 = 1 -1/3 +1/5 -1/7 + ...
 */
#include <stdio.h>
#include <math.h>
double Pi()
{
	int sign = 1;
	double pi = 0, n, tmp;
	for(n = 1, tmp = 1; fabs(tmp) >= 1e-7;)
	{
		pi += tmp;
		n += 2;
		sign = -sign;
		tmp = sign/n;
	}
	return pi*4;
}
