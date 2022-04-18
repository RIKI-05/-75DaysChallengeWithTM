class Solution {
public:
    double myPow(double x, int n) {
        if(n==INT_MIN)//edge case;
        {
            if(x>1) return 0;
            else return 1;
        }
        if(n>=0)
        {
            if(n==0) return 1;
            if(n&1)
            return x*myPow(x,n-1); 
            else
            return myPow(x*x,n/2);
        }
        else
        {  
            if(n!=INT_MIN)
            n = -1*n;
            if(n==0) return 1;
            if(n&1)
            return (1/x)*myPow(1/x,n-1);
            else
            return myPow(1/(x*x),n/2);
        }
    }
};

