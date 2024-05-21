#include <gtest/gtest.h>
#include "../Stack.h"

TEST(StackTestSuite, StackTest) {
    string filename = "../numbers.txt";
    Stack originalStack = readStackFromFile(filename);

    Stack newStack = copyNElements(originalStack, 4);
    removeMElements(newStack, 2);

    EXPECT_EQ(newStack.toString(), "6 7 ");
}