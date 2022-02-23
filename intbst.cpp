// intbst.cpp
// Implements class IntBST
// Nik Belle 5564083
// Mihir Bharti 5149646
// 2/22/22

#include <iostream>
using std::cout;
using std::endl;

template <class T>
// constructor sets up empty tree
IntBST<T>::IntBST() : root(nullptr) { }

template <class T>
// destructor deletes all nodes
IntBST<T>::~IntBST() {
    clear(root);
}

template <class T>
// recsive helper for destructor
void IntBST<T>::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}

template <class T>
// insert value in tree; return false if duplicate
bool IntBST<T>::insert(T value) {
    // handle special case of empty tree first
    if (!root) {
	root = new Node(value);
	return true;
    }
    // otherwise use recsive helper
    return insert(value, root);
}

template <class T>
// recsive helper for insert (assumes n is never 0)
bool IntBST<T>::insert(T value, Node *n) {
    if (value == n->info)
	return false;
    if (value < n->info) {
	if (n->left)
	    return insert(value, n->left);
	else {
	    n->left = new Node(value);
	    n->left->parent = n;
	    return true;
	}
    }
    else {
	if (n->right)
	    return insert(value, n->right);
	else {
	    n->right = new Node(value);
	    n->right->parent = n;
	    return true;
	}
    }
}

template <class T>
// print tree data pre-order
void IntBST<T>::printPreOrder() const {
    printPreOrder(root);
}

template <class T>
// recsive helper for printPreOrder()
void IntBST<T>::printPreOrder(Node *n) const {
    if (n) {
	cout << n->info << " ";
	printPreOrder(n->left);
	printPreOrder(n->right);
    }
}

template <class T>
// print tree data in-order, with helper
void IntBST<T>::printInOrder() const {
    printInOrder(root);
}

template <class T>
void IntBST<T>::printInOrder(Node *n) const {
    if(n){
        printInOrder(n->left);
        cout << n->info << " ";
        printInOrder(n->right);
    }
}

template <class T>
// prints tree data post-order, with helper
void IntBST<T>::printPostOrder() const {
    printPostOrder(root);
}

template <class T>
void IntBST<T>::printPostOrder(Node *n) const {
    if(n){
        printPostOrder(n->left);
        printPostOrder(n->right);
        cout << n->info << " ";
    }
}

template <class T>
// return sum of values in tree
T IntBST<T>::sum() const {
    return sum(root);
}

template <class T>
// recsive helper for sum
T IntBST<T>::sum(Node *n) const {
    if(n){
        return n->info + sum(n->left) + sum(n->right);
    }
    return 0;
}

template <class T>
// return count of values
int IntBST<T>::count() const {
    return count(root);
}

template <class T>
// recsive helper for count
int IntBST<T>::count(Node *n) const {
    if(n){
        return 1 + count(n->left) + count(n->right);
    }
    return 0;
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recsive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"

template <class T>
typename IntBST<T>::Node* IntBST<T>::getNodeFor(T value, Node* n) const{
    if(n){
        if(n->info == value){
            return n;
        }
        else if(n->info < value){
            return getNodeFor(value, n->right);
        }
        else if(n->info > value){
            return getNodeFor(value, n->left);
        }
    }
    return NULL;
    
}

template <class T>
// returns true if value is in the tree; false if not
bool IntBST<T>::contains(T value) const {
    if(getNodeFor(value, root) != NULL){
        return true;
    }
    return false;
}

template <class T>
// returns the Node containing the predecessor of the given value
typename IntBST<T>::Node* IntBST<T>::getPredecessorNode(T value) const{
    Node* n = getNodeFor(value, root);
    if(n != NULL){
        if(n->left != NULL){
            n = n->left;
            while(n->right){
                n = n->right;
            }
            return n;
        }
        else{
            if(n->parent->right == n){
                return n->parent;
            }

            else if(n->parent->left == n){
                T val = n->info;
                while(n->parent != root && n->parent->left == n){
                    n = n->parent;
                }
                if(n->parent->info < val){
                    n = n->parent;
                }
                else{
                    return NULL;
                }
                return n;
                
            }
        }
    }
    return NULL;
}

template <class T>
// returns the predecessor value of the given value or 0 if there is none
T IntBST<T>::getPredecessor(T value) const{
    if(getPredecessorNode(value)){
        return getPredecessorNode(value)->info;
    }
    return 0;
    
}

template <class T>
// returns the Node containing the successor of the given value
typename IntBST<T>::Node* IntBST<T>::getSuccessorNode(T value) const{
    Node* n = getNodeFor(value, root);
    if(n != NULL){
        if(n->right != NULL){
            n = n->right;
            while(n->left){
                n = n->left;
            }
            return n;
        }
        else{
            if(n->parent->left == n){
                return n->parent;
            }

            else if(n->parent->right == n){
                T val = n->info;
                while(n->parent != root && n->parent->right == n){
                    n = n->parent;
                }
                if(n->parent->info > val){
                    n = n->parent;
                }
                else{
                    return NULL;
                }
                return n;
                
            }
        }
    }
    return NULL;
}

template <class T>
// returns the successor value of the given value or 0 if there is none
T IntBST<T>::getSuccessor(T value) const{
    if(getSuccessorNode(value)){
        return getSuccessorNode(value)->info;
    }
    return 0;
}

template <class T>
// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST<T>::remove(T value){
    Node* n = getNodeFor(value, root);
    if(n){
        Node* parent = n->parent;
        Node* c = root;

        if (n->left == NULL && n->right == NULL) {
            if (n==root) {
                root = NULL;
            }     
            else { 
                if (parent->left == n) {
                    parent->left = NULL;
                }  
                else {
                    parent->right = NULL;
                }
            }   
        }

        else if (n->left != NULL && n->right == NULL) {
            if (n == root) {
                root = n->left;
            } 
            else {
                if (parent->left == n) {
                    parent->left = n->left;
                }
                else {
                    parent->right = n->left;
                }
            }
            n->left->parent = parent;
            delete n;
        }

        else if (c->left == NULL && n->right != NULL) {
            if (n == root) {
                root = n->right;
            }
            else {
                if (parent->left == n) {
                    parent->left = n->right;
                }
                else {
                    parent->right = n->right;
                }
            }
            n->right->parent = parent;
            delete n;
        }

        else {
            T successor = getSuccessor(value);
            remove(successor);
            n->info = successor;
        }
        return true;
    }
    return false;
}