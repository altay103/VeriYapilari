#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct n{
	int x;
	struct n* next;
	struct n* prev;
}node;
node* yazdir(node*root){
	while(root!=NULL){
		printf("%d ",root->x);
		root=root->next;
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
		return root;
	}
	node* iter=root;
	while(iter->next!=NULL){
		iter=iter->next;
	}
	iter->next=olustur();
	iter->next->prev=iter;
	iter->next->x=data;
	return root;
}
node* tersYazdir(node*root){
	if(root!=NULL){
		while(root->next!=NULL){
		root=root->next;
		}
		while(root!=NULL){
			printf("%d ",root->x);
			root=root->prev;
		}
		
	}
	printf("\n");
}
node* basaEkle(node*root,int data){
	if(root==NULL){
		return ekle(root,data);
	}
	node *iter=olustur();
	iter->x=data;
	iter->next=root;
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
	while(iter->next!=NULL){
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
	
	while(root!=NULL){
		result++;
		if(root->x==data){
			control=false;
			break;
		}
		root=root->next;
	}
	
	if(control){
		result=-1;
	}

	return result;
}
node* silme(node* root){
	if(root!=NULL){
		if(root->next==NULL){
			free(root);
			root=NULL;
			return root;
		}
		node *iter=root;
		while(iter->next!=NULL){
			iter=iter->next;
		}
		iter->prev->next=NULL;
		free(iter);
	}
	return root;
}
node* bastanSilme(node*root){
	if(root!=NULL){
		if(root->next==NULL){
			free(root);
			root=NULL;
			return root;
		}
		node* iter=root;
		root=root->next;
		root->prev=NULL;
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
	while(iter!=NULL){
		if(data<=iter->x){
			break;
		}
		sayac++;
		iter=iter->next;
	}
	if(iter==NULL){
		return ekle(root,data);
	}
	return arayaEkle(root,sayac,data);
}
int main(){
	node * root=NULL;
	root=siraliEkle(root,90);
	root=siraliEkle(root,10);
	root=siraliEkle(root,100);
	root=siraliEkle(root,80);
	root=siraliEkle(root,50);
	root=siraliEkle(root,10);
	
	yazdir(root);

	return 0;
}


