#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode* outList;
    ListNode* head;
    ListNode* firstNode = list1;
    ListNode* secondNode = list2;

    if (firstNode == nullptr && secondNode == nullptr)
        return nullptr;

    if (firstNode == nullptr)
    {
        head = new ListNode(secondNode->val);
        outList = head;
        secondNode = secondNode->next;

        while (secondNode != nullptr)
        {
            outList->next = new ListNode(secondNode->val);
            outList = outList->next;
            secondNode = secondNode->next;
        }

        return head;
    }
    else if (secondNode == nullptr)
    {
        head = new ListNode(firstNode->val);
        outList = head;
        firstNode = firstNode->next;

        while (firstNode != nullptr)
        {
            outList->next = new ListNode(firstNode->val);
            outList = outList->next;
            firstNode = firstNode->next;
        }

        return head;
    }
    else
    {
        if (firstNode->val < secondNode->val)
        {
            head = new ListNode(firstNode->val);
            outList = head;
            firstNode = firstNode->next;
        }
        else if (secondNode->val < firstNode->val)
        {
            head = new ListNode(secondNode->val);
            outList = head;
            secondNode = secondNode->next;
        }
        else
        {
            head = new ListNode(firstNode->val);
            outList = head;
            firstNode = firstNode->next;

            outList->next = new ListNode(secondNode->val);
            secondNode = secondNode->next;

            outList = outList->next;
        }
    }

    while (firstNode != nullptr && secondNode != nullptr)
    {
        if (firstNode->val < secondNode->val)
        {
            outList->next = new ListNode(firstNode->val);
            outList = outList->next;

            firstNode = firstNode->next;
        }
        else if (secondNode->val < firstNode->val)
        {
            outList->next = new ListNode(secondNode->val);
            outList = outList->next;

            secondNode = secondNode->next;
        }
        else
        {
            outList->next = new ListNode(firstNode->val);
            outList = outList->next;

            firstNode = firstNode->next;

            outList->next = new ListNode(secondNode->val);
            outList = outList->next;
            
            secondNode = secondNode->next;
        }
    }

    if (firstNode != nullptr)
    {
        while (firstNode != nullptr)
        {
            outList->next = new ListNode(firstNode->val);
            
            outList = outList->next;
            firstNode = firstNode->next;
        }
    }

    if (secondNode != nullptr)
    {
        while (secondNode != nullptr)
        {
            outList->next = new ListNode(secondNode->val);
            
            outList = outList->next;
            secondNode = secondNode->next;
        }
    }

    return head;
}

int main()
{
    // [1,2,4]
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    list1->next->next->next = nullptr;

    // [1,3,4]
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    list2->next->next->next = nullptr;

    ListNode* outList = mergeTwoLists(list1, list2);
    ListNode* head = outList;
    while (outList != nullptr)
    {
        cout << outList->val << endl;
        outList = outList->next;
    }
}

