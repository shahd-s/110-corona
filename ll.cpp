#include <iostream>
#include <vector>
using namespace std;

template <class T>
struct Node{
    
    T data;
    Node * next;
    
};

template <class T>
class CharLinkedList {
private:
    Node<char> * head;
    Node<char> * tail;
public:
    CharLinkedList(){
        head = NULL;
        tail = NULL;
    }
    
    void Add(T c){
        Node<char> * thenodeiwanttoadd = new Node<char>;
        thenodeiwanttoadd->data = c;
        thenodeiwanttoadd->next = NULL;
        
        //If this is the very first element, and thus my linked list is empty. Thus head and tail are both null. and tail is also head.
        if (head == NULL) {
            head = thenodeiwanttoadd;
            tail = head;
            
        }
        else
        {
            tail->next = thenodeiwanttoadd;
            tail = thenodeiwanttoadd;
            
        }
        
    }
 
   
    void Print(){
        Node<char> * tempHead = head;
        while (tempHead != NULL){
            cout << tempHead->data;
            tempHead= tempHead->next;
        }
        
    }

    
};




int main(){
    
    CharLinkedList<char> L;
    L.Add('c');
    L.Add('a');
    L.Add('f');
  
    
 
    L.Print();
    return 0;
}




