/**
* @file 		calistir.cpp
* @description  Txt dosyasında verilen kişi bilgilerini, kişinin yaşına göre avl ağacına ekleyen ve ödev algoritmasında istenen, düğüm hareketlerine göre yığıt oluşturan program.
* @course 		1. öğretim B grubu
* @assignment 	2. Ödev
* @date 		01.09.2020
* @author 		TARIK TOSYA
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "Stack.hpp"
#include "ADD.hpp"
using namespace std;
int main(){
	ADD *addd = new ADD();
	ifstream oku;
	string satir,isim,age,kilo;
	ifstream oku2("Kisiler.txt");
	int i,x,yas;
	oku.open("Kisiler.txt");
	char yillar[]="";
	char delim[]="#";
	while(getline(oku,satir)){	
		x=0;
		for(i=0;i<=satir.size();i++)
			yillar[i]=satir[i];
		char *token = strtok(yillar,delim);
		while (token){	
		if(x==0)
			isim=token;
		if(x==1)
			age=token;
		if(x==2)
			kilo=token;
		x++;
        token = strtok(NULL,delim);
		}
		yas=(2020)-(atoi(age.c_str()));
		addd->add(isim,age,kilo,yas);
	}
	addd->AddStk();
	addd->postOrder();
	addd->clear();
	delete addd;
	return 0; 
}