#ifndef LIST_H
#define LIST_H

#include "../node.hpp"

// Implementation of list with cursor

template<class T>
class List{
    private:
        Node<T>* first;
        Node<T>* cursor;
        unsigned int numberElements;

        Node<T>* getNode(unsigned int position);
        void displayReverseRec(Node<T>* p);
        Node<T>* searchRecursive(Node<T>*, T);


    public:
        List();
        List(List<T>& list);
        bool isEmpty();
        unsigned int size();
        void add(List<T>* list);
        void add(T element, unsigned int position);
        void add(T element);
        T get(unsigned int position);
        void replace(T element, unsigned int position);
        void remove(unsigned int position);

        void resetCursor();
        bool nextPositionCursor();
        T getCursor();

        void display();
        void displayReverse();
        Node<T>* search(T);
        

        ~List();
};

template<class T>
List<T>::List(){
    this->first = NULL;
    this->cursor = NULL;
    this->numberElements= 0;
}

template<class T>
List<T>::List(List<T>& list){
    this->first = NULL;
    this->cursor = NULL;
    this->numberElements= 0;
    this->add(list);
}

template<class T>
bool List<T>::isEmpty(){
    return this->numberElements==0;
}

template<class T>
unsigned int List<T>::size(){
    return this->numberElements;
}


// POST: adds elements (from another list) to the end of the list
template<class T>
void List<T>::add(List<T>* list){
    list->resetCursor();
    while(list->nextPositionCursor()){
        this->add(list->getCursor());
    }
}

// PRE: valid position
// POST: adds element to the desired position on the list
template<class T>
void List<T>::add(T element, unsigned int position){
    if(position < 1 || position > this->numberElements+1){
        std::cout << position << std::endl;
        std::cout << this->numberElements << std::endl;
        throw "INVALID POSITION ON THE LIST";
    }
    Node<T>* newNode = new Node<T>(element);
    if(position == 1){
        newNode->setNext(this->first);
        this->first = newNode;
    }else{
        Node<T>* prevNode = this->getNode(position-1);
        newNode->setNext(prevNode->getNext());
        prevNode->setNext(newNode);
    }
    this->numberElements++;
}

// POST: adds element to the end of the list
template<class T>
void List<T>::add(T element){
    this->add(element, this->numberElements+1);
}

template<class T>
T List<T>::get(unsigned int position){
    return this->getNode(position)->getNode();
}

template<class T>
void List<T>::replace(T element, unsigned int position){
    return this->getNode(position)->setData(element);    
}

template<class T>
void List<T>::remove(unsigned int position){
    Node<T>* toRemove = this->getNode(position);
    if(position == 1){
        this->first = toRemove->getNext();
    }else{
        Node<T>* previousNode = this->getNode(position-1);
        previousNode->setNext(toRemove->getNext());
    }
    delete toRemove;
    this->numberElements--;
}

template<class T>
void List<T>::resetCursor(){
    this->cursor = NULL;
}

template<class T>
bool List<T>::nextPositionCursor(){
    if(!this->cursor){
        this->cursor = this->first;
    }else{
        this->cursor = this->cursor->getNext();
    }
    return (this->cursor != NULL);
}

template<class T>
T List<T>::getCursor(){
    if(!this->cursor){
        throw "CURSOR NOT POINTING TO DATA!";
    }
    return this->cursor->getData();
}

template<class T>
List<T>::~List(){
    Node<T>* next;
    while(this->first != NULL){
        next = this->first->getNext();
        delete this->first;
        this->first = next;
    }
}

// POST: console out elements on the list using cursor
template<class T>
void List<T>::display(){
    this->resetCursor();
    while(this->nextPositionCursor()){
        std::cout << this->getCursor() << "\t-> ";
    }
    std::cout << "x" << std::endl;
}

// POST: console out elements on the list using recursive calls
template<class T>
void List<T>::displayReverse(){
    Node<T>* p = this->first;
    this->displayReverseRec(p);
    std::cout << "x" << std::endl;
}

template<class T>
Node<T>* List<T>::search(T element){
    return searchRecursive(this->first, element);
}


template<class T>
Node<T>* List<T>::searchRecursive(Node<T>* node, T element){
    if(!node){
        return NULL;
    }
    if(node->getData() == element){
        return node;
    }
    return searchRecursive(node->getNext(), element);
}







// PRIVATE METHODS

// PRE: valid position
// POST: returns node that on the desired position
template<class T>
Node<T>* List<T>::getNode(unsigned int position){
    Node<T>* node = this->first;
    unsigned int i = 1;
    while(node->getNext()!=NULL && i!=position){
        node = node->getNext();
        i++;
    }
    if(i!=position){
        throw "NODE INVALID POSITION";
    }
    return node;
}

template<class T>
void List<T>::displayReverseRec(Node<T>* p){
    if(!p){
        return;
    }
    this->displayReverseRec(p->getNext());
    std::cout << p->getData() << "\t-> ";
}


#endif