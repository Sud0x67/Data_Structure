#pragma once
#ifndef MAZE_H
#define MAZE_H
typedef enum direction { up, right, left, down, wrong }direction;
typedef struct {
	int x, y;
	direction i;
}Position;
typedef Position ElemType;
//使用n*n数组表示迷宫0代表此路不通，1代表未走过，2代表走过

Status comapre(Position a, Position b);

#endif // !MAZE_H


