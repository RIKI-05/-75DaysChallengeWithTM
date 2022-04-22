class Twitter {
public:
    unordered_map<int,unordered_map<int,int>>m1;
    int x;
    set<pair<int, pair<int,int>>>s1;
    Twitter() {
        x = 1;
    }
    void postTweet(int u, int t) {
        s1.insert({x++ , {u, t} });
    }
    
    vector<int> getNewsFeed(int u) {
        int k = 10;
        vector<int>v;
        for(auto it = s1.rbegin(); it!= s1.rend() ; it++)
        {
            if((it->second.first == u) || (m1[u][it->second.first] == 1))
            {
                k--;
                v.push_back(it->second.second);
            }
            if(k== 0)
                break;
        }
        return v;
    }
    
    void follow(int f, int F) {   
        m1[f][F] = 1; 
    }
    
    void unfollow(int f, int F) {
        m1[f][F] = 0;
    }
};