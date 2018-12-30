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
	
}
//统计标记雷的个数,如果小于等于雷数，返回1;大于雷数返回0
int IsTotalSignMine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col, int count){
	int SignMineCount = 0;
	for (int i = 1; i <= row; i++){
		for (int j = 1; j <= col; j++){
			if (show[i][j] == 'm'&&mine[i][j] == '1'){
				SignMineCount++;
			}
		}
	}
	if (SignMineCount == count)
		return 1;
	return 0;
}
//取消标记
void  cancel(char mine[Rows][Cols], char show[Rows][Cols], int row, int col){
	int input = 1;
	int x = 0;
	int y = 0;
	while (1){
		printf("请输入取消的坐标:>\n");
		scanf("%d %d", &x,&y);
		if ((x > 0 && x <= row) && (y > 0 && y <= col) && show[x][y] == 'm'){
			show[x][y] = '*';
			system("cls");
			ShowMine(show, row, col);
			break;
		}
		else{
			printf("请输入正确的坐标\n");
		}
	}
		

}
//扫雷
void ClearMine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col, int count){
	int x = 0;
	int y = 0;
	while (1){
		int in = 1;//1标记，2.取消标记，0.继续扫雷
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
						if (show[i][j] == '*' || show[i][j] == 'm'){
							continue;
						}
						win++;
					}
				}
				//标记雷数大于真正的雷数时，返回0
				if (win > row*col - count){
					printf("标记有误\n");

				}
				else if (win == row*col - count){
					printf("兄弟nb\n");
					ShowMine(mine, row, col);
					break;
				}
					
				system("cls");
				ShowMine(show, row, col);
				while (in){
					printf("1.标记雷 2.取消标记 0.继续扫雷\n");
					scanf("%d", &in);
					switch (in){
						//退出
						case 0:break;
						//是否标记雷
						case 1 :SignMine(show, row, col);
								break;
						//是否取消标记
						case 2:cancel(mine, show, row, col);
								break;
						default:
							printf("请重新输入\n");
					}

				}
				//判断标记的雷数是否正确并且标记的雷刚好等于count
				if (IsTotalSignMine(mine, show, row, col, count)){
					printf("兄弟，nb\n");
					break;
				}
			}
			else{
				printf("兄弟可以买彩票去啦...........菜鸡\n");
				ShowMine(mine, row, col);
				break;
			}
		}
		else{
			printf("坐标输入不正确,");
		}
	}
}