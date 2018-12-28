#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include<string.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//初始化
void Init(char arr[Rows][Cols], int rows, int cols,char set){
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++){
		for (j = 0; j < cols; j++){
			arr[i][j] = set;
		}
	}
	printf("----------------------------\n");

}
//展示
void Display(char arr[Rows][Cols], int row, int col){
	int i = 0;
	int j = 0;
	for (int k = 0; k <= col; k++){
		printf("%d ", k);
	}
	printf("\n");
	for (i = 1; i <= row; i++){
		printf("%d ", i);
		for (j = 1; j <= col; j++){
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("----------------------------\n");
}
//摆雷
void PutMine(char mine[Rows][Cols], int row, int col,int count){
	int x = 0;
	int y = 0;
	while (count >0 ){
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = 1 + '0';
			count--;
		}
	}
}
//检查
void ShowMine(char arr[Rows][Cols], int row, int col){
	int i = 0;
	int j = 0;
	for (int k = 0; k <= Col; k++){
		printf("%d ", k);
	}
	printf("\n");
	for (i = 1; i <= row; i++){
		printf("%d ", i);
		for (j = 1; j <= col; j++){
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

//获取x,y 坐标周围八个格子的雷数
int getMine(char mine[Rows][Cols], int x, int y){

	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
	
}


void OtherIsHaveMine(char mine[Rows][Cols], char show[Rows][Cols], int arr[8][2], int row, int col){
	for (int i = 0; i <8; i++){
		int x = arr[i][0];
		int y = arr[i][1];
		if (x>0 && x <= row&&y > 0 && y <= col&&(show[x][y] == '*')){
			if (getMine(mine, x, y) == 0){
				show[x][y] = ' ';
				int ch[8][2] = { x - 1, y, x - 1, y - 1,
					x, y - 1, x + 1, y - 1,
					x + 1, y, x + 1, y + 1,
					x, y + 1, x - 1, y + 1 };
				OtherIsHaveMine(mine, show, ch, row, col);
			}
			else{
				show[x][y] = getMine(mine, x, y) + '0';
			}
		}
	}
}
//是否要标记雷:   1代表标记雷(用字符m表示有雷)    0代表不标记继续扫雷
void SignMine(char show[Rows][Cols], int row, int col){
	int input = 1;
	int x = 0;
	int y = 0;
	while (input){
		printf("是否标记雷\n");
		printf("1.标记\n");
		printf("0.不标记\n");
		scanf("%d", &input);
		switch (input){
			case 0:
				printf("继续扫雷：\n");
				break;
			case 1:
				while (1){
					printf("请输入有雷的坐标:>\n");
					scanf("%d", &x);
					scanf("%d", &y);
					if ((x > 0 && x <= row) && (y > 0 && y <= col) && show[x][y] == '*'){
						show[x][y] = 'm';
						system("cls");
						ShowMine(show, row, col);
						break;
					}
					else{
						printf("请输入正确的坐标\n");
					}
				}
				break;
			default:
				printf("请正确输入;>\n");

		}
	}
	
}
//统计标记雷的个数,如果小于等于雷数，返回1;大于雷数返回0
int TotalSignMine(char show[Rows][Cols], int row, int col, int count){
	int SignMineCount = 0;
	for (int i = 1; i <= row; i++){
		for (int j = 1; j <= col; j++){
			if (show[i][j] == 'm'){
				SignMineCount++;
			}
		}
	}
	if (SignMineCount > count)
		return 0;
	return 1;
}

//扫雷
void ClearMine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col, int count){
	int x = 0;
	int y = 0;
	while (1){
		int win = 0;
		printf("请输入坐标：\n");
		scanf("%d", &x);
		scanf("%d", &y);
		if ((x > 0 && x <= row) && (y > 0 && y <= col)&&show[x][y]=='*'){
			//判断是否有雷
			if(mine[x][y] == '0'){
				//没有雷统计该格子周围八个格子的雷数
				show[x][y] = getMine(mine, x, y) + '0';
				//如果雷数等于0的话，递归判断其周围格子
				if (show[x][y] == '0'){
					show[x][y] = ' ';
					//递归判断周围格子
					int arr[8][2] = { x - 1, y, x - 1, y - 1,
						x, y - 1, x + 1, y - 1,
						x + 1, y, x + 1, y + 1,
						x, y + 1, x - 1, y + 1 };
					OtherIsHaveMine(mine, show, arr, row, col);
				}
				for (int i = 1; i <= row; i++){
					for (int j = 1; j <= col; j++){
						//if (show[i][j] == ' '||(show[i][j]-'0' <9&&show[i][j]-'0'>0))
						if (show[i][j] != '*' || show[i][j] != 'm' && show[i][j] != '*'){
							win++;
						}
					}
				}
				//标记雷数大于真正的雷数时，返回0
				if (TotalSignMine(show, row, col, count)){
					if (win == row*col - count){
						printf("挑战成功sayoulala\n");
						ShowMine(mine, row, col);
						break;
					}
				}
				else{
					printf("你标记的雷有可能不是雷，请你在标记的地方找出不是雷的位置");
				}
				system("cls");
				ShowMine(show, row, col);
				//是否标记雷
				SignMine(show, row, col);

			}
			else{
				printf("很遗憾你被炸死了...........菜鸡\n");
				ShowMine(mine, row, col);
				break;
			}
		}
		else{
			printf("坐标输入不正确,");
		}
	}
}