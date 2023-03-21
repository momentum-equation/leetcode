#include <string>
#include <iostream>
#include <vector>

#include <gtest/gtest.h>

using namespace std;

bool isSubsequence(string s, string t)
{
    bool subsequence = true;
    vector<int> posVec;

    if (s.empty())
        return true;

    int pos = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        bool foundC = false;
        for (int j = pos; j < t.length(); ++j)
        {
            if (s[i] == t[j])
            {
                foundC = true;
                posVec.push_back(j);
                pos = j + 1;
                break;
            }
        }

        subsequence = subsequence && foundC;
        if (!subsequence)
            return false;
    }
    
    for (int i = 0; i < posVec.size() - 1; ++i)
        if (posVec[i + 1] < posVec[i])
            return false;

    if (posVec.size() != s.length())
        return false;

    if (posVec.size() > posVec.back() + 1)
        return false;
    
    return true;
}

TEST(subsequence, empty_string)
{
    ASSERT_TRUE(isSubsequence("", ""));
    ASSERT_TRUE(isSubsequence("", "a"));
}

TEST(subsequence, regular_string)
{
    ASSERT_TRUE(isSubsequence("abc", "aebcd"));
    ASSERT_FALSE(isSubsequence("abc", "aecbd"));
}

TEST(subsequence, repeating_string)
{
    ASSERT_TRUE(isSubsequence("aaa", "bbaaa"));
    ASSERT_FALSE(isSubsequence("aaaa", "bbaaa"));

    ASSERT_FALSE(isSubsequence("bb", "ahbgdc"));
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
