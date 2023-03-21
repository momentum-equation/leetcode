#include <vector>
#include <algorithm>
#include <iostream>

#include <gtest/gtest.h>

using namespace std;

#define testName shortest_path

vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges)
{
    if (redEdges.empty() && blueEdges.empty())
        return { -1 };

    if (redEdges.empty())
        return {blueEdges[0][0], blueEdges[0][1], -1};
    
    if (blueEdges.empty())
        return {redEdges[0][0], redEdges[0][1], -1};

    sort(redEdges.begin(), redEdges.end(), [](const vector<int>& e1, const vector<int>& e2){
        if (e1[0] == e2[0])
            return e1[1] < e2[1];

        if (e1[1] == e2[1])
            return e1[0] < e2[0];

        return e1[1] < e2[1] && e1[0] < e2[0];
    });

    sort(blueEdges.begin(), blueEdges.end(), [](const vector<int>& e1, const vector<int>& e2){
        if (e1[0] == e2[0])
            return e1[1] < e2[1];

        if (e1[1] == e2[1])
            return e1[0] < e2[0];

        return e1[1] < e2[1] && e1[0] < e2[0];
    });

    bool stopLoop = false;
    int count = 0;
    int bluePos = 0, redPos = 0;
    int tmpVal = blueEdges[0][0];
    int lastNodeRed = false;

    vector<int> path;

    for (int i = redPos; i < redEdges.size(); ++i)
    {
        if (stopLoop)
            break;

        for (int j = bluePos; j < blueEdges.size(); ++j)
        {
            if ((count / 2) + 1 == n)
            {
                stopLoop = true;
                break;
            }

            if (redEdges[i][1] == tmpVal && redEdges[i][0] != blueEdges[j][1] && !lastNodeRed)
            {
                path.push_back(redEdges[i][0]);
                path.push_back(redEdges[i][1]);
                path.push_back(blueEdges[j][1]);

                bluePos = j;
                tmpVal = redEdges[i][1];
                lastNodeRed = true;

                count += 3;
            }
            else if (blueEdges[j][1] == tmpVal && blueEdges[j][0] != redEdges[i][1] && lastNodeRed)
            {
                path.push_back(blueEdges[j][0]);
                path.push_back(blueEdges[j][1]);
                path.push_back(redEdges[i][1]);

                redPos = i;
                tmpVal = blueEdges[j][1];
                lastNodeRed = false;

                count += 3;
            }
        }
    }

    if (path.size() == 0)
    {
        return {redEdges[0][0], redEdges[0][1], -1};
    }

    return path;
}

TEST(testName, empty)
{
    vector<vector<int>> redEdges = {{0, 1}, {1, 2}, {0, 2}, {3, 4}};
    vector<vector<int>> blueEdges = {};

    ASSERT_EQ(vector<int>({0, 1, -1}), shortestAlternatingPaths(3, redEdges, blueEdges));

    redEdges.clear();
    blueEdges.clear();

    redEdges = {};
    blueEdges = {};

    ASSERT_EQ(vector<int>({-1}), shortestAlternatingPaths(3, redEdges, blueEdges));
}

TEST(testName, simple)
{
    vector<vector<int>> redEdges = {{0, 1}, {1, 2}, {0, 2}, {3, 4}};
    vector<vector<int>> blueEdges = {{1, 3}};

    ASSERT_EQ(vector<int>({0, 1, 3}), shortestAlternatingPaths(3, redEdges, blueEdges));

    redEdges.clear();
    blueEdges.clear();

    redEdges = {{0, 1}, {1, 2}, {0, 2}, {3, 4}};
    blueEdges = {{5, 6}};

    ASSERT_EQ(vector<int>({0, 1, -1}), shortestAlternatingPaths(3, redEdges, blueEdges));

    redEdges.clear();
    blueEdges.clear();

    redEdges = {{0, 1}, {1, 2}, {0, 2}};
    blueEdges = {{2, 3}, {1, 2}};

    ASSERT_EQ(vector<int>({0, 1, 2}), shortestAlternatingPaths(3, redEdges, blueEdges));

    redEdges.clear();
    blueEdges.clear();

    redEdges = {{0, 1}, {1, 2}, {2, 3}};
    blueEdges = {{2, 3}, {1, 2}};

    ASSERT_EQ(vector<int>({0, 1, 2, 3}), shortestAlternatingPaths(4, redEdges, blueEdges));

    redEdges.clear();
    blueEdges.clear();
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
