/*
 * @Author: bpf
 * @Date: 2019-09-13 15:49:56
 * @LastEditTime: 2019-09-27 20:27:52
 * @Description: Judge a year is a leap year or not
 */
bool leapYear(int year)
{
	if((year%4==0 && year%100!=0) || (year%400==0))
		return true;
	else
		return false;
}
