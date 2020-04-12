#pragma once 

// 打印进度条 
void proBar(char sign, int sleep);

// 获取n个随机字符 
void getRandWord(int n, char *mode, char *words);

// 开始游戏 
void startGame(char *gameLevel, char *words);

// 判断第n个字符ch是否匹配words 
bool judgeChar(char ch, int n, char *words);

// 保存游戏数据 
void saveData(char *fileName);

//读取游戏数据 
void readData(char *fileName, int N);

// 打印菜单 
void printMenu();

// 主函数 
void MainProcess();

// 初始化文件 
void initFile(char *fileName);
