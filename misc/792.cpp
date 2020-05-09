class Solution {
public:
    int numMatchingSubseq(const string& S, const vector<string>& words)
    {
        int ret = 0;
        for (const string& word : words)
        {
            bool matched = true;
            size_t i = 0;
            for (const char ch : word)
            {
                i = S.find_first_of(ch, i);
                if (i == string::npos)
                {
                    matched = false;
                    break;
                }
                ++i;
            }
            if (matched)
            {
                ++ret;
            }
        }
        return ret;
    }
};
