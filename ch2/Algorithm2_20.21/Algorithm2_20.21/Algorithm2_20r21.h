#pragma once
#ifndef ALGORITHM02_2021_H
#define ALGORITHM02_2021_H
Status listInsertL(LinkList * L, int i, ElemType e);

Status mergeList(LinkList * La, LinkList * Lb, LinkList * Lc, int(*compare)(ElemType, ElemType));
Status mergeList2(LinkList * La, LinkList * Lb, LinkList * Lc, int(*compare)(ElemType, ElemType));
#endif // !ALGORITHM02_2021_H

