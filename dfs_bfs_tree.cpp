#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
void dfs_inorder(node *root)
{
    if(root!=NULL){
        dfs_inorder(root->left);
        cout << root->data << " ";
        dfs_inorder(root->right);
    }
    
}
void dfs_preorder(node *root)
{   
    if(root!=NULL){
        cout << root->data << " ";
        dfs_preorder(root->left);
        dfs_preorder(root->right);
    }
    
}
void dfs_postorder(node *root)
{
    if(root!=NULL){
        dfs_postorder(root->left);
        dfs_postorder(root->right);
        cout << root->data << " ";
    }
    
}
void bfs_tree(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int levelsize = q.size();
        while (levelsize--)
        {
            node *curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        cout<<"|";
    }
}
node* Buildtree()
{
    int rootval;
    queue<node*> q;
    cout << "enter root node value\n";
    cin >> rootval;
    if (rootval == -1)
        return nullptr;
    node *root = new node(rootval);
    q.push(root);

    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();
        int leftval, rightval;
        cout << "enter left val of"<<curr->data;
        cin >> leftval;
        if (leftval != -1)
        {
            node *left = new node(leftval);
            curr->left = left;
            q.push(left);
        }
        cout << "enter right val of "<<curr->data;
        cin >> rightval;
        if (rightval != -1)
        {
            node *right = new node(rightval);
            curr->right = right;
            q.push(right);
        }
    }
    cout<<root->data;
    return root;
}
int main()
{
    node *root = Buildtree();
    cout<<"\n preorder traversal\n";
    dfs_preorder(root);
    cout<<"\n inorder traversal\n";
    dfs_inorder(root);
    cout<<"\n postorder traversal\n";
    dfs_postorder(root);
    cout<<"\n bfs traversal\n";
    bfs_tree(root);
    return 0;
}
