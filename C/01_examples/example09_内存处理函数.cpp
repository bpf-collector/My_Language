/*
#include <string.h>
�ַ��������� VS �ڴ洦����
����	memset: c�����ַ�����nΪ�ֽ�������ͬ 
			void *memset(void *s, int c, size_t n);
strncpy	memcpy��memmove 
strncmp	memcmp
*/

#include <stdio.h>
#include <string.h>

void fun_memset()
{
	// ����һ ================================================================
	int a[10];
	memset(a, 97, sizeof(a));
	for(int t = 0; t < 10; t++)
		printf("%c ", a[t]);
	printf("\n");
	
	// ������ ================================================================ 
	int chr[100] = {0};
	/* ����һЩ���ݴ�����Ҫ���� chr[100] Ϊ0 */
	// ����1��(�����ر��Ƕ�ά����ʱ��)
	for(int i = 0; i < 100; i++)
		chr[i] = 0;
	// ����2���ڴ洦����
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
	
	// ���\0֮����Ƿ��и��� 
	printf("Str Tmp: %s\n", tmp + strlen("hello") + 1);
	printf("Mem Tmp: %s\n", tmp + strlen("hello") + 1);
	
	//��ע������������ڴ��ص�( memcpy(&chr[2], chr, 5 * sizeof(char)) )
	//		����ʹ��memcpy,����ʹ��memmove 
}

void fun_memcmp()
{
	//strcmp memcmp��� 
}
