/**
* @file 			Cevir.cpp
* @description 		"Sayilar.txt" Dosyası içerisindeki verileri satır satır okuyarak her satırdaki sayıları, verilen algoritmaya uygun sıralayarak "CircularDoublyLinkedList" içerisine kayıt etmektedir. Her satırın sonuna gelindiğinde listeyi bir diziye kaydeder ve günün sonunda bu sayıların ASCII karşılılarını ekrana yazdırır.
* @course 			1. Öğretim B Grubu
* @assignment		1. Ödev
* @date 			05.08.2020
* @outhor 			TARIK TOSYA
*/
#include "Cevir.hpp"
	Cevir::Cevir(int deger){
			this->deger=deger;
		}
		int Cevir::getDeger()const{
			return deger;
		}