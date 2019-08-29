/* srand(seed): 设置随机种子，种子相同，生成的随机数相同 */
/* rand(): 生成随机数，在此之前需要先确定随机数种子 */ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void fun_rand()
{
	srand( (unsigned int)time(NULL) );	//时间不同种子就不同 
	for(int i = 0; i < 10; i++)
	printf("%d\n", rand());
}

void run()
{
	fun_rand();
}
