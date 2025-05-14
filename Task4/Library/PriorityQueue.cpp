#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() : tail(nullptr), head(nullptr), size(0) {}

PriorityQueue::PriorityQueue(Node* tail, Node* head, int size)
    : tail(tail), head(head), size(size) {}

PriorityQueue::~PriorityQueue() {
    while (head != nullptr){
        remove();
    }
}

bool PriorityQueue::add(const int priority){
    Node node(priority, nullptr);
    if (node > *head){
        Node temp = *head;
        *head = node;
        node.setNext(&temp);
        
    }
    if (node <= *tail){
        Node temp = *tail;
        *tail = node;
        temp.setNext(&node);
    }
    if (node <= *head){
        node.setNext(head->getNext());
        head->setNext(&node);
    }

    size++;

    return true;
}

bool PriorityQueue::remove(){
    if (head == nullptr){return false;}

    Node temp = *head;
    head = temp.getNext();
    delete &temp;

    size--;

    return true;
}

Node* PriorityQueue::getHead() const{
    return head;
}

Node* PriorityQueue::getTail() const{
    return tail;
}

int PriorityQueue::getSize() const{
    return size;
}

void PriorityQueue::setHead(Node* head){
    this->head = head;
}

void PriorityQueue::setTail(Node* tail){
    this->tail = tail;
}

std::ostream& operator<<(std::ostream& os,const PriorityQueue& me){
    os << "Head: " << me.head 
        << "Tail: " << me.tail 
        << "Size: " << me.size 
        << std::endl;
    return os;
}

bool PriorityQueue::isEmpty() const{
    return (head == nullptr) and (tail == nullptr);
}
