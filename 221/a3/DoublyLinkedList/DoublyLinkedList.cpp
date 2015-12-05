#include "DoublyLinkedList.h"
#include <stdexcept>

// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error{
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// copy constructor
//O(n)
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll){
  // Initialize the list
  header.next = &trailer; 
  trailer.prev = &header;
  
  // Copy from dll
  DListNode *current = dll.getFirst();  
  
  while(current != dll.getAfterLast()){
    DListNode *newNode = new DListNode(current->obj, trailer.prev, &trailer);
    trailer.prev->next = newNode;
    trailer.prev = newNode;
    
    current = current->getNext(); //iterate
  }
  
}

// assignment operator
//O(n)
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll){
  // Delete the whole list
  
  if(!isEmpty()){
    DListNode *temp, *node = dll.getFirst();
    while(node != dll.getAfterLast()){
      temp = node;
      node = node->next;
      delete temp;
    }
  }
  
  // Copy from dll
  if(!dll.isEmpty()){
  DListNode *current = dll.getFirst();
    while(current != dll.getAfterLast()){
      DListNode *newNode = new DListNode(current->obj, trailer.prev, &trailer);
      trailer.prev->next = newNode;
      trailer.prev = newNode;

      current = current->getNext(); //iterate
    }
  }    
  return *this;
}

// insert the object to the first of the linked list
void DoublyLinkedList::insertFirst(int newobj){ 
  DListNode *newNode = new DListNode(newobj, &header, header.next);
  header.next->prev = newNode;
  header.next = newNode;
}

// insert the object to the last of the linked list
void DoublyLinkedList::insertLast(int newobj){
  DListNode *newNode = new DListNode(newobj, trailer.prev, &trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}

// remove the first object of the list
int DoublyLinkedList::removeFirst(){ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode *node = header.next;
  node->next->prev = &header;
  header.next = node->next;
  int obj = node->obj;
  delete node;
  return obj;
}

// remove the last object of the list
int DoublyLinkedList::removeLast(){
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  int obj = node->obj;
  delete node;
  return obj;
}

// destructor
DoublyLinkedList::~DoublyLinkedList(){
  DListNode *prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}

// return the first object
int DoublyLinkedList::first() const{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return header.next->obj;
}

// return the last object
int DoublyLinkedList::last() const{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return trailer.prev->obj;
}

// return the list length
int DoublyLinkedListLength(DoublyLinkedList& dll){
  DListNode *current = dll.getFirst();
  int count = 0;
  while(current != dll.getAfterLast()) {
    count++;
    current = current->getNext(); //iterate
  }
  return count;
}

// output operator
//O(n)
ostream& operator<<(ostream& out, const DoublyLinkedList& dll){
  out << "[ ";
  DListNode *current = dll.getFirst();  
  while(current != dll.getAfterLast()){
    out << current->getElem() << " ";
    
    current = current->getNext(); //iterate
  }
  out << "]";
  return out;
}
