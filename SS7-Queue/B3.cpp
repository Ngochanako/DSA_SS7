#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

typedef struct Queue{
	int data[SIZE];
	int front,rear;
}Queue;
//khoi tao hang doi
void initializeQueue(Queue* q){
	q->front=-1;
	q->rear=-1;
}
//kiem tra hang doi co rong khong
bool isEmpty(Queue* q){
	return q->front==-1;
}
//kiem tra hang doi co day khong
bool isFull(Queue* q){
	return q->rear==SIZE-1;
}
//them phan tu vao hang doi
void enqueue(Queue* q,int n){
	if(isFull(q)){
		return;
	}
	if(isEmpty(q)){
		q->front=0;
	}
	q->data[++q->rear]=n;
}
//lay phan tu ra khoi hang doi
int dequeue(Queue* q){
	int t= q->data[q->front];
	if(q->front==q->rear){
		q->front=q->rear=-1;
	}else{
		q->front++;
	}
	return t;
}
//xem phan tu dau tien hang doi
int peek(Queue* q){
	if(isEmpty(q)){
		return -1;
	}
	return q->data[q->front];
}
//hien thi hang doi
void print(Queue* q){
	for(int i=q->front;i<=q->rear;i++){
		printf("%d ",q->data[i]);
	}
}

int main(){
	int n,x;
	printf("Nhap so phan tu can them\n");
	scanf("%d",&n);
	Queue q;
	initializeQueue(&q);
	for(int i=0;i<n;i++){
		if(isEmpty(&q)){
			printf("Hang doi dang rong\n");
		}else{
			printf("Hang doi khong rong\n");
		}
		scanf("%d",&x);	
		enqueue(&q,x);
		print(&q);
	}
}
