#pragma once

#include "Queue.hpp"
#include <iostream>

template <typename T>
class ArrayQueue : public Queue<T> {
    private:
        // an array that contains the elements
        T* buffer;

        // the maximum number of elements in the queue
        int maxSize;

        // the current position of the front element in the queue
        int frontIndex;

        // the current position of the back element in the queue
        int backIndex;

        // copy the values from the argument queue to `this`
        void copy(const ArrayQueue<T>&);

    public:
        // constructor with the maximum size as the argument
        ArrayQueue(int = 100);

        // copy constructor
        ArrayQueue(const ArrayQueue<T>&);

        // overloaded assignment operator
        ArrayQueue<T>& operator=(const ArrayQueue<T>&);

        // destructor
        virtual ~ArrayQueue();

        // return the element at the back of the queue
        virtual T back() const override;

        // remove all elements in the queue, resetting to the initial state
        virtual void clear() override;

        // remove the front element from the queue
        virtual void dequeue() override;

        // add the argument to the back of the queue
        virtual void enqueue(const T&) override;

        // return the element at the front of the queue
        virtual T front() const override;

        // return the current length of the queue
        virtual int getLength() const override;

        // return the maximum size of the queue
        int getMaxSize() const;

        // determine if the queue is currently empty
        virtual bool isEmpty() const override;

        // determine if the queue is currently full
        bool isFull() const;

        template<typename U>
        friend std::ostream& operator<<(std::ostream&, const ArrayQueue<U>&);
};

template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    // TODO
	frontIndex = 0;
	backIndex = 0;
	this->buffer = new T[i];
	maxSize = i;

}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        // TODO
        // do whatever you need to do before `copy` is called
        // to ensure there are no bugs
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    // TODO
	this->length = 0;
	delete[] buffer;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will always run once since all it does is
 * return the value at the backIndex.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
	return buffer[backIndex];
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will always run once since all it does is
 * change the length to 0 to ignore the values in the array queue.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
	this->length = 0;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(n), linear time. The copy function runs itself based on the maxSize.
 * It will copy all variables till the for loop reaches the maxSize.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO
	this->frontIndex = copyObj.frontIndex;
	this->backIndex = copyObj.backIndex;
	this->maxSize = copyObj.maxSize;
	this->length = copyObj.length;
	this->buffer = new T[this->maxSize];
	for (int i = 0; i < maxSize; i++) {
		this->buffer[i] = copyObj.buffer[i];
	}
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will always on constant time since there
 * are only if else statements. The function will check itself and move the front index
 * to dequeue.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
	if(this->length == 0){
		throw std::string("ERROR: Nothing to dequeue");
	}
	if(this->length == 1){
		this->length = 0;
	}
	else{
		if(maxSize > frontIndex){
			frontIndex++;
		}
		else{
			frontIndex = 0;
		}
		this->length--;
	}
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will always run on constant time since there
 * are only if else statements. The function accounts for all situations and will move the
 * front and back index, as well as enqueue the value into the queue.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
	if (this->length == maxSize) {
		throw std::string("ERROR: Max capacity");
	}
	else if (isEmpty() == true) {
		frontIndex = 0;
		buffer[frontIndex] = elem;
		backIndex = 0;
		buffer[backIndex] = elem;

	}
	else if (backIndex == maxSize) {
		backIndex = 0;
		buffer[backIndex] = elem;
	}
	else {
		backIndex++;
		buffer[backIndex] = elem;
	}
	this->length++;

}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will always run once since all it does is
 * return the value at the front index.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
	return buffer[frontIndex];
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will always run once since all it does is
 * return the length of the queue without iterating through the table.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will always run once since all it does is
 * return the max size of the array queue.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will always run once since all it does is
 * return a bool by checking if the length is 0 or not.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will always run once since all it does is
 * return a bool by checking if the length is the same as the max size.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(n), linear time. The function prints the queue by using a for loop
 * that iterates through the queue to print each value.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template <typename T>
std::ostream& operator<<(std::ostream& outStream, const ArrayQueue<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.frontIndex; i != myObj.backIndex + 1; i++) {
            if (i == myObj.length) {
            	outStream << myObj.buffer[i];
            	break;
            }
        	outStream << myObj.buffer[i] << " ";
        }
    }

    return outStream;
}

