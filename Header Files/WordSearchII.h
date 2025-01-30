/*
 * WordSearchII.h
 *
 *  Created on: Jan 29, 2025
 *      Author: shill
 */

#ifndef WordSearchII.h
#define WordSearchII.h

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode{
    string word;
    TrieNode* next[26];
};

// Solution 2
// Add Trie, inspired by Trie implementation in this [thread](https://discuss.leetcode.com/topic/13463/maybe-the-code-is-not-too-much-by-using-next-26-c).
// Runtime: 35 ms. (Beats 95.58% of C++ solutions.)

/* struct TrieNode
 *
 * Initialize trie node
 * Parameters:
 * 	string word
 * 	TrieNode* next[26];
 *
 */
class Solution {
// Initialize parameter TrieNode* root
private:
    TrieNode* root;

/*
 * findWords
 * 	Parameters: address for the board, address for words
 * 	1. Loop through the board
 * 	2. Enact backtrack
 * 	3. Return the result
 */
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words);

    /*
     * backtrack
     * Parameters: address for the board, vector for result, row number, column number, numRows, numCol, pointer to TrieNode
     * 1. Check if the row exists,
     * 		if the column exists,
     * 		if the row is more than the amount of rows,
     * 		if the column is more than the amount of columns,
     * 		if the pointer can't move any further
     * 2. Create a temporary board
     * 3. Set the row and column equal to 0
     * 4. Enact backtrack on the last row, next row, last column, and last column
    */
    void backtrack(vector<vector<char>>& board, vector<string>& res, int r, int c, int numRows, int numCol, TrieNode* p);

    /*
     * buildTrie
     * Parameter: string vector words
     * 1. Create root TrieNode
     * 2. Look through the words
     * 3. Loop through each word
     * 4. If the pointer can't move further, create a new TrieNode
     * 5. Set the pointer equal to the new TrieNode
     */
    void buildTrie(vector<string>& words);
};




#endif /* WordSearchII.h */
