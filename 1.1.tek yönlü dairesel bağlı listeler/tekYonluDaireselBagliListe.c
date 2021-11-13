#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

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
		if(iter==root){
			break;
		}
	}
	printf("\n");
}
node* ekle(node*root,int data){
	if(root==NULL){
		root=olustur();
		root->next=root;
		root->x=data;
		return root;
	}
	node * iter=root;
	while(iter->next!=root){
		iter=iter->next;
	}
	iter->next=olustur();
	iter=iter->next;
	iter->x=data;
	iter->next=root;
	return root;
}
node* basaEkle(node*root,int data){
	if(root==NULL){
		return ekle(root,data);
	}
	node *iter=NULL;
	iter=ekle(iter,data);
	iter->next=root;
    
	node* iter2=iter->next;
	while(iter2->next!=root){
		iter2=iter2->next;
	}
	iter2->next=iter;
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

		if(iter->next==root){

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
	if(root==NULL){
		return -1;
	}
	int sonuc=0;
	bool bulunmadi=true;
	node*iter=root;
	
	do{
		if(iter->x==data){
			bulunmadi=false;
			break;
		}	
		sonuc++;	
		iter=iter->next;
	}while(iter!=root);
	
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
			int sona=uzunluk(root)-1;
			node*iter2=root;
			int i;
			for(i=0;i<sona;i++){
				iter2=iter2->next;
			}
			iter2->next=iter;
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
	node*root=NULL;
	root=ekle(root,10);
	root=basaEkle(root,20);
	root=arayaEkle(root,30,1);
	yazdir(root);
	return 0;
}

