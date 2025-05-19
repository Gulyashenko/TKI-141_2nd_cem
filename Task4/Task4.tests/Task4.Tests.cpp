#include "CppUnitTest.h"
#include "../Library/PriorityQueue.h"
#include "../Library/Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PriorityQueueTests
{
    TEST_CLASS(NodeTests)
    {
    public:
        TEST_METHOD(NodeConstructor_Default_Success)
        {
            // Arrange & Act
            Node node;
            
            // Assert
            Assert::AreEqual(node.getPriority(), 0);
            Assert::IsNull(node.getNext());
        }

        TEST_METHOD(NodeConstructor_WithParameters_Success)
        {
            // Arrange
            Node* nextNode = new Node(5, nullptr);
            
            // Act
            Node node(10, nextNode);
            
            // Assert
            Assert::AreEqual(node.getPriority(), 10);
            Assert::AreEqual(node.getNext(), nextNode);
            
            delete nextNode;
        }

        TEST_METHOD(NodeSwap_Success)
        {
            // Arrange
            Node node1(5, nullptr);
            Node node2(10, nullptr);
            
            // Act
            node1.swap(node2);
            
            // Assert
            Assert::AreEqual(node1.getPriority(), 10);
            Assert::AreEqual(node2.getPriority(), 5);
        }

        TEST_METHOD(NodeComparisonOperators_Success)
        {
            // Arrange
            Node node1(5, nullptr);
            Node node2(10, nullptr);
            Node node3(5, nullptr);
            
            // Assert
            Assert::IsTrue(node1 == node3);
            Assert::IsTrue(node1 != node2);
            Assert::IsTrue(node2 > node1);
            Assert::IsTrue(node1 < node2);
            Assert::IsTrue(node1 >= node3);
            Assert::IsTrue(node1 <= node3);
        }
    };

    TEST_CLASS(PriorityQueueTests)
    {
    public:
        TEST_METHOD(PriorityQueueConstructor_Default_Success)
        {
            // Arrange & Act
            PriorityQueue queue;
            
            // Assert
            Assert::IsNull(queue.getHead());
            Assert::IsNull(queue.getTail());
            Assert::AreEqual(queue.getSize(), 0);
            Assert::IsTrue(queue.isEmpty());
        }

        TEST_METHOD(PriorityQueueConstructor_Copy_Success)
        {
            // Arrange
            PriorityQueue original;
            original.add(5);
            original.add(3);
            original.add(7);
            
            // Act
            PriorityQueue copy(original);
            
            // Assert
            Assert::AreEqual(copy.getSize(), original.getSize());
            Assert::AreEqual(copy.getHead()->getPriority(), original.getHead()->getPriority());
            Assert::AreEqual(copy.getTail()->getPriority(), original.getTail()->getPriority());
        }

        TEST_METHOD(PriorityQueueConstructor_Move_Success)
        {
            // Arrange
            PriorityQueue original;
            original.add(5);
            original.add(3);
            int originalSize = original.getSize();
            Node* originalHead = original.getHead();
            Node* originalTail = original.getTail();
            
            // Act
            PriorityQueue moved(std::move(original));
            
            // Assert
            Assert::AreEqual(moved.getSize(), originalSize);
            Assert::AreEqual(moved.getHead(), originalHead);
            Assert::AreEqual(moved.getTail(), originalTail);
            Assert::IsTrue(original.isEmpty());
        }

        TEST_METHOD(PriorityQueueConstructor_InitializerList_Success)
        {
            // Arrange & Act
            PriorityQueue queue = {5, 3, 7, 1};
            
            // Assert
            Assert::AreEqual(queue.getSize(), 4);
            Assert::AreEqual(queue.getHead()->getPriority(), 7);
            Assert::AreEqual(queue.getTail()->getPriority(), 1);
        }

        TEST_METHOD(Add_ToEmptyQueue_Success)
        {
            // Arrange
            PriorityQueue queue;
            int priority = 5;
            
            // Act
            bool result = queue.add(priority);
            
            // Assert
            Assert::IsTrue(result);
            Assert::AreEqual(queue.getSize(), 1);
            Assert::IsFalse(queue.isEmpty());
            Assert::AreEqual(queue.getHead()->getPriority(), priority);
            Assert::AreEqual(queue.getTail()->getPriority(), priority);
        }

        TEST_METHOD(Add_MultipleElementsInOrder_Success)
        {
            // Arrange
            PriorityQueue queue;
            
            // Act
            queue.add(5);
            queue.add(3);
            queue.add(7);
            queue.add(1);
            
            // Assert
            Assert::AreEqual(queue.getSize(), 4);
            Assert::AreEqual(queue.getHead()->getPriority(), 7);
            Assert::AreEqual(queue.getTail()->getPriority(), 1);
        }

        TEST_METHOD(Remove_FromEmptyQueue_ReturnsFalse)
        {
            // Arrange
            PriorityQueue queue;
            
            // Act
            bool result = queue.remove();
            
            // Assert
            Assert::IsFalse(result);
            Assert::AreEqual(queue.getSize(), 0);
        }

        TEST_METHOD(Remove_SingleElement_Success)
        {
            // Arrange
            PriorityQueue queue;
            queue.add(5);
            
            // Act
            bool result = queue.remove();
            
            // Assert
            Assert::IsTrue(result);
            Assert::AreEqual(queue.getSize(), 0);
            Assert::IsTrue(queue.isEmpty());
            Assert::IsNull(queue.getHead());
            Assert::IsNull(queue.getTail());
        }

        TEST_METHOD(Remove_MultipleElements_Success)
        {
            // Arrange
            PriorityQueue queue = {5, 3, 7, 1};
            
            // Act & Assert
            Assert::IsTrue(queue.remove());
            Assert::AreEqual(queue.getSize(), 3);
            Assert::AreEqual(queue.getHead()->getPriority(), 5);
            
            Assert::IsTrue(queue.remove());
            Assert::AreEqual(queue.getSize(), 2);
            Assert::AreEqual(queue.getHead()->getPriority(), 3);
            
            Assert::IsTrue(queue.remove());
            Assert::AreEqual(queue.getSize(), 1);
            Assert::AreEqual(queue.getHead()->getPriority(), 1);
            
            Assert::IsTrue(queue.remove());
            Assert::AreEqual(queue.getSize(), 0);
            Assert::IsTrue(queue.isEmpty());
        }

        TEST_METHOD(AssignmentOperator_Success)
        {
            // Arrange
            PriorityQueue original = {5, 3, 7};
            PriorityQueue copy;
            
            // Act
            copy = original;
            
            // Assert
            Assert::AreEqual(copy.getSize(), original.getSize());
            Assert::AreEqual(copy.getHead()->getPriority(), original.getHead()->getPriority());
            Assert::AreEqual(copy.getTail()->getPriority(), original.getTail()->getPriority());
        }

        TEST_METHOD(Destructor_ClearsQueue_Success)
        {
            // Arrange
            PriorityQueue* queue = new PriorityQueue();
            queue->add(5);
            queue->add(3);
            queue->add(1);
            
            // Act
            delete queue;
            
            // No direct assert, but if destructor works correctly, no memory leaks
        }

        TEST_METHOD(OutputOperator_Success)
        {
            // Arrange
            PriorityQueue queue = {5, 3};
            
            // Act
            std::ostringstream os;
            os << queue;
            std::string result = os.str();
            
            // Assert
            Assert::IsTrue(result.find("Size: 2") != std::string::npos);
        }
    };
}
