#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>
using namespace std;

template <typename Object> //bunu yazınca şablon sınıfa dönüştü.
class ArrayList{
	private:
		Object *items;//Herhangi bir arraylist olabilir. TİPİ yani. Ama diyelim kişi atadık bir kez. Sonrasında hep kişi atamalısın.
		int length;//*items Dizinin ilk elemanının adresini gösteriyor.
		int capacity;
		
		void reserve(int newcapacity){
			if(newcapacity<=capacity) return;
			Object *tmp=new Object[newcapacity];
			for(int i=0;i<length;i++){//eski diziyi yeni dizimize eleman eleman kopyalıyor.
				tmp[i]=items[i];
			}
			delete [] items;
			items=tmp;
			capacity=newcapacity;
		}
	public:
		ArrayList(){
			length=0;
			capacity=100;//100 elema alabilir.
			items = new Object[capacity];//HEAP bellekte oluşturduk.
			
		}
		int size() const{
			return length;
		}
		bool isEmpty()const{//bu liste boş mu?
			return length==0;
		}
		void insert(int index,const Object& item){//Araya eleman ekleme. İndex nereye ekleneceğini söyler İtem da neyin ekleneceği.
			// if (index <0 || index >length) throw hata
			if(length == capacity) reserve(2*capacity);//dizide yer kalmamışsa reserve ile bize yer ayırır 2*capacity kadar.
			for(int i=length-1;i>=index;i--)//1 sağa kaydırma işlemi
				items[i+1]=items[i];
			items[index]=item;
			length++;
		}
		void add(const Object& item){//Sona ekler
			insert(length,item);
		}
		const Object& first()const{//ilk elemanı döndürme
			//if (length==0) throw hata
			return items[0];
		} 
		const Object& last()const{//son elemanı döndürme
			//if (length==0) throw hata
			return items[length-1];
		}
		void clear(){//Bir anda Temizler. AVANTAJLI ARRAYLİST
			length=0;//temizlendi bile
		}
		const Object& elementAt(int index)const{//Belirtilen indexteki elemanı getirir
			// if (index <0 || index >=length) throw hata
			return items[index];
		}
		int indexOf(const Object& item)const{//Bilinen elemanın indexini döndürür
			for(int index=0;index<length;index++)
				if(items[index]==item) return index;
		}
		//throw elemanyok hatası
		void remove(const Object& item){//bu elemanı sil demek
			int index = indexOf(item);//önce konumunu bulduk ve aşağıya yolladık
			removeAt(index);
		}
		void removeAt(int index){//bu indexteki elemanı sil
			// if (index <0 || index >=length) throw hata
			//hangi elemani sileceksen onun bir sağından başlayarak silinenin yerine doğru 1 kaydırarak gelmelisin.
			for(int i=index+1;i<length;i++)
				items[i-1]=items[i];
			length--;
		}
		friend ostream& operator<<(ostream& screen,ArrayList<Object>&right){
			screen<<endl;
			for(int index=0;index<right.length;index++){
				screen<<right.items[index]<<" ";
			}
			screen<<endl;
			return screen;
		}
		~ArrayList(){//bu diziyi yok ettik
			delete [] items;
		}
};


#endif
