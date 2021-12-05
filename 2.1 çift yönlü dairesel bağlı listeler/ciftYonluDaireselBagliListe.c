#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct n{
	int x;
	struct n* next;
	struct n* prev;
}node;
node* yazdir(node*root){
	if(root!=NULL){
		node*iter=root;
		do{
		printf("%d ",iter->x);
		iter=iter->next;
		}while(iter!=root);	
	}
	
	printf("\n");
}
node* olustur(){
	node* root;
	root=(node*)malloc(sizeof(node));
	root->next=NULL;
	root->prev=NULL;
}
node* ekle(node*root,int data){
	if(root==NULL){
		root=olustur();
		root->x=data;
		root->next=root;
		root->prev=root;
		return root;
	}
	node* iter=root;
	while(iter->next!=root){
		iter=iter->next;
	}
	iter->next=olustur();
	iter->next->prev=iter;
	iter->next->x=data;
	iter->next->next=root;
	root->prev=iter->next;

	return root;
}
node* basaEkle(node*root,int data){
	if(root==NULL){
		return ekle(root,data);
	}
	node *iter=olustur();
	iter->x=data;
	iter->next=root;
	iter->prev=root->prev;
	root->prev->next=iter;
	root->prev=iter;
	root=iter;
	return root;
}
node* arayaEkle(node*root,int index,int data){
	if(root==NULL||index==0){
		return basaEkle(root,data);
	}
	node* iter=root;
	int count=1;
	while(iter->next!=root){
		if(count>=index){
			break;
		}
		count++;
		iter=iter->next;
	}
	node* iter2=iter->next;
	iter->next=olustur();
	iter->next->prev=iter;
	iter=iter->next;
	iter->x=data;
	iter->next=iter2;
	iter2->prev=iter;
	return root;
}
int arama(node*root,int data){
	int result=-1;
	bool control=true;
	if(root!=NULL){
		if(root->x==data){
			return 0;
		}
	}
	node*iter=root;
	while(iter!=root){
		result++;
		if(iter->x==data){
			control=false;
			break;
		}
		iter=iter->next;
	}
	
	if(control){
		result=-1;
	}

	return result;
}
node* silme(node* root){
	if(root!=NULL){
		if(root->next==root){
			free(root);
			root=NULL;
			return root;
		}
		node *iter=root;
		while(iter->next!=root){
			iter=iter->next;
		}
		iter=iter->prev;
		free(iter->next);
		iter->next=root;
		root->prev=iter;
	}
	return root;
}
node* bastanSilme(node*root){
	if(root!=NULL){
		if(root->next==root){
			free(root);
			root=NULL;
			return root;
		}
		node* iter=root;
		root=root->next;
		root->prev=iter->prev;
		iter->prev->next=root;
		free(iter);
	}
	return root;
}
node* siraliEkle(node* root,int data){

	if(root==NULL||data<=root->x){
		return basaEkle(root,data);
	}
	node * iter=root;
	int sayac=0;
	do{
		if(data<=iter->x){
			break;
		}
		sayac++;
		iter=iter->next;
	}while(iter!=root);
	if(iter==root){
		return ekle(root,data);
	}
	return arayaEkle(root,sayac,data);
}
int main(){
	node * root=NULL;
	root=ekle(root,10);
	root=ekle(root,20);
	root=ekle(root,30);
	root=basaEkle(root,40);
	root=arayaEkle(root,2,50);
	
	yazdir(root);
	printf("arama sonucu:%d\n",arama(root,40));
	root=silme(root);
	root=bastanSilme(root);
	root=siraliEkle(root,90);
	root=siraliEkle(root,10);
	root=siraliEkle(root,50);
	yazdir(root);
	return 0;
}


