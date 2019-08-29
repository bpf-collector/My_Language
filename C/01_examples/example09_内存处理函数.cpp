/*
#include <string.h>
字符串处理函数 VS 内存处理函数
重置	memset: c按照字符处理，n为字节数，下同 
			void *memset(void *s, int c, size_t n);
strncpy	memcpy、memmove 
strncmp	memcmp
*/

#include <stdio.h>
#include <string.h>

void fun_memset()
{
	// 案例一 ================================================================
	int a[10];
	memset(a, 97, sizeof(a));
	for(int t = 0; t < 10; t++)
		printf("%c ", a[t]);
	printf("\n");
	
	// 案例二 ================================================================ 
	int chr[100] = {0};
	/* 经过一些数据处理，需要重置 chr[100] 为0 */
	// 方法1：(烦！特别是多维数据时！)
	for(int i = 0; i < 100; i++)
		chr[i] = 0;
	// 方法2：内存处理函数
	memset(chr, 0, sizeof(chr));
}

void fun_memcpy()
{
	char chr[] = "hello\0mike";
	char tmp[20];
	printf("Len Of Chr: %d\n", sizeof(chr));
	strncpy(tmp, chr, sizeof(chr));
	
	memset(tmp, 0, sizeof(tmp));
	memcpy(tmp, chr, sizeof(chr));
	
	// 检查\0之后的是否有复制 
	printf("Str Tmp: %s\n", tmp + strlen("hello") + 1);
	printf("Mem Tmp: %s\n", tmp + strlen("hello") + 1);
	
	//【注】：如果出现内存重叠( memcpy(&chr[2], chr, 5 * sizeof(char)) )
	//		则不能使用memcpy,而需使用memmove 
}

void fun_memcmp()
{
	//strcmp memcmp差不多 
}
