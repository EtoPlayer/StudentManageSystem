#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <conio.h>

#pragma warning(disable:4996)

// �ṹ��ͱ���
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

// ����
int MenuSelect();
void input(link l);
void Save(link l);
void load(link l);

