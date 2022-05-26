#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

template <typename Object>//Şablon yapı
struct Node{//DÜĞÜM DOSYAMIZ
	Object data;
	Node<Object> *next;
	
	Node(const Object& data,Node<Object> *next=NULL){
		this->data = data;
		this->next = next;//Düğümü oluşturduk.
	}
};

//Bu sınıf aynı kaldı. Tek yönlü bağıla göre.
#endif
