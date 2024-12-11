#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

typedef struct Node{
	int data;
	struct Node* next;
}Node;
typedef struct Queue{
    Node* front;
    Node* rear;
    int size;
}Queue;
//khoi tao hang doi
void initializeQueue(Queue* q){
	q->front=NULL;
	q->rear=NULL;
	q->size=0;
}
//kiem tra hang doi co rong khong
bool isEmpty(Queue* q){
	return q->size==0;
}
//them phan tu vao dau hang doi
void addFront(Queue* q,int n){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=n;
	newNode->next=q->front;
	if(isEmpty(q)){
		q->rear=newNode;
	}
	q->front=newNode;
	q->size++;
}
//them phan tu vao cuoi hang doi
void addRear(Queue* q,int n){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=n;
	newNode->next=NULL;
	if(isEmpty(q)){
		q->front=newNode;
		q->rear=newNode;
	}else{
		q->rear->next=newNode;
	    q->rear=newNode;
	}
	q->size++;
}
//lay phan tu ra dau hang doi
int removeFront(Queue* q){
	if(isEmpty(q)){
		return -1;
	}
	Node* tmp=q->front;
	int t= q->front->data;
	q->front=q->front->next;
	if(q->front==NULL){
		q->rear=NULL;
	}
	q->size--;
	free(tmp);
	return t;
}
//lay phan tu ra cuoi hang doi
int removeRear(Queue* q){
	if(isEmpty(q)){
		return -1;
	}
	Node* tmp=q->rear;
	int t= q->rear->data;
	Node* temp=q->front;
	while(temp->next!=q->rear){
		temp=temp->next;
	}
	temp->next=NULL;
	q->rear=tmp;
	q->size--;
	if(q->size==0){
		q->front=NULL;
	}
	free(tmp);
	return t;
}
//xem phan tu dau tien hang doi
int peek(Queue* q){
	if(isEmpty(q)){
		return -1;
	}
	return q->front->data;
}
//hien thi hang doi
void print(Queue* q){
	Node* tmp=q->front;
	while(tmp!=NULL){
		printf("%d ",tmp->data);
		tmp=tmp->next;
	}
}

int main(){
	Queue q;
	initializeQueue(&q);
    addFront(&q,10);
    addRear(&q,20);
    addFront(&q,5);
    print(&q);
    printf("Lay ra phan tu dau:%d\n",removeFront(&q));
     print(&q);
    printf("Lay ra phan tu cuoi:%d\n",removeRear(&q));
     print(&q);
}
