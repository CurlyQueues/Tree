#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node {
  public:
    Node();
    Node( T );
    ~Node();

    T data;
    Node<T> * left;
    Node<T> * right;
};

// Implement this
template <typename T>
Node<T>::Node() {
	left = NULL;
	right = NULL;
	data = 0;
}

template <typename T>
Node<T>::Node( T value ) {
	left = NULL;
	right = NULL;
	data = value;
}

template <typename T>
Node<T>::~Node() {
	if(left != NULL){
		delete left;
	}
	if(right != NULL){
		delete right;
	}

	data = 0;

}

#endif