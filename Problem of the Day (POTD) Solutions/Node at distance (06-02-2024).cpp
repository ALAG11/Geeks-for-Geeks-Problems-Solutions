class Solution
{
   private:
        set<Node*> ans;
        void solve(Node *root, int lvl, vector<Node*> v, int k) {
            if(!root)
                return;
            
            // store the node in vector
            v.push_back(root);
            // if node is a leaf node then find index 
            if(!root->left && !root->right) {
                int indx = lvl - k;
                // if calculate index is valid, means we have a node
                if(indx >= 0)
                    ans.insert(v[indx]); // sote it in ans
                
                return;
            }
            
            // recursive call for left and right, 
            // while we move to either of the side our level is increased by 1.
            solve(root->left, lvl+1, v, k);
            solve(root->right, lvl+1, v, k);
        }
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k)
    {
        //Add your code here. 
        vector<Node*> v;
        solve(root, 0, v, k);
        
        return ans.size();
    }
};