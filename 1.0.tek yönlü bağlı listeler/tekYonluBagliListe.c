#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct n{
	int x;
	struct n* next;
}node;
node* olustur(){
	node* temp=(node*)malloc(sizeof(node));
	temp->next=NULL;
	return temp;
}
void yazdir(node*root){
	node *iter=root;
	while(iter!=NULL){
		printf("%d ",iter->x);
		iter=iter->next;
	}
	printf("\n");
}
node* ekle(node*root,int data){
	if(root==NULL){
		root=olustur();
		root->x=data;
		return root;
	}
	
	node * iter=root;
	while(iter->next!=NULL){
		iter=iter->next;
	}
	iter->next=olustur();
	iter=iter->next;
	iter->x=data;
	return root;
}
node* basaEkle(node*root,int data){
	if(root==NULL){
		return ekle(root,data);
	}
	node *iter=NULL;
	iter=ekle(iter,data);
	iter->next=root;
	root=iter;
	return root;
}
node* arayaEkle(node* root,int data, int index){
	if(root==NULL||index==0){
		return basaEkle(root,data);
	}
	int i;
	
	node *iter=root;

	for(i=1;i<index;i++){

		if(iter->next==NULL){

			break;
		}
		iter=iter->next;
	}

	node* iter2=iter->next;
	iter->next=olustur();
	iter=iter->next;
	iter->x=data;
	iter->next=iter2;
	return root;
}
int arama(node*root,int data){
	int sonuc=0;
	bool bulunmadi=true;
	while(root!=NULL){
		if(root->x==data){
			bulunmadi=false;
			break;
		}
		sonuc++;
		root=root->next;
	}
	if(bulunmadi){
		sonuc=-1;
	}
	return sonuc;
}
node* silme(node*root,int data){
	if(arama(root,data)!=-1){
		int index=arama(root,data);
		if(index==0){
			node*iter=root->next;
			free(root);
			root=iter;
			return root;
		}
		int i;
		node*iter=root;
		for(i=0;i<index-1;i++){
			iter=iter->next;
		}
		node*iter2=iter->next->next;
		free(iter->next);
		iter->next=iter2;
		return root;
	}
	return root;
}
node* basdanSil(node*root){
	return silme(root,root->x);
}
node* sondanSil(node*root){
	node*iter=root;
	while(iter->next!=NULL){
		iter=iter->next;
	}
	return silme(root,iter->x);
}
int main(){
	node * root=NULL;
	root=basaEkle(root,10);
	root=basaEkle(root,40);
	root=basaEkle(root,30);
	root=arayaEkle(root,80,1);
	yazdir(root);
	root=silme(root,40);
	yazdir(root);
	return 0;
}



/*
fonksiyonlar

*/
