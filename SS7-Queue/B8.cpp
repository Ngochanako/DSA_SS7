#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
	char data[50];
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
void enqueue(Queue* q,char s[],int p){
	Node* newNode=(Node*)malloc(sizeof(Node));
	strcpy(newNode->data,s);
	newNode->priority=p;
	newNode->next=NULL;
	//hang doi rong
	if(isEmpty(q)){
		q->head=newNode;
		return;
	}
	//tim phan tu truoc priority
	Node* tmp=q->head;
	if(p<=tmp->priority){
		newNode->next=tmp;
		q->head=newNode;
		return;
	}
	while(tmp->next!=NULL&&tmp->next->priority<p){
		tmp=tmp->next;
	}
	newNode->next=tmp->next;
	tmp->next=newNode;
}
//lay phan tu dau hang doi
char* dequeue(Queue* q){
	if(isEmpty(q)){
		return "";
	}
	Node* tmp=q->head;
	static char res[50];
	strcpy(res,q->head->data);
	q->head=tmp->next;
	free(tmp);
	return res;
}
//xem phan tu dau hang doi
char* peek(Queue* q){
	return q->head->data;
}
//in hang doi
void print(Queue *q){
	Node* tmp=q->head;
	while(tmp!=NULL){
		printf("%s ",tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
}
int main(){
	Queue q;
	initialize(&q);
	enqueue(&q,"Su kien A",1);
	print(&q);
	enqueue(&q,"Su kien B",2);
	print(&q);
	printf("Lay ra phan tu :%s\n",dequeue(&q));
	print(&q);
	enqueue(&q,"Su kien C",3);
	print(&q);
	printf("Lay ra phan tu :%s\n",dequeue(&q));
	print(&q);
}
