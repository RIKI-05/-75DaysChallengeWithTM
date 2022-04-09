class Solution {
public:
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        long long mod = 1000000007;
        hor.push_back(0);
        hor.push_back(h%mod);
        ver.push_back(0);
        ver.push_back(w%mod);
        
        sort(hor.begin(),hor.end());
        sort(ver.begin(),ver.end());
        
        int hdiff=0;
        int vdiff =0;
        for(int i=0;i<hor.size()-1;i++){
            int a = ((hor[i+1]%mod)-(hor[i]%mod))%mod;
            hdiff= max(hdiff,a);
        }

        for(int i=0;i<ver.size()-1;i++){

            int a = ((ver[i+1]%mod)-(ver[i]%mod))%mod;
            vdiff = max(vdiff,a);
        }
        
        
        int ans = (hdiff%mod)*(vdiff%mod)%mod;
        
        return ans;
    }
};