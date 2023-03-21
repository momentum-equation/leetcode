#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head)
{
    if (head == nullptr)
        return nullptr;

    ListNode* reverseList;
    ListNode* headReverseList;

    ListNode* inputList = head;

    vector<int> linkedListValues;
    while (inputList != nullptr)
    {
        if (inputList != nullptr)
            linkedListValues.push_back(inputList->val);

        inputList = inputList->next;
    }

    headReverseList = new ListNode(linkedListValues.back());
    reverseList = headReverseList;
    
    for (auto it = linkedListValues.rbegin() + 1; it != linkedListValues.rend(); ++it)
    {
        reverseList->next = new ListNode(*it);
        reverseList = reverseList->next;
    }

    return headReverseList;
}

int main()
{
    // [1,3,4]
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    list2->next->next->next = nullptr;

    ListNode* outList = reverseList(list2);
    while (outList != nullptr)
    {
        cout << outList->val << endl;
        outList = outList->next;
    }

    return 0;
}
