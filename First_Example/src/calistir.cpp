/**
* @file 			calistir.cpp
* @description 		"Sayilar.txt" Dosyası içerisindeki verileri satır satır okuyarak her satırdaki sayıları, verilen algoritmaya uygun sıralayarak "CircularDoublyLinkedList" içerisine kayıt etmektedir. Her satırın sonuna gelindiğinde listeyi bir diziye kaydeder ve günün sonunda bu sayıların ASCII karşılılarını ekrana yazdırır.
* @course 			1. Öğretim B Grubu
* @assignment		1. Ödev
* @date 			05.08.2020
* @outhor 			TARIK TOSYA
*/

#include <sstream>  
#include <fstream>
#include <iostream>
#include "algoritma.hpp"
#include "Node.hpp"
#include "Cevir.hpp"
using namespace std;


int main(){
	algoritma *sayilar = new algoritma();
	int sutun;
	cout<<"***Sayilar.txt DOSYASINDA RANDOM SAYILAR TANIMLANMISTIR.***"<<endl<<"***EGER Sayilar.txt DOSYASINA BIR EKLEME YAPMAMIS ISENIZ 7(YEDI) GIRINIZ.***"<<endl<<"***KAC SATIR OLDUGU ONEMSIZDIR***"<<endl<<"BIR SATIRDA KAC ELEMAN OLDUGUNU YAZINIZ:::";
	cin>>sutun;
	int sayi;
	int i=0;
	int x;
	
	ifstream write("Sayilar.txt");
	Cevir **cevir=new Cevir*[sutun];
	while(write>>sayi){
		x=sayilar->Obeb(sayi);
		if (i==0){
		sayilar->add(sayi);
		}
		else {
			if(sayi<=x){
				if((x%sayi)==0){
					sayilar->insert(((sayilar->indexOf(x))+1),sayi);
				}
				else if((i-(x%sayi))<=0){
					sayilar->insert(0,sayi);
				}
				else  {
					sayilar->insert((i-(x%sayi)),sayi);	
				}
			}
			if(sayi>x){
				if((sayi%x)==0){
					sayilar->insert(((sayilar->indexOf(x))+1),sayi);
				}
				else if((i-(sayi%x))<=0){
					sayilar->insert(0,sayi);
				}
				else {
					sayilar->insert((i-(sayi%x)),sayi);	
				}
			}
		}
			i++;
		if(i==sutun){
			i=0;
			for(int a=0;a<sutun;a++){
				cevir[a]=new Cevir(sayilar->dataOf(a));
				printf("%c",cevir[a]->getDeger());
			}
			cout<<endl;
			for(int k=0;k<sutun;k++){
					delete cevir[k];
			}
			
			sayilar->clear();
		}
	}
			delete [] cevir;
			delete sayilar;
			return 0;
}