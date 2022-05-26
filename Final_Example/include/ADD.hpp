/**
* @file 		ADD.hpp
* @description 	Txt dosyasında verilen kişi bilgilerini, kişinin yaşına göre avl ağacına ekleyen ve ödev algoritmasında istenen, düğüm hareketlerine göre yığıt oluşturan program.
* @course 		1. öğretim B grubu
* @assignment 	2. Ödev
* @date 		01.09.2020
* @author		TARIK TOSYA
*/

#ifndef ADD_HPP
#define ADD_HPP
#include "Node.hpp"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class ADD{
	private:
		Node *root; 
		Node* SearchAndAdd(Node *subNode,const string isim,string age,string kilo,int yas);
		Node* SwapWithLeftChild(Node *subNode);
		Node* SwapWithRightChild(Node *subNode);
		int Height(Node *subNode);
		void AddStk(Node *subNode);
		void postOrder1(Node *subNode);
		void RemoveNode(Node *&subNode);
	public:
		ADD();
		bool isEmpty()const;
		void add(const string& isim,string age,string kilo,int yas);
		int Height();
		void AddStk();
		void postOrder();
		void clear();
		~ADD();
};
#endif