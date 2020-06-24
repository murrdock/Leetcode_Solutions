class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n = deck.size();
        int i = n-1;
        deque<int> dq;
        dq.push_back(deck[i]);
        while(i > 0){
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(deck[--i]);
        }
        return vector<int>(dq.begin(),dq.end());
    }
};
