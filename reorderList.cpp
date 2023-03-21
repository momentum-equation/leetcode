#include "ListNode.h"

#include <vector>

#include <gtest/gtest.h>

using namespace std;


void reorderList(ListNode* head)
{
    int size = 0;

    ListNode* inputList = head;
    while (inputList != nullptr)
    {
        inputList = inputList->next;
        size++;
    }

    int mid;
    if (size % 2 != 0)
        mid = (size + 1) / 2;
    else
        mid = size / 2;

    vector<ListNode*> cachedLastNodes(size - mid);

    inputList = head;

    int count = 0;
    int lastIdx = 0;
    while (inputList != nullptr)
    {
        if (count >= mid)
        {
            cachedLastNodes[lastIdx] = inputList;
            lastIdx++;
        }

        inputList = inputList->next;
        count++;
    }

    lastIdx = size - mid - 1;

    count = 0;
    cout << "Reordering begin\n";
    while (head != nullptr)
    {
        if (count % 2 == 1)
        {
            cout << "odd count\n";
            ListNode* node = head;
            head = cachedLastNodes[lastIdx];
            head->next = node;
            lastIdx--;
        }

        count++;
        head = head->next;
    }
    cout << "Reordering end\n";
}

int main(int argc, char* argv[])
{
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);

    reorderList(list);

    ListNode* tmp = list;
    while (tmp != nullptr)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    return 0;
}
