/**
* @file 			algoritma.cpp
* @description 		"Sayilar.txt" Dosyası içerisindeki verileri satır satır okuyarak her satırdaki sayıları, verilen algoritmaya uygun sıralayarak "CircularDoublyLinkedList" içerisine kayıt etmektedir. Her satırın sonuna gelindiğinde listeyi bir diziye kaydeder ve günün sonunda bu sayıların ASCII karşılılarını ekrana yazdırır.
* @course 			1. Öğretim B Grubu
* @assignment		1. Ödev
* @date 			05.08.2020
* @outhor 			TARIK TOSYA
*/
#include "algoritma.hpp"
#include "Node.hpp"
#include <iostream>
using namespace std;

 Node* algoritma::FindPreviousNode(int index){
	Node* prev = head;
	int i=1;
	for(Node* itr=head;i!=index;itr=itr->next,i++){
		prev = prev->next;
	}
	return prev;
	}
	algoritma::algoritma(){
		head = NULL;
		size=0;
		obb=0;
		enbuyuk=0;
		deger=0;
	}
		
	int algoritma::Obeb(int sayi1){
		Node* sayi2=head;
		for(int i=0;i<size;i++){
			if(sayi1>sayi2->data) {
				obb = sayi1;
			} 
			else {
				obb = sayi2->data;
			}
			deger=sayi2->data;
			for(obb; obb>0; obb--) {
				if( (sayi1%obb==0) && (sayi2->data%obb==0) ) {
					if(obb>=enbuyuk){
						enbuyuk=obb;
						return deger;
						break;
					}
					if(i==size-1){
						return sayi2->data;
						break;
					}	
				}
			}
				sayi2=sayi2->next;
		}
	}
	
	int algoritma::indexOf(const int& item)const{
		int index=0;
		for(Node* itr=head;index<size;itr=itr->next){
			if(itr->data == item) return index;
				index++;
			}
		return -1;
	}
	int algoritma::dataOf(int indx)const{
		Node* itr = head;
		if(indx==0)
			return itr->data;
		if(indx>0){
			for(int i=1;i<=indx;i++){
			itr=itr->next;
			}
		return itr->data;
		}
	}
	void algoritma::add(const int& item){
		insert(size,item);
	}
	void algoritma::insert(int index,const int& item){
		if(index == 0){
			if(size == 0){
				head = new Node(item,NULL,NULL);
				head->next = head->prev = head;
			}
			else{
				head = new Node(item,head,head->prev);
				head->next->prev = head;
				head->prev->next = head;
			}
		}
		else{
			Node* prv = FindPreviousNode(index);
			prv->next = new Node(item,prv->next,prv);
			prv->next->next->prev = prv->next;
		}
		size++;
	}
	bool algoritma::isEmpty()const{
			return size == 0;
	}
	void algoritma::removeAt(int index){
		Node* del;
		if(index == 0){
			del = head;
			if(size==1)
				head = head->next = head->prev =NULL;
			else{
				head=head->next;
				head->prev = del->prev;
				del->prev->next = head;
			}
		}
		size--;
		delete del;
	}
	void algoritma::clear(){
		while(!isEmpty())
			removeAt(0);
	}
	ostream& operator<<(ostream& screen,const algoritma& right){
		int index=0;
		for(Node* itr=right.head;index<right.size;itr=itr->next,index++){
			screen<<itr->data<<" ";
		}
		screen<<endl;
		return screen;
	}
	algoritma::~algoritma(){
		clear();
	}