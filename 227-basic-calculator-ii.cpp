class Solution {
public:
    int calculate(string s) {
        vector<char> op;
        vector<int> num;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == ' ')
                continue;
            if (!isdigit(ch)) {
                op.push_back(s[i]);
                continue;
            } else {
                num.push_back(sumNumber(i, s));
                if (!op.empty() && (op.back() == '*' || op.back() == '/')) {
                    int b = num.back(); num.pop_back();
                    int a = num.back(); num.pop_back();
                    num.push_back(calcWithOp(a, b, op.back()));
                    op.pop_back(); 
                }
            }
        }
        int ans = num[0];
        for (int i = 0; i < op.size(); i++)
            ans = calcWithOp(ans, num[i + 1], op[i]);
        return ans;
    }
private :
    int sumNumber(int& i, string& s) {
        int n = 0;
        while (i < s.size() && isdigit(s[i])) {
            n = n * 10 + s[i] - '0';
            i++;
        }
        i--;
        return n;
    }
    int calcWithOp(int a, int b, char op) {
        switch (op) {
            case '+' : return a + b;
            case '-' : return a - b;
            case '*' : return a * b;
            case '/' : return a / b;
        }
    }
};