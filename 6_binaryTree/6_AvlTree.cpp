#include<iostream>

class Node {

private:
	int data;
	int height;
	class Node *left;
	class Node *right;

public:
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
		height = 0;
	}
	
	friend class AvlTree;
};

class AvlTree {

public:
	typedef Node N;
	N *root;	
	
	AvlTree() {
		root = NULL;
	}

	int NodeHeight(N* &n) {
		int hl;
		int hr;

		hl = n && n->left ? n->left->height : 0;
		hr = n && n->right ? n->right->height : 0;

		return hl > hr ? hl+1 : hr+1;
	}

	int BalanceFactor(N* &n) {
	
		int hl;
		int hr;

		hl = n && n->left ? n->left->height : 0;
		hr = n && n->right ? n->right->height : 0;

		return hl-hr;
	}
	
	void LLRotation(N* &n) {
		
		N *nl = n->left;
		N *nlr = nl->right;

		nl->right = n;
		n->left = nlr;
		
		n->height = NodeHeight(n);
		nl->height = NodeHeight(nl);

		if (n == root)
			root = nl;
	}

// LR and RL called as Double Rotation
	void LRRotation(N* &n) {
		
		N *nl = n->left;
		N *nlr = nl->right;

		nl->right = nlr->left;
		n->left = nlr->right;
		
		nlr->left = nl;
		nlr->right = n;

		n->height = NodeHeight(n);
		nl->height = NodeHeight(nl);
		nlr->height = NodeHeight(nlr);
		
		if (n == root)
			root = nlr;

	}

	void RRRotation(N* &n) {

		N *nr = n->right;
		N *nrl = nr->left;
	
		nr->left = n;
		n->right = nrl;
		
		n->height = NodeHeight(n);
		nr->height = NodeHeight(nr);
	
		if (n == root)
			root = nr;
	}

	void RLRotation(N* &n) {
		
		N *nr = n->right;
		N *nrl = nr->left;

		n->right = nrl->left;
		nr->left = nrl->right;
	
		nrl->left = n;
		nrl->right = nr;

		nrl->height = NodeHeight(nrl);
		nr->height = NodeHeight(nr);
		n->height = NodeHeight(n);

		if (n == root)
			root = nrl;
	}

	void InsertNode(N* &n, int data) {
		
		if(n == NULL) {
			n = new Node(data);
			return;
		}

		if(data > n->data)
			InsertNode(n->right, data);
		else
			InsertNode(n->left, data);

		n->height = NodeHeight(n);

		if (BalanceFactor(n) == 2) { // Means Weightage is on Left side
			
			if (BalanceFactor(n->left) == 1)
				LLRotation(n);
			else if (BalanceFactor(n->left) == -1)
				LRRotation(n);
		}
		else if (BalanceFactor(n) == -2) {
			
			if (BalanceFactor(n->right) == 1)
				RLRotation(n);
			else if (BalanceFactor(n->right) == -1)
				RRRotation(n);
		}
	}

	void display(N* &n, int nspaces, std::string type) {

		if(n == NULL)
			return;

		for(int i=0; i < nspaces; ++i)
			std::cout << " ";

		std::cout << n->data << "(" << type <<  ")" << std::endl;
		
		display(n->left, nspaces+4, "L");
		display(n->right, nspaces+4, "R");
	}
};

int main() {

	AvlTree obj;

/* For LL Rotation

	obj.InsertNode(obj.root, 10);
	obj.InsertNode(obj.root, 12);
	obj.InsertNode(obj.root, 7);
	obj.InsertNode(obj.root, 8);
	obj.InsertNode(obj.root, 5);
	obj.InsertNode(obj.root, 3);
*/

/* For LR Rotation
	obj.InsertNode(obj.root, 10);
	obj.InsertNode(obj.root, 12);
	obj.InsertNode(obj.root, 6);
	obj.InsertNode(obj.root, 8);
	obj.InsertNode(obj.root, 7);
	obj.InsertNode(obj.root, 9);
*/	

/* For RR Rotation
	obj.InsertNode(obj.root, 10);
	obj.InsertNode(obj.root, 9);
	obj.InsertNode(obj.root, 12);
	obj.InsertNode(obj.root, 11);
	obj.InsertNode(obj.root, 15);
	obj.InsertNode(obj.root, 19);
*/

// For RL Rotation
	obj.InsertNode(obj.root, 5);
	obj.InsertNode(obj.root, 3);
	obj.InsertNode(obj.root, 15);
	obj.InsertNode(obj.root, 10);
	obj.InsertNode(obj.root, 16);
	obj.InsertNode(obj.root, 8);

	obj.display(obj.root, 0, "Root");
}
