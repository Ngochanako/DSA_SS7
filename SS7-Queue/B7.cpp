#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	int priority;
	struct Node* next;
}Node;
typedef struct Queue{
	Node* head;
}Queue;
//khoi tao hang doi
void initialize(Queue* q){
	q->head=NULL;
}
//kiem tra hang doi co rong khong
bool isEmpty(Queue* q){
	return q->head==NULL;
}
//them phan tu vao hang doi
void enqueue(Queue* q,int n,int p){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=n;
	newNode->priority=p;
	newNode->next=NULL;
	//hang doi rong
	if(isEmpty(q)){
		q->head=newNode;
		return;
	}
	//tim phan tu truoc priority
	Node* tmp=q->head;
	if(tmp->priority<=p){
		newNode->next=tmp;
		q->head=newNode;
		return;
	}
	while(tmp->next!=NULL&&tmp->next->priority>=p){
		tmp=tmp->next;
	}
	newNode->next=tmp->next;
	tmp->next=newNode;
}
//lay phan tu dau hang doi
int dequeue(Queue* q){
	if(isEmpty(q)){
		return -1;
	}
	Node* tmp=q->head;
	int res=q->head->data;
	q->head=tmp->next;
	free(tmp);
	return res;
}
//xem phan tu dau hang doi
int peek(Queue* q){
	return q->head->data;
}
//in hang doi
void print(Queue *q){
	Node* tmp=q->head;
	while(tmp!=NULL){
		printf("%d ",tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
}
int main(){
	Queue q;
	initialize(&q);
	enqueue(&q,10,1);
	print(&q);
	enqueue(&q,20,2);
	print(&q);
	enqueue(&q,30,1);
	print(&q);
	printf("Lay ra phan tu :%d\n",dequeue(&q));
	print(&q);
	enqueue(&q,40,3);
	print(&q);
}
