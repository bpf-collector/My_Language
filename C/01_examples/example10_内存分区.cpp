/*
�ڴ������
	ջ�����������Զ����䡢�ͷš�����ź����������ֲ������� 
	�������ֶ�����ռ䡢�ֶ��ͷš���malloc/new/free/delete�� 
	ȫ����������ų�����ȫ�ֱ�������̬������ 
	��������������ϵͳ���� 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ȫ��������
char *fun_test_global()
{
	// p��ջ���� "123abcd"��ȫ�ֳ�����
	char p[] = "123abcd";
	printf("fun_1: %s\n", p);
	// ʹ���꣬p�ͷſռ� 
	return p;
}

void fun_global()
{
	// �������룬p�ĵ�ַ��ָ���ڴ��ѱ����գ� 
	char *p = fun_test_global();
	printf("fun_1: %s\n", p);
}

void fun_dui()
{
	char *p; // Ұָ�룬������ջ�� 
	p = (char *)malloc(20); // ���ٵĿռ��ڶ���
	strcpy(p, "abcdefg");
	printf("\nfun_2: %s", p);
	free(p); // ��Ҫ�ֶ��ͷ� 
}

void run()
{
	fun_global();
	fun_dui();
}

int main()
{
	run();
}
