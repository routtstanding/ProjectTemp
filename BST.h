#pragma once
//michelle routt copied and pasted from skeleton


//
// Created by Henok on 10/12/2022.
// Specified that we could use it on the Project
// This also contains the functions Michelle Routt wrote for the HW3
//


#include <algorithm>
#include <iostream>
#include <algorithm>

#include "Exceptions.h"

using namespace std;

// BinarySearchTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void _insert( x )       --> Insert x
// void _remove( x )       --> Remove x
// bool _contains( x )     --> Return true if x is present
// Comparable FindMin( )  --> Return smallest item
// Comparable FindMax( )  --> Return largest item
// boolean IsEmpty( )     --> Return true if empty; else false
// void Clear( )      --> Remove all items
// void _printTreeInorder( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class BinarySearchTree
{
public:
    BinarySearchTree() : _root{ nullptr }
    {
    }

    /**
     * Copy constructor
     */
    BinarySearchTree(const BinarySearchTree& rhs) : _root{ nullptr }
    {
        _root = _clone(rhs._root);
    }

    /**
     * Move constructor
     */
    BinarySearchTree(BinarySearchTree&& rhs)  noexcept : _root{ rhs._root }
    {
        rhs._root = nullptr;
    }

    /**
     * Destructor for the tree
     */
    ~BinarySearchTree()
    {
        Clear();
    }

    /**
     * Copy assignment
     */
    BinarySearchTree& operator=(const BinarySearchTree& rhs)
    {
        BinarySearchTree copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    /**
     * Move assignment
     */
    BinarySearchTree& operator=(BinarySearchTree&& rhs)
    {
        std::swap(_root, rhs._root);
        return *this;
    }


    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable& FindMin() const
    {
        if (IsEmpty())
            throw UnderflowException{ };
        return _findMin(_root)->element;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable& FindMax() const
    {
        if (IsEmpty())
            throw UnderflowException{ };

        return _findMax(_root)->element;
    }

    int Height() {
        return _height(_root);
    }

    int Depth(const Comparable& element) {
        cout << "Depth of node " << element << " = ";
        return _depth(_root, element);
    }

    /**
     * Returns true if x is found in the tree.
     */
    bool Contains(const Comparable& x) const
    {
        return _contains(x, _root);
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool IsEmpty() const
    {
        return _root == nullptr;
    }

    /**
     * Print the tree contents in sorted order.
     */
    void PrintTree(ostream& out = cout) const
    {
        if (IsEmpty())
            out << "Empty tree" << endl;

        else {
            //cout << "Root: " << _root->element << endl;
            
            cout << "In-Order: " << endl;
            _printTreeInorder(_root, out);
            cout << endl;

            //commenting these out since we only care about in order

            /*cout << "Pre-Order: " << endl;
            _printTreePreOrder(_root, out);
            cout << endl;
            
            cout << "Post-Order: " << endl;;
            _printTreePostOrder(_root, out);
            cout << endl;*/
        }

        out << endl;
    }

    /**
     * Make the tree logically empty.
     */
    void Clear()
    {
        _makeEmpty(_root);
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void Insert(const Comparable& x)
    {
        _insert(x, _root);
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void Insert(Comparable&& x)
    {
        _insert(std::move(x), _root);
    }

    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void Remove(const Comparable& x)
    {
        _remove(x, _root);
    }


private:
    struct BinaryNode
    {
        //int data; //MR was here
        Comparable element;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt)
            : element{ theElement }, left{ lt }, right{ rt } { }

        BinaryNode(Comparable&& theElement, BinaryNode* lt, BinaryNode* rt)
            : element{ std::move(theElement) }, left{ lt }, right{ rt } { }
    };

    BinaryNode* _root;


    /**
     * Internal method to _insert into a subtree.
     * x is the item to _insert.
     * t is the node that roots the subtree.
     * Set the new _root of the subtree.
     */
    void _insert(const Comparable& x, BinaryNode*& t)
    {
        if (t == nullptr)
            t = new BinaryNode{ x, nullptr, nullptr };
        else if (x < t->element)
            _insert(x, t->left);
        else if (t->element < x)
            _insert(x, t->right);
        else
            ;  // Duplicate; do nothing
    }

    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
    bool _contains(const Comparable& x, BinaryNode* t) const
    {
        if (t == nullptr)
            return false;
        else if (x < t->element)
            return _contains(x, t->left);
        else if (t->element < x)
            return _contains(x, t->right);
        else
            return true;    // Match
    }

    /**
     * Internal method to make subtree empty.
     */
    void _makeEmpty(BinaryNode*& t)
    {
        if (t != nullptr)
        {
            _makeEmpty(t->left);
            _makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }

    /**
     * Internal method to _insert into a subtree.
     * x is the item to _insert.
     * t is the node that roots the subtree.
     * Set the new _root of the subtree.
     */
    void _insert(Comparable&& x, BinaryNode*& t)
    {
        if (t == nullptr)
            t = new BinaryNode{ std::move(x), nullptr, nullptr };
        else if (x < t->element)
            _insert(std::move(x), t->left);
        else if (t->element < x)
            _insert(std::move(x), t->right);
        else
            ;  // Duplicate; do nothing
    }

    /**
     * Internal method to _remove from a subtree.
     * x is the item to _remove.
     * t is the node that roots the subtree.
     * Set the new _root of the subtree.
     */
    void _remove(const Comparable& x, BinaryNode*& t)
    {
        if (t == nullptr)
            return;   // Item not found; do nothing
        if (x < t->element)
            _remove(x, t->left);
        else if (t->element < x)
            _remove(x, t->right);
        else if (t->left != nullptr && t->right != nullptr) // Two children
        {
            t->element = _findMin(t->right)->element;
            _remove(t->element, t->right);
        }
        else
        {
            BinaryNode* oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
        }
    }

    /**
     * Internal method to _clone subtree.
     */
    BinaryNode* _clone(BinaryNode* t) const
    {
        if (t == nullptr)
            return nullptr;
        else
            return new BinaryNode{ t->element, _clone(t->left), _clone(t->right) };
    }


    BinaryNode* _findMin(BinaryNode* t) const
    {

        BinaryNode* current = t;

        while (current->left != NULL)
        {
            current = current->left;
        }
        return (current);

        //michelle routt here
        //basically what i want to do is recursively loop through the entire BST
        //find whatever node is NULL
        //the whatever node's left node is "null", this will be the min val

        //the return needs to be an int for the main


    }


    /**
     * Internal method to GetHashValue the largest item in a subtree t.
     * Return node containing the largest item.
     */
    BinaryNode* _findMax(BinaryNode* t) const
    {
        BinaryNode* current = t;

        while (current->right != NULL)
        {
            current = current->right;
        }
        return (current);

        //michelle routt here
         //basically what i want to do is recursively loop through the entire BST
         //find whatever node is NULL
         //the whatever node's RIGHT node is "null", this will be the min val




    }



    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void _printTreeInorder(BinaryNode* t, ostream& out) const
    {
        //LVR

        if (t == NULL)
        {
            return;
        }

        _printTreeInorder(t->left, out);

        out << t->element << " ";

        _printTreeInorder(t->right, out);



    }

    void _printTreePostOrder(BinaryNode* t, ostream& out) const
    {
        //LRV

        if (t == NULL)
        {
            return;
        }

        _printTreePostOrder(t->left, out);

        _printTreePostOrder(t->right, out);

        out << t->element << " ";

        //i think the tree given in the main is broken .. should i fix?

    }

    void _printTreePreOrder(BinaryNode* t, ostream& out) const
    {
        //VLR

        if (t == NULL)
        {
            return;
        }

        out << t->element << " ";

        _printTreePreOrder(t->left, out);

        _printTreePreOrder(t->right, out);

    }


    int _height(BinaryNode* t)
    {
        //number of edges from the root to the deepest node
        //empty tree = height 0

        int h = 0;

        if (t == NULL) //if tree is empty return nothing
        {
            return 0;
        }

        //recursively do a depth search

        int depthL = _height(t->left);
        int depthR = _height(t->right);

        if (depthL > depthR)
        {
            return (depthL + 1);
        }
        else
        {
            return (depthR + 1);
        }

        //return h;
    }
};

//#endif //HW3_BST_H
