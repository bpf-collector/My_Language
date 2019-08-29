/*
内存分区：
	栈区：编译器自动分配、释放。【存放函数参数、局部变量】 
	堆区：手动申请空间、手动释放。【malloc/new/free/delete】 
	全局区：【存放常量、全局变量、静态变量】 
	代码区：【操作系统管理】 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 全局区分析
char *fun_test_global()
{
	// p在栈区， "123abcd"在全局常量区
	char p[] = "123abcd";
	printf("fun_1: %s\n", p);
	// 使用完，p释放空间 
	return p;
}

void fun_global()
{
	// 出现乱码，p的地址所指的内存已被回收！ 
	char *p = fun_test_global();
	printf("fun_1: %s\n", p);
}

void fun_dui()
{
	char *p; // 野指针，存在于栈区 
	p = (char *)malloc(20); // 开辟的空间在堆区
	strcpy(p, "abcdefg");
	printf("\nfun_2: %s", p);
	free(p); // 需要手动释放 
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
