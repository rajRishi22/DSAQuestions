// 1.Ans
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int j = 1; j <= n; j++)
            dp[0][j] = dp[0][j-1]+s2[j-1];
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0]+s1[i-1];
            for (int j = 1; j <= n; j++) {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1]);
            }
        }
        return dp[m][n];
    }
};

// 2.Ans

    bool checkValidString(string s) {
        int cmin = 0, cmax = 0;
        for (char c : s) {
            if (c == '(')
                cmax++, cmin++;
            if (c == ')')
                cmax--, cmin = max(cmin - 1, 0);
            if (c == '*')
                cmax++, cmin = max(cmin - 1, 0);
            if (cmax < 0) return false;
        }
        return cmin == 0;
    }

// 3.Ans

class Solution {
public:
    bool checkValidString(string s) {

      int length = s.length() - 1;
int openCount = 0, closedCount = 0;
for (int i = 0; i <= length; i++)
{
	if (s[i] == '*' || s[i] == '(') openCount++;
	else openCount--;
	if (s[length - i] == '*' || s[length - i] == ')') closedCount++;
	else closedCount--;
	if (openCount < 0 || closedCount < 0) return false;
}
return true;
        
    }
};

// 4.Ans

class Solution {
public:
    void preorder(TreeNode* root, string &ans){
        if(root==NULL) return;

        ans += to_string(root->val);
        if(root->left==NULL && root->right==NULL) return;

        ans.push_back('(');
        preorder(root->left, ans);
        ans.push_back(')');
        if(root->right) ans.push_back('(');
        preorder(root->right, ans);
        if(root->right) ans.push_back(')');
    }

    string tree2str(TreeNode* root) {
        string ans;
        preorder(root, ans);
        return ans;
    }
};

// 5.Ans
int compress(vector<char>& chars) {
	int i = 0;
	for(int j = 1, count = 1; j <= chars.size(); j++, count++) {
		if(j == chars.size() || chars[j] != chars[j - 1]) {
			chars[i++] = chars[j - 1];  
			if(count >= 2) 
				for(char digit : to_string(count)) 
					chars[i++] = digit;
			count = 0;
		}
	}
	return i;
}

// 6.Ans

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        
        if(s.size() < p.size()) return {};
        
        vector<int> freq_p(26,0);
        vector<int> window(26,0);
        
        for(int i=0;i<p_len;i++){
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        
        vector<int> ans;
        if(freq_p == window) ans.push_back(0);
        
        for(int i=p_len;i<s_len;i++){
            window[s[i-p_len] - 'a']--;
            window[s[i] - 'a']++;
            
            if(freq_p == window) ans.push_back(i-p_len+1);
        }
        return ans;
    }
};

// 7.Ans

class Solution {
public:
    string decodeString(const string& s, int& i) {
        string res;
        
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                    
                i++; // '['
                string t = decodeString(s, i);
                i++; // ']'
                
                while (n-- > 0)
                    res += t;
            }
        }
        
        return res;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};

// 8.Ans

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length();
        if(s == goal){
            set<char> temp(s.begin(), s.end());
            return temp.size() < goal.size(); 
        }

        int i = 0;
        int j = n - 1;

        while(i < j && s[i] == goal[i]){
            i++;
        }

        while(j >= 0 && s[j] == goal[j]){
            j--;
        }

        if(i < j){
            swap(s[i], s[j]);
        }

        return s == goal;
    }
};

