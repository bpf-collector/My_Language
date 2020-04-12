// FIle: MS_prime
#include <math.h>

bool prime(int num)
{
	int i = 2;
	for(; i <= sqrt(num); i++)
		if(num % i == 0)
			break;
	if(i <= sqrt(num))
		return false;
	else
		return true;
}
