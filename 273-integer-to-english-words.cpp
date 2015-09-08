class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        string ans;
        vector<string> vans;
        for (int i = 0; i < number.size(); i++) {
            int now = num / number[i];
            if (now != 0) {
                toString(now, vans);
                vans.push_back(name[i]);
            }
            num %= number[i];
        }
        for (int i =0; i < vans.size(); i++) {
            if (vans[i] != "") {
                ans += ans == "" ? vans[i] : ' ' + vans[i];
            }
        }
        return ans;
    }
private :
    vector<string> name = {"Billion", "Million", "Thousand", ""};
    vector<int> number = {1000000000, 1000000, 1000, 1};
    vector<string> small = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> decade = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    void toString(int num, vector<string> &vans) {
        vans.push_back(Hundred(num / 100));
        num %= 100;
        if (num != 0 && num < 20) {
            vans.push_back(small[num]);
            return ;
        }
        vans.push_back(decade[num / 10]);
        vans.push_back(small[num % 10]);
    }
    string Hundred(int num) {
        if (num == 0)
            return "";
        return small[num] + " Hundred";
    }
};