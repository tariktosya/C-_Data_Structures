/**
* @file 		Node.cpp
* @description 	Txt dosyasında verilen kişi bilgilerini, kişinin yaşına göre avl ağacına ekleyen ve ödev algoritmasında istenen, düğüm hareketlerine göre yığıt oluşturan program.
* @course 		1. öğretim B grubu
* @assignment 	2. Ödev
* @date 		01.09.2020
* @author		TARIK TOSYA
*/

#include "Node.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include "Stack.hpp"
using namespace std;
	Node::Node(const string& dt, string ag, string kl, int ys, Node *lf= NULL, Node *rg= NULL) 
	{
		oldheight=0;
		yas=ys;
		isim = dt;
		age=ag;
		kilo=kl;
		left = lf;
		right = rg;
		height = 0;
	}		
