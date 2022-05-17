
class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        stack<int>s;
        vector<int>v(n,-1);
        for(int i =n-1;i>=0;i--){
            while(!s.empty() and  s.top()>=arr[i])s.pop();
            
            v[i]=(s.empty())?-1:s.top();
            s.push(arr[i]);
            
        }
        
        return v;
    } 
};
