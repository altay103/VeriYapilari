#include<stdio.h>
#include<stdlib.h>


typedef struct n{
	int x;
	struct n* next;
}node;
node* stack=NULL;
node* create(){
	node*newOne=(node*)malloc(sizeof(node));
	newOne->next=NULL;
	return newOne;
}
void push(int data){
	if(stack==NULL){
		stack=create();
		stack->x=data;
	}else{
		node *newOne=create();
		newOne->x=data;
		newOne->next=stack;
		stack=newOne;	
	}
}
void prints(){
	node* iter=stack;
	while(iter!=NULL){
		printf("%d ",iter->x);
		iter=iter->next;
	}
	printf("\n");
}
int top(){
	return stack->x;
}
int pop(){
	if(stack==NULL){
		return -1;
	}
	int data=stack->x;
	node*iter=stack;
	stack=stack->next;
	free(iter);
	return data;
}
int main(){
	stack=NULL;
	push(90);
	push(50);
	push(80);
	prints();
	printf("pop():%d\n",pop());
	printf("pop():%d\n",pop());
	printf("pop():%d\n",pop());
	prints();
	printf("pop():%d\n",pop());
	return 0;
}

