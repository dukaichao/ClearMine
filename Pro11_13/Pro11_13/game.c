#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include<string.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
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
void PutMine(char mine[Rows][Cols], int row, int col){
	int count = EASY_COUNT;
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

//判断它的周围八个是否有雷
void OtherIsHaveMine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col){
		if (getMine(mine, row, col) == 0){
			show[row][col] = ' ';
			//再次遍历周围的雷
			if ((row - 1) > 0 && show[row - 1][col] == '*'){
				OtherIsHaveMine(mine, show, row - 1, col);//递归
			}
			if (row - 1 > 0 && col + 1 <= Col && show[row - 1][col + 1] == '*'){
				OtherIsHaveMine(mine, show, row - 1, col + 1);
			}
			if (col + 1 <= Col && show[row][col + 1] == '*'){
				OtherIsHaveMine(mine, show, row, col + 1);
			}
			if (row + 1 <= Row && col + 1 <= Col && show[row + 1][col + 1] == '*'){
				OtherIsHaveMine(mine, show, row + 1, col + 1);
			}
			if (row + 1 <= Row && show[row + 1][col] == '*'){
				OtherIsHaveMine(mine, show, row + 1, col);
			}
			if (row + 1 <= Row && col - 1 > 0 && show[row + 1][col - 1] == '*'){
				OtherIsHaveMine(mine, show, row + 1, col - 1);
			}
			if (row - 1 > 0 && show[row][col - 1] == '*'){
				OtherIsHaveMine(mine, show, row, col - 1);
			}
			if (row - 1 > 0 && col - 1 > 0 && show[row - 1][col + 1] == '*'){
				OtherIsHaveMine(mine, show, row - 1, col + 1);
			}
		}
		else{//周边有雷
			show[row][col] =getMine(mine, row, col) + '0';
		}
	}

//扫雷
void ClearMine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col){
	int x = 0;
	int y = 0;
	int count = EASY_COUNT;
	int win = 0;
	while (win < (Row*Col - count)){
		printf("请输入坐标：\n");
		scanf("%d", &x);
		scanf("%d", &y);
		if ((x > 0 && x <= row) && (y > 0 && y <= col)){
			//判断是否有雷
			if (mine[x][y] == '0'){
				//没有雷统计该格子周围八个格子的雷数
				show[x][y] = getMine(mine, x, y) + '0';
				//如果雷数等于0的话，递归判断其周围格子
				if (show[x][y] == '0'){
					show[x][y] = ' ';
					//递归判断周围格子
					OtherIsHaveMine(mine, show, row, col);
					//扫一次雷后统计有雷的边界数，方便我们标记雷的位置
					ShowMine(show, row, col);
					win++;
				}
				else{
					printf("很遗憾你被炸死了...........菜鸡\n");
					ShowMine(mine, row, col);
					break;
				}
			}
			if (win == Row*Col - count){
				printf("恭喜你，挑战成功.......\n");
				break;
			}
		}
	}
}