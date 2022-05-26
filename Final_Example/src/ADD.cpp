/**
* @file 		ADD.cpp
* @description 	Txt dosyasında verilen kişi bilgilerini, kişinin yaşına göre avl ağacına ekleyen ve ödev algoritmasında istenen, düğüm hareketlerine göre yığıt oluşturan program.
* @course 		1. öğretim B grubu
* @assignment 	2. Ödev
* @date 		01.09.2020
* @author		TARIK TOSYA
*/

#include "ADD.hpp"
#include "Node.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include "Stack.hpp"
using namespace std;

		Node ADD::*root; 
		Node* ADD::SearchAndAdd(Node *subNode,const string isim,string age,string kilo,int yas)
		{
			if(subNode == NULL)
			{
				subNode = new Node(isim,age,kilo,yas,NULL,NULL);
				subNode->stck->push("O");
				subNode->oldheight=Height(subNode);	
			}
			else if(yas <= subNode->yas)
			{
				subNode->left = SearchAndAdd(subNode->left,isim,age,kilo,yas);
				
				if(Height(subNode->left) == Height(subNode->right)+2)
				{
					if(yas < subNode->left->yas) 
					{
						subNode = SwapWithLeftChild(subNode); 
					}
					else
					{
						
						subNode->left = SwapWithRightChild(subNode->left);
						subNode = SwapWithLeftChild(subNode);
					}
				}		
			}
			else if(yas > subNode->yas)
			{
				subNode->right = SearchAndAdd(subNode->right,isim,age,kilo,yas);
						
				if(Height(subNode->right) == Height(subNode->left)+2)
				{
					if(yas > subNode->right->yas) 
					{
						subNode = SwapWithRightChild(subNode); 
					}
					else
					{
						subNode->right = SwapWithLeftChild(subNode->right);
						subNode = SwapWithRightChild(subNode);	
					}
				}	
			}
			subNode->height = Height(subNode);
			return subNode;
		}
		Node* ADD::SwapWithLeftChild(Node *subNode)
		{
			Node *tmp = subNode->left;
			subNode->left = tmp->right;
			tmp->right = subNode;
			subNode->height = Height(subNode);
			tmp->height = max(Height(tmp->left),subNode->height)+1;
			return tmp;
		}
		Node* ADD::SwapWithRightChild(Node *subNode)
		{
			Node *tmp = subNode->right;
			subNode->right = tmp->left;
			tmp->left = subNode;
			subNode->oldheight=subNode->height;
			subNode->height = Height(subNode);
			tmp->height = max(Height(tmp->right),subNode->height)+1;
			return tmp;
		}
		int ADD::Height(Node *subNode)
		{	
			if(subNode == NULL) {
				return -1;
			}
			return 1+max(Height(subNode->left),Height(subNode->right));
		}
		void ADD::AddStk(Node *subNode){
			if(subNode != NULL){
				AddStk(subNode->left);
				AddStk(subNode->right);
				if(Height(subNode) < subNode->oldheight){
					subNode->oldheight=Height(subNode);
					subNode->stck->push("A");
					//cout<<subNode->isim<<"A YAZDIM"<<endl;
				}
				else if(Height(subNode) > subNode->oldheight){
					subNode->oldheight=Height(subNode);
					subNode->stck->push("Y");
					//cout<<subNode->isim<<"Y YAZDIM"<<endl;
				}
				else 
					subNode->stck->push("D");
				//cout<<subNode->isim<<"D YAZDIM"<<endl;
			}
		}
		void ADD::postOrder1(Node *subNode)
		{	
			if(subNode != NULL){
				postOrder1(subNode->left);
				postOrder1(subNode->right);	
				cout<<subNode->isim<<", ";
				cout<<subNode->age<<", ";
				cout<<subNode->kilo<<"  Yigit: ";
				cout<<subNode->stck->top()<<endl;	
			}
		}
		void ADD::RemoveNode(Node *&subNode){ 
			Node *deletedNode = subNode;
			if(subNode->right == NULL) subNode = subNode->left;
			else if(subNode->left == NULL) subNode = subNode->right;
			else{
				deletedNode = subNode->left;
				Node *parentNode = subNode;
				while(deletedNode->right != NULL)
				{
					parentNode = deletedNode;
					deletedNode = deletedNode->right;
				}
				subNode->isim = deletedNode->isim;
				subNode->age = deletedNode->age;
				subNode->kilo = deletedNode->kilo;
				if(parentNode == subNode) 
					subNode->left = deletedNode->left;
				else 
					parentNode->right = deletedNode->left;
			}
			delete deletedNode;
		}
		ADD::ADD()	{
			root= NULL;
		}
		bool ADD::isEmpty()const{
			return root == NULL;
		}
		void ADD::add(const string& isim,string age,string kilo,int yas)	{
			root = SearchAndAdd(root,isim,age,kilo,yas);
		}
		int ADD::Height()	{
			return Height(root);
		}
		void ADD::AddStk(){
			AddStk(root);
		}
		void ADD::postOrder(){
			postOrder1(root);
		}
		void ADD::clear(){
			while(!isEmpty())
				RemoveNode(root);
		}
		ADD::~ADD(){
			clear();
		}

