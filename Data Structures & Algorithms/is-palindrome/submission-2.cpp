class Solution {
public:
    bool isPalindrome(string s) {
    
        int n = s.size();
        

        int i = 0, j = s.size()-1;

        while(i < j){
            while(!(((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i]>= '0') && (s[i] <= '9')) || ((s[i] >= 'A') && (s[i] <= 'Z')))){
                i++;
            }
            while(!(((s[j] >= 'a') && (s[j] <= 'z')) || ((s[j]>= '0') && (s[j] <= '9')) || ((s[j] >= 'A') && (s[j] <= 'Z')))){
                j--;
            }
            if(i < j){
                if((s[i] != s[j]) && (tolower(s[i])!=tolower(s[j])))return false;
                i++;
                j--;
            }

        }

        return true;
    }
};
