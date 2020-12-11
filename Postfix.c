#define _CRT_SECURE_NO_WARNINGS
//7+3*(2+3*(2-1)+(4*2)-6)+2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Stack* Position;
struct _Stack;
typedef struct _Stack {
	int El;
	Position next;
}Stack;

void Push(Position, Position);
Position createEl(int);
void printList(Position);
int Pop(Position);


int main() {
	Stack head;
	head.next = NULL;
	Position K = NULL;
	FILE* File;
	File = fopen("Text.txt", "r");
	if (!File)
		printf("Wrong allocation!");

	char* buffer = NULL;
	buffer = (char*)malloc(1024);
	fgets(buffer, 1024, File);

	int count = 0, value_c = 0, value_i = 0, number = 0;
	int n;
	n = strlen(buffer);
	int result = 0, res = 0;
	char operation;
	int el1 = 0, el2 = 0;


	while (result <= n) {
		value_c = 0;
		value_i = 0;
		value_i = sscanf(buffer,"%d%n", &number, &count);
		if(value_i==1)
		{
			K = createEl(number);
			Push(&head, K);
		}
		else {
			value_c = sscanf(buffer, "%c%n", &operation, &count);
			if (value_c == 1) {
				if (operation == '+') {
					el1 = Pop(&head);
					el2 = Pop(&head);
					res = el1 + el2;
					K = createEl(res);
					Push(&head, K);
				}
				else if (operation == '-') {
					el1 = Pop(&head);
					el2 = Pop(&head);
					res = el2 - el1;
					K = createEl(res);
					Push(&head, K);
				}
				else if(operation == '*') {
					el1 = Pop(&head);
					el2 = Pop(&head);
					res = el1 * el2;
					K = createEl(res);
					Push(&head, K);
				}
			}
		}
		buffer += count;
		result += count;
	}

	res = Pop(&head);
	printf("Result of postfix is: %d", res);
	printList(&head);
	return 0;
}


Position createEl(int El) {
	Position Q;
	Q = (Position)malloc(sizeof(Stack));
	if (!Q)
		printf("Memory not allocated!");
	Q->El = El;
	Q->next = NULL;
	return Q;
}

void Push(Position head, Position K) {

	while (head->next != NULL)
		head = head->next;

	K->next = head->next;
	head->next = K;
}

int Pop(Position head) {
	if (head->next == NULL)
		return 0;
	Position temp;
	while (head->next->next != NULL)
		head = head->next;
	temp = head->next;
	head->next = NULL;
	return temp->El;
	free(temp);
}


void printList(Position head) {
	if (NULL == head->next)
		printf("\n\tLinked list is emtpy!");

	head = head->next;
	while (head != NULL) {
		printf("\t\n%d", head->El);
		head = head->next;
	}

	puts("\n");
}