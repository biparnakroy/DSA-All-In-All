class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int tw = 0 ;

        int n = bills.size();
        for(int i =0;i<n;i++){
            if(bills[i]==5){
                five++;
            }
            if(bills[i]==10){
                if(five>0){
                    five--;
                    ten++;
                }
                else return false;
            }
            if(bills[i]==20){
                if(ten>0 && five>0){
                    ten--;
                    five--;
                    tw++;
                }else if(five>2){
                    five=five-3;
                    tw++;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};