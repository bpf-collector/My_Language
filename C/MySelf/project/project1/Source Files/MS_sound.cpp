// File: MS_sound
#include <windows.h>

void sound(int Hz, int time)
//ÏµÍ³·äÃù£ºprintf("\07"); printf("\a");
{
	Beep(Hz, time);
}
