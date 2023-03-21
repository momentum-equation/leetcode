#include <iostream>
#include <string>
#include <algorithm>

#include <gtest/gtest.h>

using namespace std;


int longestPalindrome(string s)
{
    if (s.length() < 2)
    {
        return s.length();
    }
    else if (s.length() == 2)
    {
        if (s[0] == s[1])
            return 2;
        else
            return 1;
    }

    sort(s.begin(), s.end());

    char tmp = '\0';
    int count = 0;
    int evenSum = 0;
    int oddMax = 0;
    vector<int> oddVals;
    for (int i = 0; i < s.length() + 1; ++i)
    {
        if (tmp != s[i])
        {
            if (count % 2 == 0)
                evenSum += count;
            else
            {
                oddVals.push_back(count);
                oddMax = oddMax > count ? oddMax : count;
            }

            count = 1;
            tmp = s[i];
        }
        else
        {
            count++;
        }
    }

    int oddMaxCount = 0;
    for (int i = 0; i < oddVals.size(); ++i)
    {
        if (oddVals[i] < oddMax)
            evenSum += oddVals[i] - 1;
        else if (oddVals[i] == oddMax)
            oddMaxCount++;
    }

    if (oddMax > 1 && oddMaxCount > 0)
        evenSum += (oddMaxCount - 1) * (oddMax - 1);

    return evenSum + oddMax;
}

TEST(longest_palindrome, empty_string)
{
    string s = "";
    ASSERT_EQ(longestPalindrome(s), 0);
}

TEST(longest_palindrome, single_char_string)
{
    string s = "a";
    ASSERT_EQ(longestPalindrome(s), 1);
}

TEST(longest_palindrome, two_chars)
{
    string s = "aa";
    ASSERT_EQ(longestPalindrome(s), 2);

    s = "ab";
    ASSERT_EQ(longestPalindrome(s), 1);

    s = "abc";
    ASSERT_EQ(longestPalindrome(s), 1);
}

TEST(longest_palindrome, multiple_chars)
{
    string s = "ssa";
    ASSERT_EQ(longestPalindrome(s), 3);

    s = "ssass";
    ASSERT_EQ(longestPalindrome(s), 5);

    s = "abccccdd";
    ASSERT_EQ(longestPalindrome(s), 7);

    s = "Abccccdd";
    ASSERT_EQ(longestPalindrome(s), 7);

    s = "aaabbbbbccccdd";
    ASSERT_EQ(longestPalindrome(s), 13);

    s = "aaabbbbbccccdddddd";
    ASSERT_EQ(longestPalindrome(s), 17);

    s = "aaaaaaccccd";
    ASSERT_EQ(longestPalindrome(s), 11);

    s = "ssaaaa";
    ASSERT_EQ(longestPalindrome(s), 6);

    s = "aaabbcccddde"; // dabcccbad
    ASSERT_EQ(longestPalindrome(s), 9);
}

TEST(longest_palindrome, long_string)
{
    string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    ASSERT_EQ(longestPalindrome(s), 983);

    s = "ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";
    ASSERT_EQ(longestPalindrome(s), 867);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
