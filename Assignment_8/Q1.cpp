#include<iostream>
using namespace std;
class Node
{
	public:
	 int data;
	 Node* left;
	 Node* right;
	 Node(int val)
	 {
	 	data=val;
	 	left=right=NULL;
	 }
};
//root left right 
void Preorder(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);
	
}
//left root right
void Inorder(Node* root)
{
	if(root==NULL)
	{
	return;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}
//left right root

void Postorder(Node* root)
{
	if(root==NULL)
	{
		return;
		
	}
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->data<<" ";
	
}
int main()
{
	Node* root=new Node(1);
	 root->left=new Node(2);
	 root->right=new Node(3);
	 root->right->left=new Node(4);
	 root->right->right=new Node(5);
	Preorder(root);
	cout<<endl;
	Inorder(root);
	cout<<endl;
	Postorder(root);
}
