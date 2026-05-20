class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int i=0;
        while(i<path.length()){
            if(path[i]=='/'){
                i++;
                continue;
            }
            string str="";
            while(i<path.length() && path[i]!='/'){
                str+=string(1,path[i]);
                i++;
            }
            if(str==".") continue;
            else if(str==".."){
                if(!s.empty()) s.pop();
            }
            else{
                s.push(str);
            }
        }
        vector<string> temp;
        while(!s.empty()) {
            temp.push_back(s.top());
            s.pop();
        }
        reverse(temp.begin(), temp.end());
        string res = "";
        for(string dir : temp) {
            res += "/" + dir;
        }
        return res.empty() ? "/" : res;

    }
};