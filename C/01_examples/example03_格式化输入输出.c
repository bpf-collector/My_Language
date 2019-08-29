/* sprintf(): 将格式化字符串存储起来 */
/* sscanf(): 从字符串中得到格式化数据 */

#include <stdio.h>

void fun_sprintf()
{
	char name[] = "Mike";
	int age = 12;
	
	printf("printf():  %s : %d\n", name, age);
		
	char tmp[30];
	sprintf(tmp, "sprintf(): %s : %d\n", name, age);
	printf("%s", tmp);
}

void fun_sscanf()
{
	int a, b, c;
	printf("input a b c: ");
	scanf("%d %d %d", &a, &b, &c);
	printf("scanf():  a = %d, b = %d, c = %d\n", a, b, c);
	
	char tmp[] = "a = 13, b = 24, c = 36";
	sscanf(tmp, "a = %d, b = %d, c = %d", &a, &b, &c);
	printf("sscanf(): a = %d, b = %d, c = %d\n", a, b, c);
}

void run()
{
	fun_sprintf();
	fun_sscanf();
}
