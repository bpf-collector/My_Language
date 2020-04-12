/*
 * @Author: bpf
 * @Date: 2019-09-13 15:49:56
 * @LastEditTime: 2019-09-27 20:33:30
 * @Description: file content
 */
#include "MS_leapYear.cpp"
#include "MS_sound.cpp"
#include "MS_random.cpp"
#include "MS_prime.cpp"
#include "MS_equation.cpp"
#include "MS_wordsCount.cpp"
#include "MS_Fibonacci.cpp"
#include "MS_Hanio.cpp"
#include "MS_leastMultiple.cpp"
#include "MS_maximumDivisor.cpp"
#include "MS_calcPi.cpp"
#pragma once

// File: MS_leapYear
bool leapYear(int year);

// File: MS_sound
void sound(int Hz, int time);

// File: MS_random
void random(int num, int *randList);

// FIle: MS_prime
bool prime(int num);

// File: MS_equation
void equation(double a, double b, double c);

// File: MS_wordsCount
int wordsCount(char *str);

// File: MS_Fibonacci[쳲���������]
void Fibonacci(int n);

// File: MS_Hanio[��ŵ��]
void move(char A, char B);
void Hanio(int n, char A, char B, char C);

// File: MS_leastMutiple
int  Multiple(int m, int n);

// File: MS_maximumDivisor
int  Dividor(int m, int n);

// File: MS_calcPi
double Pi();
