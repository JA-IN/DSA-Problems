/* Structure of binary tree node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int DFS(Node* root, int& ans) {

        if (root == nullptr)
            return INT_MAX;

        int leftMin = DFS(root->left, ans);
        int rightMin = DFS(root->right, ans);

         // Minimum among descendants only
        int descendantMin = min(leftMin, rightMin);

        // Update answer only if there is at least one descendant
        if (descendantMin != INT_MAX) {
            ans = max(ans, root->data - descendantMin);
        }

        // Minimum of the entire subtree (including current node)
        return min(root->data, descendantMin);
    }

    int maxDiff(Node* root) {
        // code here
        int ans = INT_MIN ;
        DFS(root , ans);
        
        return ans;
    }
};