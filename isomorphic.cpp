#include <set>
#include <iostream>
#include <unordered_map>

#include <gtest/gtest.h>

using namespace std;

#define testCaseName isomorphic


bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
        return false;

    if (s.empty() && t.empty())
        return true;

    map<char, char> pairs1;
    map<char, char> pairs2;

    for (int i = 0; i < s.length(); ++i)
    {
        if (pairs1.find(s[i]) != pairs1.end())
        {
            if (pairs1[s[i]] == t[i])
                continue;
            else if (pairs1[s[i]] != t[i])
                return false;
        }
        else if (pairs2.find(t[i]) != pairs2.end())
        {
            if (pairs2[t[i]] == s[i])
                continue;
            else if (pairs2[t[i]] != s[i])
                return false;
        }
        else
        {
            pairs1[s[i]] = t[i];
            pairs2[t[i]] = s[i];
        }
    }

    return true;
}

TEST(testCaseName, empty)
{
    ASSERT_TRUE(isIsomorphic("", ""));
}

TEST(testCaseName, non_empty)
{
    ASSERT_TRUE(isIsomorphic("a", "b"));

    ASSERT_TRUE(isIsomorphic("add", "ebb"));

    ASSERT_FALSE(isIsomorphic("adb", "itt"));

    ASSERT_FALSE(isIsomorphic("itt", "adb"));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
