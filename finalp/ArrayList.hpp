#pragma once

#include "List.hpp"
#include <iostream>

template<typename T>
class ArrayList: public List<T> {
private:
    // an array that contains the elements
    T *buffer;

    // the maximum number of elements in the list
    int maxSize;

public:
    // constructor with the maximum size as the argument
    ArrayList(int = 100);

    // destructor
    ~ArrayList();

    // add the argument to the end of the list
    void append(const T&) override;

    // remove all elements in the list, resetting to the initial state
    void clear() override;

    // return the element at the given position (argument)
    T getElement(int) const override;

    // return the current length of the list
    int getLength() const override;

    // return the maximum size of the list
    int getMaxSize() const;

    // insert the given element (argument 2) at
    // the given position (argument 1)
    void insert(int, const T&) override;

    // determine if the list currently empty
    bool isEmpty() const override;

    // determine if the list currently full
    bool isFull() const;

    // remove the element at the given position (argument)
    void remove(int) override;

    // replace the element at the given position (argument 1) with
    // the value given (argument 2)
    void replace(int, const T&) override;

    // overloaded stream insertion operator to make printing easier
    template<typename U>
    friend std::ostream& operator<<(std::ostream&, const ArrayList<U>&);
};

template<typename T>
ArrayList<T>::ArrayList(int i) :
        buffer(new T[i]), maxSize(i) {
    // The initializers above take care of everything; without them, I could have written:
    // buffer = new T[i];
    // maxSize = i;
}

template<typename T>
ArrayList<T>::~ArrayList() {
    delete[] buffer;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. Time complexity will be the same for when the list is full or not.
 * The function just adds the value into the next available spot.
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename T>
void ArrayList<T>::append(const T &elem) {
    if (isFull()) {
        throw std::string("append error: arraylist is full");
    }

    buffer[this->length] = elem;
    this->length++;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function just changes the length to 0.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename T>
void ArrayList<T>::clear() {
    this->length = 0;
    // We could additionally do the following:
    //
    // delete [] buffer;
    // buffer = new T[maxSize];
    //
    // But the user will only notice the difference if T's destructor matters
}

/*
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function searches and finds the value without needing
 * to iterate through the list.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename T>
T ArrayList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw std::string("getElement error: position out of bounds");
    }

    return buffer[position];
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
int ArrayList<T>::getLength() const {
    return this->length;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will always run once since all it does is
 * return the maxSize of the list.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename T>
int ArrayList<T>::getMaxSize() const {
    return maxSize;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time only when the list is full and the user entered an invalid position.
 * However, it will be T(n) when inserting into the list, since the list has to move all elements to open a
 * space in the list for a new value.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename T>
void ArrayList<T>::insert(int position, const T &elem) {
    if (isFull()) {
        throw std::string("insert error: arraylist is full");
    }
    if (position < 0 || position > this->length) {
        // I'll allow position == this->length, where we'll treat it the same as append,
        // but it's ok if you don't.
        // (The difference is whether you check > versus >=, above)
        throw std::string("insert error: position out of bounds");
    }

    // Move each element at an index greater than or equal to the given position
    // to the next largest index,
    // so that we have room for the element we're inserting
    for (int i = this->length; i > position; i--) {
        buffer[i] = buffer[i - 1];
    }
    // Put the element in place and update the length
    buffer[position] = elem;
    this->length++;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will always run once since all it does is
 * return the bool by checking if the length is 0.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename T>
bool ArrayList<T>::isEmpty() const {
    return this->length == 0;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will always run once since all it does is
 * return a bool by checking if the lengh is equal to the max size.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename T>
bool ArrayList<T>::isFull() const {
    return this->length == maxSize;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will always run on constant time since it just
 * changes the index of the buffer to remove the value.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename T>
void ArrayList<T>::remove(int position) {
    if (position < 0 || position >= this->length) {
        throw std::string("remove error: position out of bounds");
    }

    // Move each element at an index greater than the given position
    // to the next smallest index, effectively overwriting the element to be removed
    for (int i = position; i < this->length - 1; i++) {
        buffer[i] = buffer[i + 1];
    }
    this->length--;
    // Note that buffer[this->length] now has an extra copy
    // of the last element in the list (buffer[this->length - 1]),
    // but the user won't have a direct way to tell that it's there.
    // (For example, trying to getElement at that index would throw an out of bounds error)
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will always run once to insert the value at the position
 * disregarding if the position is used or not.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename T>
void ArrayList<T>::replace(int position, const T &elem) {
    if (position < 0 || position >= this->length) {
        throw std::string("replace error: position out of bounds");
    }

    buffer[position] = elem;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(n), linear time. There is a for loop in the function that iterates through the
 * array to print out the values in the list.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename T>
std::ostream& operator<<(std::ostream &outStream, const ArrayList<T> &myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    } else {
        // Output a space after all but the last element
        for (int i = 0; i < myObj.length - 1; i++) {
            outStream << myObj.buffer[i] << ' ';
        }
        outStream << myObj.buffer[myObj.length - 1];
    }

    return outStream;
}
