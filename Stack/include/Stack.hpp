#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
using namespace std;

template <typename Object>
class Stack{
	private:
		Object *items;
		int topOfStack;//en son eleman hangi indexte
		int length;
		int capacity;
		
		void reserve(int newCapacity){//yer açma 
			Object* tmp = new Object[newCapacity];
			for(int i=0;i<length;i++){//eleman kopyaladık
				tmp[i] = items[i];
			}
			delete [] items; //eski diziyi sildik
			items = tmp;//items yeni diziyi gösteriyor
			capacity = newCapacity;
		}
	public:
		Stack(){
			capacity = 100;
			items = new Object[100];
			topOfStack = -1;//burada eleman yok demektir
			length = 0;
		}
		bool isEmpty(){
			return topOfStack==-1;
		}
		void push(const Object& item){//ekleme
			if(length==capacity) 
			reserve(2*capacity);//dolu olan yerde yer açma
			topOfStack+=1;
			items[topOfStack] = item;
			length+=1;
		}
		const Object& top()const{//çıkmak üzere olan elemanı gösterir. boş ise hata verir
			return items[topOfStack];
		}
		void pop(){//eleman çıkarır. Boşken hata verir
			topOfStack-=1;
			length-=1;
		}
		void makeEmpty(){//yığıtı temizler
			topOfStack = -1;
			length = 0;
		}
		~Stack(){
			delete [] items;
		}
};
#endif