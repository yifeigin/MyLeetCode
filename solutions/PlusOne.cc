class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool addone = true;
        int counter = digits.size()-1;
        while (counter>=0 && addone) {
              if (digits[counter]==9) {
                digits[counter]=0;
                counter--;
              }
              else {
                digits[counter]++;
                addone = false;
                return digits;
              }          
        }
        if (counter==-1) {
            digits.reserve(digits.size() + 1);
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};