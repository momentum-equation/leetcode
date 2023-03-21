#include "ListNode.h"

#include <cmath>
#include <iostream>

#include <gtest/gtest.h>


using namespace std;
/* 
[2, 4, 3]
[5, 6, 4]

out = [7, 0, 8] (342 + 465 = 807)
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    if (!l1 && !l2)
        return nullptr;

    if (!l1)
        return l2;

    if (!l2)
        return l1;

    ListNode* n1 = l1;
    uint8_t l1Size = 0;
    ListNode* l1Last;
    while (n1 != nullptr)
    {
        l1Last = n1;
        n1 = n1->next;
        ++l1Size;
    }

    ListNode* n2 = l2;
    uint8_t l2Size = 0;
    ListNode* l2Last;
    while (n2 != nullptr)
    {
        l2Last = n2;
        n2 = n2->next;
        ++l2Size;
    }

    if (l1Size > l2Size)
    {
        while (l2Size != l1Size)
        {
            l2Last->next = new ListNode();
            l2Last = l2Last->next;
            ++l2Size;
        }
    }
    else if (l2Size > l1Size)
    {
        while (l1Size != l2Size)
        {
            l1Last->next = new ListNode();
            l1Last = l1Last->next;
            ++l1Size;
        }
    }

    ListNode* node1 = l1;
    ListNode* node2 = l2;

    int sum = (node1->val + node2->val) % 10;
    int carry = (node1->val + node2->val) / 10;

    ListNode* outHead = new ListNode(sum);
    ListNode* outNode = outHead;

    node1 = node1->next;
    node2 = node2->next;

    while (node1 != nullptr && node2 != nullptr)
    {   
        sum = (node1->val + node2->val + carry) % 10;
        carry = (node1->val + node2->val + carry) / 10;
        
        outNode->next = new ListNode(sum);
        outNode = outNode->next;

        node1 = node1->next;
        node2 = node2->next;
    }

    if (carry != 0)
        outNode->next = new ListNode(carry);

    return outHead;
}

#define TEST_NAME linked_list_number_add

TEST(TEST_NAME, empty_lists)
{
    ListNode* l1{};
    ListNode* l2{};

    ASSERT_EQ(addTwoNumbers(l1, l2), nullptr);
}

TEST(TEST_NAME, one_empty_list)
{
    ListNode* l1{};
    ListNode* l2 = new ListNode(5);

    ListNode* out = addTwoNumbers(l1, l2);
    int value = out->val;

    ASSERT_EQ(value, 5);
}

TEST(TEST_NAME, multiple_digits)
{
    ListNode* l1{};
    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(1);

    ListNode* out = addTwoNumbers(l1, l2);
    
    ASSERT_EQ(out->val, 2);
    ASSERT_EQ(out->next->val, 1);
}

TEST(TEST_NAME, non_empty_lists)
{
    ListNode* l1 = new ListNode(5);
    ListNode* l2 = new ListNode(4);

    ListNode* out = addTwoNumbers(l1, l2);
    ASSERT_EQ(out->val, 9);
}

TEST(TEST_NAME, carry)
{
    ListNode* l1 = new ListNode(5);
    ListNode* l2 = new ListNode(7);

    ListNode* out = addTwoNumbers(l1, l2);

    ASSERT_EQ(out->val, 2);
    ASSERT_EQ(out->next->val, 1);
}

TEST(TEST_NAME, carry_multiple_digits)
{
    ListNode* l1 = new ListNode(5);
    l1->next = new ListNode(4);

    ListNode* l2 = new ListNode(7);
    l2->next = new ListNode(1);

    ListNode* out = addTwoNumbers(l1, l2);

    ASSERT_EQ(out->val, 2);
    ASSERT_EQ(out->next->val, 6);
}

TEST(TEST_NAME, carry_result_more_digits)
{
    ListNode* l1 = new ListNode(5);
    l1->next = new ListNode(8);

    ListNode* l2 = new ListNode(7);
    l2->next = new ListNode(1);

    ListNode* out = addTwoNumbers(l1, l2);
    ASSERT_EQ(out->val, 2);
    ASSERT_EQ(out->next->val, 0);
    ASSERT_EQ(out->next->next->val, 1);
}

TEST(TEST_NAME, overflow)
{
    ListNode* l1 = new ListNode(9);

    ListNode* l2 = new ListNode(1);

    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);

    l2->next->next->next->next = new ListNode(9);
    l2->next->next->next->next->next = new ListNode(9);
    l2->next->next->next->next->next->next = new ListNode(9);

    l2->next->next->next->next->next->next->next = new ListNode(9);
    l2->next->next->next->next->next->next->next->next = new ListNode(9);
    l2->next->next->next->next->next->next->next->next->next = new ListNode(9);

    ListNode* out = addTwoNumbers(l1, l2);
    ASSERT_EQ(out->val, 0);
    ASSERT_EQ(out->next->val, 0);
    ASSERT_EQ(out->next->next->val, 0);

    ASSERT_EQ(out->next->next->next->val, 0);
    ASSERT_EQ(out->next->next->next->next->val, 0);
    ASSERT_EQ(out->next->next->next->next->next->val, 0);

    ASSERT_EQ(out->next->next->next->next->next->next->val, 0);
    ASSERT_EQ(out->next->next->next->next->next->next->next->val, 0);
    ASSERT_EQ(out->next->next->next->next->next->next->next->next->val, 0);

    ASSERT_EQ(out->next->next->next->next->next->next->next->next->next->val, 0);
    ASSERT_EQ(out->next->next->next->next->next->next->next->next->next->next->val, 1);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
