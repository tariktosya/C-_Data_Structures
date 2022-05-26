#ifndef ALGORITMA_HPP
#define ALGORITMA_HPP
#include "Node.hpp"
#include <iostream>
using namespace std;
class algoritma{
	private:
		Node* head;
		int size;
		int obb;
		int enbuyuk;
		int deger;
	public:
		Node* FindPreviousNode(int index);
		algoritma();
		void insert(int index,const int& item);
		int Obeb(int sayi1);
		void removeAt(int index);
		int indexOf(const int& item)const;
		int dataOf(int indx)const;
		void add(const int& item);
		bool isEmpty()const;
		void clear();
		friend ostream& operator<<(ostream& ,const algoritma& );
		~algoritma();
};

#endif
