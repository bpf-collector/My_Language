/* strchr(str, val): 在str中匹配第一个val，匹配成功返回其地址，失败返回NULL */
/* strstr(str1, str2)：在str1中匹配第一个str2，匹配成功返回其地址，失败返回NULL */
/* strtok(str, delim)：在str中以snap分割，返回其分节，同时改变原字符串str。 
	第一次使用时，str使用原字符串；之后使用时，str使用NULL */

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
	
	char *p = strtok(tmp, ",");	// 第一次使用原字符串 
	printf("# Processed: ");
	while(p != NULL)
	{
		printf("%s ", p);
		p = strtok(NULL, ",");	// 之后使用NULL
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
