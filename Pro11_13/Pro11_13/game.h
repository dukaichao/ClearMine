
#ifndef _GAME_H_
#define Row 9
#define Col 9
#define Rows Row+2
#define Cols Col+2
#define EASY_COUNT 10

//��ʼ��
void Init(char arr[Rows][Cols], int rows, int cols,char Set);
//չʾ
void Display(char arr[Rows][Cols], int row, int col);
//����
void PutMine(char arr[Rows][Cols],int row, int col);
//���
void ShowMine(char arr[Rows][Cols], int row, int col);
//ɨ��
void ClearMine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col);
//��Χû���ÿ�
void OtherIsHaveMine(char arr[Rows][Cols], char show[Rows][Cols], int row, int col);
#endif