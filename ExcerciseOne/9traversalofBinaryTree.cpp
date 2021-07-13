//Binary tree 
//build tree by its preorder and inorder
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class BinNode{
    public:
        char val;
        BinNode* left;
        BinNode* right;
        BinNode(char _val,BinNode* _left = nullptr,BinNode* _right=nullptr)
        {
            val = _val;
            left = _left;
            right = _left;
        }
};
vector<char>pos;
unordered_map<char,int> table;
BinNode* bulidTree(vector<char>&preOrder,vector<char>&inOrder,
                    int preLeft,int preRight,int inLeft,int inRight)
{
    if(preLeft > preRight)return nullptr;
    char newRootValue = preOrder[preLeft];
    BinNode* newRoot = new BinNode(newRootValue);
    //find root in inorder
    int rootPosIn = table[newRootValue];
    newRoot->left = bulidTree(preOrder,inOrder,preLeft + 1,preLeft + rootPosIn - inLeft ,
                    inLeft, rootPosIn - 1 );

    newRoot->right = bulidTree(preOrder, inOrder,
                preLeft + rootPosIn - inLeft + 1, preRight,
                    rootPosIn + 1, inRight);
    return newRoot;
}

void postOrder(BinNode*root)
{
    if(root==nullptr)return ;
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
        //cout<<isdigit(pre[0]);
        vector<char>preOrder(100);
        vector<char>inOrder(100);
        for(int i = 0; i < n;i++)
        {
            preOrder[i] = pre[i];
            inOrder[i] = in[i];
            //pos map
            table[inOrder[i]] = i;
        }
        BinNode* root = bulidTree(preOrder,inOrder,0,n-1,0,n-1);
        postOrder(root);
        for(int i = 0 ; i < n ; i ++)
        {
            cout<<pos[i];
        }
        cout<<endl;
        pos.clear();
    }
}