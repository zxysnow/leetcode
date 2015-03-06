class Solution {
public:
    string intToRoman(int num) {
        string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};    
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans;
        int p = 0;
        while (num) {
            while (num >= value[p]) {
                num -= value[p];
                ans += symbol[p];
            }
            p++;
        }
        return ans;
    }
};
