#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int bfs(vector<vector<int>> &horizontal, vector<vector<int>> &vertical, vector<pair<int, int>> &prev) {
    if (prev.size() == 4) {
        return 1;
    }
    pair<int, int> curr = prev[prev.size() - 1];
    int total = 0;
    for (int i : horizontal[curr.first]) {
        pair<int, int> temp(curr.first, i);
        // cout << curr.first << curr.second << "!!" << endl;
        if (prev.end() == find(prev.begin(), prev.end(), temp)) {
            prev.push_back(temp);
            total += bfs(horizontal, vertical, prev);
            prev.pop_back();
        }
    }
    for (int i : vertical[curr.second]) {
        pair<int, int> temp(i, curr.second);
        if (prev.end() == find(prev.begin(), prev.end(), temp)) {
            prev.push_back(temp);
            total += bfs(horizontal, vertical, prev);
            prev.pop_back();
        }
    }
    return total;
}
int main() {
    int t;
    cin >> t;
    for (int a = 0; a < t; a++) {
        int r, c;
        cin >> r >> c;
        vector<vector<char>> layout(r, vector<char>(c));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> layout[i][j];
            }
        }
        vector<vector<int>> horizontal(r, vector<int>());
        vector<vector<int>> vertical(c, vector<int>());
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (layout[i][j] == '.') {
                    horizontal[i].push_back(j);
                    vertical[j].push_back(i);
                }
            }
        }
        // for (int i = 0; i < r; ++i) {
        //     for (int j = 0; j < c; ++j) {
        //         cout << layout[i][j];
        //     }
        // }
        int result = 0;
        vector<pair<int, int>> prev;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (layout[i][j] == '.') {
                    prev.push_back(pair<int, int>(i, j));
                    result += bfs(horizontal, vertical, prev);
                    prev.pop_back();
                }
            }
        }
        cout << result << endl;
    }
}
