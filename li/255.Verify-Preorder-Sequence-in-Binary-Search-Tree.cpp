// Time O(n)
// Space O(H)
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if (!n) return true;
        
        stack<int>stk;
        int parent = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && stk.top() < preorder[i]) {
                parent = stk.top();
                stk.pop();
            }
            if (parent >= preorder[i])
                return false;
            stk.push(preorder[i]);
        }
        
        return true;
    }
};

// Time O(n*H)
// Space O(H)
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) 
    {
        return DFS(preorder,0,preorder.size()-1);
    }
    
    bool DFS(vector<int>& preorder, int start, int end)
    {
        if (start >= end) return true;
        
        int root=preorder[start];
        int i = start+1;
        while (i<=end && preorder[i]<root) i++;
                
        for (int j=i; j<=end; j++)        
        {
            if (preorder[j]<=root) return false;
        }
        return DFS(preorder,start+1,i-1)&&DFS(preorder,i,end);
    }
};
