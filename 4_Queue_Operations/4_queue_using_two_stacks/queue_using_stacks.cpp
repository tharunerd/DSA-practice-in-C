#include <iostream>
#include <stack>

using namespace std;

/*
 * Queue implemented using two stacks:
 *  - e_stk (enqueue stack): used to push new elements.
 *  - d_stk (dequeue stack): used to pop elements in FIFO order.
 *
 * Core idea:
 *  - Enqueue: push directly onto e_stk.
 *  - Dequeue: if d_stk is empty, move all items from e_stk to d_stk (reverses order),
 *             then pop from d_stk. This achieves FIFO behavior.
 */
class Queue
{
private:
    stack<int> e_stk; // Stack for enqueue operations
    stack<int> d_stk; // Stack for dequeue operations

public:
    Queue() = default;
    ~Queue() = default;

    void enqueue(int x);
    int dequeue();
};

void Queue::enqueue(int x)
{
    // Always push to the enqueue stack
    e_stk.push(x);
}

int Queue::dequeue()
{
    // Default return value if queue is empty (underflow)
    int x = -1;

    // If the dequeue stack is empty, we may need to transfer from enqueue stack
    if (d_stk.empty())
    {
        // If both stacks are empty, the queue is empty -> underflow
        if (e_stk.empty())
        {
            cout << "Queue Underflow" << endl;
            return x;
        }
        else
        {
            // Move all elements from e_stk to d_stk to maintain FIFO order
            while (!e_stk.empty())
            {
                d_stk.push(e_stk.top());
                e_stk.pop();
            }
        }
    }

    // Now d_stk has the front element on top
    x = d_stk.top();
    d_stk.pop();
    return x;
}

// Small helper to compute array length at compile time
template <typename T, size_t N>
constexpr size_t arr_len(const T (&)[N]) { return N; }

int main()
{
    int A[] = {1, 3, 5, 7, 9};
    const size_t n = arr_len(A);

    Queue q;

    cout << "Enqueue: " << flush;
    for (size_t i = 0; i < n; i++)
    {
        q.enqueue(A[i]);
        cout << A[i] << flush;
        if (i < n - 1)
        {
            cout << " <- " << flush;
        }
    }
    cout << endl;

    cout << "Dequeue: " << flush;
    for (size_t i = 0; i < n; i++)
    {
        cout << q.dequeue() << flush;
        if (i < n - 1)
        {
            cout << " <- " << flush;
        }
    }
    cout << endl;

    return 0;
}
