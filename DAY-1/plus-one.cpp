class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
            int n = digits.size();
            for(int i =0;i<n;i++){
                if(digits[i]<9){
                    digits[i]+=1;
                    break;
                }
                else{
                    digits[i]=0;
                }
            }
            if(digits[n-1]==0) digits.push_back(1);
            reverse(digits.begin(),digits.end());
    
        return digits;
    }
};