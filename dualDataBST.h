/*	Header for the BST (Binary Search Tree)
	Jeff DeWolfe Oct 23, 2019
	This BST holds two separate data objects	*/

#pragma once
#include <iostream>
using namespace std;

template <typename T1, typename T2>
struct dualDataNode
{
	T1 data1; //Primary data
	T2 data2; //Secondary data
	dualDataNode<T1, T2> *left;
	dualDataNode<T1, T2> *right;
};

template <typename T1, typename T2>
class BST
{
protected:
	dualDataNode<T1, T2> *root;
public:
	BST();
	~BST();
	bool isEmpty() const;
	void insert(const T1& item1, const T2& item2);
	void remove(const T1& item1);
	bool find(T1 item1);
	T2 getSecondaryData(T1 item1);
	void traverse() const;
	void traverse(bool rev) const;
	int leafCount();
	int getHeight();
private:
	bool find(dualDataNode<T1, T2> *p, T1 item1);
	T2 getSecondaryData(dualDataNode<T1, T2> *p, T1 item1);
	void traverse(dualDataNode<T1, T2> *p) const;
	void reverseTraverse(dualDataNode<T1, T2> *p) const;
	void destroy(dualDataNode<T1, T2> *&p);
	void removeFromTree(dualDataNode<T1, T2> *&p);
	int leafCount(dualDataNode<T1, T2> *p);
	int getHeight(dualDataNode<T1, T2> *p);
};