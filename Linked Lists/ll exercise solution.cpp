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
    void Delete(int i){
        int count = 0;
        
        
        //if we want to delete the first element: Then we are deleting the head.
        if (i == 0){
            //head is just equal to the next element.
            head = head->next;
            return;
        }
        

        Node<char> * tempHead = head;
        Node<char> * prev = tempHead;
        while (tempHead != NULL){
            
            
            if (count == i){
                //if this is the last element:
                if (tempHead->next == NULL) {
                    tail = prev;
                    tail->next = NULL;
                    return;
                }
                
                //if we are an inbetween element:
                
                prev->next = tempHead->next;
            }
            prev=tempHead;
            tempHead= tempHead->next;
            count++;
            }
        
    }
    
    void DeleteEveryOther(){
        int it = 0;
        Node<char> * tempHead = head;
        Node<char> * prev = tempHead;
        while (tempHead != NULL) {
            if (it % 2 == 0 ) {
                //then we delete
                //remember we have 3 cases for deletion.
                //case 1: first element
                if (it == 0){
                    //head is just equal to the next element.
                    head = head->next;
                    
                }else //if we are at the last element
                    if (tempHead->next == NULL) {
                        tail = prev;
                        tail->next = NULL;
                        return;
                    }
                else
                    prev->next = tempHead->next;
            }
            prev=tempHead;
            tempHead= tempHead->next;
            it++;
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
    L.Add('r');
    L.Add('z');
    L.Add('x');
    
    L.DeleteEveryOther();
    L.Print();
    return 0;
}





/*
int main(){
    CharLinkedList l;
    l.Add('c');
    l.Add('a');
    l.Add('f');
    l.OP();
    return 0;
}

 
 
 class CharLinkedList {
 private:
 //head is always my first node.
 Node* head;
 Node* tail;
 
 public:
 CharLinkedList(){
 head = NULL;
 tail = head;
 }
 void Add(char thecharacteriwanttoadd){
 
 Node* nodeiwanttoadd = new Node;
 nodeiwanttoadd->data = thecharacteriwanttoadd;
 nodeiwanttoadd->next= NULL;
 
 //Case 1: this is the first time I'm adding an element, and my linked list is empty. so this element is both head and tail.
 if (head == NULL) {
 head = nodeiwanttoadd;
 tail = nodeiwanttoadd;
 }
 else
 {
 tail-> next = nodeiwanttoadd;
 tail = tail->next;
 
 }
 }
 
 void OP(){
 Node *temp = head;
 while (temp != NULL){
 cout << temp->data << endl;
 temp=temp->next;
 
 }
 }
 
 };
 
 */
