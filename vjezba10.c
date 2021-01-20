#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#

#define DATA_SIZE (11)
#define FILE_NAME_SIZE (1024)

struct _node;
typedef struct _node *NodePosition;
typedef struct _node {
	char data[DATA_SIZE];
	NodePosition left;
	NodePosition right;

}Node;

struct _list;
typedef struct _list *ListPosition;
typedef struct _list {
	NodePosition data;
	ListPosition next;

}List;
int toInfixList(ListPosition head, NodePosition current);
int pushBack(ListPosition head, NodePosition data);
int isNumber(char *str);
NodePosition pop(ListPosition head);
int push(ListPosition head, NodePosition data);
NodePosition readPostfixFromFile(char* filename);
NodePosition createNode(char *data);
ListPosition createListNode(NodePosition data);
void Print (NodePosition);

int main() {
	List infixresult;
	NodePosition root = NULL;
	char filename[FILE_NAME_SIZE] = { 0 };
	printf("insert filename for postfix:\t\n");
	scanf("%s", filename);
	infixresult.next = NULL;

	root = readPostfixFromFile(filename);
	if (root == NULL) {
		return EXIT_FAILURE;
	}
	toInfixList(&infixresult, root);
	for (ListPosition p = infixresult.next; p != NULL; p = p->next) {
		printf("%s", p->data->data);
	}

	return EXIT_SUCCESS;
}

NodePosition readPostfixFromFile(char *filename) {
	List head;
	NodePosition result;
	head.next = NULL;
	FILE *fp = NULL;
	char readString[DATA_SIZE];
	fp = fopen(filename, "r");
	if (NULL == fp) {
		printf("greška");
		return 0;
	}
	while (!feof(fp)) {
		NodePosition node = NULL;
		fscanf(fp, " %s", readString);
		node = createNode(readString);
		if (node = NULL) {
			fclose(fp);
			return NULL;
		}
		if (isNumber(node->data)) {
			push(&head, node);
		}
		else {
			NodePosition left = NULL;
			NodePosition right = NULL;

			right = pop(&head);
			if (NULL == right) {
				printf("greška");
				return NULL;
			}
			//provjerit i lijevo dijete..
			push(&head, node);
		}

	}
	result = pop(&head);
	if (result == NULL) {
		printf("greška");
		return NULL;

	}
	if (pop(&head) != NULL) {
		printf("postfix ne valja");
		return NULL;
	}
	return result;
}
NodePosition createNode(char* data) {
	NodePosition p = NULL;
	p = (NodePosition)malloc(sizeof(Node));
	if (NULL == p) {
		printf("Memory allocation failed");
		return NULL;
	}
	strcpy(p->data, data);
	p->left = NULL;
	p->right = NULL;

	return p;

}

ListPosition createListNode(NodePosition data) {
	ListPosition node = NULL;
	node = (ListPosition)malloc(sizeof(List));
	if (node == NULL) {
		printf("Greška");
		return NULL;
	}

	node->data = data;
	node->next = NULL;
	return node;


}

int push(ListPosition head, NodePosition data) {
	ListPosition node = NULL;
	node = createListNode(data);
	if (node == NULL)
		return -1;
	node->next = head->next;
	head->next = node;
	return 0;

}
NodePosition pop(ListPosition head) {
	NodePosition result;
	ListPosition first = head->next;
	if (first == NULL) {
		return NULL;
	}
	head->next = first->next;
	result = first->data;
	free(first);
	return result;
}
int isNumber(char *str) {
	int number = 0;
	if (sscanf(str, " %d", &number) == 1) {
		return 1;
	}
	else
		return 0;


}
int pushBack(ListPosition head, NodePosition data) {
	ListPosition p = head;

	while (p->next != NULL) {
		p = p->next;
	}
	return push(head, data);

}

int toInfixList(ListPosition head, NodePosition current) {
	if (current == NULL) return;
	toInfixList(head, current->left);
	pushBack(head, current);
	toInfixList(head, current->right);

	return 0;

}

void Print(NodePosition P)
{
	FILE* fp = NULL;

	fp = fopen("file1.txt", "w");



	if (P != NULL)
	{
		Print(P->left);
		Print(P->right);
		printf("%s", P->data);
		puts("");
	}

	if (P != NULL)
	{
		printf("%s", P->data);
		Print(P->left);
		Print(P->right);
		puts("");
	}

	if (P != NULL)
	{
		if (P->left != NULL)
			fprintf(fp, "(");
		Print(P->left);
		fprintf(fp, "%s", P->data);
		Print(P->right);
		if (P->right != NULL)
			fprintf(fp, ")");
	}

}