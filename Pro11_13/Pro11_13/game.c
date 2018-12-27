#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include<string.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
//��ʼ��
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
//չʾ
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
//����
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
//���
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

//��ȡx,y ������Χ�˸����ӵ�����
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

//�ж�������Χ�˸��Ƿ�����
void OtherIsHaveMine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col){
		if (getMine(mine, row, col) == 0){
			show[row][col] = ' ';
			//�ٴα�����Χ����
			if ((row - 1) > 0 && show[row - 1][col] == '*'){
				OtherIsHaveMine(mine, show, row - 1, col);//�ݹ�
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
		else{//�ܱ�����
			show[row][col] =getMine(mine, row, col) + '0';
		}
	}

//ɨ��
void ClearMine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col){
	int x = 0;
	int y = 0;
	int count = EASY_COUNT;
	int win = 0;
	while (win < (Row*Col - count)){
		printf("���������꣺\n");
		scanf("%d", &x);
		scanf("%d", &y);
		if ((x > 0 && x <= row) && (y > 0 && y <= col)){
			//�ж��Ƿ�����
			if (mine[x][y] == '0'){
				//û����ͳ�Ƹø�����Χ�˸����ӵ�����
				show[x][y] = getMine(mine, x, y) + '0';
				//�����������0�Ļ����ݹ��ж�����Χ����
				if (show[x][y] == '0'){
					show[x][y] = ' ';
					//�ݹ��ж���Χ����
					OtherIsHaveMine(mine, show, row, col);
					//ɨһ���׺�ͳ�����׵ı߽������������Ǳ���׵�λ��
					ShowMine(show, row, col);
					win++;
				}
				else{
					printf("���ź��㱻ը����...........�˼�\n");
					ShowMine(mine, row, col);
					break;
				}
			}
			if (win == Row*Col - count){
				printf("��ϲ�㣬��ս�ɹ�.......\n");
				break;
			}
		}
	}
}