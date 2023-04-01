#include <bits/stdc++.h>

// #include <atcoder/all>

using namespace std;
// using namespace atcoder;

int H, W;
long long Maze[11][11];

int main()
{
    // 入力
    cin >> H >> W;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            cin >> Maze[i][j];

    // 初期化（右への移動を0、下への移動を1とする）
    int moves[20], l = H + W - 2;
    int Answer = 0;
    for (int i = 1; i <= l; i++)
    {
        if (i <= W - 1)
        {
            moves[i] = 0;
        }
        else
        {
            moves[i] = 1;
        }
    }

    // 探索（moves: "00...11"からmoves: "11..00"までのパターンを全探索する）
    do
    {
        int x = 1, y = 1;
        set<int> S;
        S.insert(Maze[y][x]);

        for (int i = 1; i <= l; i++)
        {
            if (moves[i])
            {
                y++;
            }
            else
            {
                x++;
            }
            S.insert(Maze[y][x]);
        }

        if (S.size() == l + 1)
            Answer++;
    } while (next_permutation(moves + 1, moves + l + 1));

    // 出力
    cout << Answer << endl;
    return 0;
}