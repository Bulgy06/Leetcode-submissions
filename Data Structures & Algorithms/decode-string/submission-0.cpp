class Solution {
public:
    string decodeString(string s) {
        stack<string> decode;
        for(int i=0;i<s.length();i++){
            if(s[i]!=']') decode.push(string(1,s[i]));
            else{
                string substr="";
                while(decode.top()!="[" && !decode.empty()){
                    substr=decode.top()+substr;
                    decode.pop();
                }
                decode.pop();
                string k="";
                while(!decode.empty() && isdigit(decode.top()[0])){
                    k=decode.top()+k;
                    decode.pop();
                }
                int repeatCount=stoi(k);
                string repeat="";
                for(int j=0;j<repeatCount;j++){
                    repeat+=substr;
                }
                decode.push(repeat);
            }
        }
        string res="";
        while(!decode.empty()){
            res=decode.top()+res;
            decode.pop();
        }
        return res;
        
    }
};