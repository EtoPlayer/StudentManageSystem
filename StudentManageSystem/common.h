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
extern int MenuSelect();
extern void input(link l);
extern void Save(link l);
extern void load(link l);
extern void list(link l);
extern void display(Node* p);
extern void search(link l);
extern void del(link l);

