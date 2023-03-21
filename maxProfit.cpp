#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

using namespace std;


int maxProfit(vector<int>& prices)
{
    if (prices.empty())
        return 0;

    if (prices.size() == 1)
        return 0;

    if (prices.size() == 2)
    {
        if (prices[0] < prices[1])
            return prices[1] - prices[0];
        else
            return 0;
    }

    int localMinima = INT32_MAX;
    int localMaxima = INT32_MIN;

    int localDifference = 0;

    int localMinimaPos = -1;
    int localMaximaPos = -1;

    if (prices[0] <= prices[1])
    {
        localMinima = prices[0];
        localMinimaPos = 0;
    }
    
    for (int i = 1; i < prices.size() - 1; ++i)
    {
        if (prices[i] < prices[i - 1] && prices[i] <= prices[i + 1])
        {
            if (prices[i] < localMinima)
            {
                localMinima = prices[i];
                localMinimaPos = i;
            }
            localDifference = localDifference > (prices[i + 1] - prices[i]) ? localDifference : (prices[i + 1] - prices[i]);
        }

        if (prices[i] >= prices[i - 1] && prices[i] >= prices[i + 1])
        {
            if (prices[i] > localMaxima)
            {
                localMaxima = prices[i];
                localMaximaPos = i;
            }
            else if (prices[i] == localMaxima)
            {
                localMaximaPos = i;
            }
            localDifference = localDifference > (prices[i] - prices[i - 1]) ? localDifference : (prices[i] - prices[i - 1]);
        }

        if (localMaxima > localMinima && localMaximaPos > localMinimaPos)
            localDifference = localDifference > (localMaxima - localMinima) ? localDifference : (localMaxima - localMinima);

        if (localMinimaPos > localMaximaPos)
        {
            localMaxima = INT32_MIN;
            localMaximaPos = -1;
        }
    }

    if (prices[prices.size() - 1] >= prices[prices.size() - 2])
    {
        if (prices[prices.size() - 1] >= localMaxima)
        {
            localMaxima = prices[prices.size() - 1];
            localMaximaPos = prices.size() - 1;
        }
    }

    if (localMaximaPos == -1 || localMinimaPos == -1)
        return 0;

    return localDifference > (localMaxima - localMinima) ? localDifference : (localMaxima - localMinima);
}

TEST(max_profit, empty_array)
{
    vector<int> arr;
    ASSERT_EQ(maxProfit(arr), 0);
}

TEST(max_profit, min_before_max)
{
    vector<int> arr = { 1, 5, 7, 3, 6, 4 };
    ASSERT_EQ(maxProfit(arr), 6);

    arr = { 3, 3, 5, 0, 0, 3, 1, 4 };
    ASSERT_EQ(maxProfit(arr), 4);

    arr = { 2, 4, 11, 1, 7 };
    ASSERT_EQ(maxProfit(arr), 9);
}

TEST(max_profit, max_before_min)
{
    vector<int> arr = { 7, 1, 5, 3, 6, 4 };
    ASSERT_EQ(maxProfit(arr), 5);

    arr = { 2, 4, 1 };
    ASSERT_EQ(maxProfit(arr), 2);
}

TEST(max_profit, local_difference)
{
    vector<int> arr = { 3, 2, 6, 5, 0, 3 };
    ASSERT_EQ(maxProfit(arr), 4);

    arr = { 2, 1, 2, 0, 1 };
    ASSERT_EQ(maxProfit(arr), 1);
}

TEST(max_profit, multiple_extremas)
{
    vector<int> arr = { 2, 1, 2, 1, 0, 1, 2 };
    ASSERT_EQ(maxProfit(arr), 2);

    arr = { 4, 2, 4, 2, 5 };
    ASSERT_EQ(maxProfit(arr), 3);

    arr = { 1, 4, 1, 3 };
    ASSERT_EQ(maxProfit(arr), 3);

    arr = { 4, 1, 4, 3 };
    ASSERT_EQ(maxProfit(arr), 3);
}

TEST(max_profit, repeating_numbers)
{
    vector<int> arr = { 1, 1, 1, 1 };
    ASSERT_EQ(maxProfit(arr), 0);

    arr = { 2, 2, 5 };
    ASSERT_EQ(maxProfit(arr), 3);
}

TEST(max_profit, descending_order)
{
    vector<int> arr = { 7, 6, 4, 3, 1 };
    ASSERT_EQ(maxProfit(arr), 0);
}

TEST(max_profit, extrema_at_extremes)
{
    vector<int> arr = { 1, 2, 4 };
    ASSERT_EQ(maxProfit(arr), 3);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
