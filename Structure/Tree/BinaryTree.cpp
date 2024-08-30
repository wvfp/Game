#include "BinaryTree.hpp"

template<typename T>
Tree<T>::Tree():_size(0)
{}

template<typename T>
Tree<T>::Tree(const T* arr,int sz){
	for(int i=0;i < sz;i++){
		this->insert(arr[i]);
	}
	_size=sz;
	return;
}

template<typename T>
Tree<T> Tree<T>::operator=(const Tree<T>  t){
	_size = t._size;
	root = t.root;
	return *this;
}
template<typename T>
Tree<T> Tree<T>::copy(){
	Tree<T> tmp;
	tmp._size = this->_size;
	tmp.root = this->root->copy();
	return tmp;
}

template<typename T>
void Tree<T>::insert(T& val){
	NodePtr<T> node = NodePtr<T>(nullptr,new Node(val));
	root->add(node);	
}

template<typename T>
void Tree<T>::search(const T&){
	
}

template<typename T>
void Tree<T>::remove(const T&){

}

template<typename T>
bool Tree<T>::empty(){
	return _size==0;
}


