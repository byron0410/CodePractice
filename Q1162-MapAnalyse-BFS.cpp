
#include <iostream>
#include <vector>
#include <queue>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

class Solution
{
public:
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, n;
    struct searchQueue
    {
        int x;
        int y;
        int steps;
    };
    bool assistArray[101][101];
    vector<vector<int>> copyOfSourse;

    int findLand(int x, int y)
    {
        memset(assistArray, 0, sizeof assistArray);
        queue<searchQueue> sQueue;
        sQueue.push({x, y, 0});
        assistArray[x][y] = 1;
        while (!sQueue.empty())
        {
            auto firstOfQueue = sQueue.front();
            sQueue.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = firstOfQueue.x + dx[i], ny = firstOfQueue.y + dy[i];
                if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1)
                    continue;
                if (!assistArray[nx][ny])
                {
                    assistArray[nx][ny] = 1;
                    sQueue.push({nx, ny, firstOfQueue.steps + 1});
                    if (copyOfSourse[nx][ny])
                        return firstOfQueue.steps + 1;
                }
            }
        }
        return -1;
    }

    int maxDistance(vector<vector<int>> &grid)
    {
        copyOfSourse = grid;
        n = grid.size();
        int dis = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0)
                {
                    dis = MAX(dis, findLand(i, j));
                }
        return dis;
    }
};