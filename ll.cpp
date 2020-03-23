#include <iostream>
#include <vector>
using namespace std;

 
struct Node{
    
    char data;
    Node * next;
    
};


class CharLinkedList {
private:
    Node * head;
    Node * tail;
public:
    CharLinkedList(){
        head = NULL;
        tail = NULL;
    }
    
    void Add(char c){
        Node* thenodeiwanttoadd = new Node;
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
        Node* tempHead = head;
        while (tempHead != NULL){
            cout << tempHead->data;
            tempHead= tempHead->next;
        }
        
    }

    
};




int main(){
    
    CharLinkedList L;
    L.Add('c');
    L.Add('a');
    L.Add('f');
  
    
 
    L.Print();
    return 0;
}




