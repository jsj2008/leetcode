/*
 参考网上神代码，代码风格非常优美
 首先要考虑溢出，将stol之后，再转回来，判断是否可逆
 其次是乘法优先级的考虑
 */
class Solution {
public:
    // cur: {string} expression generated so far.
    // pos: {int}    current visiting position of num.
    // cv:  {long}   cumulative value so far.
    // pv:  {long}   previous operand value.
    // op:  {char}   previous operator used.
    void dfs(std::vector<string>& res, const string& num, const int target,
             string cur, int pos, const long cv, const long pv, const char op) {
        if (pos == num.size() && cv == target) {
            res.push_back(cur);
            return;
        }
        for (int i = pos + 1; i <= num.size(); ++i) {
            string t = num.substr(pos, i - pos);
            long now = stol(t);
            if (to_string(now).size() != t.size())
                continue;  // avoid long stack overflow
            dfs(res, num, target, cur + '+' + t, i, cv + now, now, '+');
            dfs(res, num, target, cur + '-' + t, i, cv - now, now, '-');
            dfs(res, num, target, cur + '*' + t, i,
                (op == '-') ? cv + pv - pv * now
                : ((op == '+') ? cv - pv + pv * now : pv * now),
                pv * now, op);
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.empty()) return res;
        for (int i = 1; i <= num.size(); ++i) {
            string s = num.substr(0, i);
            long cur = stol(s);
            if (to_string(cur).size() != s.size()) continue;
            dfs(res, num, target, s, i, cur, cur, '#');
        }
        return res;
    }
};