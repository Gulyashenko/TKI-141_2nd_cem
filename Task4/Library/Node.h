#pragma once
#include <iostream>

/**
 * @brief class node
 */
class Node{
    private:
        /**
         * @brief priority - priority of element
         * @brief next - next element
         */
        int priority;
        Node* next;
    public:
        /**
         * @brief default constructor
         */
        Node();
        /**
         * @brief constructor
         */
        Node(int priority, Node* next);
        /**
         * @brief destructor
         */
        ~Node();

        /**
         * @brief function for get priority
         * @return priority
         */
        int getPriority() const;
        /**
         * @brief function for get next element
         */
        Node* getNext() const;

        /**
         * @brief function for set next element
         * @param next - next element
         */
        void setNext(Node* next);

        /**
         * @brief swap function
         * @param other - other element
         */
        void swap(Node& other);

        /**
         * @brief operator for compare
         * @param other - other element
         */
        bool operator==(const Node& other) const;
        /**
         * @brief operator for compare
         * @param other - other element
         */
        bool operator!=(const Node& other) const;
        /**
         * @brief operator for compare
         * @param other - other element
         */
        bool operator>=(const Node& other) const;
        /**
         * @brief operator for compare
         * @param other - other element
         */
        bool operator<=(const Node& other) const;
        /**
         * @brief operator for compare
         * @param other - other element
         */
        bool operator>(const Node& other) const;
        /**
         * @brief operator for compare
         * @param other - other element
         */
        bool operator<(const Node& other) const;
        /**
         * @brief operator for output
         * @param os - output stream
         * @param me - element
         * @return output stream
         */
        friend std::ostream& operator<<(std::ostream& os,const Node& me);
};
