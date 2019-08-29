/* strchr(str, val): ��str��ƥ���һ��val��ƥ��ɹ��������ַ��ʧ�ܷ���NULL */
/* strstr(str1, str2)����str1��ƥ���һ��str2��ƥ��ɹ��������ַ��ʧ�ܷ���NULL */
/* strtok(str, delim)����str����snap�ָ������ֽڣ�ͬʱ�ı�ԭ�ַ���str�� 
	��һ��ʹ��ʱ��strʹ��ԭ�ַ�����֮��ʹ��ʱ��strʹ��NULL */

#include <stdio.h>
#include <string.h>

void fun_strchr()
{
	char tmp[] = "Mike and me are students.";
	printf("# Orginal string: %s\n", tmp);
	
	char *p = strchr(tmp, 'n');
	if(p != NULL)
		printf("# Processed for strchr():\n\tchar: %c\n\tstring: %s\n", *p, p);
	else
		printf("Failed!\n");
	return ;
}

void fun_strstr()
{
	char tmp[] = "Mike and me are students.";
	printf("# Orginal string: %s\n", tmp);
		
	char *p = strstr(tmp, "are");
	if(p != NULL)
		printf("# Processed for strstr():\n\tstring: %s\n", p);
	else
		printf("Failed!\n");
	return ;
}

void fun_strtok()
{
	char tmp[] = "Apple,Banana,020-12345678,Green";
	printf("# Orginal string: %s\n", tmp);
	
	char *p = strtok(tmp, ",");	// ��һ��ʹ��ԭ�ַ��� 
	printf("# Processed: ");
	while(p != NULL)
	{
		printf("%s ", p);
		p = strtok(NULL, ",");	// ֮��ʹ��NULL
	}
	return ;
}

void run()
{
	fun_strchr();
	printf("\n============================================================\n");
	fun_strstr();
	printf("\n============================================================\n");
	fun_strtok();
}
