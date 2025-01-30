#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode{
    string word;
    TrieNode* next[26];
};

/* Word Search II
 *
 * 1. Create a private class
 * 2. Create backtrack
 * 3. Create findWords
 * 4. Create buildTrie
 */

class Solution {
// Initialize parameter TrieNode* root
private:
    TrieNode* root;

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>res;
        buildTrie(words);
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                backtrack(board, res, i, j, board.size() - 1, board[0].size() - 1, root);
        return res;
    }


    void backtrack(vector<vector<char>>& board, vector<string>& res, int r, int c, int numRows, int numCol, TrieNode* p){
        if(r < 0 || c < 0 || r > numRows || c > numCol || board[r][c] == '0'|| !p->next[board[r][c] - 'a']) return;
        p = p->next[board[r][c] - 'a'];
        if(p->word.size() > 0){
            res.push_back(p->word);
            p->word = "";
        }
        char tmp = board[r][c];
        board[r][c] = '0';
        backtrack(board, res, r - 1, c, numRows, numCol, p);
        backtrack(board, res, r + 1, c, numRows, numCol, p);
        backtrack(board, res, r, c + 1, numRows, numCol, p);
        backtrack(board, res, r, c - 1, numRows, numCol, p);
        board[r][c] = tmp;
    }

    void buildTrie(vector<string>& words){
        root = new TrieNode();
        for(auto x: words){
            TrieNode* p = root;
            for(auto c: x){
                if(!p->next[c - 'a']) p->next[c - 'a'] = new TrieNode();
                p = p->next[c - 'a'];
            }
            p->word = x;
        }
    }
};
