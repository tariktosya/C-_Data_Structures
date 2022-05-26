#ifndef CIRCULARLINKEDLIST_HPP
#define CIRCULARLINKEDLIST_HPP

#include "Node.hpp"

template<typename Object>//Şablon sınıf
class CircularLinkedList{
	private:
		Node<Object> *head;//listenin ilk elamanının adresini gösteriyor.Düğüm türünden bir pointer.
		int size;
		Node<Object>* FindPreviousNode(int index)const{
				Node<Object> *prev=head;
				int i=1;//for döngüsünde.burada itr düğümler arasında dolaşan bir yapıdır.
				for(Node<Object> *itr=head;i!=index;itr=itr->next,i++){//***burada null silindi
					prev = prev->next;//düğüm üzerinde ilerletmek. artırmak yani.
				}
				return prev;
			}   
			void updateLastNode(){
				Node<Object> *lastNode = FindPreviousNode(size);//***eklendi
				lastNode->next=head;//***eklendi
			}
	public:
		CircularLinkedList(){
			head=NULL;
			size=0;
		}
		int Count()const{
			return size;
		}
		bool isEmpty()const{
			return size == 0;
		}
		void add(const Object& item){//sona ekleme
			insert(size,item);
		}
		void insert(int index, const Object& item){//araya ekleme
			//if(index<0 || index>size) hata
			if(index == 0){//en başa ekleme. Head değişir
				head = new Node<Object>(item,head);//Düğüm oluşturduk.
			}
			else{//araya ve sona ekleme
				Node<Object> *prv = FindPreviousNode(index);
				prv->next = new Node<Object>(item,prv->next);//Yeni düğüm oluştu. item oraya yerleşti ve prv->next ile bir sonraki düğüm bağlanmış oldu yeni elemana.
			}
			size++;
			if(index==0) updateLastNode();//***ekledik bunu. son elemanı güncelledi private alanda
		}
		bool find(const Object& item){//Arama
			int i=0;
			for(Node<Object> *itr=head;i<size;itr=itr->next){
					if(itr->data == item) return true;
					i++;
			}
			return false;
		}
		const Object& first()const{
			//if(isEmpty()) hata
			return head->data;
		}
		const Object& last()const{
			//if(isEmpty()) hata
			return FindPreviousNode(size)->data;
		}
		const Object& elementAt(int index)const{//index veristenen elemanı
			//if(index<0 || index >=size) hata
			if(index == 0) return first;
			return FindPreviousNode(index)->next->data;
		}
		int indexOf(const Object& item)const{//elemanı ver indexini iste
			int i=0;
			for(Node<Object> *itr=head;i<size;itr=itr->next){//**değişti
				if(itr->data == item) return i;
				i++;
			}
			return -1;
		}
		void remove(const Object& item){//veriyi girerek silmek
			int index=indexOf(item);
			//if(i = -1) throw hata
			removeAt(index);
		}
		void removeAt(int index){//verilen indexteki veriyi sil
			//if(index<0 || index>=size) hata
			Node<Object> *del;
			if(index==0){
				del=head;//çöp oluşmaması adına
				head=head->next;
			}
			else{
				Node<Object> *prv = FindPreviousNode(index);//önceki elemanına eriştik
				del=prv->next;//çöp oluşmaması için
				prv->next=prv->next->next;
			}
			size--;
			delete del;
			
			if(index==0 && size !=0)//***değişti
				updateLastNode();
		}
		friend ostream& operator<<(ostream& screen,CircularLinkedList&right){
			int i=0;
			for(Node<Object> *itr=right.head;i<right.size; itr=itr->next){//***değişti
				screen<<itr->data<<" ";
				i++;
			}
			screen<<endl;
			return screen;
		}
		void PrintNodesFromPosition(int index){//***herhangi bir indexten bütün listeyi yazdır.
		Node<Object> *itr = FindPreviousNode(index)->next;
			for	(int i=0;i<size;itr=itr->next,i++){
				cout<<itr->data<<" ";
			}	
			cout<<endl;
		}
		void clear(){//listenin elemanlarını temizler ama liste hayattadır
			while(!isEmpty())//gidip ilk elemanı sileriz.
				removeAt(0);//böylece çöz oluşmaz
		}
		~CircularLinkedList(){//yıkıcı fonksiyon. Liste yok olur tamamen
			clear();//
		}
};
#endif