#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool exist(vector< vector<char> >& board, string word) {
        this->word = word;
        this->board = board;
        this->M = board.size();
        this->N = board[0].size();
        for (int i = 0;i < M;i++) {
            for (int j = 0;j < N;j++) {
                if (dfs(0, i, j)) return true;
            }
        }
        return false;
    }

private:
    int M;
    int N;
    string word;
    vector< vector<char> > board;
    bool dfs(int index, int row, int col) {
        if (this->board[row][col] != this->word[index]) return false;
        if (index >= this->word.size() - 1) return true;
        char cur = board[row][col];
        cout << cur << endl;
        board[row][col] = '*';
        bool res = false;
        if (row > 0) res = dfs(index + 1, row - 1, col);
        if (!res && row < this->M - 1) res = dfs(index + 1, row + 1, col);
        if (!res && col > 0) res = dfs(index + 1, row, col - 1);
        if (!res && col < this->N - 1) res = dfs(index + 1, row, col + 1);
        board[row][col] = cur;
        return res;
    }
};

int main() {
    char v1[] = {'A','B','C','E'};
    char v2[] = {'S','F','C','S'};
    char v3[] = {'A','D','E','E'};
    
    vector< vector<char> > vv(3);	
	for(int i=0;i<3;i++) 
        vv[i].resize(4);
    
    vv[0].insert(vv[0].begin(), v1, v1 + 4);
    vv[1].insert(vv[1].begin(), v2, v2 + 4);
    vv[2].insert(vv[2].begin(), v3, v3 + 4);

    char v4[] = {'a'};
    vector< vector<char> > vv2(1);
    vv2[0].insert(vv2[0].begin(), v4, v4 + 1);

    Solution s;
    bool res = s.exist(vv2, "a");
    cout << "end" << res << endl;
    return 0;
}