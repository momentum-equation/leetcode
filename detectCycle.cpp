#include <vector>
#include <unordered_set>

#include "ListNode.h"

#include <gtest/gtest.h>

using namespace std;


ListNode *detectCycle(ListNode *head)
{
    if (!head)
        return nullptr;

    ListNode* inputList = head;
    unordered_set<ListNode*> nodeSet;
    while (inputList != nullptr)
    {
        auto it = nodeSet.find(inputList);
        if (it != nodeSet.end())
            return *it;

        nodeSet.emplace(inputList);
        inputList = inputList->next;
    }

    return nullptr;
}

TEST(detect_cycle, empty_list)
{
    ListNode* list = nullptr;
    ASSERT_EQ(detectCycle(list), nullptr);
}

TEST(detect_cycle, straight_list)
{
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);

    ASSERT_EQ(detectCycle(list), nullptr);
}

TEST(detect_cycle, cyclic_list)
{
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = list->next;

    ASSERT_EQ(detectCycle(list), list->next);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
