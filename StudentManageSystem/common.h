#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <conio.h>

#pragma warning(disable:4996)

// 结构体和变量
struct Student {
	int num;
	char name[15];
	char sex[2];
	int age;
	double score[3];
	double sum;
	double ave;
};

typedef struct node {
	struct Student data;
	struct node* next;
} Node, * link; 

// 函数
int MenuSelect();
void input(link l);
void Save(link l);
void load(link l);

