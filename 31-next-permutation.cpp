class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int pos = -1;
        int n = num.size();
        if (n <= 1)
            return ;
        for (int i = n - 2; i >= 0; i--) {
            if (num[i + 1] > num[i]) {
                pos = i;
                break;
            }
        }
		if (pos == -1) {
			reverse(num.begin(), num.end());
			return ;
		}
        
        int id = -1;
        for (int i = n - 1; i > pos; i--) {
            if (num[i] > num[pos]) {
                id = i;
                break;
            }
        }
        swap(num[pos], num[id]);
        
        reverse(num.begin() + pos + 1, num.end());
    }
};
