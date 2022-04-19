int divide(int dividend, int divisor) {
        int result=0;
        bool negdiv=false;
        if(dividend<0)
        {
            negdiv=true;
            dividend=dividend*-1;
        }
        bool negdir=false;
        if(divisor<0)
        {
            negdir=true;
            divisor=divisor*-1;
        }
        //cout<<dividend<<" "<<divisor<<endl;
        long temp=0;
        long count=1;
        while(dividend>=divisor)
        {
            temp=divisor,count=1;
            while(temp<=dividend)
            {
                temp<<=1;
                count<<=1;
            }
           
            result+=count>>1;
            temp=temp>>1;
            dividend-=temp;
        }
        if(negdiv==negdir)
        {
            return result;
        }
        return -1*result;
    }