class Solution {
public:
    int SumSquare(int n) {
        int sum = 0;
        while(n) {
            sum += (n%10)*(n%10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int head = n, tail = n;
        while (true) {
            head = SumSquare(SumSquare(head));
            tail = SumSquare(tail);
            if (head==tail) break;
        }
        return head==1;
    }
};