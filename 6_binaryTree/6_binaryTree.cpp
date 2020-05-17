#include<iostream>
#include<sys/time.h>

class TreeNode {
	private:
		int data;
		TreeNode *left;
		TreeNode *right;

	public:
		friend class BinaryTree;	
		TreeNode(const int& d) : data( d ) {
		}
};

class BinaryTree {

	private:	
		typedef TreeNode Tnode;

	public:	
		Tnode *root = NULL;

		BinaryTree() {
		}
		
		~BinaryTree() {
		
		}

		Tnode *insertNode(const int& data) {
			
			Tnode *node = NULL;
			node = new Tnode(data);
			node->left = NULL;
			node->right = NULL;

			return node;
		}

		void createNodes(Tnode* &root, int nodes) { // Taking root as reference
			
			static int data = 1;
			struct timeval cur;
			
			gettimeofday(&cur, NULL);
			srand(cur.tv_sec);
		
			if (root == NULL) {
				root = insertNode(data++);
				nodes--;
			}
			
			if(!nodes)
				return;
			
			if (nodes % 2)	
				createNodes(root->left, nodes);
			else
				createNodes(root->right, nodes);
		}

		void displayTree(Tnode* &root, const int& nspaces, std::string type) { // PreOrder Traversal

			if (root == NULL)
				return;

			for(int i = 0; i < nspaces; ++i)
				std::cout << " ";
			
			std::cout << root->data << "(" << type << ")" << std::endl;
			displayTree(root->left, nspaces+4, "L");
			displayTree(root->right, nspaces+4, "R");
		}
};

int main() {
	
	int size;
	BinaryTree *obj = new BinaryTree;

	std::cout << "Enter Number of Nodes of Tree" << std::endl;
	std::cin >> size; 

	obj->createNodes(obj->root, size);
	obj->displayTree(obj->root, 0, "Root");

	return 0;
}
