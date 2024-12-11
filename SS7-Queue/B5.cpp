#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

typedef struct Item{
	char data[50];
	int priority;
}Item;
typedef struct Queue{
    Item list[SIZE];
	int size;
}Queue;
//khoi tao hang doi
void initializeQueue(Queue* q){
	q->size=0;
}
//kiem tra hang doi co rong khong
bool isEmpty(Queue* q){
	return q->size==0;
}
//kiem tra hang doi co day khong
bool isFull(Queue* q){
	return q->size==SIZE;
}
//them phan tu vao hang doi uu tien
void enqueue(Queue* q,char s[],int p){
	if(isFull(q)){
		return;
	}
	strcpy(q->list[q->size].data,s);
	q->list[q->size].priority=p;
	q->size++;
	for(int i=q->size-1;i>0;i--){
		if(q->list[i].priority<q->list[i-1].priority){
			Item tmp=q->list[i];
			q->list[i]=q->list[i-1];
			q->list[i-1]=tmp;
		}else{
			break;
		}
	}
}
//lay phan tu ra khoi hang doi
char* dequeue(Queue* q){
	char s[50]="";
	strcpy(s, q->list[0].data);
	q->size--;
	for(int i=0;i<q->size-1;i++){
		q->list[i]=q->list[i+1];
	}
	return s;
}
//xem phan tu dau tien hang doi
char* peek(Queue* q){
	if(isEmpty(q)){
		return "";
	}
	return q->list[0].data;
}
//hien thi hang doi
void print(Queue* q){
	for(int i=0;i<q->size;i++){
		printf("%s ",q->list[i].data);
	}
}

int main(){
	Queue q;
	initializeQueue(&q);
	enqueue(&q,"Task A",2);
	enqueue(&q,"Task B",1);
	enqueue(&q,"Task C",3);
	printf("Phan tu uu tien cao nhat:%s\n",peek(&q));
	printf("Lay ra phan tu:%s\n",dequeue(&q));
	printf("Phan tu uu tien cao nhat:%s\n",peek(&q));
	printf("Lay ra phan tu:%s\n",dequeue(&q));
}
