// File: MS_sound
#include <windows.h>

void sound(int Hz, int time)
//ϵͳ������printf("\07"); printf("\a");
{
	Beep(Hz, time);
}
