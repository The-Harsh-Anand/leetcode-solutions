class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        unordered_map<string,int> depthMap;
        vector<vector<string>> ans;
        if (!wordset.contains(endWord))
            return {};

        // BFS Traversal
        queue<string> q;
        q.push(beginWord);
        depthMap[beginWord] = 1;
        wordset.erase(beginWord);

        int i, n = beginWord.length(), changes = 1;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string word = q.front();
                int level = depthMap[word];
                q.pop();

                if(word==endWord) break;

                for (i = 0; i < n; i++) {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if (wordset.contains(word)) {
                            wordset.erase(word);
                            q.push(word);
                            depthMap[word] = level+1;
                        }
                    }
                    word[i] = original;
                }
            }
        }

        //Using DFS to find all the paths
        vector<string> seq = {endWord};
        dfs(depthMap,ans,seq,beginWord,endWord);
        return ans;
    }
    void dfs(unordered_map<string,int>& depthMap, vector<vector<string>>& ans, vector<string>& seq, string beginWord, string word) {
        if(word==beginWord) {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }

        int levels = depthMap[word],i;
        for(i=0;i<word.size();i++) {
            char original = word[i];
            for(char c='a';c<='z';c++) {
                word[i] = c;
                if(depthMap[word] && depthMap[word]+1==levels) {
                    seq.push_back(word);
                    dfs(depthMap,ans,seq, beginWord, word);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
};