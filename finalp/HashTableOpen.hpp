#pragma once

#include "Dictionary.hpp"

template<typename Key, typename Val>
class HashTableOpen: public Dictionary<Key, Val> {
protected:
    // an element in a dictionary, contains a key and a value
    struct Record {
        Key k;
        Val v;

        Record() :
                k(Key()), v(Val()) {
        }
        Record(Key x, Val y) :
                k(x), v(y) {
        }
    };

    // a node for the (head of a) linked list at each slot of the hash table
    struct Node {
        Record r;
        Node *next;

        Node(Record record = Record(), Node *node = nullptr) :
                r(record), next(node) {
        }
    };

    // the size of the hash table (total number of slots)
    int M;

    int length;

    // the underlying (dynamic) array of (dynamic) linked lists
    Node **ht;
    // (Note that ht could have been of type LinkedList<Record>*,
    // but it can be more efficient to use just a Node pointer as a linked list)

    // an abstract method for turning a key into an integer
    // (subclasses will have to implement this for the appropriate type of Key)
    virtual int hash(const Key&) const = 0;

public:
    // default constructor
    HashTableOpen(int = 100);

    // destructor
    virtual ~HashTableOpen();

    // it would be good practice to have a copy constructor and assignment operator,
    // but we'll skip those for this lab.

    // remove all records in the dictionary, resetting to the initial state
    virtual void clear() override;

    // retrieve the record that matches the argument key
    // if multiple records match, return an arbitrary one
    virtual Val find(const Key&) const override;

    // add the record as a key-value pair to the dictionary
    virtual void insert(const Key&, const Val&) override;

    // remove the record that matches the argument key from the dictionary
    // if multiple records match, remove an arbitrary one
    virtual void remove(const Key&) override;

    // return the number of records in the dictionary
    virtual int size() const override;
};

template<typename Key, typename Val>
HashTableOpen<Key, Val>::HashTableOpen(int maxSize) {
    // TODO
	M = maxSize;
    ht = new Node*[M]();
    length = 0;
}

template<typename Key, typename Val>
HashTableOpen<Key, Val>::~HashTableOpen() {
    // TODO
    clear();
    delete[] ht;
    M = 0;
    length = 0;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(n), the time complexity for this function is linear. The function will run
 * n times depending on the size of the hash table, since it will iterate to clear all data
 * inside the hash table.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename Key, typename Val>
void HashTableOpen<Key, Val>::clear() {
    // TODO
    for (int i = 0; i < M; ++i) {
        Node* curr = ht[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        ht[i] = nullptr;
    }

    length = 0;
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: Best case scenario T(1), average case would be T(n). Best case scenario happens
 * when the value you are trying to find is in the first spot in the hash table. Otherwise,
 * it will run in linear time based on the size of the array.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename Key, typename Val>
Val HashTableOpen<Key, Val>::find(const Key &k) const {
    // TODO
    int index = hash(k) % M;
    Node* curr = ht[index];

    while (curr) {
        if (curr->r.k == k) {
            return curr->r.v;
        }
        curr = curr->next;
    }

    throw std::string("ERROR: KEY NOT FOUND");
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(n), the time complexity for this function is linear. The function will run
 * n times depending on the size of the hash table, since it will iterate to the index
 * to insert the value.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename Key, typename Val>
void HashTableOpen<Key, Val>::insert(const Key &k, const Val &v) {
    // TODO
    int index = hash(k) % M;
    Node* curr = ht[index];

    while (curr) {
        if (curr->r.k == k) {
            curr->r.v = v;
            return;
        }
        curr = curr->next;
    }

    ht[index] = new Node(Record(k, v), ht[index]);
    length++;

}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(n), the time complexity for this function is linear. The function will run
 * n times depending on the size of the hash table, since it will iterate to the index
 * to remove the value.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename Key, typename Val>
void HashTableOpen<Key, Val>::remove(const Key &k) {
    // TODO
	 int index = hash(k) % M;
	 Node* curr = ht[index];
	 Node* prev = nullptr;

	    while (curr) {
	        if (curr->r.k == k) {
	            if (prev) {
	                prev->next = curr->next;
	            } else {
	                ht[index] = curr->next;
	            }
	            delete curr;
	            length--;
	            return;
	        }
	        prev = curr;
	        curr = curr->next;
	    }

	    throw std::string("ERROR: KEY NOT FOUND");
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 *
 * Answer: T(1), constant time. The function will always run once since all it does is
 * return the length of the hash table without iterating through the table.
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
template<typename Key, typename Val>
int HashTableOpen<Key, Val>::size() const {
    // TODO
	return length;
}
