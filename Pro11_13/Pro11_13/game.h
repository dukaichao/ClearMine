
#ifndef _GAME_H_
#define Row 9
#define Col 9
#define Rows Row+2
#define Cols Col+2
#define EASY_COUNT 10

//初始化
void Init(char arr[Rows][Cols], int rows, int cols,char Set);
//展示
void Display(char arr[Rows][Cols], int row, int col);
//摆雷
void PutMine(char arr[Rows][Cols],int row, int col);
//检查
void ShowMine(char arr[Rows][Cols], int row, int col);
//扫雷
void ClearMine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col);
//周围没雷置空
void OtherIsHaveMine(char arr[Rows][Cols], char show[Rows][Cols], int row, int col);
#endif