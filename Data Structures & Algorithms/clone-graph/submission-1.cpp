/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void DFS(Node* node, Node* clone_node, unordered_map<Node*, Node*>&map_){
        for(Node* n : node->neighbors){
            if(map_.find(n) == map_.end()){
                Node* clone = new Node(n->val);
                map_[n] = clone;
                clone_node->neighbors.push_back(clone);
                DFS(n, clone, map_);
            }
            else{
                clone_node->neighbors.push_back(map_[n]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*>map_;

        map_.clear();

        if(!node) return NULL;

        Node* clone_node = new Node(node->val);

        map_[node] = clone_node;

        DFS(node, clone_node, map_);

        return clone_node;
    }
};
