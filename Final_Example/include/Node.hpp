/**
* @file 		Node.hpp
* @description 	Txt dosyasında verilen kişi bilgilerini, kişinin yaşına göre avl ağacına ekleyen ve ödev algoritmasında istenen, düğüm hareketlerine göre yığıt oluşturan program.
* @course 		1. öğretim B grubu
* @assignment 	2. Ödev
* @date 		01.09.2020
* @author		TARIK TOSYA
*/

#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <string>
#include <sstream>
#include "Stack.hpp"
using namespace std;
class Node {
	public:
	string isim;
	Node* left; 
	Node* right; 
	string kilo;
	string age;
	int yas;
	int height;
	int oldheight;
	Stack *stck=new Stack();
	Node(const string& , string , string , int , Node *lf, Node *rg);		
};


#endif