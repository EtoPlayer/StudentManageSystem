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
		scanf_s("%d", &p->data.name);
		printf("sex:");
		scanf_s("%d", &p->data.sex);
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