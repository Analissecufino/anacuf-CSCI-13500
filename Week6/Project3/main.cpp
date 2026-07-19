#include <iostream>
#include "linkedlist.hpp"

int main() {

// test constructor 
LinkedList list;
std::cout << "LinkedList constructed OK" << std::endl;


// test for InsertNode function 
list.InsertNode(10);
list.InsertNode(20);
list.InsertNode(30);
std::cout << "InsertNode calls completed" << std::endl;

// test for PrintValues function 
list.PrintValues();

// test for PrintAddresses function 
list.PrintAddresses();


// test for InsertNodeFront
list.InsertNodeFront(5);
list.PrintValues();


// test for GetSize function 
std::cout << "size: " << list.GetSize() << std::endl;


// test for Contains function 
std::cout << "contains 20: " << list.Contains(20) << std::endl;
std::cout << "contains 99: " << list.Contains(99) << std::endl;

// test for GetValueAtPosition function 
std::cout << "position 2: " << list.GetValueAtPosition(2) << std::endl;
try {
  list.GetValueAtPosition(99);
} catch (const std::out_of_range& e) {
  std::cout << "caught: " << e.what() << std::endl;
}

// test for InsertNodeAt function
list.InsertNodeAt(15, 3);
list.PrintValues();

// test for Remove function 
bool removed = list.Remove(1);
std::cout << "removed: " << removed << std::endl;
list.PrintValues();
std::cout << "size now: " << list.GetSize() << std::endl;

// test for reverselist function

LinkedList* reversed = list.ReverseList();
std::cout << "original list: ";
list.PrintValues();
std::cout << "reversed list: ";
reversed->PrintValues();
std::cout << "original list size: " << list.GetSize() << std::endl;

// test for MergeIntertwine function

LinkedList list_a, list_b;
list_a.InsertNode(1);
list_a.InsertNode(2);
list_b.InsertNode(100);
list_b.InsertNode(200);
list_b.InsertNode(300);

LinkedList* merged = list_a.MergeIntertwine(list_b);
std::cout << "list_a: "; list_a.PrintValues();
std::cout << "list_b: "; list_b.PrintValues();
std::cout << "merged: "; merged->PrintValues();

//test for destructor

delete reversed;
delete merged;



return 0;
}

