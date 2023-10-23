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
         this->right=NULL;
     }
};

node* insertBst(int x,node *root){
    if(root==NULL)
    {
       node *root = new node(x);
       return root;
    }
    
    if(x>root->data)
    {
        root->right=insertBst(x,root->right);
    }
    if(x<root->data)
    {
        root->left=insertBst(x,root->left);
    }
    return root;
    
}

void levelOrderTraversal(node* root)
{
    node* temp=root;
    queue<node*> q ;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
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

node* takeInput(node* root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        root=insertBst(data,root);
        cin>>data;
    }
    
    return root;
}

bool searchInBst(int x,node* root)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==x)
    {
        return true;
    }
    
    if(root->data>x)
    {
        searchInBst(x,root->left);
    }
    else
    {
        searchInBst(x,root->right);
    }
    
}



int main()
{
    node* root=NULL;
    cout<<"Enter the elements in BST :"<<endl;
    root=takeInput(root);
    //10 7 9 5 15 17 16 19 -1
    levelOrderTraversal(root);
    
    int x;
    while(x!=-1)
    {
        
    cout<<"Enter the element to search "<<endl;
    cin>>x;
    if(searchInBst(x,root))
    {
    cout<<"The element is present"<<endl;
    }
    else cout<<"The element is absent"<<endl;
    }
}

//Author -- Tejas Mali