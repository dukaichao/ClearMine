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
	printf("��ѡ���Ѷ�:>\n");
	printf("1.�򵥡���10\n");
	printf("2.һ�㡪��20\n");
	printf("3.���ѡ���30\n");
	int input = 0;
	int countMine = 0;
	scanf("%d", &input);
	switch (input){
	case 1:
		countMine = EASY_COUNT;
		PutMine(Mine, Row, Col, countMine);
		//���Mine
		printf("���\n");
		ShowMine(Mine, Row, Col);
		//ɨ��
		ClearMine(Mine,Show, Row, Col, countMine);
		break;
	case 2:
		countMine = GENERAL_COUNT;
		PutMine(Mine, Row, Col, countMine);
		//���Mine
		printf("���\n");
		ShowMine(Mine, Row, Col);
		//ɨ��
		ClearMine(Mine, Show, Row, Col, countMine);
		break;
	case 3:
		countMine = HARD_COUNT;
		PutMine(Mine, Row, Col, countMine);
		//���Mine
		printf("���\n");
		ShowMine(Mine, Row, Col);
		//ɨ��
		ClearMine(Mine, Show, Row, Col, countMine);
		break;
	default:
		printf("����������:>");
	}
}
void menu(){
	printf("1..��ʼ��Ϸ\n");
	printf("0..����\n");
}
void test(){
	
	int input = 1;
	while (input){
		printf("��ѡ��\n");
		menu();
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