/* const ������ָ�������ָ���ܸı䣬����ֵ���ܸı� */
/* const *��   ָ����ָ���ڴ治�ܸı�*/

void fun_const()
{
	const int a = 10; // ���� >>> ֻ�� 
	//a = 20; //err
	
	char buf[] = "abcdefg";
	char const * p1 = buf;	// const����*��p1ָ����ڴ治�ܱ�
	//p1[0] = '0'; //err �ı�p1ָ����ڴ� 
	//p1 = "123"; //ok   �ı�p1��ָ�� 
	const char * p2 = buf;	// ����ͬ�ϣ�const����*��p2ָ����ڴ治�ܱ�
	//p2[0] = '0'; //err
	//p2 = NULL; //ok
	char * const p3 = buf;	// const����p3��p3ֵ���ܱ�
	//p3[0] = '0'; //ok
	//p3 = NULL; // err 
	const char * const p4 = buf;	// const����*��p4��p4ָ����ڴ治�ܱ䣬p4ֵ���ܱ�
	//p4[0] = '0'; //err
	//p4 = NULL; //err
}

void run()
{
	fun_const();
}
