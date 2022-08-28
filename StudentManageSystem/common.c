#include <common.h>

int MenuSelect()
{
	int i = 0;

	printf("\n\n\t ********************STUDENTS LIST********************");
	printf("\t}*           1.input record         *|\n");
	printf("\t}*           2.delete record        *|\n");
	printf("\t}*           3.list record          *|\n");
	printf("\t}*           4.search record        *|\n");
	printf("\t}*           5.save record          *|\n");
	printf("\t}*           6.load record          *|\n");
	printf("\t}*           7.quit                 *|\n");
	printf("\n\n\t *****************************************************");

	do {
		printf("\n\tEnter your choice:");
		scanf_s("%d", &i);
	} while (i <= 0 || i > 7);

	return i;
}

void input(link l)
{
	int i;
	Node* p, * q;

	while (1) {
		p = (Node*)malloc(sizeof(Node));
		if (p == NULL) {
			printf("failure\n");
		}

		printf("input number:");
		scanf_s("%d", &p->data.num);
		if (&p->data.num == 0) {
			break;
		}

		for (q = l; q->next != NULL; q = q->next) {
			if (q->data.num == p->data.num) {
				printf("has existed,please input again.");
				scanf_s("%d", &p->data.num);
			}
		}

		printf("name:");
		scanf_s("%c", &p->data.name);
		printf("sex:");
		scanf_s("%c", &p->data.sex);
		printf("age:");
		scanf_s("%d", &p->data.age);

		for (i = 0; i < 3; i++) {
			scanf_s("%lf", &p->data.score[i]);
		}
		p->data.sum = p->data.score[0] + p->data.score[1] + p->data.score[2];
		p->data.ave = p->data.sum / 3;

		p->next = NULL;
		q->next = p;
		q = p;
	}

}

void Save(link l)
{
	Node* p;
	FILE* fp;
	p = l->next;

	if ((fp = fopen("E:\\code\StudentManageSystem", "wb")) == NULL) {
		printf("can not open file\n");
		exit(1);
	}

	printf("\nSaving file\n");
	while (p) {
		fwrite(p, sizeof(Node), 1, fp);
		p = p->next;
	}
	fclose(fp);
	getch();
}

void load(link l)
{
	Node* p, * r;
	FILE* fp;
	l->next = NULL;
	r = l;

	if ((fp = fopen("E:\\code\StudentManageSystem", "wb")) == NULL) {
		printf("can not open file\n");
		exit(1);
	}

	printf("\nloading file\n");
	while (!feof(fp)) {
		p = (Node*)malloc(sizeof(Node));
		if (!p) {
			printf("memory malloc failure");
			return;
		}

		if (fread(p, sizeof(Node), 1, fp) != 1) {
			break;
		}
		else {
			p->next = NULL;
			r->next = p;
			r = p;
		}
	}
}

void list(link l)
{
	Node* p;
	p = l->next;

	if (p == NULL) {
		printf("no student record!");
	}

	while (p != NULL) {
		display(p);
		p = p->next;
	}

	getch();
}

void display(Node *p)
{
	printf("STUDENT INFORMATION\n");
	printf("number:%d\n", p->data.num);
	printf("name:%s\n", p->data.name);
	printf("sex:%s\n", p->data.sex);
	printf("age:%d\n", p->data.age);
	printf("Chinese:%lf\n", p->data.score[0]);
	printf("Math:%lf\n", p->data.score[1]);
	printf("English:%lf\n", p->data.score[2]);
	printf("sum:%lf\n", p->data.sum);
	printf("average:%lf\n", p->data.ave);
}

void search(link l)
{
	int num;
	Node* p;
	p = l->next;

	printf("input number of the student:\n");
	scanf("%d", &num);
	while (p) {
		if (p->data.num == num) {
			display(p);
			getch();
			break;
		}
		p = p->next;
	}
	if (p == NULL) {
		printf("can not find the student!");
	}
}

void del(link l)
{
	int num;
	Node* p, *q;
	q = l;
	p = q->next;

	printf("please input the student number you want to delete:\n");
	scanf("%d", &num);

	while (p) {
		if (p->data.num == num) {
			q->next = p->next;
			free(p);
			printf("delete successfully!\n");
			break;
		} else {
			q = p;
			p = q->next;
		}
	}

	if (p == NULL) {
		printf("can not find the student!");
	}

	getch();
}