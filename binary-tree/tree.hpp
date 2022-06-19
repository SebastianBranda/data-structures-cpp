#ifndef TREE_H
#define TREE_H

#include "nodeBinary.hpp"
#include "../queue/queue.hpp"

template<class T>
class Tree{
    private:
        NodeBinary<T>* root;

        void preorderWalk(NodeBinary<T>* node);
        void inorderWalk(NodeBinary<T>* node);
        void postorderWalk(NodeBinary<T>* node);
        void levelWalk(NodeBinary<T>* node); 
        NodeBinary<T>* seach(NodeBinary<T>* node, T element);
        void destructorRec(NodeBinary<T>* node);

    public:
        Tree();
        void insert(T element);
        void preorderWalk();
        void inorderWalk();
        void postorderWalk();
        void levelWalk(); 
        NodeBinary<T>* seach(T element);

        ~Tree();
};

template<class T>
Tree<T>::Tree(){
    this->root = NULL;
}

template<class T>
void Tree<T>::insert(T element){
    if(this->root == NULL){
        this->root = new NodeBinary<T>(element);
        this->root->setLeftChild(NULL);
        this->root->setRightChild(NULL);
        return;        
    }
    NodeBinary<T>* node = this->seach(element);
    NodeBinary<T>* parent = NULL; 
    if(node != NULL){
        throw "ELEMENT IS ALREADY ON THE TREE";
    }

    node = this->root;
    while(node != NULL){
        parent = node;
        if(element < node->getData()){
            node = node->getLeftChild();
        }else{
            node = node->getRightChild();
        }
    }
    node = new NodeBinary<T>(element);
    node->setLeftChild(NULL);
    node->setRightChild(NULL);
    if(node->getData() < parent->getData()){
        parent->setLeftChild(node);
    }else{
        parent->setRightChild(node);
    }
}


template<class T>
void Tree<T>::preorderWalk(){
    this->preorderWalk(this->root);
    std::cout << " X " << std::endl;
}

template<class T>
void Tree<T>::preorderWalk(NodeBinary<T>* node){
    if(node != NULL){
        std::cout << node->getData() << "\t ";
        preorderWalk(node->getLeftChild());
        preorderWalk(node->getRightChild());
    }
}

template<class T>
void Tree<T>::inorderWalk(){
    this->inorderWalk(this->root);    
    std::cout << " X " << std::endl;
}

template<class T>
void Tree<T>::inorderWalk(NodeBinary<T>* node){
    if(node != NULL){
        this->inorderWalk(node->getLeftChild());
        std::cout << node->getData() << "\t ";
        this->inorderWalk(node->getRightChild());
    }
}

template<class T>
void Tree<T>::postorderWalk(){
    this->postorderWalk(this->root);
    std::cout << " X " << std::endl;
}

template<class T>
void Tree<T>::postorderWalk(NodeBinary<T>* node){
    if(node != NULL){
        this->postorderWalk(node->getLeftChild());;
        this->postorderWalk(node->getRightChild());
        std::cout << node->getData() << "\t ";
    }
}

template<class T>
void Tree<T>::levelWalk(){
    this->levelWalk(this->root);
    std::cout << " X " << std::endl;
}

template<class T>
void Tree<T>::levelWalk(NodeBinary<T>* root){
    if(root == NULL){
        throw "ROOT IS NULL";
    }
    Queue<NodeBinary<T>*> q;
    NodeBinary<T>* node;
    q.enqueue(root);
    while(!q.isEmpty()){
        node = q.dequeue();
        std::cout << node->getData() << "\t ";
        if(node->getLeftChild() != NULL){
            q.enqueue(node->getLeftChild());
        }
        if(node->getRightChild() != NULL){
            q.enqueue(node->getRightChild());
        }
    }
}

template<class T>
NodeBinary<T>* Tree<T>::seach(NodeBinary<T>* node, T element){
    if(node == NULL){
        return NULL;
    }
    if(node->getData() == element){
        return node;
    }else if(node->getData() < element){
        return this->seach(node->getLeftChild(), element);
    }else{
        return this->seach(node->getRightChild(), element);
    }
}

template<class T>
NodeBinary<T>* Tree<T>::seach(T element){
    return this->seach(this->root, element);
}


template<class T>
void Tree<T>::destructorRec(NodeBinary<T>* node){
    if(node == NULL){
        return;
    }
    this->destructorRec(node->getLeftChild());
    this->destructorRec(node->getRightChild());
    delete node;
}

template<class T>
Tree<T>::~Tree(){
    this->destructorRec(this->root);
}

#endif