// ex_结构体
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Student        //结构体 
{
	int clas;
	char name [8];
	int num;
};

int main ()
{
	struct Student * p = (Student*)malloc (sizeof (struct Student));  
    p->clas = 2;
	strcpy(p->name, "Jane");
	p->num = 13;

	struct Student ch ;
	ch.clas = 2;
	strcpy(ch.name, "Jake");
	ch.num = 26;
	
	struct Student shu = {2, "Joke", 39};
	
	printf("Class%d %s NO.%d\n", p->clas, p->name, p->num);
    printf("Class%d %s NO.%d\n", shu.clas, shu.name, shu.num);
    printf("Class%d %s NO.%d", ch.clas, ch.name, ch.num);
	return 0;
}
