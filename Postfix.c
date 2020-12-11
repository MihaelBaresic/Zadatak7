#define _CRT_SECURE_NO_WARNINGS
//2+3*(2+3*(2-1)+(4*2)-6)+2

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
Position create(char);
void printList(Position);
int Pop(Position);
int Result(Position);

int main() {
	Stack head;
	head.next = NULL;
	Position K = NULL;
	FILE* File;
	File = fopen("Text.txt", "r");
	if (!File)
		printf("Wrong allocation!");
	
	char line[1024];
	fgets(line, 1024, File);
	
	int number;

	int i = 0;
	do {
		if(line[i]!=' ')
			switch (line[i]) {
			case('+'):
				K = create(line[i]);
				Push(&head, K);
				break;
			case('-'):
				K = create(line[i]);
				Push(&head, K);
				break;
			case('*'):
				K = create(line[i]);
				Push(&head, K);
				break;
			case('('):
				K = create(line[i]);
				Push(&head, K);
				break;
			case(')'):
				K = create(line[i]);
				Push(&head, K);
				break;
			default:
				number = (int)(line[i]);
				K = create(number);
				Push(&head, K);
				break;
			}
		i++;
	} while (line[i] != '\0');

	

	int r;
	r = Result(&head);
	printf("\n\tThe result of postfix is: %d", r);
	int n;
	

	printList(&head);
	return 0;
}


Position create(int El) {
	Position Q;
	Q = (Position)malloc(sizeof(Stack));
	if (!Q)
		printf("Memory not allocated!");
	Q->El = El;
	Q->next = NULL;
	return Q;
}

int Result(Position head) {
	
	head = head->next;
	do{
		
		
		
		
		
		
		
		head = head->next;
	} while (head != NULL);



	return 0;
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
		printf("\t\n%d",head->El);
		head = head->next;
	}

	puts("\n");
}
