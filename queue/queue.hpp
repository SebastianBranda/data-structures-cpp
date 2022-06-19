#ifndef QUEUE_H
#define QUEUE_H

#include "../node.hpp"

template<class T>
class Queue{
    private:
    Node<T>* front;
    Node<T>* rear;

    public:
    Queue();
    void enqueue(T element);
    T dequeue();
    bool isEmpty();
    void display();

    ~Queue();
};

template<class T>
Queue<T>::Queue(){
    this->front = NULL;
    this->rear = NULL; 
}

template<class T>
void Queue<T>::enqueue(T element){
    Node<T>* node = new Node<T>(element);
    if(node == NULL){
        throw "CANT ALLOCATE ELEMENT";
    }
    node->setNext(NULL);
    if(this->front == NULL){
        this->front = node;
    }else{
        this->rear->setNext(node);
    }
    this->rear = node;
}

template<class T>
T Queue<T>::dequeue(){
    if(this->front == NULL){
        throw "NO ELEMENTS ON QUEUE";
    }
    Node<T>* node = this->front;
    T element = node->getData();
    this->front = node->getNext();
    if(this->front == NULL){
        this->rear = NULL;
    }
    delete node;
    return element;
}

template<class T>
void Queue<T>::display(){
    Node<T>* node = this->front;
    while(node != NULL){
        std::cout << node->getData() << "\t-> ";
        node = node->getNext();
    }
    std::cout << "x" << std::endl;
}

template<class T>
bool Queue<T>::isEmpty(){
    return (this->front==NULL);
}

template<class T>
Queue<T>::~Queue(){
    Node<T>* node = NULL;
    while(this->front != NULL){
        node = this->front;
        this->front = this->front->getNext();
        delete node;
    }
    this->rear = NULL;
}

#endif

