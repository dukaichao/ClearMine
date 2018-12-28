#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include<string.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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
//�Ƿ�Ҫ�����:   1��������(���ַ�m��ʾ����)    0������Ǽ���ɨ��
void SignMine(char show[Rows][Cols], int row, int col){
	int input = 1;
	int x = 0;
	int y = 0;
	while (input){
		printf("�Ƿ�����\n");
		printf("1.���\n");
		printf("0.�����\n");
		scanf("%d", &input);
		switch (input){
			case 0:
				printf("����ɨ�ף�\n");
				break;
			case 1:
				while (1){
					printf("���������׵�����:>\n");
					scanf("%d", &x);
					scanf("%d", &y);
					if ((x > 0 && x <= row) && (y > 0 && y <= col) && show[x][y] == '*'){
						show[x][y] = 'm';
						system("cls");
						ShowMine(show, row, col);
						break;
					}
					else{
						printf("��������ȷ������\n");
					}
				}
				break;
			default:
				printf("����ȷ����;>\n");

		}
	}
	
}
//ͳ�Ʊ���׵ĸ���,���С�ڵ�������������1;������������0
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

//ɨ��
void ClearMine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col, int count){
	int x = 0;
	int y = 0;
	while (1){
		int win = 0;
		printf("���������꣺\n");
		scanf("%d", &x);
		scanf("%d", &y);
		if ((x > 0 && x <= row) && (y > 0 && y <= col)&&show[x][y]=='*'){
			//�ж��Ƿ�����
			if(mine[x][y] == '0'){
				//û����ͳ�Ƹø�����Χ�˸����ӵ�����
				show[x][y] = getMine(mine, x, y) + '0';
				//�����������0�Ļ����ݹ��ж�����Χ����
				if (show[x][y] == '0'){
					show[x][y] = ' ';
					//�ݹ��ж���Χ����
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
				//���������������������ʱ������0
				if (TotalSignMine(show, row, col, count)){
					if (win == row*col - count){
						printf("��ս�ɹ�sayoulala\n");
						ShowMine(mine, row, col);
						break;
					}
				}
				else{
					printf("���ǵ����п��ܲ����ף������ڱ�ǵĵط��ҳ������׵�λ��");
				}
				system("cls");
				ShowMine(show, row, col);
				//�Ƿ�����
				SignMine(show, row, col);

			}
			else{
				printf("���ź��㱻ը����...........�˼�\n");
				ShowMine(mine, row, col);
				break;
			}
		}
		else{
			printf("�������벻��ȷ,");
		}
	}
}