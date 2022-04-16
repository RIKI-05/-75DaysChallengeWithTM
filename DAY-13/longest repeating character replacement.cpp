class Solution {
class Solution {
public:
    int characterReplacement(string s, int k) {
    
    unordered_map<char, int> mp;
    
    int i=0;
    int j=0;
            
    int ans = 0;
    int n = s.length();
    
    int maxfreq = 0;
    
    while(j<n)
    {
        
        mp[s[j]]++;
                
        maxfreq = max(maxfreq, mp[s[j]]);
        
     
        int replacement = ((j-i+1) - maxfreq);
        
        if(replacement <= k)
        {
            ans = max(ans , j-i+1);
            j++;
        }
        else{
            
            mp[s[i]]--;
               i++;
               j++;
            
            
        }
        
        
    }
    
    return ans;
    
}
};