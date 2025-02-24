#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode{
    string word;
    TrieNode* next[26];
};

/* Word Search II (Runtime 262ms (beats 82.34%), Memory 19.02MB (beats 76.79%))
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
/*
 * findWords
 * 	Parameters: address for the board, address for words
 *  Return Type: vector<string>
 *  Method: backtrack
 * 	1. Loop through the board
 * 	2. Enact backtrack
 * 	3. Return the result
 */
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>res;
        buildTrie(words);
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                backtrack(board, res, i, j, board.size() - 1, board[0].size() - 1, root);
        return res;
    }

    /*
     * backtrack
     * Parameters: address for the board, vector for result, row number, column number, numRows, numCol, pointer to TrieNode
     * Return type: void
     * Method: recursion
     * 1. Check if the row exists,
     * 		if the column exists,
     * 		if the row is more than the amount of rows,
     * 		if the column is more than the amount of columns,
     * 		if the pointer can't move any further
     * 2. Create a temporary board
     * 3. Set the row and column equal to 0
     * 4. Enact backtrack on the last row, next row, last column, and last column
    */
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

    /*
     * buildTrie
     * Parameter: vector<string>& words
     * Return type: void
     * Method: pointer technique
     * 1. Create root TrieNode
     * 2. Look through the words
     * 3. Loop through each word
     * 4. If the pointer can't move further, create a new TrieNode
     * 5. Set the pointer equal to the new TrieNode
     */
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
