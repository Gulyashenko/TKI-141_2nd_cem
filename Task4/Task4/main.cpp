#include "../Library/PriorityQueue.h"
/**
 * @brief Function for input
 * @param message
 * @return input
 */
int input(const char* message);

/**
 * @brief Main function
 */
int main(void){
    PriorityQueue queue;
    int countOfElementsInQueue = input("Enter count of elements in queue");

    for (int i = 0; i <= countOfElementsInQueue; i++){
        int priority = input("Enter priority");
        queue.add(priority);
    }
    
    if (queue.isEmpty()){
        std::cout << "Queue is empty" << std::endl;
    } else {
        std::cout << queue << std::endl;
    }
    return 0;
}

int input(const char* message){
    if (message != nullptr){std::cout << message << std::endl;}

    int value;
    std::cin >> value;

    if (std::cin.fail()){
        std::cout << "Invalid input" << std::endl;
        throw;
    }

    return value;
}
