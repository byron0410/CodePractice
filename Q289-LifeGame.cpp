// 周围8个：<2或>3-死亡; 2~3-存活; ==3-复活
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int16_t n = board.size();
        int16_t m = board.at(0).size();
        int16_t dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        vector<vector<int>> copy;
        copy = board;
        for (int16_t i = 0; i < n; ++i)
            for (int16_t j = 0; j < m; ++j)
            {
                int16_t count = 0;
                for (int16_t k = 0; k < 8; ++k)
                {
                    int16_t nx = i + dx[k], ny = j + dy[k];
                    if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1)
                        continue;
                    if (copy[nx][ny])
                        ++count;
                }
                if (count < 2 || count > 3)
                    board[i][j] = 0;
                else if (count == 3)
                    board[i][j] = 1;
            }
    }
};