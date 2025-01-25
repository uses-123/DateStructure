#include <iostream>
#include <queue>
 
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):
    val(x),left(NULL),right(NULL)
    {}
};
 
class Solution
{
public:
    void bfs(TreeNode *root)  //���ص���һ��int��vector
    {
        queue<TreeNode *>q;  //��������
 
        if(root==NULL)
            return;

        q.push(root);
 
        while(!q.empty())
        {
            cout<<q.front()->val<<" ";
            if(q.front()->left!=NULL)
            {
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL)
            {
                q.push(q.front()->right);
            }
            q.pop();  //������һ��Ԫ��
        }
        return;
    }
};
 
int main()
{
    Solution sol;
    //��ʼ��һ����
    TreeNode* root = new TreeNode(8);
    TreeNode* b1 = new TreeNode(6);
    TreeNode* b2 = new TreeNode(10);
    TreeNode* c1 = new TreeNode(5);
    TreeNode* c2 = new TreeNode(7);
    TreeNode* c3 = new TreeNode(9);
    TreeNode* c4 = new TreeNode(1);
 
    root->left = b1;
    root->right = b2;
 
    b1->left = c1;
    b1->right = c2;
    b2->left = c3;
    b2->right = c4;
 
    sol.bfs(root);
        
    return 0;
}
