/*
 * @Author: bpf
 * @Date: 2019-09-13 15:49:56
 * @LastEditTime: 2019-09-27 20:25:43
 * @Description: sound
 */
#include <windows.h>

void sound(int Hz, int time)
//ÏµÍ³·äÃù printf("\07"); printf("\a");
{
	Beep(Hz, time);
}
