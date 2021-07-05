//Binary tree 
//build tree by its preorder and inorder
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class BinNode{
    public:
        int val;
        BinNode* left;
        BinNode* right;
        BinNode(int _val,BinNode* _left = nullptr,BinNode* _right=nullptr)
        {
            val = _val;
            left = _left;
            right = _left;
        }
};
BinNode* bulidTree(vector<int>&preOrder,vector<int>&inOrder,
                    int preLeft,int preRight,int inLeft,int inRight)
{

}
vector<int>pos(100);
unordered_map<int,int> table;
vector<int> postOrder(BinNode*root)
{
    if(root==nullptr)return;
    postOrder(root->left);
    postOrder(root->right);
    pos.push_back(root->val);
} 
int main()
{
    int n = 0;
    while(cin>>n)
    {
        if(n==0)break;
        string pre,in;
        cin>>pre>>in;
        vector<int>preOrder(100);
        vector<int>inOrder(100);
        for(int i = 0; i < n;i++)
        {
            preOrder[i]= pre[i]- '0';
            inOrder[i] = in[i]- '0';
            table[i] = i;
        }
        BinNode* root = bulidTree(preOrder,inOrder,0,n-1,0,n-1);
        postOrder(root);
        for(int i = 0 ; i < n ; i ++)
        {
            cout<<pos[i];
        }
        pos.clear();
    }
}