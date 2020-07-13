/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void FindDepth(Node* node, int &depth) {
        if (node != nullptr) {
            depth++;
            int maxChildDepth = 0;
            
            for (int i = 0; i < node->children.size(); ++i) {
                int childDepth = depth;
                
                FindDepth(node->children[i], childDepth);
                if (childDepth > maxChildDepth) {
                    maxChildDepth = childDepth;
                }
            }
            
            if (maxChildDepth > depth) {
                depth = maxChildDepth;
            }
        }
    }
    int maxDepth(Node* root) {
        int depth = 0;
        
        FindDepth(root, depth);
        
        return depth;
    }
};
