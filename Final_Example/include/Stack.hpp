/**
* @file 		Stack.hpp
* @description	Txt dosyasında verilen kişi bilgilerini, kişinin yaşına göre avl ağacına ekleyen ve ödev algoritmasında istenen, düğüm hareketlerine göre yığıt oluşturan program.
* @course 		1. öğretim B grubu
* @assignment 	2. Ödev
* @date 		01.09.2020
* @author 		TARIK TOSYA
*/
#ifndef STACK_HPP
#define STACK_HPP
#include <string>
#include <iostream>
using namespace std;

class Stack{
	private:
		string *item;
		int topStack;
		int length;
		int capacity;
		void reserve(int newCapacity);
	public:
		Stack();
		bool isEmpty();
		void push(const string& itemm);
		const string& top()const;
		void pop();
		void makeEmpty();
		~Stack();
};

#endif