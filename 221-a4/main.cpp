#include "BinaryTree.h"
#include <iostream>
#include <fstream>


int main() {
	//read file
	string file;
	cout << "Enter a file: ";
	cin >> file;
	ifstream is(file.c_str(), ifstream::in);
	
	//print contents of file
	cout << "Given input: " << endl;
	int data;
	BinaryTree tree = *(new BinaryTree());
	while(!is.eof()) {
		is >> data;
		if(is.good()) {
			cout << data << endl;
			tree.insert(data);
		}
	}
	cout << endl << "Tree: " << endl << tree << endl;
	
	//print tree
	int* cost = new int(0);
	if(tree.size() < 16){
		cout << "Pre-order traversal: " << endl;
        tree.preOrderTraversal(tree.getRoot());
        cout << endl << "In-order traversal: " << endl;
        tree.inOrderTraversal(tree.getRoot());
        cout << endl << "Post-order traversal: " << endl;
        tree.postOrderTraversal(tree.getRoot());
        cout << endl;
    }else{
        cout << "Enter a output file location (which ends in .txt)" << endl;
        cin >> file;
		ofstream os(file.c_str());
		os << tree;
		cout << "Tree output to file: " << file << endl;
	}
	cout << "Number of nodes: " << tree.size() << endl;
	cout << "Average search cost: " << tree.avgcost(tree.getRoot(), cost) << endl << endl;
	
	//Pick an element to remove, remove it
	cout << "Please enter an element to remove: ";
	cin >> data;
	tree.remove(data, tree.getRoot());
    cout << endl;
	
	//print new tree
	*cost = 0;
	if(tree.size() < 16){
		cout << "In-order traversal: " << endl;
        tree.preOrderTraversal(tree.getRoot());
        cout << endl << "In-order traversal: " << endl;
        tree.inOrderTraversal(tree.getRoot());
        cout << endl << "Post-order traversal: " << endl;
        tree.postOrderTraversal(tree.getRoot());
        cout << endl;
    }else{
		cout << "Enter a output file location (which ends in .txt)" << endl;
        cin >> file;
        ofstream os(file.c_str());
		os << tree;
		cout << "Tree output to file" << file << endl;
	}
	cout << "Number of nodes: " << tree.size() << endl;
	cout << "Average search cost: " << tree.avgcost(tree.getRoot(), cost) << endl;
	
	delete cost;
}