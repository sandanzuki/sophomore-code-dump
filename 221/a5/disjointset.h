#pragma once

#include "TemplateDoublyLinkedList.h"
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Disjoint Set
template <typename T>
class DisjointSet {
private:
	vector<DListNode<T>*> nodeLocator;
public:
	~DisjointSet(){
		for(int i = 0; i < nodeLocator.size(); ++i){
			if(nodeLocator[i] != NULL){
				while(nodeLocator[i]->getNext() != NULL){
					nodeLocator[i]->delete_after();
				}
				delete nodeLocator[i];
			}
		}
	}
	
    DisjointSet(int n){
		//nodeLocator = vector<DListNode<T>*>(n);
	}
	
    vector<DListNode<T>*> getNodeLocator() const{
		return nodeLocator;
	}
	
    DListNode<T>* MakeSet(int key, T node){
		DListNode<T> *temp = new DListNode<T>(key, node);
		temp->setRepresentative(temp);
		temp->setTrailer(temp);
		//nodeLocator[key] = temp->getRepresentative();
		nodeLocator.push_back(temp->getRepresentative());
		return temp;
	}
	
    DListNode<T>* Union(DListNode<T>& nodeI, DListNode<T>& nodeJ){
		DListNode<T>* temp;
		DListNode<T>* smaller;
		DListNode<T>* dummy;
		if(nodeI.getListSize() >= nodeJ.getListSize()){
			temp = &nodeI;
			smaller = &nodeJ;
			dummy = &nodeJ;
		}else{
			temp = &nodeJ;
			smaller = &nodeI;
			dummy = &nodeI;
		}
		if(temp->getRepresentative() != smaller->getRepresentative()){
			smaller->setPrevious(temp->getRepresentative()->getTrailer());
			temp->getRepresentative()->getTrailer()->setNext(smaller);
			temp->getRepresentative()->setTrailer(smaller->getTrailer());
			while(smaller->getTrailer() != temp->getRepresentative()->getTrailer()){
				smaller->setRepresentative(temp->getRepresentative());
				temp->getRepresentative()->setListSize(temp->getRepresentative()->getListSize()+smaller->getRepresentative()->getListSize());
				smaller->setListSize(temp->getRepresentative()->getListSize());
				smaller = smaller->getNext();
			}
			temp->getRepresentative()->setListSize(temp->getRepresentative()->getListSize()+smaller->getRepresentative()->getListSize());
			smaller->setListSize(temp->getRepresentative()->getListSize());
			dummy->setRepresentative(temp->getRepresentative());
			//nodeLocator.erase(nodeLocator.begin()+smaller->getKey()-1);
			//nodeLocator[smaller->getKey()-1] = NULL;
		}else{
			cout << "The two sets are the same!" << endl;
		}
		return temp;   
    }
	
    DListNode<T>* FindSet(DListNode<T> node){
		return nodeLocator[node.getKey()-1]->getRepresentative();
	}
    
	DListNode<T>* FindSet(int nodeKey){
		return nodeLocator[nodeKey-1]->getRepresentative();
	}
};

template <typename T>
ostream& operator<<(ostream& out, const DisjointSet<T>& ds){
	for(int i = 0; i < ds.getNodeLocator().size(); ++i){		
		if(ds.getNodeLocator()[i]->getRepresentative() == ds.getNodeLocator()[i]){
			out << "{ " ;
			DListNode<T> *temp = ds.getNodeLocator()[i];
			while(temp != ds.getNodeLocator()[i]->getTrailer()){
				out << temp->getKey() << ":" << temp->getElem() << " ";
				temp = temp->getNext();
			}
			out << temp->getKey() << ":" << temp->getElem() << " ";
			temp = temp->getNext();
			out << "}" << endl;
		}
	}
	return out;
}