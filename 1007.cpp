#include "stdafx.h"
#include <stdio.h>
/*
typedef struct maxSubSeq {
	int MaxSum;
	int start;
	int end;
}MaxSubSeq;

MaxSubSeq maxSequence(int A[], int n)
{
	int i;
	int ThisSum = 0, start = 0;
	int flag = 0;
	MaxSubSeq max;
	max.MaxSum = 0;
	max.start = 0;
	max.end = n - 1;
	for (i = 0; i<n; i++) {
		if (ThisSum == 0)
			start = i;
		else if (ThisSum == -1)
			ThisSum = 0;
		ThisSum += A[i];
		if (ThisSum > max.MaxSum) {
			max.MaxSum = ThisSum;
			max.start = start;
			max.end = i;
		}
		else if (ThisSum < 0) {
			ThisSum = 0;
		}
		else if (ThisSum == 0) { //等于0时，标记为-1，使start不变；
			ThisSum = -1;
			flag = i;
		}
	}
	if (max.MaxSum == 0 && flag) { //满足该条件时一定是数列中为0的串最大，所以不管flag是多少，只要输出的是0就够了
		max.start = flag;
		max.end = flag;
	}
	return max;
}

int main()
{
	int n;
	MaxSubSeq max;
	scanf_s("%d", &n);
	int A[n];
	int i;
	for (i = 0; i<n; i++)
		scanf_s("%d", &A[i]);
	//function()
	max = maxSequence(A, n);

	printf("%d %d %d", max.MaxSum, A[max.start], A[max.end]);//如果数列中全是负数，则max的值就是初始化的赋值
	return 0;
}*/