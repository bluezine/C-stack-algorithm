#include <stdio.h>
#include <stdlib.h>

struct Stack {
	int data;
	struct Stack *up;
	struct Stack *down;
};

struct Stack *bottom;
struct Stack *current;
struct Stack *top;

void push(int data) {
	printf("[Push] %d\n", data);
	current = (struct Stack *)malloc(sizeof(struct Stack));
	current->data = data;
	current->down = NULL;
	current->up = NULL;
	if (bottom == NULL) {
		bottom = top = current;
	}
	else {
		current->down = top;
		top->up = current;
		top = current;
	}
}

void pop() {
	printf("[Pop] %d\n", top->data);
	top->down->up = NULL;
	top = top->down;
}

void printStack() {
	current = bottom;
	printf("Stack Data : ");
	while (1) {
		printf("%d ", current->data);
		if (current->up == NULL) {
			printf("\n");
			break;
		}
		current = current->up;
	}

}

int main(void) {
	push(1);
	push(2);
	push(3);
	printStack();
	pop();
	printStack();
	push(4);
	push(5);
	push(6);
	printStack();
	return 0;
}
