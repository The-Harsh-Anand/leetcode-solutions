class Solution {
public:
    int ladderLength(string beginWord, string endWord,vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        if (!wordset.contains(endWord))
            return 0;

        // BFS Traversal
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        wordset.erase(beginWord);

        int i, n = beginWord.length(), changes = 1;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string word = q.front().first;
                int level = q.front().second;

                q.pop();
                if(word==endWord) return level;

                for (i = 0; i < n; i++) {
                    char k = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if (wordset.contains(word)) {
                            wordset.erase(word);
                            q.push({word, level + 1});
                        }
                    }
                    word[i] = k;
                }
            }
        }
        return 0;
    }
};