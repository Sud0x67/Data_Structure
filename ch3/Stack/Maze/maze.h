#pragma once
#ifndef MAZE_H
#define MAZE_H
typedef enum direction { up, right, left, down, wrong }direction;
typedef struct {
	int x, y;
	direction i;
}Position;
typedef Position ElemType;
//ʹ��n*n�����ʾ�Թ�0�����·��ͨ��1����δ�߹���2�����߹�

Status comapre(Position a, Position b);

#endif // !MAZE_H


