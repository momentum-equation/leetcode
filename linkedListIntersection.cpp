#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include <gtest/gtest.h>

using namespace std;

vector<char> intersectingLinkedLists(const vector<list<char>>& lists)
{
    vector<char> intersectingLists;
    unordered_map<char, unordered_set<char>> headNodesMap;   

    for (int i = 0; i < lists.size(); ++i)
    {
        auto head = lists[i].begin();
        auto node = head;

        if (headNodesMap[*head].empty())
            headNodesMap[*head] = unordered_set<char>();

        while (node != lists[i].end())
        {
            for (auto it = headNodesMap.begin(); it != headNodesMap.end(); ++it)
            {
                if (it->second.find(*node) != it->second.end())
                {
                    intersectingLists.push_back(it->first);
                    intersectingLists.push_back(*head);
                }
            }

            headNodesMap[*head].emplace(*node);
            node++;
        }
    }

    return intersectingLists;
}

TEST(intersecting_lists, empty_lists)
{
    vector<list<char>> lists;
    lists.push_back({});
    lists.push_back({});

    ASSERT_EQ(intersectingLinkedLists(lists), vector<char>());
}

TEST(intersecting_lists, non_empty_lists)
{
    vector<char> out;

    vector<list<char>> lists;
    lists.push_back({'a'});
    lists.push_back({'b'});

    ASSERT_EQ(intersectingLinkedLists(lists), out);

    lists.clear();
    lists.push_back({'a'});
    lists.push_back({'a'});

    out = {'a', 'a'};

    ASSERT_EQ(intersectingLinkedLists(lists), out);

    out.clear();
    lists.clear();
    lists.push_back({'a', 'b', 'c'});
    lists.push_back({'p', 'b', 'r'});

    out = {'a', 'p'};

    ASSERT_EQ(intersectingLinkedLists(lists), out);

    out.clear();
    lists.clear();
    lists.push_back({'a', 'b', 'c', 'd'});
    lists.push_back({'p', 'q', 'b', 'r'});
    lists.push_back({'w', 'x', 'y', 'z'});
    lists.push_back({'i', 'j', 'k', 'c'});
    lists.push_back({'e', 'r', 'f', 'g', 'h', 'a'});

    out = {'a', 'p', 'a', 'i', 'p', 'e', 'a', 'e'};

    ASSERT_EQ(intersectingLinkedLists(lists), out);

    out.clear();
    lists.clear();
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
