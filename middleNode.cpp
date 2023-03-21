#include <iostream>

#include <gtest/gtest.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head)
{
    if (head == nullptr)
        return nullptr;

    ListNode* inputList = head;
    int size = 0;

    while (inputList != nullptr)
    {
        inputList = inputList->next;
        size++;
    }

    cout << size << endl;

    int midPos;
    if (size % 2 != 0)
        midPos = (size + 1) / 2;
    else
        midPos = size / 2 + 1;

    int count = 0;
    ListNode* midNode = head;
    while (count != midPos - 1)
    {
        midNode = midNode->next;
        count++;
    }

    return midNode;
}

TEST(middle_linked_list, empty_list)
{
    ListNode* list = nullptr;
    ASSERT_EQ(middleNode(list), nullptr);
}

TEST(middle_linked_list, even_elements)
{
    ListNode* list = new ListNode(1);
    list->next = new ListNode(3);
    list->next->next = new ListNode(4);
    list->next->next->next = new ListNode(5);

    ASSERT_EQ(middleNode(list)->val, 4);
}

TEST(middle_linked_list, odd_elements)
{
    ListNode* list = new ListNode(1);
    list->next = new ListNode(3);
    list->next->next = new ListNode(4);

    ASSERT_EQ(middleNode(list)->val, 3);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
