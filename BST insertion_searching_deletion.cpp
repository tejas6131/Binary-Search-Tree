#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;
    
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right = NULL;
    }
};


node* insertVal(int data,node* root)
{
    
    if(root==NULL)
    {
        root=new node(data);
        return root;
    }
     if(data>root->data)
    {
        root->right=insertVal(data,root->right);
    }
    else {
        root->left=insertVal(data,root->left);
    }
    
    return root;
}



void insertintoTree(node* &root){
   
    int data;
   while(data!=-1)
   { 
        cout<<"Enter the node data : "<<endl;
        cin>>data;
       if(data!=-1)
        root=insertVal(data,root);
   }

}


bool search(node* root,int key)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==key)
    {
        return true;
    }
    
    if(key>root->data)
    {
        search(root->right,key);
    }
    else search(root->left,key);
}

void leverOrderTraversal(node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        node *temp=q.front();
        q.pop();
        
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
               q.push(temp->right);
            }
            
        }
    }
}

void inorderTraversal(node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
void preorderTraversal(node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}



node* maxRoot(node* root)
{
    if(root->right==NULL)
    {
        return root;
    }
    else
    maxRoot(root->right);
}




node* deleteFromBST(node* root,int del)
{
    if(root==NULL) return root;
    
    if(root->data==del)
    {
        //case 1
    if(root->left ==NULL && root->right==NULL)
    {
        delete(root);
        return NULL;
    }
    
    
    //case 2 
    if(root->left==NULL && root->right!=NULL)
    {
        node *temp=root->right;
        delete root;
        return temp;
    }
    else if(root->left!=NULL && root->right==NULL){
        node *temp=root->left;
        delete root;
        return temp;
    }
    
    
    //case 3 
    else 
    {
        root->data=maxRoot(root->left)->data;
        root->left=deleteFromBST(root->left,root->data);
        return root;
    }
    }
    
    
    if(root->data>del)
    {
        root->left=deleteFromBST(root->left,del);
        return root;
    }
    else if (root->data<del)
    {
        root->right=deleteFromBST(root->right,del);
        return root;
    }
    
    
    
    
}








int main()
{
    node* root=NULL;
    insertintoTree(root);
    leverOrderTraversal(root);
    int del;
    while(del!=-1)
    {
        cout<<endl<<"Enter the element to delete from BST : "<<endl;
        cin>>del;
        root=deleteFromBST(root,del);
        cout<<endl<<"The tree after deletion :"<<endl;
        leverOrderTraversal(root);
    }
    
    
    // inorderTraversal(root);
    // cout<<endl;
    // preorderTraversal(root);
    // cout<<endl;
    // postorderTraversal(root);
    //10 15 7 5 17 9 16 19 -1
    // int key;
    // while(key!=-1)
    // {
    //     cout<<endl<<"Enter the element to search in the BST : "<<endl;
    //     cin>>key;
    //     bool ans =search(root,key);
    //     if(ans){
    //         cout<<"Element is present"<<endl;
    //     }
    //     else cout<<"Element is absent"<<endl;
    // }
    
}
