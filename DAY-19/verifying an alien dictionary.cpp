class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int>m;
        int idx=0;
        for(auto x : order){
            m[x] = idx;
            idx++;
        }
        for(int i =0;i<words.size()-1;i++){
            string curr = words[i];
            string next = words[i+1];
            int len = (curr.length()>next.length())?next.length():curr.length();
            if(curr.length()!=len ){
                string s = curr.substr(0,len);
                // cout<<s<<endl;
                if(s==next) return false;
            }
            
            for(int j=0;j<len;j++ ){
                if(m[curr[j]]>m[next[j]])return false;
                if(m[curr[j]]<m[next[j]])break;
            }
        }
        
        return true;
    }
}; 