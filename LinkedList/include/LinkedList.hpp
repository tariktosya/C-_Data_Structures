#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int ogrenci_sirasi;
	int ogrenci_puani;
	int ogrenci_no;
	struct n* next;
}node;	

void bastir(node*r){
	while(r!=NULL){
		printf("ogrencinin sirasi : %d \nogrenci puani : %d \nogrencinin numarasi : %d \n", r->ogrenci_sirasi, r->ogrenci_puani, r->ogrenci_no );
		r = r->next;
	}
	printf("\n");
	
}	
void yazdir(node*r, int ogrenci_puani){
	while(r!=NULL && r->ogrenci_puani > ogrenci_puani){
		printf("ogrencinin sirasi : %d \nogrenci puani : %d \nogrencinin numarasi : %d \n", r->ogrenci_sirasi, r->ogrenci_puani, r->ogrenci_no );
		r = r->next;
	}
	printf("\n");
}
node* ekle(node *r, int ogrenci_sirasi, int ogrenci_puani, int ogrenci_no){
	if(r==NULL){
		r=(node*) malloc (sizeof(node));
		r->next = NULL;
		r->ogrenci_sirasi = ogrenci_sirasi;
		r->ogrenci_puani = ogrenci_puani;
		r->ogrenci_no = ogrenci_no;
		return r;
	}
	if(r->ogrenci_puani < ogrenci_puani){
		node * temp = (node*) malloc (sizeof(node));
		temp->ogrenci_sirasi = ogrenci_sirasi;
		temp->ogrenci_puani = ogrenci_puani;
		temp->ogrenci_no = ogrenci_no;
		temp->next = r;
		return temp;
	 } 	
	node * iter = r;
	while(iter->next !=NULL && iter->next->ogrenci_puani > ogrenci_puani ){
		iter= iter-> next;		
	}

		node *temp = (node*) malloc (sizeof(node));
		temp->next = iter->next;
		iter->next = temp;
		temp->ogrenci_sirasi = ogrenci_sirasi;
		temp->ogrenci_puani = ogrenci_puani;
		temp->ogrenci_no = ogrenci_no;
		return r;
			
}
node *sil(node *r,int ogrenci_no){
	node *temp;
	node *iter = r;
	if(r->ogrenci_no == ogrenci_no){
		temp = r;
		r = r->next;
		free (temp);
		return r;
	}
	while (iter->next !=NULL && iter->next->ogrenci_no != ogrenci_no){
			iter = iter->next;		
	}
	if(iter->next == NULL){
		printf("deger bulunamadi");
		return r;
	}
	temp = iter->next;
	iter->next =iter->next->next;
	free (temp);
	return r;
}


int main()
{
	node * root;
	root = NULL;
	root = ekle(root,0,40,18060311);	
	root = ekle(root,1,50,20060045);
	root = ekle(root,2,75,19061091);
	root = ekle(root,3,90,20060134);
	root = ekle(root,4,40,20060678);
	root = ekle(root,5,75,18061086);
	root = ekle(root,6,50,20060032);
	root = ekle(root,7,60,20060067);
	root = ekle(root,8,60,19060456);
	root = ekle(root,9,75,18060245);
	root = ekle(root,10,40,20060110);
	root = ekle(root,11,90,20060234);
	root = ekle(root,12,60,20060141);
	root = ekle(root,13,50,20060011);
	root = ekle(root,14,60,20060012);
	bastir(root);
	root = sil(root,18061086);
	bastir(root);
	yazdir(root,80);
	yazdir(root,50);
	yazdir(root,30);
	yazdir(root,40);
	yazdir(root,100);
	yazdir(root,70);	
}

