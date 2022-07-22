//https://leetcode.com/problems/populating-next-right-pointers-in-each-node
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root){
            return nullptr;
        }
        
        queue<Node*> q;
        q.push(root);
        root->next = nullptr;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            if (curr->left){
                q.push(curr->left);
                q.push(curr->right);
                curr->left->next = curr->right;
                if (!curr->next){
                    curr->right->next = nullptr;
                }
                else{
                    curr->right->next  = curr->next->left;
                }
            }
            
            
        }
        return root;
    }
};
