#include "PriorityQueue.h"
#include <algorithm>

PriorityQueue::PriorityQueue() : tail(nullptr), head(nullptr), size(0) {}

PriorityQueue::PriorityQueue(const PriorityQueue& other){
    tail = other.tail;
    head = other.head;
    size = other.size;
}

PriorityQueue::PriorityQueue(PriorityQueue&& other){
    head->swap(*other.head);
    tail->swap(*other.tail);
    std::swap(size, other.size);
}

PriorityQueue::~PriorityQueue() {
    while (head != nullptr){
        remove();
    }
}

bool PriorityQueue::add(const int priority){
    if (head == nullptr){
        head = new Node(priority, nullptr);
        tail = head;
        size++;
        return true;
    }
    Node node(priority, nullptr);
    if (node > *head){
        Node temp = *head;
        *head = node;
        node.setNext(&temp);
    }
    if (node <= *head){
        Node* current = head;
        while (node < *current){
            current = current->getNext();
        }
        node.setNext(current);
        current->setNext(&node);
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

bool PriorityQueue::operator=(const PriorityQueue& other){
    if (this == &other){
        return false;
    }

    this->remove();
    
    head = other.head;
    tail = other.tail;
    size = other.size;
    return 1;
}
