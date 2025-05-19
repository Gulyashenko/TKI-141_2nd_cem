#include "Node.h"

Node::Node()
{
    priority = 0;
	next = nullptr;
}

Node::Node(int priority, Node* next)
{
    this->priority = priority;
    this->next = next;
}

Node::~Node()
{
}

void Node::swap(Node& other){
    int tempPriority = priority;
    priority = other.priority;
    other.priority = tempPriority;

    Node* tempNext = next;
    next = other.next;
    other.next = tempNext;
}

int Node::getPriority() const{
    return priority;
}

Node* Node::getNext() const
{
	return next;
}

void Node::setNext(Node* next)
{
	this->next = next;
}

bool Node::operator==(const Node& other) const{
    return priority == other.priority;
}

bool Node::operator!=(const Node& other) const{
    return priority != other.priority;
}

bool Node::operator>(const Node& other) const{
    return priority > other.priority;
}

bool Node::operator<(const Node& other) const{
    return priority < other.priority;
}

bool Node::operator>=(const Node& other) const{
    return priority >= other.priority;
}

bool Node::operator<=(const Node& other) const{
    return priority <= other.priority;
}

std::ostream& operator<<(std::ostream& os,const Node& me){
    os << me.priority << me.next;
    return os;
}
