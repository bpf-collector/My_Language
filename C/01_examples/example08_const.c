/* const 变量：指针变量的指向不能改变，变量值不能改变 */
/* const *：   指针所指的内存不能改变*/

void fun_const()
{
	const int a = 10; // 变量 >>> 只读 
	//a = 20; //err
	
	char buf[] = "abcdefg";
	char const * p1 = buf;	// const修饰*，p1指向的内存不能变
	//p1[0] = '0'; //err 改变p1指向的内存 
	//p1 = "123"; //ok   改变p1的指向 
	const char * p2 = buf;	// 含义同上，const修饰*，p2指向的内存不能变
	//p2[0] = '0'; //err
	//p2 = NULL; //ok
	char * const p3 = buf;	// const修饰p3，p3值不能变
	//p3[0] = '0'; //ok
	//p3 = NULL; // err 
	const char * const p4 = buf;	// const修饰*、p4，p4指向的内存不能变，p4值不能变
	//p4[0] = '0'; //err
	//p4 = NULL; //err
}

void run()
{
	fun_const();
}
