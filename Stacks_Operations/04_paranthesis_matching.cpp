#include <iostream>      // Include input/output stream library
#include <cstring>       // Include C string manipulation functions
using namespace std;     // Use the standard namespace

// Node class for linked list implementation of stack
class Node
{
public:
    char data;           // Data stored in the node (character)
    Node *next;          // Pointer to the next node
};

// Stack class using linked list
class Stack
{
private:
    Node *top;           // Pointer to the top of the stack

public:
    Stack();             // Constructor
    ~Stack();            // Destructor
    void push(char x);   // Push a character onto the stack
    char pop();          // Pop a character from the stack
    char peek(int index);// Peek at a specific index in the stack
    int isEmpty();       // Check if the stack is empty
    int isFull();        // Check if the stack is full (always false for linked list)
    char stackTop();     // Get the top character of the stack
};

// Constructor: initialize top to nullptr
Stack::Stack()
{
    top = nullptr;
}

// Destructor: delete all nodes in the stack
Stack::~Stack()
{
    Node *p = top;           // Start from the top
    while (top)              // While there are nodes
    {
        top = top->next;     // Move top to next node
        delete p;            // Delete current node
        p = top;             // Move p to new top
    }
}

// Push a character onto the stack
void Stack::push(char x)
{
    Node *t = new Node;      // Create a new node
    if (t == nullptr)        // Check if memory allocation failed
    {
        cout << "Stack Overflow!" << endl; // Print overflow message
    }
    else
    {
        t->data = x;         // Set node data
        t->next = top;       // Point to current top
        top = t;             // Update top to new node
    }
}

// Pop a character from the stack
char Stack::pop()
{
    Node *p;
    char x = -1;             // Default return value if stack is empty
    if (top == nullptr)      // If stack is empty
    {
        cout << "Stack Underflow!" << endl; // Print underflow message
    }
    else
    {
        p = top;             // Point to top node
        x = p->data;         // Get data from top node
        top = top->next;     // Move top to next node
        delete p;            // Delete old top node
    }
    return x;                // Return popped value
}

// Check if the stack is full (always returns 1 if memory is available)
int Stack::isFull()
{
    Node *t = new Node;      // Try to allocate a new node
    int r = t ? 1 : 0;       // If allocation successful, return 1, else 0
    delete t;                // Free allocated node
    return r;
}

// Check if the stack is empty
int Stack::isEmpty()
{
    return top ? 0 : 1;      // Return 1 if top is nullptr, else 0
}

// Get the character at the top of the stack
char Stack::stackTop()
{
    if (top)
    {
        return top->data;    // Return data if stack is not empty
    }
    return -1;               // Return -1 if stack is empty
}

// Peek at a specific index in the stack (1-based index)
char Stack::peek(int index)
{
    if (isEmpty())
    {
        return -1;           // Return -1 if stack is empty
    }
    else
    {
        Node *p = top;       // Start from top

        for (int i = 0; p != nullptr && i < index - 1; i++)
        {
            p = p->next;     // Move to next node
        }

        if (p != nullptr)
        {
            return p->data;  // Return data at index
        }
        else
        {
            return -1;       // Return -1 if index is out of bounds
        }
    }
}

// Function to check if parentheses in an expression are balanced
int isBalanced(char *exp)
{
    Stack stk;               // Create a stack

    for (int i = 0; i < strlen(exp); i++) // Loop through each character
    {
        if (exp[i] == '(')   // If opening parenthesis
        {
            stk.push(exp[i]); // Push to stack
        }
        else if (exp[i] == ')') // If closing parenthesis
        {
            if (stk.isEmpty())  // If stack is empty, not balanced
            {
                return false;
            }
            else
            {
                stk.pop();      // Pop matching opening parenthesis
            }
        }
    }
    return stk.isEmpty() ? true : false; // If stack is empty, balanced
}

// Main function to test isBalanced
int main()
{

    char E[] = "((a+b)*(c-d))";      // Balanced expression
    cout << isBalanced(E) << endl;   // Output: 1 (true)

    char F[] = "((a+b)*(c-d)))";     // Extra closing parenthesis
    cout << isBalanced(F) << endl;   // Output: 0 (false)

    char G[] = "(((a+b)*(c-d))";     // Missing closing parenthesis
    cout << isBalanced(G) << endl;   // Output: 0 (false)

    return 0;
}