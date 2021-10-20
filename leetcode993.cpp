/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>
#include <queue>
class Solution {
public:
    //使用BFS 
    bool isCousins(TreeNode *root, int x, int y) {
        queue< TreeNode* > q; //建立Queue
        q.push(root); // push root
        //int cc = 0;
        bool find_x=false, find_y = false; 
        while(!q.empty()){ 
            
            for(int i=q.size()-1;i>=0;i--){ // 搜索queue內的node (一次只搜尋到同一個depth的node)
                TreeNode *node = q.front(); 
                q.pop();
                //cout << "node val " << node->val << "  ";
                if(node->left != NULL && node->right!=NULL){ //同一個parent 不是cousin
                    int l = node->left->val , r = node->right->val;
                    if(( l==x && r==y ) || (l==y && r == x) ) //雖然值相同 但不是cousin 
                        return false; 
                }
                
                //確定不是child 後 將不同parent的child push進queue 下一輪使用
                if(node->left != NULL){ 
                    q.push(node->left);
                    //cout << "leftChild val " <<node->left->val << " "; 
                }
                if(node->right != NULL){ 
                    q.push(node->right);
                    //cout << "righthild val " <<node->right->val << " "; 
                }
                
                //判斷此node值是否與x或y相同
                if(node->val == x) find_x = true;
                if(node->val == y) find_y = true;
                
                //cout << "qsize " << q.size() << endl;
            }   
            
            //cout << " check " << cc << endl;
            //cc+=1;
            
            //跑完同一個depth後查看是否有cousins
             if(find_x && find_y) return true; //同時true 代表找到counsin
            else if(find_x || find_y) return false; 
            //其中一個true 代表不是同一個depth
            
        }
        return false; //跑完所有node 就回傳false
    }
};
