class MyCalendarThree {
public:
    map<int,int> m;
    MyCalendarThree() {

    }
    int traverse(){
        int res = 0;
        int k = 0;
        for(auto &e : m){
            k += e.second;
            res = max(res, k);
        }
        return res;
    }
    int book(int start, int end) {
        m[start] += 1;
        m[end] -= 1;
        return traverse();
    }
};
