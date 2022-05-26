#include "Stack.hpp"

class Ogrenci{
	private:
		string isim;
		int no;
	public:
		Ogrenci(string isim, int no){
			this->isim = isim;
			this->no = no;
		}
		friend ostream& operator<<(ostream& scr,Ogrenci& left){
			scr<<left.isim<<endl<<left.no<<endl;
			return scr;
		}
};

int main(){
	Stack<int> *Sayilar = new Stack<int>();
	Stack<int> *Sayilarim = new Stack<int>();
	Sayilar->push(100);
	Sayilar->push(200);
	Sayilar->push(300);
	Sayilar->pop();
	Sayilar->push(400);
	Sayilar->push(500);
	Sayilar->pop();
	cout<<Sayilar->top()<<endl;
	Sayilarim->push(888);
	cout<<Sayilarim->top()<<endl;
	
	
	Stack<Ogrenci*> *ogrenciler = new Stack<Ogrenci*>();
	ogrenciler->push(new Ogrenci("Ahmet",2002));
	ogrenciler->push(new Ogrenci("Ayse",2006));
	delete ogrenciler->top();//çıkmak üzere olan elemanı sildik
	ogrenciler->pop();
	cout<< *ogrenciler->top();
	//cout<<*ogr;
	delete ogrenciler;
	delete Sayilar;
	
	return 0;
}