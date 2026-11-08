class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> result;
        string tmp1 = "";
        string tmp2 = "";
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i]) {
                if (tmp1!= "" && tmp2 != "") {
                    // push
                    result.push_back({tmp1, tmp2});
                    // reset
                    tmp1 = "";
                    tmp2 = "";
                }
                continue;
            }
            tmp1 += s1[i];
            tmp2 += s2[i];
        }

        if (tmp1!= "" && tmp2 != "") {
            // push
            result.push_back({tmp1, tmp2});
            // reset
            tmp1 = "";
            tmp2 = "";
        }

        return result;
    }
};