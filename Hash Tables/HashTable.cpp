
#include<string>
#include<iostream>
#include <algorithm>
using namespace std;

template <typename Object>
class List
{
private:
    // The basic doubly linked list node.
    // Nested inside of List, can be public
    // because the Node is itself private
    struct Node
    {
        Object  data;
        Node   *prev;
        Node   *next;
        
        Node( const Object & d = Object{ }, Node * p = nullptr, Node * n = nullptr )
        : data{ d }, prev{ p }, next{ n } { }
        
        Node( Object && d, Node * p = nullptr, Node * n = nullptr )
        : data{ std::move( d ) }, prev{ p }, next{ n } { }
    };
    
public:
    class const_iterator
    {
    public:
        
        // Public constructor for const_iterator.
        const_iterator( ) : current{ nullptr }
        { }
        
        // Return the object stored at the current position.
        // For const_iterator, this is an accessor with a
        // const reference return type.
        const Object & operator* ( ) const
        { return retrieve( ); }
        
        const_iterator & operator++ ( )
        {
            current = current->next;
            return *this;
        }
        
        const_iterator operator++ ( int )
        {
            const_iterator old = *this;
            ++( *this );
            return old;
        }
        
        const_iterator & operator-- ( )
        {
            current = current->prev;
            return *this;
        }
        
        const_iterator operator-- ( int )
        {
            const_iterator old = *this;
            --( *this );
            return old;
        }
        
        bool operator== ( const const_iterator & rhs ) const
        { return current == rhs.current; }
        
        bool operator!= ( const const_iterator & rhs ) const
        { return !( *this == rhs ); }
        
    protected:
        Node *current;
        
        // Protected helper in const_iterator that returns the object
        // stored at the current position. Can be called by all
        // three versions of operator* without any type conversions.
        Object & retrieve( ) const
        { return current->data; }
        
        // Protected constructor for const_iterator.
        // Expects a pointer that represents the current position.
        const_iterator( Node *p ) :  current{ p }
        { }
        
        friend class List<Object>;
    };
    
    class iterator : public const_iterator
    {
    public:
        
        // Public constructor for iterator.
        // Calls the base-class constructor.
        // Must be provided because the private constructor
        // is written; otherwise zero-parameter constructor
        // would be disabled.
        iterator( )
        { }
        
        Object & operator* ( )
        { return const_iterator::retrieve( ); }
        
        // Return the object stored at the current position.
        // For iterator, there is an accessor with a
        // const reference return type and a mutator with
        // a reference return type. The accessor is shown first.
        const Object & operator* ( ) const
        { return const_iterator::operator*( ); }
        
        iterator & operator++ ( )
        {
            this->current = this->current->next;
            return *this;
        }
        
        iterator operator++ ( int )
        {
            iterator old = *this;
            ++( *this );
            return old;
        }
        
        iterator & operator-- ( )
        {
            this->current = this->current->prev;
            return *this;
        }
        
        iterator operator-- ( int )
        {
            iterator old = *this;
            --( *this );
            return old;
        }
        
    protected:
        // Protected constructor for iterator.
        // Expects the current position.
        iterator( Node *p ) : const_iterator{ p }
        { }
        
        friend class List<Object>;
    };
    
public:
    List( )
    { init( ); }
    
    ~List( )
    {
        clear( );
        delete head;
        delete tail;
    }
    
    List( const List & rhs )
    {
        init( );
        for( auto & x : rhs )
            push_back( x );
    }
    
    List & operator= ( const List & rhs )
    {
        List copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
    
    
    List( List && rhs )
    : theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail }
    {
        rhs.theSize = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }
    
    List & operator= ( List && rhs )
    {
        std::swap( theSize, rhs.theSize );
        std::swap( head, rhs.head );
        std::swap( tail, rhs.tail );
        
        return *this;
    }
    
    
    // Return iterator representing beginning of list.
    // Mutator version is first, then accessor version.
    iterator begin( )
    { return iterator( head->next ); }
    
    const_iterator begin( ) const
    { return const_iterator( head->next ); }
    
    // Return iterator representing endmarker of list.
    // Mutator version is first, then accessor version.
    iterator end( )
    { return iterator( tail ); }
    
    const_iterator end( ) const
    { return const_iterator( tail ); }
    
    // Return number of elements currently in the list.
    int size( ) const
    { return theSize; }
    
    // Return true if the list is empty, false otherwise.
    bool empty( ) const
    { return size( ) == 0; }
    
    void clear( )
    {
        while( !empty( ) )
            pop_front( );
    }
    
    // front, back, push_front, push_back, pop_front, and pop_back
    // are the basic double-ended queue operations.
    Object & front( )
    { return *begin( ); }
    
    const Object & front( ) const
    { return *begin( ); }
    
    Object & back( )
    { return *--end( ); }
    
    const Object & back( ) const
    { return *--end( ); }
    
    void push_front( const Object & x )
    { insert( begin( ), x ); }
    
    void push_back( const Object & x )
    { insert( end( ), x ); }
    
    void push_front( Object && x )
    { insert( begin( ), std::move( x ) ); }
    
    void push_back( Object && x )
    { insert( end( ), std::move( x ) ); }
    
    void pop_front( )
    { erase( begin( ) ); }
    
    void pop_back( )
    { erase( --end( ) ); }
    
    // Insert x before itr.
    iterator insert( iterator itr, const Object & x )
    {
        Node *p = itr.current;
        ++theSize;
        return iterator( p->prev = p->prev->next = new Node{ x, p->prev, p } );
    }
    
    // Insert x before itr.
    iterator insert( iterator itr, Object && x )
    {
        Node *p = itr.current;
        ++theSize;
        return iterator( p->prev = p->prev->next = new Node{ std::move( x ), p->prev, p } );
    }
    
    // Erase item at itr.
    iterator erase( iterator itr )
    {
        Node *p = itr.current;
        iterator retVal( p->next );
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        --theSize;
        
        return retVal;
    }
    
    iterator erase( iterator from, iterator to )
    {
        for( iterator itr = from; itr != to; )
            itr = erase( itr );
        
        return to;
    }
    
private:
    int   theSize;
    Node *head;
    Node *tail;
    
    void init( )
    {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
};

template <class T, class V>
struct HashEntry
{
    T key; //the phone number for example
    V value;
    HashEntry(){};
    HashEntry(T t, V v){
        key=t;
        value =v;
    }
    bool operator==(const HashEntry& rhs){
        return ((rhs.key == key) && (rhs.value == value));
    }
    friend ostream& operator <<(ostream & out, HashEntry& e){
        out << e.key << ": " << e.value;
        return out;
    }
};


template <class T, class V>
class HashTable{
private:
    static const int size=10;
    List<HashEntry<T, V>> l[size];
public:
    bool isEmpty(){
        for (int i =0; i<size; i++) {
            if (!l[i].empty()) {
                return false;
            }
            
        }
        return true;
    }
    void insert(T key, V value){
        //this is where I'm going to put my entry
        int index = HashFunc(key);
        HashEntry<T, V> entry(key, value);
        //so I know I will place entry in l[index] ==> this is my list that I will push_back on.
        
        //if it exists
        
        //I need to traverse l[index] and make sure that entry does not already exist, if it does, I will overwrite it.
        for(auto i=l[index].begin(); i != l[index].end(); i++){
            //if exists, overwrite and return
            if (entry.key == (*i).key) {
                cout <<"exists, so I'm overwriting\n";
                *i =entry;
                return;
            }
        }
        
        l[index].push_back(entry);
        
        
    }
    int HashFunc(T key){
        return key % size;
    }
    V search(T key){
        int index = HashFunc(key);
        //now I know my item exists in l[index]. need to look through l[index] until I find my entry;
        
        for(auto i=l[index].begin(); i != l[index].end(); i++){
            if((*i).key == key)
                return (*i).value;
        }
        return NULL;
    }
    
    void traverse(){
        for (int index=0; index<size; index++) {
            for(auto i=l[index].begin(); i != l[index].end(); i++){
                //if exists, overwrite and return
                cout << *i << endl;
            }
        }
        
    }
    
};
/*
 HashTable<int, string> h;
 h.insert(900, "shahd");
 h.insert(200, "mohamed");
 h.insert(304, "salma");
 
 //pretend its of size 3;
 0: [ 900, "salma",   200, "mohamed"   ]
 1: [ 304, "salma", {}, {}   ]
 2: [ {}, {}, {}   ]
 
 HashTable t;
 t.insert(900, "shahd"); //hashes to zero
 t.insert(900, "salma");
 
 */

int main(){
    
  
    
    HashTable <int, string>h;
    h.insert(900, "shahd");
    h.traverse();
    h.insert(900, "mohamed");
    h.insert(60, "h");
  
    cout << h.search(900);
   
}















