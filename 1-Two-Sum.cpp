class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        
		vector<int> ans;
        vector< pair<int, int> > p;

        for(int i=0; i<numbers.size(); i++)
            p.push_back(make_pair(numbers[i], i + 1));
        sort(p.begin(), p.end());
        for(int i=0; i<p.size(); i++) {
            int other = target - p[i].first;
            std::vector< pair<int, int> >::iterator it = lower_bound(p.begin() + i + 1, p.end(), make_pair(other,0));
            if( it == p.end() )
                continue;
            int pos = it - p.begin();
            if( p[pos].first != other )
                continue;
            ans.push_back(p[i].second);
            ans.push_back(p[pos].second);
            if( ans[0] > ans[1] )
                swap(ans[0], ans[1]);
            break;
        }
	    return ans;
    }
};
