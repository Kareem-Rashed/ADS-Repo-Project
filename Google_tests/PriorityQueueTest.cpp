#include <gtest/gtest.h>
#include "PriorityQueue.h"


using namespace std;

// Test the PriorityQueue for int type
TEST(PriorityQueueTest, Initialization)
{
    PriorityQueue<int> pq;
    EXPECT_TRUE(pq.isEmpty())<<"Error: PQ should be empty after initialization.";
    EXPECT_EQ(pq.getSize(), 0) <<"Error: PQ length should be 0 after initialization.";

    if (pq.isEmpty() && pq.getSize() == 0) {
        cout << "Success: PQ initialized correctly as empty.\n";
    }
}
TEST(PriorityQueueTest, Insertion)
{
    PriorityQueue<int> pq;

    pq.insert(5, 1);  // Insert with value and priority
    EXPECT_EQ(pq.getSize(), 1) << "Error: PQ size should be 1 after inserting an element.";

    pq.insert(10, 2);
    EXPECT_EQ(pq.getSize(), 2) << "Error: PQ size should be 2 after inserting another element.";

    pq.insert(3, 0);
    EXPECT_EQ(pq.getSize(), 3) << "Error: PQ size should be 3 after inserting another element.";

    cout << "Success: Insertion test passed. All elements inserted correctly.\n";
}



TEST(PriorityQueueTest, Dequeue)
{
    PriorityQueue<int> pq;

    pq.insert(5, 1);
    pq.insert(10, 2);
    pq.insert(3, 0);  // The lowest priority (0) should be dequeued first

    Node<int>* node = pq.dequeue();
    EXPECT_EQ(node->getPriority(), 0) << "Error: Dequeued node should have the lowest priority.";
    EXPECT_EQ(pq.getSize(), 2) << "Error: PQ size should be 2 after one dequeue.";

    node = pq.dequeue();
    EXPECT_EQ(node->getPriority(), 1) << "Error: Dequeued node should have the next lowest priority.";
    EXPECT_EQ(pq.getSize(), 1) << "Error: PQ size should be 1 after another dequeue.";

    node = pq.dequeue();
    EXPECT_EQ(node->getPriority(), 2) << "Error: Dequeued node should have the highest priority.";
    EXPECT_EQ(pq.getSize(), 0) << "Error: PQ size should be 0 after all dequeues.";

    cout << "Success: Dequeue test passed. All elements dequeued correctly (lowest priority first).\n";
}

#include <gtest/gtest.h>
#include "PriorityQueue.h"

using namespace std;

// Test for inserting multiple elements with the same priority
TEST(PriorityQueueTest, InsertSamePriorityOrder)
{
    PriorityQueue<int> pq;

    // Insert elements with the same priority
    pq.insert(10, 1);  // Insert element 10 with priority 1
    pq.insert(20, 1);  // Insert element 20 with priority 1
    pq.insert(30, 1);  // Insert element 30 with priority 1
    pq.insert(40, 1);  // Insert element 40 with priority 1

    // Check the size after insertions
    EXPECT_EQ(pq.getSize(), 4) << "Error: PQ size should be 4 after insertions.";

    // Dequeue and check if the elements come out in the order they were inserted (FIFO for same priority)
    int dequeued1 = pq.dequeue()->data;
    EXPECT_EQ(dequeued1, 10) << "Error: First dequeued element should be 10.";

    int dequeued2 = pq.dequeue()->data;
    EXPECT_EQ(dequeued2, 20) << "Error: Second dequeued element should be 20.";

    int dequeued3 = pq.dequeue()->data;
    EXPECT_EQ(dequeued3, 30) << "Error: Third dequeued element should be 30.";

    int dequeued4 = pq.dequeue()->data;
    EXPECT_EQ(dequeued4, 40) << "Error: Fourth dequeued element should be 40.";

    // After all dequeue operations, the priority queue should be empty
    EXPECT_TRUE(pq.isEmpty()) << "Error: PQ should be empty after all elements are dequeued.";

    // Success message
    cout << "Success: Elements with the same priority were dequeued in the order they were inserted." << endl;
}

TEST(PriorityQueueTest, EmptyQueue)
{
    PriorityQueue<int> pq;

    EXPECT_TRUE(pq.isEmpty()) << "Error: PQ should be empty initially.";
    EXPECT_EQ(pq.getSize(), 0) << "Error: PQ size should be 0 initially.";

    pq.insert(5, 1);
    pq.dequeue();

    EXPECT_TRUE(pq.isEmpty()) << "Error: PQ should be empty after removing all elements.";
    EXPECT_EQ(pq.getSize(), 0) << "Error: PQ size should be 0 after all elements are dequeued.";

    cout << "Success: Empty queue test passed. PQ handled empty state correctly.\n";
}

TEST(PriorityQueueTest, CopyConstructor)
{
    PriorityQueue<int> pq1;
    pq1.insert(5, 1);
    pq1.insert(10, 2);

    PriorityQueue<int> pq2 = pq1;  // Using copy constructor

    EXPECT_EQ(pq2.getSize(), 2) << "Error: Copied PQ should have the same size as the original.";
    EXPECT_FALSE(pq2.isEmpty()) << "Error: Copied PQ should not be empty.";
    EXPECT_EQ(pq2.dequeue()->getPriority(), 1) << "Error: Copied PQ should dequeue the lowest priority element first.";

    cout << "Success: Copy constructor test passed. Copied queue works correctly.\n";
}

#include <sstream>
#include <gtest/gtest.h>

TEST(PriorityQueueTest, Display)
{
    PriorityQueue<int> pq;
    pq.insert(5, 1);
    pq.insert(10, 2);
    pq.insert(3, 0);  // The lowest priority (0) should be displayed first

    std::ostringstream output;
    std::streambuf* original = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    pq.display();

    std::cout.rdbuf(original);

    EXPECT_NE(output.str().find("3"), std::string::npos) << "Error: Display should include element 3 (lowest priority).";
    EXPECT_NE(output.str().find("5"), std::string::npos) << "Error: Display should include element 5.";
    EXPECT_NE(output.str().find("10"), std::string::npos) << "Error: Display should include element 10.";

    cout << "Success: Display test passed. All elements printed correctly (lowest priority first).\n";
}