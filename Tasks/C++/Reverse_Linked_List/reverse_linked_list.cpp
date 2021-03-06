#include "pch.h"
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void push(Node** head_ref, int new_data) {
	Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void printList(Node *n) {
	while (n != NULL) {
		cout << n->data;
		n = n->next;
	}
}

static void reverse(Node** header_ref) {
	 Node* prev = NULL;
     Node* current = *header_ref;
	 Node* next;
	 while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	 }
	 *header_ref = prev;
}

int main() {
	Node* a = new Node;
	Node* b = new Node;
	Node* c = new Node;
	Node* d = new Node;
	Node* e = new Node;

	a->data = 222;
	a->next = b;
	b->data = 333;
	b->next = c;
	c->data = 444;
	c->next = d;
	d->data = 666;
	d->next = e;
	e->data = 777;
	e->next = NULL;

	//push(&a, 1000);

	//reverse(&a);
	printList(a);

	system("PAUSE");
}

