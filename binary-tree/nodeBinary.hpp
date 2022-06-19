#ifndef NODEBINARYTREE_H
#define NODEBINARYTREE_H

template< class T>
class NodeBinary{
    private:
        T data;
        NodeBinary<T>* leftChild;
        NodeBinary<T>* rightChild;
    public:
        NodeBinary(T data);
        T getData();
        void setData(T newData);
        NodeBinary<T>* getLeftChild();
        void setLeftChild(NodeBinary<T>* newLeftChild);
        NodeBinary<T>* getRightChild();
        void setRightChild(NodeBinary<T>* newRightChild);

        ~NodeBinary();
};

template<class T>
NodeBinary<T>::NodeBinary(T data){
    this->data = data;
    this->leftChild = NULL;
    this->rightChild = NULL;
}

template<class T>
T NodeBinary<T>::getData(){
    return this->data;
}

template<class T>
void NodeBinary<T>::setData(T newData){
    this->data = newData;
}

template<class T>
NodeBinary<T>* NodeBinary<T>::getLeftChild(){
    return this->leftChild;
}

template<class T>
void NodeBinary<T>::setLeftChild(NodeBinary<T>* newLeftChild){
    this->leftChild = newLeftChild;
}

template<class T>
NodeBinary<T>* NodeBinary<T>::getRightChild(){
    return this->rightChild;
}

template<class T>
void NodeBinary<T>::setRightChild(NodeBinary<T>* newRightChild){
    this->rightChild = newRightChild;
}

template<class T>
NodeBinary<T>::~NodeBinary(){

}



#endif