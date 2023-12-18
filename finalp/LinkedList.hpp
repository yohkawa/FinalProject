#pragma once

#include "CircleList.hpp"
#include <iostream>

template<typename T>
class LinkedList: public CircleList<T> {
protected:
    // represents an element in the linked list
    struct Node {
        T value;
        Node *next;

        Node(T v = T(), Node *n = nullptr) :
                value(v), next(n) {
        }
    };

    // a pointer to the front of the list
    Node *head;

private:
    // Recursive methods that do most of the work for the respective public methods
    void clearRec(Node*);

public:
    LinkedList();
    ~LinkedList();

    T getCurrent() const override;
    T goNext() override;

    void append(const T&) override;
    void clear() override;
    unsigned getLength() const override;

    // overloaded stream insertion operator to make printing easier
    template<typename U>
    friend std::ostream& operator<<(std::ostream&, const LinkedList<U>&);
};

template<typename T>
LinkedList<T>::LinkedList() :
        head(nullptr) {
	this->length = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will always run once since all it does is
 * move the head pointer over to the next element.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename T>
T LinkedList<T>::goNext() {
    // TODO
	head = head->next;
	return head->value;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will always run once since all it does is
 * return the current head value.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename T>
T LinkedList<T>::getCurrent() const {
    // TODO
	return head->value;
}

/*
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function runs on constant time. All it does
 * is add a new element to the list without iterating through the entire list.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename T>
void LinkedList<T>::append(const T &elem) {
	if (this->length == 0) {
			Node* temp = new Node(elem);

			head = temp;
			head->next = head;
			this->length++;

	}
	else {
			Node* curr = head;
			Node *temp = new Node(elem, curr->next);
//			head->next = temp;
//			head = head->next;

			temp->next = curr->next;
			curr->next = temp;
		    curr = temp;
			this->length++;

	}
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will run on constant time to clear the list
 * and change the length to 0.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename T>
void LinkedList<T>::clear() {
    clearRec(head);
    head = nullptr;
    this->length = 0;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(n), linear time. This function is recursive. It runs based on the number
 * of elements in the list. Therefore, this function is linear time.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename T>
void LinkedList<T>::clearRec(Node *node) {
    // TODO
	if (node != NULL) {
		head = node->next;
		node->next = nullptr;
		delete node;
		clearRec(node->next);
	}
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will always run once since all it does is
 * return the length of the list without iterating through the list.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename T>
unsigned LinkedList<T>::getLength() const {
    return this->length;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(n), linear time. The function will run till it reaches the end. It prints
 * all elements in the list.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename T>
std::ostream& operator<<(std::ostream &outStream, const LinkedList<T> &myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.";
    } else {
        typename LinkedList<T>::Node *curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
    }

    return outStream;
}
