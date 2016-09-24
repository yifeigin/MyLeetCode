class Solution {
public:
    string reverseVowels(string s) {
       int i=0;
       int j=s.length()-1;
       string vowels="aeiouAEIOU";
       while(j>i) {
           while (vowels.find(s[i])==string::npos && i<j) i++;
           while (vowels.find(s[j])==string::npos && i<j) j--;
           swap(s[i], s[j]);
           i++;
           j--;
       }
       return s;
    } 
};