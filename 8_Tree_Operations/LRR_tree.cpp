
#include <iostream>
using namespace std;

/*
    -------------------------
      AVL TREE IMPLEMENTATION
    -------------------------
    Each node stores:
    - data      : Value
    - lchild    : Pointer to left subtree
    - rchild    : Pointer to right subtree
    - height    : Height of the node (1 for leaf)
*/

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
    int height;
};

class AVL
{
public:
    Node *root;

    AVL() { root = nullptr; }

    // Utility functions
    int NodeHeight(Node *p);
    int BalanceFactor(Node *p);

    // Rotations
    Node *LLRotation(Node *p);
    Node *RRRotation(Node *p);
    Node *LRRotation(Node *p);
    Node *RLRotation(Node *p);

    // Insert operation
    Node *rInsert(Node *p, int key);

    // Traversal
    void Inorder(Node *p);
    void Inorder() { Inorder(root); }

    Node *getRoot() { return root; }
};

/*-------------------------------------------------------
    Function: NodeHeight
    Purpose : Calculate height based on child heights
 -------------------------------------------------------*/
int AVL::NodeHeight(Node *p)
{
    if (!p)
        return 0;

    int hl = p->lchild ? p->lchild->height : 0;
    int hr = p->rchild ? p->rchild->height : 0;

    return max(hl, hr) + 1;
}

/*-------------------------------------------------------
    Function: BalanceFactor
    Purpose : Determine if node is balanced
              BF = height(left subtree) - height(right subtree)
              Valid AVL values = {-1, 0, 1}
 -------------------------------------------------------*/
int AVL::BalanceFactor(Node *p)
{
    if (!p)
        return 0;

    int hl = p->lchild ? p->lchild->height : 0;
    int hr = p->rchild ? p->rchild->height : 0;

    return hl - hr;
}

/*-------------------------------------------------------
                LL ROTATION (Left-Left Case)
    Trigger: Inserting into left subtree of left child
 -------------------------------------------------------*/
Node *AVL::LLRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    // Perform rotation
    pl->rchild = p;
    p->lchild = plr;

    // Update heights
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    // If p was root, update root
    if (p == root)
        root = pl;

    return pl; // new root of subtree
}

/*-------------------------------------------------------
                RR ROTATION (Right-Right Case)
    Trigger: Inserting into right subtree of right child
 -------------------------------------------------------*/
Node *AVL::RRRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    // Perform rotation
    pr->lchild = p;
    p->rchild = prl;

    // Update heights
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    // If p was root, update root
    if (p == root)
        root = pr;

    return pr; // new root of subtree
}

/*-------------------------------------------------------
                LR ROTATION (Left-Right Case)
    Trigger: Inserted into RIGHT subtree of LEFT child
 -------------------------------------------------------*/
Node *AVL::LRRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    // First rotate left subtree (Left-Right)
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    // Now rotate with parent
    plr->lchild = pl;
    plr->rchild = p;

    // Update heights
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    // Update root if needed
    if (p == root)
        root = plr;

    return plr;
}

/*-------------------------------------------------------
                RL ROTATION (Right-Left Case)
    Trigger: Inserted into LEFT subtree of RIGHT child
 -------------------------------------------------------*/
Node *AVL::RLRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    // First rotation on right child
    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;

    // Now rotate with parent
    prl->lchild = p;
    prl->rchild = pr;

    // Update heights
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    // Update root if required
    if (p == root)
        root = prl;

    return prl;
}

/*-------------------------------------------------------
                    AVL INSERTION
    Recursive insert, then update heights,
    and perform rotations if balance is violated.
 -------------------------------------------------------*/
Node *AVL::rInsert(Node *p, int key)
{

    // Normal BST insertion
    if (p == nullptr)
    {
        Node *t = new Node;
        t->data = key;
        t->lchild = t->rchild = nullptr;
        t->height = 1; // leaf node height is 1
        return t;
    }

    if (key * p)
    {
        if (p)
        {
            Inorder(p->lchild);
            cout << p->data << " ";
            Inorder(p->rchild);
        }
    }

    /*-------------------------------------------------------
                             MAIN
     -------------------------------------------------------*/
    int main()
    {

        // LL Rotation Demo
        AVL t1;
        t1.root = t1.rInsert(t1.root, 30);
        ;

        // RR Rotation Demo
        AVL t2;
        t2.root = t2.rInsert(t2.root, 10);
        t2.root = t2.rInsert(t2.root, 20);
        t2.root = t2.rInsert(t2.root, 30);
        cout << "RR Rotation: ";
        t2.Inorder();
        cout << endl;

        return 0;
    }
