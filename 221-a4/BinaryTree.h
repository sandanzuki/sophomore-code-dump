#ifndef BINARYTREE_H
#define BINARYTREE_H


#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class BinaryTree{
    public:
    class Empty{}; // error class, thrown when tree is empty.
    struct Node{
        int data, cost;
        Node *left, *right;
        
        Node(int n = 0, Node *l = NULL, Node *r = NULL){
            data = n, left = l, right = r, cost = -1;
        }
        
        Node *getleft(){
            return left;
        }

        Node *getright(){
            return right;
        }

        int getdata(){
            return data;
        }

        int getcost(){
            return cost;
        }

        int size(Node *t){
            if(t == NULL) return 0;
            else return 1 + size(t->left) + size(t->right);
        }
        
        int height(Node *t){
            if (t == NULL) return 0;
            else{
                int lheight = height(t->left) + 1, rheight = height(t->right) + 1;
                return (lheight > rheight) ? lheight : rheight;
            }
        }
        
        Node* copy(){
            Node *root = new Node(data);
            if (left != NULL) root->left = left->copy();
            if (right != NULL) root->right = right->copy();
            return root;
        }
		
    };
    
    BinaryTree(){
        root = NULL;
    }
    
	BinaryTree(int n){
        root = new Node(n);
		root->cost = 1;
    }
    
	~BinaryTree(){ 
        deleteTree(root); 
        root = NULL; 
    }
    
    void deleteTree(Node *root){
        if(root == NULL) return;
        if(root->left != NULL)
            deleteTree(root->left);
        if(root->right != NULL)
            deleteTree(root->right);
        delete root;
    }
    
	Node *getRoot() const{ 
        return root;
    }
    
	bool isEmpty() const{ 
        return root == NULL;
    }
	
    int size(){ 
        return root->size(root);
    }
	
    int height() const{
        return root->height(root); 
    }
    
	double avgcost(Node *node, int *cost){
        *cost += node->getcost();
        if(node->left != NULL) avgcost(node->left, cost);
        if(node->right != NULL) avgcost(node->right, cost);
        return (double)(*cost)/(double)(size());
    }
	
    void copy(BinaryTree& right){
		if (this != &right){
			deleteTree(root);
			if(right.root != NULL) root = right.root->copy();
		}
	}
    
	void merge(int data, BinaryTree& first, BinaryTree& second){
        if (first.root == second.root && first.root != NULL){
            cerr << "left tree and right tree are the same, merge aborted" << endl;
            return;
        }
        if(this != &first && this != &second) deleteTree(root);

        root = new Node(data, first.root, second.root);

        if(this != &first) first.root = NULL;
        if(this != &second) second.root = NULL;
    }
    
    Node* find(int n, Node* t){
        while (t != NULL){
            if (n < t->data) t = t->left;
            else if (n > t->data) t = t->right;
            else return t;
        }
    }
	
	void updatecost(Node *t, int counter = 0){
		if(t != NULL){
			counter++;
			t->cost = counter;
			updatecost(t->left, counter);
			updatecost(t->right, counter);
			
		}
	}
    
    Node* insert(int n, Node* t, int counter = 0){
		if(t == NULL){
			t = new Node(n);
            t->cost = ++counter;
        }else if(n < t->data){
            ++counter;
            t->left = insert(n, t->left, counter);
        }else if(n > t->data){
            ++counter;
            t->right = insert(n, t->right, counter);
        }
        return t;
    }

    Node* remove(int n, Node *t, int counter = 0) throw (Empty){
        if(t == NULL) Empty();
        if(t == getRoot() && n == t->data){ // if t is root of whole tree, special case
            if(t->left == NULL && t->right == NULL){ // if root has no children
                delete root;
                root = NULL;
            }else if(t->left != NULL && t->right != NULL){ // if root has two children
                t->data = findMin(t->right)->data;
                t->right = removeMin(t->right);
            }else{ // if root has only one child
                Node *temp = t;
                root = (t->left != NULL) ? t->left : t->right;
                delete temp;
            }
        }else if(n < t->data){ // search for node with n
           	if(t->left == NULL) return t;
            t->left = remove(n, t->left);
        }else if(n > t->data){ // search for node with n
			if(t->right == NULL) return t;
            t->right = remove(n, t->right);
        }else if(t->left != NULL && t->right != NULL){ // if t has two children
            t->data = findMin(t->right)->data;
            t->right = removeMin(t->right);
        }else{ // if t only has one child
            Node *temp = t;
            t = (t->left != NULL) ? t->left : t->right;
            delete temp;
        }
		updatecost(root);
        return t;
    }

    void insert(int x){
	    root = insert(x, root);
    }

    void remove(int x){
        remove(x, root);
    }
 
	Node* findMin(Node *t) throw (Empty){
        if(t == NULL) throw Empty();
        while(t->left != NULL) t = t->left;
        return t;
    }

	Node* removeMin(Node *t) throw (Empty){
        if(t == NULL) throw Empty();
        if(t->left != NULL)
            t->left = removeMin(t->left);
        else{
            Node *temp = t;
            t = t->right;
            delete temp;
        }
        return t;
    }
	
	void preOrderTraversal(Node* t){
		cout << t->data << "[" << t->cost << "] ";
		if (t->left != NULL) preOrderTraversal(t->left);
		if (t->right != NULL) preOrderTraversal(t->right);
	}
	
	void inOrderTraversal(Node* t){
		if (t->left != NULL) inOrderTraversal(t->left);
		cout << t->data << "[" << t->cost << "] ";
		if (t->right != NULL) inOrderTraversal(t->right);
    }
	
	void postOrderTraversal(Node* t){
		if (t->left != NULL) postOrderTraversal(t->left);
		if (t->right != NULL) postOrderTraversal(t->right);
		cout << t->data << "[" << t->cost << "] ";
	}
    
    
    
    private:
    Node *root;
    
    friend ostream& operator<<(ostream &os, const BinaryTree& tree);
    
};

int num_nodes(int height){
    if(height == 0) return 1;
    else return (num_nodes(height-1)*2);
}

inline ostream& operator<<(ostream &os, const BinaryTree& tree){
    if(tree.isEmpty()) return os;
    BinaryTree::Node* dummy = NULL;
	queue<BinaryTree::Node*> queue;
	int currLevel = 1;
	int nextLevel = 0;
	int currHeight = -1;
    int counter = 0;
    int totalnodes = 0;
    for(int i = 0; i < tree.height(); i++){
        totalnodes += num_nodes(i);
    }
	queue.push(tree.getRoot());
	while(counter < totalnodes){
	//while(!queue.empty()){
		BinaryTree::Node *node = queue.front();
		queue.pop();
        counter++;
		--currLevel;
		if(node != NULL){
			os << node->getdata() << ' ';
			queue.push(node->getleft());
			queue.push(node->getright());
			nextLevel += 2;
		}else{
			os << "X ";
            queue.push(dummy);
            queue.push(dummy);
            nextLevel += 2;
            
        }
        if(currLevel == 0){
			os << endl;
			currLevel = nextLevel;
			nextLevel = 0;
			++currHeight;
		}
	}
    return os;
}


#endif
