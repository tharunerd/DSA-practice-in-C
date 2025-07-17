// stacks using c++
#include <iostream>
#include <stack>
using namespace std;

class Stack {
private:
    stack<int> s;
public:
    // Push an element onto the stack
    void push(int value) {
        s.push(value);
    }

    // Pop an element from the stack
    void pop() {
        if (!s.empty()) {
            s.pop();
        } else {
            cout << "Stack is empty, cannot pop." << endl;
        }
    }

    // Get the top element of the stack
    int top() {
        if (!s.empty()) {
            return s.top();
        } else {
            cout << "Stack is empty, no top element." << endl;
            return -1; // or throw an exception
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return s.empty();
    }

    // Get the size of the stack
    int size() {
        return s.size();
    }

    void display() {
        stack<int> temp = s; // Create a copy to display elements
        cout << "Stack elements: ";
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    // Clear the stack
    void clear() {
        while (!s.empty()) {
            s.pop();
        }
    }

    peek() {
        return top();
    }   
    ~Stack() {
        clear(); // Ensure stack is cleared on destruction
    }   
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "Top element: " << stack.top() << endl;

    stack.pop();
    stack.display();

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Stack size: " << stack.size() << endl;

    stack.clear();
    cout << "After clearing, is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
