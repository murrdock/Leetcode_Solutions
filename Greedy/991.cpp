class Solution {
public:
    int brokenCalc(int X, int Y) {
        int y = Y;
        int steps = 0;
        while(y > X){
            if(y % 2) {
                y = y + 1;
            } else {
                y = y / 2;
            }
            steps++;
        }
        steps += X-y;
        return steps;
    }
};
