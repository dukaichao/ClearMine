#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
#include <time.h>
#include <stdlib.h>
void game(){
	char set1 = '0';
	char set2 = '*';
	//����
	char Mine[Rows][Cols] = { 0 };
	//�½�����
	char Show[Rows][Cols] = { 0 };
	//��ʼ������
	Init(Mine, Rows, Cols,set1);
	Init(Show, Rows, Cols,set2);
	//չʾ
	Display(Mine, Row, Col);
	Display(Show, Row, Col);
	//����
	PutMine(Mine, Row, Col);
	//���Mine
	printf("���\n");
	ShowMine(Mine, Row, Col);
	//ɨ��
	ClearMine(Mine,Show, Row, Col);
}
void menu(){
	printf("1..��ʼ��Ϸ\n");
	printf("2..����\n");
}
void test(){
	menu();
	int input = 1;
	while (input){
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input){
			case 1:
				game();
				break;
			case 0:
				break;
			default:
				printf("����������");
				break;
			}
		}
}
int main(){
	srand((unsigned int)time(0));
	test();
	system("pause");
	return 0;
}