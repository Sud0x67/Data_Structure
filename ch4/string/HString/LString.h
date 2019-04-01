#ifndef  LSTRING_H
#define LSTRING_H
#define CHUNKSIZE 80
typedef struct Chunk {
	char str[CHUNKSIZE];
	struct Chunk *next;
}Chunk;
typedef struct {
	Chunk *head, *tail;
	int len;
}LString;
#endif // ! LSTRING_H
