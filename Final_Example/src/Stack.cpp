/**
* @file 		Stack.cpp
* @description 	Txt dosyasında verilen kişi bilgilerini, kişinin yaşına göre avl ağacına ekleyen ve ödev algoritmasında istenen, düğüm hareketlerine göre yığıt oluşturan program.
* @course 		1. öğretim B grubu
* @assignment 	2. Ödev
* @date 		01.09.2020
* @author		TARIK TOSYA
*/

#include <iostream>
#include <string>
#include <sstream>
#include "Stack.hpp"
using namespace std;
		void Stack::reserve(int newCapacity){
			string* tmp = new string[newCapacity];
			for(int i=0;i<length;i++){
				tmp[i] = item[i];
			}
			delete [] item; 
			item = tmp;
			capacity = newCapacity;
		}
		Stack::Stack(){
			capacity = 100;
			item = new string[100];
			topStack = -1;
			length = 0;
		}
		bool Stack::isEmpty(){
			return topStack==-1;
		}
		void Stack::push(const string& itemm){
			if(length==capacity) 
			reserve(2*capacity);
			topStack+=1;
			item[topStack] = itemm;
			length+=1;
		}
		const string& Stack::top()const{
			return item[topStack];
		}
		void Stack::pop(){
			topStack-=1;
			length-=1;
		}
		void Stack::makeEmpty(){
			topStack = -1;
			length = 0;
		}
		Stack::~Stack(){
			delete [] item;
		}
	
