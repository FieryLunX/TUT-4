//Konsepnya FIFO (First In First Out)

#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next, *prev;
};

struct node *curr, *head, *tail;

struct node* new_node(int value){
	curr = (struct node*) malloc(sizeof(struct node));
	curr->value = value;
	curr-> next = curr->prev = NULL;
	return curr;
}

void enqueue (int value){
	curr = new_node(value);
	
	if (head == NULL){
		head = tail = curr;
	}
	else {
		tail->next = curr;
		curr->prev = tail;
		tail= curr;
	}
}

void view(){
	curr = head;
	if (head == NULL){
		printf ("No Data!");
	}
	while (curr != NULL){
		printf ("Value: %d \n", curr->value);
		curr = curr->next;
	}
}

int main (){
	
	enqueue(1);
	enqueue(2);
	enqueue(3);
	
	view();
	
	return 0;
}
