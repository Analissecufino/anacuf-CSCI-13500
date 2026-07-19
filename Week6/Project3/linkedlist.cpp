#include "linkedlist.hpp"
#include <iostream>
#include <stdexcept>

// default constructor empty list at start
LinkedList::LinkedList(): size_(0), head_(nullptr){}

// @param: Takes in a const int parameter representing the value to insert.
// @return: Returns nothing.
void LinkedList::InsertNode(const int value) {

// Insert the provided value as a new node at the end of the list.
// Ensure that the list's tracking variables are updated accordingly.

Node* new_node = new Node(value);

if (head_ == nullptr) {
   
    head_ = new_node;
}

else{
    
    Node* current = head_;
     while (current->next != nullptr) {

        current = current->next;
     }

     current->next = new_node;
}

size_++;
}

// take care of implementing print functions first to test implementations going forward

// Print all values sequentially, separated by " -> ",
// and terminate the output with "nullptr" and a newline.
void LinkedList::PrintValues() const{

    Node* current = head_;
    
    while (current != nullptr) {

        std::cout << current->value << " -> ";
        current = current->next;
    }

    std::cout << "nullptr" << std::endl;
}

// Print the 1-based position, a space, and the node's memory address
// for every node in the list.
void LinkedList::PrintAddresses() const{

    Node* current = head_;
    int position = 1;

    while (current != nullptr) {

        std::cout << position << " " << current << std::endl;
        current = current->next;
        position++;
    }
}

// @param: Takes in a const int parameter representing the value to insert.
// @return: Returns nothing.
void LinkedList::InsertNodeFront(const int value){
    Node* new_node = new Node(value);

    // New node points at the old head, then becomes the new head.
    // This works even if head_ is nullptr (empty list).

    new_node->next = head_;
    head_ = new_node;
    size_++;
}

// implement size check to continue comparing size updates between function test calls
// @return: Returns the current number of nodes in the list.
int LinkedList::GetSize() const{
    return size_;
}

// @param: Takes in a const int target value.
// @return: Returns true if the value is found, false otherwise.
bool LinkedList::Contains(const int value) const{
    Node* current = head_;

    while (current != nullptr) {

        if (current->value == value){
            
            return true;
        }

        current = current->next;
    }
    
    return false;
}

// @param: Takes in a const int representing the 1-based position.
// @return: Returns the integer value at that position.
// @throws: std::out_of_range if the position is < 1 or > size_.
int LinkedList::GetValueAtPosition(const int position) const{

    //validate position with range of 1 - size of list, if outside of range throw out of bounds message 
    if (position < 1 || position > size_) {
       
        throw std::out_of_range("Position is out of range.");
    }

    Node* current = head_;

    for (int i = 1; i < position; i++) {

        current = current->next;
    }

    return current->value;
}

// @param: value to insert, and the 1-based position where it should land.
// @return: Returns nothing.
// @throws: std::out_of_range if the position is invalid.
void LinkedList::InsertNodeAt(const int value, const int position){

    //validate positions using same logic used in getvalueatposition
    if (position < 1 || position > size_ +1) {
        
        throw std::out_of_range("Position is out of range.");
    }

    //re assign at specific positions since logic already implemented 

    if (position == 1) {
        
        InsertNodeFront(value);
        return;
    }

    if (position == size_ + 1) {
        
        InsertNode(value);
        return;
    }

    // otherwise (general case) 
    // same walking through list logic within the range of 1 - position before target position 
    Node* node_previous = head_;
    
    for (int i = 1; i < position - 1; i++) {
        
        node_previous = node_previous->next;
    }


    // create new node to insert between previous node and the node after it to assume position 
    Node* new_node = new Node(value);
    new_node->next = node_previous->next;
    node_previous->next = new_node;
    size_++;
}

// @param: Takes in a const int representing the 1-based position to remove.
// @return: Returns true if successfully removed, false otherwise.
bool LinkedList::Remove(const int position) {
    Node* prev = nullptr;
    Node* current = head_;

    for (int i = 1; i < position; i++) {
       
        prev = current;
        current = current->next;
    }

    if (prev == nullptr) {
        
        head_ = current->next;
    }
    
    else {
       
        prev->next = current->next;
    }

    delete current;
    size_--;
    return true;
}

// @return: Returns a pointer to a new LinkedList containing the reversed nodes.
LinkedList* LinkedList::ReverseList() {
    LinkedList* reversed_list = new LinkedList();

    // walk through list and flip each next node pointer to point backwards 
    Node* current = head_;
    Node* node_previous = nullptr;
    while (current != nullptr) {
        
        Node* next_node = current->next;
        current->next = node_previous;
        node_previous = current; 
        current = next_node;
    }

    // previous points to what used to be end of list 
    reversed_list->head_ = node_previous;
    reversed_list->size_ = size_;

    //original list releases nodes and is empty
    head_ = nullptr;
    size_ = 0;

    return reversed_list;
}

// @param: Takes in a const reference to a second LinkedList.
// @return: Returns a dynamically allocated pointer to the new merged list.
LinkedList* LinkedList::MergeIntertwine(const LinkedList& second_list) const{
    LinkedList* merged_list = new LinkedList();

    Node* current_this = head_;
    Node* current_other = second_list.head_;

    // Alternating values from each list to add to merged list. use InsertNode to append the alternating nodes to merged list 
    // will continue traversing to append altering values so long as one list still has nodes left 
    while (current_this != nullptr || current_other != nullptr) {
        
        if (current_this != nullptr) {
            
            merged_list->InsertNode(current_this->value);
            current_this = current_this->next;
        }

        if (current_other != nullptr) {
            
            merged_list->InsertNode(current_other->value);
            current_other = current_other->next;
        }
    }

    return merged_list;
}

// Free all dynamically allocated memory used by the list's nodes.
// Ensure no orphaned memory is left behind upon object destruction.
LinkedList::~LinkedList() {
    Node* current = head_;
    
    while (current != nullptr) {
        
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }

    head_ = nullptr;
    size_ = 0;
}







