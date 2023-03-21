#include <vector>
#include <iostream>

#include <gtest/gtest.h>


using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/*
    root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
    root = [1,null,3,2,4,null,5,6]
*/

/*
      0
    / | \
    1 2 3
   / \
   4 5
*/

vector<int> preorder(Node* root)
{
    vector<int> output;
    if (!root)
        return output;

    output.push_back(root->val);

    int level = 0;
    Node* currentNode = root;
    while (!currentNode->children.empty())
    {
        int childCount = 0;
        while (currentNode->children.begin() + childCount != currentNode->children.end())
        {
            output.push_back(currentNode->children[childCount]->val);
            ++childCount;
        }
        currentNode = currentNode->children[level];
        ++level;
    }

    return output;
}

TEST(nary_tree_preorder, empty_tree)
{
    Node* root = nullptr;
    ASSERT_EQ(preorder(root), vector<int>());
}

TEST(nary_tree_preorder, simple_tree)
{
    Node* root = new Node(0);
    for (int i = 0; i < 3; ++i)
        root->children.push_back(new Node(i + 1));

    root->children[0]->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));

    vector<int> output = { 0, 1, 2, 3, 4, 5 };
    ASSERT_EQ(output, preorder(root));
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
