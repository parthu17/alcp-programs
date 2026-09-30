#include<bits/stdc++.h>
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
    return root;
}
void levelorder(node* root){
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int levelsize=q.size();
        while(levelsize--){
            node* curr=q.front();
            q.pop();
            cout<<curr->data<<" ";
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        cout<<"\n";
    }

}
int main(){
    node* root=Buildtree();
    levelorder(root);
    return 0;
}