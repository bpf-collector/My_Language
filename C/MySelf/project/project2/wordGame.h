#pragma once 

// ��ӡ������ 
void proBar(char sign, int sleep);

// ��ȡn������ַ� 
void getRandWord(int n, char *mode, char *words);

// ��ʼ��Ϸ 
void startGame(char *gameLevel, char *words);

// �жϵ�n���ַ�ch�Ƿ�ƥ��words 
bool judgeChar(char ch, int n, char *words);

// ������Ϸ���� 
void saveData(char *fileName);

//��ȡ��Ϸ���� 
void readData(char *fileName, int N);

// ��ӡ�˵� 
void printMenu();

// ������ 
void MainProcess();

// ��ʼ���ļ� 
void initFile(char *fileName);
