#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int passed_value): value(passed_value), next(nullptr) {};
};

int main(){
    Node n(10);
    std::cout << "value: " << n.value << std::endl;
    std::cout << "next: " << n.next << std::endl;
    return 0;
}
