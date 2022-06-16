 #ifndef STACK_H
 #define STACK_H

#include "../node.hpp"

template<class T>
class Stack{
    private:
        Node<T>* top;

    public:
        Stack();
        void push(T element);
        T pop(); 
        bool isEmpty();
        void display();
        ~Stack();
};

template<class T>
Stack<T>::Stack(){
    this->top = NULL;
}

template<class T>
void Stack<T>::push(T element){
    Node<T>* newElement = new Node<T>(element);
    newElement->setNext(this->top);
    this->top = newElement;
}

template<class T>
T Stack<T>::pop(){
    Node<T>* element = this->top;
    T elementData = element->getData();
    this->top = element->getNext();
    delete element;
    return elementData;
}

template<class T>
bool Stack<T>::isEmpty(){
    return (this->top == NULL);
}

template<class T>
void Stack<T>::display(){
    Node<T>* element = this->top;
    while(element){
        std::cout << element->getData() << "\t-> ";
        element = element->getNext();
    }
    std::cout << "x" << std::endl;
}

template<class T>
Stack<T>::~Stack(){
    if(this->top == NULL){
        return;
    }
    Node<T>* nextNode = this->top->getNext();
    while(nextNode != NULL){
        delete this->top;
        this->top = nextNode;
        nextNode = this->top->getNext();
    }
    delete this->top;
    this->top = NULL;
}

 #endif