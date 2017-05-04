#ifndef __TREE_H__
#define __TREE_H__
#include "node.h"
using namespace std;
template <typename T>
class Tree{
public:
	~Tree();
	void insert( T );
	bool contains(Node<T> * N, T);
	bool contains( T );
	void remove( T );
	void remove(Node<T> * N, T);
	bool isFull();
	bool isFull(Node<T> * N);
	int height();
	int height(Node<T> * N);
	void preorder();
	void inorder();
	void postorder();
	void preorder(Node<T> * N);
	void inorder(Node<T> * N);
	void postorder(Node<T> * N);
private:
	Node<T> * root;
};


template <typename T>
Tree<T>::~Tree() {
	delete root;
}

template <typename T>
void Tree<T>::insert(T value) {
	if(root == NULL){
		root = new Node<T>(value);
	}
	else if(root->data >= value){

		if(root->left == NULL){
			root->left = new Node<T>(value);

		}
		Node<T> * temporary = root->left;
		root->left = new Node<T>(value);
		root->left->left = temporary;
	}

	else if(root->data >= value){

		if(root->right == NULL){
			root->right = new Node<T>(value);

		}
		Node<T> * temporary = root->right;
		root->right = new Node<T>(value);
		root->right->right = temporary;
	}


}

template <typename T>
bool Tree<T>::contains(Node<T> * N, T value)
{
	if (N->data == value) {
		return true;
	} else if (N->left && value < N->data) {
		return contains(N->left, value);
	} else if (N->right && value > N->data) {
		return contains(N->right, value);
	}
	return false;
}
template <typename T>
bool Tree<T>::contains(T value) {
	if(root == NULL){
		return false;
	}
	else{
		if(value == root->data){
			return true;
		}
		else if(root->left && value < root->data){
			return contains(root->left, value);
		}
		else if(root->right && value > root->data){
			return contains(root->right, value);
		}
	}
	return false;
}


template<typename T>
void Tree<T>::remove(Node<T> * N, T value) {
	if (N->data == value) {
		if (N->left != NULL) {
			Node<T> *tmp = N->left;
			if (tmp->right != NULL) {
				do {
					tmp = tmp->right;
				} while (tmp->right != NULL);
				N->data = tmp->data;
				delete tmp;
				tmp = NULL;
			} else {
				N->data = tmp->data;
				N->left = tmp->left;
				delete tmp;
			}
		} else if (N->right != NULL) {
			Node<T> *tmp = N->right;
			if (tmp->left != NULL) {
				do {
					tmp = tmp->left;
				} while (tmp->left != NULL);
				N->data = tmp->data;
				delete tmp;
				tmp = NULL;
			} else {
				N->data = tmp->data;
				N->right = tmp->right;
				delete tmp;
			}
		} else {
			N->data = 0;
			delete N;
			N = NULL;
		}

	} else {
		if (N->left)
			remove(N->left, value);
		else if (N->right)
			remove(N->right, value);
	}

 
}

template <typename T>
void Tree<T>::remove(T value) {
	if (root == NULL) 
		return;
	remove(root, value);
}


template <typename T>
bool Tree<T>::isFull(){

	return isFull(root);	
}
template <typename T>
bool Tree<T>::isFull(Node<T> *N) {
	if(N == NULL){
		return true;
	}
	if(root->left == NULL && root->right == NULL){
		return true;
	}

	if((root->right) && (root->left)){
		return (isFull(root->right) && isFull(root->left));
	}

	return false;
	
}

template <typename T>
int Tree<T>::height(Node<T> *N)
{
	if (N == NULL) {
		return 0;
	} else {
		int lheight = height(root->left);
		int rheight = height(root->right);
		if(rheight > lheight)
			return (rheight + 1);
		else
			return (lheight + 1);
	}
	return 0;
}

template <typename T>
int Tree<T>::height() {
	return height(root);
}

template <typename T>
void Tree<T>::preorder(Node<T> *N)
{
	if(N != NULL){
		cout << N->data <<endl;
		preorder(root->left);
		preorder(root->right);
	}
}

template <typename T>
void Tree<T>::preorder() {
	preorder(root);	
}



template <typename T>
void Tree<T>::inorder(Node<T> *N) {
	if(N != NULL){
		inorder(root->left);
		cout << N->data << endl;
		inorder(root->right);
	}
	
}
template <typename T>
void Tree<T>::inorder() {
	preorder(root);	
}


template <typename T>
void Tree<T>::postorder(Node<T> *N) {
	if(N != NULL){
		postorder(root->left);
		postorder(root->right);
		cout << N->data << endl;
	}

}

template <typename T>
void Tree<T>::postorder() {
	preorder(root);	
}

#endif