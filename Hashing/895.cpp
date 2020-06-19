class FreqStack {
public:
    int m;
    unordered_map<int, stack<int>> freq;
    unordered_map<int, int> element;
    FreqStack() {
        m = 0;
    }

    void push(int x) {
        element[x]++;
        freq[element[x]].push(x);
        m = max(m, element[x]);
    }

    int pop() {
        int res = freq[m].top();
        freq[m].pop();
        if(freq[m].size() == 0)
            m--;
        element[res]--;
        return res;
    }
};
