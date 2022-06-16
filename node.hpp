#ifndef NODE_H
#define NODE_H

template<class T>
class Node{
    private:
        T data;
        Node* next;

    public:
        Node(T data);
        T getData();
        void setData(T newData);
        Node<T>* getNext();
        void setNext(Node<T>* newNext);
        ~Node();
};

template<class T>
Node<T>::Node(T data){
    this->data = data;
    this->next = NULL;
}

template<class T>
T Node<T>::getData(){
    return this->data;
}

template<class T>
void Node<T>::setData(T newData){
    this->data = newData;
}

template<class T>
Node<T>* Node<T>::getNext(){
    return this->next;
}

template<class T>
void Node<T>::setNext(Node<T>* newNext){
    this->next = newNext;
}

template<class T>
Node<T>::~Node(){

}

#endif