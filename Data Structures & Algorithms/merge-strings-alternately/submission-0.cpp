class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        int smallest=(n1<=n2)? n1:n2;
        string str="";
        int j=0;
        for(int i=0;i<smallest;i++){
            str.push_back(word1[i]);
            str.push_back(word2[i]);
            j=j+1;
        }
        if(n1<n2){
            for(int i=j;i<n2;i++){
                str.push_back(word2[i]);
            }
        }
        else{
            for(int i=j;i<n1;i++){
                str.push_back(word1[i]);
            }
        }
        return str;

    }
};