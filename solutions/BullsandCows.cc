class Solution {
public:
    string getHint(string secret, string guess) {
       map<char, int> counter;
       int bulk = 0;
       int cow = 0;
       for (int i=0; i<secret.size(); i++) {
           if (secret[i]==guess[i]) {
               guess[i]='.';
               bulk++;
           }
           else counter[secret[i]]++;
       }
       for (int i=0; i<guess.size(); i++) {
           if(guess[i]!='.' && counter[guess[i]]>0) {
               cow++;
               counter[guess[i]]--;
           }
       }
       return to_string(bulk)+"A"+to_string(cow)+"B";
       
    }
};