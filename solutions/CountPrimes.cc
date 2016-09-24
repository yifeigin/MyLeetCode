class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        int counter = n>>1;
        int root = sqrt(n-1);
        bool* count = new bool[n];
        for (int i=3; i<=root; i+=2) if (!count[i]) for (int j=i*i, s=i<<1;j<n;j+=s) if (!count[j]) { count[j]=1;counter--;}
        delete[] count;
        return counter;
    }
   
};