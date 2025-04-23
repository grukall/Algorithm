#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board(9, vector<int>(9));
vector<pair<int, int>> emptyCells;

bool row[9][10] = {false};
bool col[9][10] = {false};
bool block[9][10] = {false};

int getBlockIndex(int i, int j) {
    return (i / 3) * 3 + (j / 3);
}

bool solve(int idx) {
    if (idx == emptyCells.size()) return true;

    int i = emptyCells[idx].first;
    int j = emptyCells[idx].second;
    int blockIdx = getBlockIndex(i, j);

    for (int num = 1; num <= 9; num++) {
        if (!row[i][num] && !col[j][num] && !block[blockIdx][num]) {
            // Mark as used
            board[i][j] = num;
            row[i][num] = col[j][num] = block[blockIdx][num] = true;

            if (solve(idx + 1)) return true;

            // Backtrack
            board[i][j] = 0;
            row[i][num] = col[j][num] = block[blockIdx][num] = false;
        }
    }

    return false;
}

int main() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            int val = board[i][j];
            if (val == 0) {
                emptyCells.push_back({i, j});
            } else {
                row[i][val] = true;
                col[j][val] = true;
                block[getBlockIndex(i, j)][val] = true;
            }
        }

    solve(0);

    for (const auto &r : board) {
        for (int num : r)
            cout << num << ' ';
        cout << '\n';
    }

    return 0;
}
