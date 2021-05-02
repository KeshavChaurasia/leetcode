class Solution {
public:
    string addStrings(string num1, string num2) {
        int num1Length = num1.length()-1;
        int num2Length = num2.length()-1;
        int carry = 0;
        string finalSum = "";
        while(num1Length >= 0 || num2Length >= 0){
            int leftNum1 = num1Length >= 0 ? num1[num1Length] - '0' : 0;
            int leftNum2 = num2Length >= 0 ? num2[num2Length] - '0' : 0;
            int sum = (leftNum1 + leftNum2 + carry) % 10;
            carry = (leftNum1 + leftNum2 + carry) / 10;
            finalSum.push_back((char)sum+'0');
            num1Length--;
            num2Length--;
        }
        if(carry != 0){
            finalSum.push_back((char)carry+'0');
        }
        reverse(finalSum.begin(), finalSum.end());
        return finalSum;
    }
};