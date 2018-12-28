
#ifndef _GAME_H_
#define Row 9
#define Col 9
#define Rows Row+2
#define Cols Col+2
#define EASY_COUNT 10
#define GENERAL_COUNT 20
#define HARD_COUNT 30

//��ʼ��
void Init(char arr[Rows][Cols], int rows, int cols,char Set);
//չʾ
void Display(char arr[Rows][Cols], int row, int col);
//����
void PutMine(char arr[Rows][Cols], int row, int col, int count);
//���
void ShowMine(char arr[Rows][Cols], int row, int col);
//ɨ��
void ClearMine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col, int count);
//�Ƿ�����
void SignMine(char show[Rows][Cols], int row, int col);
//��Χû���ÿ�
void OtherIsHaveMine(char mine[Rows][Cols], char show[Rows][Cols], int arr[8][2], int row, int col);
//ͳ�Ʊ���׵ĸ���,���С�ڵ�������������1;������������0
int TotalSignMine(char show[Rows][Cols], int row, int col, int count);
#endif