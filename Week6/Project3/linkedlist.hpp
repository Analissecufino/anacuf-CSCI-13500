#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP 

struct Node {
    int value;
    Node* next;
    Node(int passed_value): value(passed_value), next(nullptr) {}
}; 

class LinkedList {
 public:
    LinkedList();                 
    ~LinkedList();

    // @param: Takes in a const int parameter representing the value to insert.
    // @return: Returns nothing.
    void InsertNode(const int value);

    // @param: Takes in a const int parameter representing the value to insert.
    // @return: Returns nothing.
    void InsertNodeFront(const int value);

    // @param: Takes in a const int target value.
    // @return: Returns true if the value is found, false otherwise.
    bool Contains(const int value) const;

    // @param: Takes in a const int representing the 1-based position to remove.
    // @return: Returns true if successfully removed, false otherwise
    bool Remove(const int position);

    // prints all values in the list in "10 -> 23 -> 4 -> nullptr" format.
    void PrintValues() const;

    // prints the 1-based position and memory address of every node
    void PrintAddresses() const;

    // @param: Takes in a const int representing the 1-based position.
    // @return: Returns the integer value at that position.
    // @throws: std::out_of_range if the position is < 1 or > size_.
    int GetValueAtPosition(const int position) const;

    // Reverses the list in place, then transfers ownership of the reversed nodes to new heap.
    // @return: Returns a pointer to a new LinkedList containing the reversed nodes 
    LinkedList* ReverseList();

    // @param: value to insert, and the 1-based position where it should land.
    // @return: Returns nothing.
    // @throws: std::out_of_range if the position is invalid.   
    void InsertNodeAt(const int value, const int position);

    // @return: the current number of nodes in the list.
    int GetSize() const;

    // Builds a new merged list by alternating values from this list and second list 
    LinkedList* MergeIntertwine(const LinkedList& second_list) const;

 private: 
    int size_;
    Node* head_;   
};

#endif //LINKEDLIST_HPP