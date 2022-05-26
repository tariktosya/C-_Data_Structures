#include "CircularLinkedList.hpp"
#include <cstdlib>

int main(){
	CircularLinkedList<string> *isimler = new CircularLinkedList<string>();//Şablon budur. Aynı veri yapısıyla baika türde diziler tanımladık.
	int secenek=0;
	int konum;
	string isim;
	
	do{
		system("CLS");//ekranı temizler
		cout<<"1. isim ekle"<<endl;
		cout<<"2. isim sil"<<endl;
		cout<<"3. Konumdan isim sil"<<endl;
		cout<<"4. Konuma isim ekle"<<endl;
		cout<<"5. konum bul"<<endl;
		cout<<"6. isim sayisi"<<endl;
		cout<<"7. ilk isim"<<endl;
		cout<<"8. son isim"<<endl;
		cout<<"9. isimleri listele"<<endl;
		cout<<"10. isimleri temizle"<<endl;
		cout<<"11. Konumdan  tüm listeyi yaz"<<endl;
		cout<<"12. cikis"<<endl;
		cout<<"Secim";
		cin>>secenek;
		system("CLS");
		switch(secenek){
			case 1:
				cout<<"isim:";
				cin.ignore();
				getline(cin,isim);
				isimler->add(isim);
			break;
			case 2:
				cout<<"isim:";
				cin.ignore();
				getline(cin,isim);
				isimler->remove(isim);
			break;
			case 3:
				cout<<"Konum:";
				cin>>konum;
				isimler->removeAt(konum);
			break;
			case 4:
				cout<<"Konum";
				cin>>konum;
				cout<<"isim:";
				cin.ignore();
				getline(cin,isim);
				isimler->insert(konum,isim);
			break;
			case 5:
				cout<<"isim:";
				cin.ignore();
				getline(cin,isim);
				konum=isimler->indexOf(isim);
				cout<<"Konum:"<<konum<<endl;
				cin.ignore();//Ekranı durdurma
				cin.get();
			break;
			case 6:
				cout<<"isim sayisi:"<<isimler->Count()<<endl;
				cin.ignore();//Ekranı durdurma
				cin.get();
			break;
			case 7:
				cout<<"ilk isim:"<<isimler->first()<<endl;
				cin.ignore();//Ekranı durdurma
				cin.get();
			break;
			case 8:
				cout<<"Son isim:"<<isimler->last()<<endl;
				cin.ignore();//Ekranı durdurma
				cin.get();
			break;
			case 9:
				cout<<*isimler;
				cin.ignore();//Ekranı durdurma
				cin.get();
			break;
			case 10:
				isimler->clear();
			break;
			case 11:
				cout<<"Konum:";
				cin>>konum;
				isimler->PrintNodesFromPosition(konum);
				cin.ignore();//Ekranı durdurma
				cin.get();
			break;
			case 12:
			break;
			default:
				cout<<"Yanlis secenek"<<endl;
				cin.ignore();
				cin.get();
			break;
		}
	}while(secenek !=11);
	
	delete isimler;
	return 0;
}