/*	Implementation of the BST (Binary Search Tree)
	Jeff DeWolfe Oct 23, 2019
	This BST holds two separate data objects	*/

#include <algorithm>
#include "dualDataBST.h"
using namespace std;

//CONSTRUCTOR
template <typename T1, typename T2>
BST<T1, T2>::BST()
{
	root = NULL;
}

//DESTRUCTOR
template <typename T1, typename T2>
BST<T1, T2>::~BST()
{
	destroy(root);
}

//IS EMPTY?
template <typename T1, typename T2>
bool BST<T1, T2>::isEmpty() const
{
	return (root == NULL); //If root is NULL, Tree is empty
}

//INSERT
template <typename T1, typename T2>
void BST<T1, T2>::insert(const T1& item1, const T2& item2)
{
	dualDataNode<T1, T2> *newNode = new dualDataNode<T1, T2>; //Construct node to insert
	dualDataNode<T1, T2> *current;
	dualDataNode<T1, T2> *trail;

	newNode->data1 = item1; //Primary data
	newNode->data2 = item2; //Secondary data
	newNode->left = NULL;
	newNode->right = NULL;

	if (isEmpty())
		this->root = newNode;

	else
	{
		current = this->root; //Start at root
		trail = NULL;

		while (current != NULL)
		{
			trail = current;

			if (current->data1 == item1)
			{
				cout << "No duplicates allowed (" << item1 << ")" << endl;
				return;
			}
			else if (current->data1 > item1)
				current = current->left;
			else
				current = current->right;
		}
		if (trail->data1 > item1)
			trail->left = newNode;
		else
			trail->right = newNode;
	}
}

//REMOVE
template <typename T1, typename T2>
void BST<T1, T2>::remove(const T1& item1)
{
	dualDataNode<T1, T2> *curr;
	dualDataNode<T1, T2> *trail;
	bool found = false;

	if (this->root == NULL)
		cout << "Nothing to delete" << endl;
	else
	{
		curr = this->root; //Start at the root
		trail = curr;

		while (curr != NULL && !found) //Until found
		{
			if (curr->data1 == item1)
				found = true;
			else
			{
				trail = curr;
				if (curr->data1 > item1)
					curr = curr->left;
				else
					curr = curr->right;
			}
		}

		if (found)
		{
			if (curr == this->root)
				removeFromTree(this->root); //If root, remove root
			else if (trail->data1 > item1)
				removeFromTree(trail->left);
			else
				removeFromTree(trail->right);
		}
		else
			cout << "Item not found" << endl;
	}
}

//FIND Start
template <typename T1, typename T2>
bool BST<T1, T2>::find(T1 item1)
{
	return find(root, item1); //Use root if node not specified
}

//FIND
template <typename T1, typename T2>
bool BST<T1, T2>::find(dualDataNode<T1, T2> *p, T1 item1)
{
	if (p == NULL) return false;
	if (p->data1 == item1) return true;
	if (p->data1 > item1) return find(p->left, item1);
	else return find(p->right, item1);
}

//GET DATA Start
template <typename T1, typename T2>
T2 BST<T1, T2>::getSecondaryData(T1 item1)
{
	return getSecondaryData(root, item1); //Use root if node not specified
}

//GET DATA
template <typename T1, typename T2>
T2 BST<T1, T2>::getSecondaryData(dualDataNode<T1, T2> *p, T1 item1)
{
	if (p == NULL) return NULL;
	if (p->data1 == item1) return p->data2;
	if (p->data1 > item1) return getSecondaryData(p->left, item1);
	else return getSecondaryData(p->right, item1);
}

//TRAVERSE Start
template <typename T1, typename T2>
void BST<T1, T2>::traverse() const
{
	traverse(root); //Use root if node not specified
}

//TRAVERSE Start
template <typename T1, typename T2>
void BST<T1, T2>::traverse(bool rev) const
{
	if (rev) reverseTraverse(root); //Reverse = true
	else traverse(root);
}

//TRAVERSE & Print
template <typename T1, typename T2>
void BST<T1, T2>::traverse(dualDataNode<T1, T2> *p) const
{
	if (p != NULL)
	{
		traverse(p->left);
		cout << p->data1 << " ";
		traverse(p->right);
	}
}

//REVERSE & Print
template <typename T1, typename T2>
void BST<T1, T2>::reverseTraverse(dualDataNode<T1, T2> *p) const
{
	if (p != NULL)
	{
		reverseTraverse(p->right);
		cout << p->data1 << " ";
		reverseTraverse(p->left);
	}
}

//DESTROY
template <typename T1, typename T2>
void BST<T1, T2>::destroy(dualDataNode<T1, T2> *&p)
{
	if (p != NULL)
	{
		destroy(p->left);
		destroy(p->right);
		//cout << "Destroying " << p->data1 << endl;
		delete p; //Delete node
		p = NULL; //Set to NULL
	}
}

//REMOVE FROM TREE
template <typename T1, typename T2>
void BST<T1, T2>::removeFromTree(dualDataNode<T1, T2> *&p)
{
	dualDataNode<T1, T2> *curr;
	dualDataNode<T1, T2> *trail;
	dualDataNode<T1, T2> *temp;

	if (p == NULL)
		cout << "Nothing to delete" << endl;

	else if (p->left == NULL && p->right == NULL) //If leaf
	{
		temp = p; //Hold temp node
		p = NULL; //Set  to NULL
		delete temp; //Get rid of temp 
	}
	else if (p->left == NULL)
	{
		temp = p;
		p = temp->right;
		delete temp;
	}
	else if (p->right == NULL)
	{
		temp = p;
		p = temp->left;
		delete temp;
	}
	else
	{
		curr = p->left;
		trail = NULL;
		while (curr->right != NULL)
		{
			trail = curr;
			curr = curr->right;
		}
		p->data1 = curr->data1;
		if (trail == NULL)
			p->left = curr->left;
		else
			trail->right = curr->left;
		delete curr;
	}
}

//LEAF COUNT Start
template <typename T1, typename T2>
int BST<T1, T2>::leafCount()
{
	return leafCount(root); //Use root if node not specified
}

//LEAF COUNT
template <typename T1, typename T2>
int BST<T1, T2>::leafCount(dualDataNode<T1, T2> *p)
{
	if (p == NULL) return 0;
	if (p->left == NULL && p->right == NULL) return 1; //Count leaf if no branches
	else return leafCount(p->left) + leafCount(p->right); //Recursive
}

//HEIGHT Start
template <typename T1, typename T2>
int BST<T1, T2>::getHeight()
{
	return getHeight(root); //Use root if node not specified
}

//HEIGHT
template <typename T1, typename T2>
int BST<T1, T2>::getHeight(dualDataNode<T1, T2> *p)
{
	if (p == NULL) return -1; //No height if node is not there
	return 1 + max(getHeight(p->left), getHeight(p->right)); //Return the biggest
}