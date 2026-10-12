#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    TreeNode* root;
    
    TreeNode* insert(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
        
        if (val < node->val) {
            node->left = insert(node->left, val);
        } else if (val > node->val) {
            node->right = insert(node->right, val);
        }
        
        return node;
    }
    
    void findKthLargest(TreeNode* node, int& cnt, int& result) {
        if (node == nullptr || cnt <= 0) {
            return;
        }
        
        // Traverse right subtree first (larger values)
        findKthLargest(node->right, cnt, result);
        
        // Process current node
        cnt--;
        if (cnt == 0) {
            result = node->val;
            return;
        }
        
        // Traverse left subtree (smaller values)
        findKthLargest(node->left, cnt, result);
    }
    
public:
    Solution() : root(nullptr) {}
    
    void buildBST(int values[], int n) {
        for (int i = 0; i < n; i++) {
            root = insert(root, values[i]);
        }
    }
    
    int getKthLargest(int cnt) {
        int result = -1;
        findKthLargest(root, cnt, result);
        return result;
    }
    
    ~Solution() {
        // Clean up memory (optional for this problem)
    }
};

int main() {
    int values[7];
    int cnt;
    
    // Read 7 BST node values
    for (int i = 0; i < 7; i++) {
        cin >> values[i];
    }
    
    // Read the count for kth largest
    cin >> cnt;
    
    Solution sol;
    sol.buildBST(values, 7);
    
    int result = sol.getKthLargest(cnt);
    cout << result << endl;
    
    return 0;
}