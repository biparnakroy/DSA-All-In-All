class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 0;
        for (int i = 0; i < digits.size(); i++) {
            int temp =0;
            if (i==0)
                temp = digits[i] + 1+carry;
            else
                temp = digits[i] +carry;
            carry = temp / 10;
            temp=temp%10;
            digits[i] = temp;
        }
        if(carry>0) digits.push_back(carry);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};