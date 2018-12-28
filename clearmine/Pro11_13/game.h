
#ifndef _GAME_H_
#define Row 9
#define Col 9
#define Rows Row+2
#define Cols Col+2
#define EASY_COUNT 10
#define GENERAL_COUNT 20
#define HARD_COUNT 30

//初始化
void Init(char arr[Rows][Cols], int rows, int cols,char Set);
//展示
void Display(char arr[Rows][Cols], int row, int col);
//摆雷
void PutMine(char arr[Rows][Cols], int row, int col, int count);
//检查
void ShowMine(char arr[Rows][Cols], int row, int col);
//扫雷
void ClearMine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col, int count);
//是否标记雷
void SignMine(char show[Rows][Cols], int row, int col);
//周围没雷置空
void OtherIsHaveMine(char mine[Rows][Cols], char show[Rows][Cols], int arr[8][2], int row, int col);
//统计标记雷的个数,如果小于等于雷数，返回1;大于雷数返回0
int TotalSignMine(char show[Rows][Cols], int row, int col, int count);
#endif