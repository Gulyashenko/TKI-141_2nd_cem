#pragma once
#include "Node.h"

/**
 * @brief Class priority queue
 */
class PriorityQueue
{
    /**
     * @brief tail - tail of queue
     * @brief head - head of queue
     * @brief size - size of queue
     */
    private:
        Node* tail;
        Node* head;
        int size;
    public:
        /**
         * @brief default constructor
         */
        PriorityQueue();
        /**
         * @brief constructor
         */
        PriorityQueue(Node* tail, Node* head, int size);
        /**
         * @brief destructor
         */
        ~PriorityQueue();

        /**
         * @brief function for add element in PriorityQueue
         * @param priority - priority of element
         * @return true if element was added
         */
        bool add(const int priority);
        /**
         * @brief function for remove element from PriorityQueue
         * @return true if element was removed
         */
        bool remove();

        /**
         * @brief function for check if PriorityQueue is empty
         * @return true if PriorityQueue is empty
         */
        bool isEmpty() const;

        /**
         * @brief function for get head of PriorityQueue
         * @return head of PriorityQueue
         */
        Node* getHead() const;
        /**
         * @brief function for get tail of PriorityQueue
         * @return tail of PriorityQueue
         */
        Node* getTail() const;
        /**
         * @brief function for get size of PriorityQueue
         * @return size of PriorityQueue
         */
        int getSize() const;

        /**
         * @brief function for set head of PriorityQueue
         * @param head - head of PriorityQueue
         */
        void setHead(Node* head);
        /** @brief function for set tail of PriorityQueue
         * @param tail - tail of PriorityQueue
         */
        void setTail(Node* tail);

        /**
         * @brief operator for print PriorityQueue
         * @param os - output stream
         * @param me - PriorityQueue
         * @return output stream
         */
        friend std::ostream& operator<<(std::ostream& os,const PriorityQueue& me);
};
