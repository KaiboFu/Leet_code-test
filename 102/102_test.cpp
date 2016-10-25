# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <map>
# include <cstdlib>
# include <cstdio>
# include <cstring>
using namespace std;

class TreeNode{
public:
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
    void CreateTreeNode(TreeNode* &T);
    void InOrder(TreeNode* &T);
    void PreOrder(TreeNode* &T);
    void PosOrder(TreeNode* &T);
    bool operator==(const TreeNode* T1);
private:
    int val;
    TreeNode *left, *right;
};

void TreeNode::CreateTreeNode(TreeNode* &T){
    int data;
    cin >> data;
    if (data == -1) T = NULL;
    else {
        T = new TreeNode(data);
        T->val = data;
        CreateTreeNode(T->left);
        CreateTreeNode(T->right);
    }
}

void TreeNode::PreOrder(TreeNode* &T){
    if(T){
        cout << T->val << " ";
        PreOrder(T->left);
        PreOrder(T->right);
    }
}

void TreeNode::InOrder(TreeNode* &T){
    if(T){
        InOrder(T->left);
        cout << T->val << " ";
        InOrder(T->right);
    }
}

void TreeNode::PosOrder(TreeNode* &T){
    if(T){
        PosOrder(T->left);
        PosOrder(T->right);
        cout << T->val << " ";
    }
}

bool TreeNode::operator==(const TreeNode* &T1){
    if
}

vector<vector<int> > levelOrder(TreeNode *root){
    vector<vector<int> > vvi;
    if(vvi == NULL)
        return vvi;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        vector<int> vi;
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left != NULL) q.push(temp->left);
            if (temp->right != NULL) q.push(temp->right);
            vi.push_back(temp->val);
        }
        vvi.push_back(vi);
    }
    return vi;
}

int main(){
    TreeNode *T = NULL;
    vector<vector<int> > vvi;
    T->CreateTreeNode(T);cout<<endl;
    T->PreOrder(T);cout<<endl;
    T->InOrder(T);cout<<endl;
    T->PosOrder(T);cout<<endl;
    levelOrder(T);
    return 0;
}
