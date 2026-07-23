class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        if (!dict.count(endWord)) return ans;

        unordered_map<string, vector<string>> parents;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            int sz = q.size();
            unordered_set<string> levelVisited;
            for (int i = 0; i < sz; i++) {
                string word = q.front(); q.pop();
                string original = word;
                for (int j = 0; j < word.size(); j++) {
                    char old = word[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[j] = c;
                        if (dict.count(word) && !visited.count(word)) {
                            if (!levelVisited.count(word)) {
                                q.push(word);
                                levelVisited.insert(word);
                            }
                            parents[word].push_back(original);
                            if (word == endWord) found = true;
                        }
                    }
                    word[j] = old;
                }
            }
            for (auto &w : levelVisited) visited.insert(w);
        }

        if (found) {
            vector<string> path;
            path.push_back(endWord);
            dfs(endWord, beginWord, parents, path, ans);
        }
        return ans;
    }

    void dfs(string word, string beginWord, unordered_map<string, vector<string>>& parents,
             vector<string>& path, vector<vector<string>>& ans) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        for (auto &p : parents[word]) {
            path.push_back(p);
            dfs(p, beginWord, parents, path, ans);
            path.pop_back();
        }
    }
};
