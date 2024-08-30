#ifndef _BINARYTREE_
#define _BINARYTREE_

#include <memory>
#include <iostream>
#include <vector>

template<typename T>
class Tree;

template<typename T>
class Node;

template<typename T>
using NodePtr = std::shared_ptr<Node<T> >;

template<typename T>
class Tree{
public:
	using ElementType = T;

	Tree();
	//Tree(const vector<T>&);
	Tree(const T*,int);
	Tree<T> operator=(const Tree<T>);
	Tree<T> copy();
	void insert(T&);
	void search(const T&);
	void remove(const T&);
	bool empty();
	NodePtr<T>& maxNode();
	NodePtr<T>& minNode(); 
	T& max();
	T& min(); 
	NodePtr<T> getRootNdoe();
	unsigned int height();
	unsigned int size();
	void clear();
	void inorderTreeWalk();
	void preorderTreeWalk();
	void postorderTreeWalk();
private:
	NodePtr<T> root;
	unsigned int _size;
};


template<typename T>
class Node{
public:
	Node(NodePtr<T>,const T&);
	Node(const T&&);
	Node<T> operator=(const Node& rhs);
	Node<T> copy();
	void* add(const Node&);
	void setParent(NodePtr<T> p){
		parent = p;
	}
	T& getValue(){
		return value;
	}
private:
	T value;
	NodePtr<T> parent;
	NodePtr<T> left;
	NodePtr<T> right;
};

#endif //_BINARYTREE_
