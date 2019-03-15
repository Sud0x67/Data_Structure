#include<stdio.h>
#include<stdlib.h>
#include"PreDefined.h"
#include "maze.h"
#include "Stack.h"
/*typedef enum direction{up,right,left,down,wrong}direction;
typedef struct {
	int x, y;
	direction i;
}Position;
typedef Position ElemType;
//使用n*n数组表示迷宫0代表此路不通，1代表未走过，2代表走过
int a[10][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,1,0,1,1,1,0,1,0},
	{0,1,1,0,1,1,1,0,1,0},
	{0,1,1,1,1,0,0,1,1,0},
	{0,1,0,0,0,1,1,1,1,0},
	{0,1,1,1,0,1,1,1,1,0},
	{0,1,0,1,1,1,0,1,1,0},
	{0,1,0,0,0,1,0,0,1,0},
	{0,0,1,1,1,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0}
};
Position start = { 1,1,up };
Position start = { 8,8,up };
*/
//判断是否走过
//尽管这个实现不够优雅，已经很好了
Status comapre(Position a, Position b)
{
	if (a.x == b.x&&a.y == b.y)return TRUE;
	return FALSE;
}
Status printMap(Position *p)
{
	Position pos = *p;
	printf("(%d,%d)", pos.x, pos.y);
	switch (pos.i)
	{
	case up:
		printf("up"); break;
	case right:
		printf("right"); break;
	case down:
		printf("down"); break;
	case left:
		printf("left"); break;
	default:
		printf("wrong"); break;
	}
	printf("\n");
	return OK;
}
 footPrint(Stack S, Position curPosition)
 {
	 ElemType* p = S.base;
	 while (p != S.top)
	 {
		 if ((*p).x == curPosition.x&&(*p).y == curPosition.y)
			 return TRUE;
	 }
	 return FALSE;
}
 Status mazePath(int maze[][10], Position start, Position end)
 {
	 Stack S;
	 initStack(&S);
	 Position curPosition = start;
	 while (!comapre(curPosition, end))
	 {
		 Position nextPosition;
		 curPosition.i = up;
		 switch (curPosition.i)
		 {
		 case up:
			 if (curPosition.x - 1 > 0 && curPosition.x - 1 < 10 && maze[curPosition.x - 1][curPosition.y]==1)
			 {
				 maze[curPosition.x - 1][curPosition.y] = 2;
				 push(&S, curPosition);
				 curPosition.x--;
				 break;
			 }
			 else
			 {
				 curPosition.i = right;
			 }
		 case right:
			 if (curPosition.y + 1 > 0 && curPosition.x + 1 < 10 && maze[curPosition.x ][curPosition.y +1]==1)
			 {
				 maze[curPosition.x][curPosition.y + 1] = 2;
				 push(&S, curPosition);
				 curPosition.y++;
				 break;
			 }
			 else
			 {
				 curPosition.i = down;
			 }
		 case down:
			 if (curPosition.x+1 > 0 && curPosition.x + 1  < 10 && maze[curPosition.x+1][curPosition.y ]==1)
			 {
				 maze[curPosition.x + 1][curPosition.y] = 2;
				 push(&S, curPosition);
				 curPosition.x++;
				 break;
			 }
			 else
			 {
				 curPosition.i = left;
			 }
		 case left:
			 if (curPosition.y- 1 > 0 && curPosition.y-1 < 10 && maze[curPosition.x][curPosition.y-1]==1)
			 {
				 maze[curPosition.x][curPosition.y - 1] = 2;
				 push(&S, curPosition);
				 curPosition.y--;
				 break;
			 }
			 else
			 {
				 curPosition.i = wrong;
			 }
		 default:
			 maze[curPosition.x][curPosition.y] == 0;
			 pop(&S, &curPosition);
			 break;
		 }
	 }
	 stackTraverse(S, printMap);
 }

 void main()
 {
	 int maze1[10][10] = {
		 { 0,0,0,0,0,0,0,0,0,0 },
		 { 0,1,1,0,1,1,1,0,1,0 },
		 { 0,1,1,0,1,1,1,0,1,0 },
		 { 0,1,1,1,1,0,0,1,1,0 },
		 { 0,1,0,0,0,1,1,1,1,0 },
		 { 0,1,1,1,0,1,1,1,1,0 },
		 { 0,1,0,1,1,1,0,1,1,0 },
		 { 0,1,0,0,0,1,0,0,1,0 },
		 { 0,0,1,1,1,1,1,1,1,0 },
		 { 0,0,0,0,0,0,0,0,0,0 }
	 };
	 Position start1 = { 1,1,up };
	 Position end1 = { 8,8,up };
	 mazePath(maze1, start1, end1);
	 system("pause");
}