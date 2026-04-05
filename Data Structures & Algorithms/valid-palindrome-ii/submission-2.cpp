class Solution {
public:
    bool isPalindrome(string s,int l,int r) {
        while(l<r){
            if(!isalnum(s[l])){
                l++;
                continue;
            }
            else if(!isalnum(s[r])){
                r--;
                continue;
            }
            else if(tolower(s[l])!=tolower(s[r])) return false;
            else{
                l++;
                r--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0;
        int r=s.length()-1;
        int op=0;
        while(l<r){
            if(!isalnum(s[l])){
                l++;
                continue;
            }
            else if(!isalnum(s[r])){
                r--;
                continue;
            }
            else if(tolower(s[l])!=tolower(s[r])){
                int l1=l;
                int r1=r;
                return isPalindrome(s,l1+1,r1) || isPalindrome(s,l1,r1-1);
            }
            l++;
            r--;
        }
        return true;
    }
};