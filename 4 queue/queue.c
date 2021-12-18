#include<stdio.h>
#include<stdlib.h>

typedef struct n{
	int x;
	struct n* next;
}node;
node* queue=NULL;
node* create(){
	node*root=(node*)malloc(sizeof(node));
	root->next=NULL;
	return root;
}
void enqueue(int data){
	node* iter=create();
	iter->x=data;
	iter->next=queue;
	queue=iter;
}
void printq(){
	node*iter=queue;
	while(iter!=NULL){
		printf("%d ",iter->x);
		iter=iter->next;
	}
	printf("\n");
}
int dequeue(){
	if(queue==NULL){
		return -1;
	}
	if(queue->next==NULL){
		int data=queue->x;
		free(queue);
		queue=NULL;
		return data;
	}

	node* iter=queue;
	while(iter->next->next!=NULL){
		iter=iter->next;
			
	}
		
	int data=iter->next->x;
	free(iter->next);
	iter->next=NULL;
	return data;
}
int rear(){
	return queue->x;
}
int front(){
	node* iter=queue;
	while(iter->next!=NULL){
		iter=iter->next;
	}
	return iter->x;
}
int main(){
	enqueue(30);
	enqueue(70);
	enqueue(90);
	printq();
	printf("rear():%d\n",rear());
	printf("front():%d\n",front());
	printf("dequeue():%d\n",dequeue());
	printf("rear():%d\n",rear());
	printf("front():%d\n",front());
	printf("dequeue():%d\n",dequeue());
	printf("rear():%d\n",rear());
	printf("front():%d\n",front());
	printf("dequeue():%d\n",dequeue());
	printf("dequeue():%d\n",dequeue());
	
	return 0;
}


