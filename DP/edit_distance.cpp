class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word2.length() < word1.length())
           swap(word1,word2);

        vector<int> prev(word2.length()+1);
        vector<int> T(word2.length()+1);
        for(int i = 0; i < prev.size(); i++)
            prev[i] = i;
        for(int j = 0; j < word1.length(); j++){
            T[0] = j+1;
            for(int i = 1; i < T.size(); i++){
                if(word1[j] == word2[i-1])
                    T[i] = prev[i-1];
                else
                    T[i] = min(T[i-1], min(prev[i], prev[i-1])) + 1;
            }
            prev.swap(T);
        }
        return prev[T.size()-1];
    }
};
