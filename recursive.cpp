#include<iostream>
using namespace std;

// structure of a tree
struct node{
	int data;
	node*left;
	node*right;
	
	node(int value){
		data = value;
		left = right = NULL;
	}
};

//  creating a tree

node* createTree(){
	int data;
	cout<<"enter the node value(-1 for no node): ";
	cin>>data;
	
	if(data == -1){
		return 0;
	}
	else{
		node* root = new node(data);
		cout<<"enter left child of"<<data<<":"<<endl;
		root->left = createTree();
		
		cout<<"enter right child of"<<data<<":"<<endl;
		root->right = createTree();
		
		return root;
	}
	
}

//tree traversal methods
void preorderTraversal(node* root){
	if(root == NULL){
		return;
	}
	
	cout<<root->data<<" ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
	
}

void inorderTraversal(node* root){
	if(root == NULL){
		return;
	}
	
	inorderTraversal(root->left);
	cout<<root->data<<" ";
	inorderTraversal(root->right);
	
}


void postorderTraversal(node* root){
	if(root == NULL){
		return;
	}
	
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout<<root->data<<" ";

	
}


int main(){
	cout<<"build your tree: "<<endl;
	node* root = createTree();
	
	cout<<"tree traversal methods: "<<endl;
	
	cout<<"preorderTraversal: ";
	preorderTraversal(root);
	
	cout<<"postorderTraversal: ";
	postorderTraversal(root);
	
	cout<<"inorderTraversal: ";
	inorderTraversal(root);
	
}
