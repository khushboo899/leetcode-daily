class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> freq;

        // Step 1: Count frequency
        for (string word : words) {
            freq[word]++;
        }

        // Step 2: Buckets based on frequency
        vector<vector<string>> bucket(words.size() + 1);

        for (auto &it : freq) {
            bucket[it.second].push_back(it.first);
        }

        vector<string> ans;

        // Step 3: Start from highest frequency
        for (int f = words.size(); f >= 1; f--) {

            // Same frequency → alphabetical order
            sort(bucket[f].begin(), bucket[f].end());

            for (string word : bucket[f]) {

                ans.push_back(word);

                if (ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};