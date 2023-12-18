#pragma once

#include "Dictionary.hpp"
#include "ArrayList.hpp"

// an enum to represent which search implementations can be used
enum class SearchImpl {
    SEQ_ITER,
    SEQ_REC,
    BIN_ITER,
    BIN_REC,
};

template<typename Key, typename Val>
class ArrayListDictionary: public Dictionary<Key, Val> {
private:
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

    // the underlying array-based list
    ArrayList<Record> *list;

    // sequential search algorithm (iterative)
    Val seqSearchIter(const Key&) const;

    // sequential search algorithm (recursive)
    Val seqSearchRec(const Key&, int) const;

    // binary search algorithm (iterative)
    Val binSearchIter(const Key&) const;

    // binary search algorithm (recursive)
    Val binSearchRec(const Key&, int, int) const;

    // copy the state of the argument dictionary to `this`
    void copy(const ArrayListDictionary<Key, Val>&);

    // variable to store which search implementation to use
    SearchImpl searchHow;

public:

    // constructor with the search implementation and the maximum size as the arguments
    ArrayListDictionary(SearchImpl, int = 100);

    // copy constructor
    ArrayListDictionary(const ArrayListDictionary<Key, Val>&);

    // overloaded assignment operator
    ArrayListDictionary<Key, Val>& operator=(
            const ArrayListDictionary<Key, Val>&);

    // destructor
    virtual ~ArrayListDictionary();

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
ArrayListDictionary<Key, Val>::ArrayListDictionary(SearchImpl si, int i) :
        list(new ArrayList<Record>(i)), searchHow(si) {
}

template<typename Key, typename Val>
ArrayListDictionary<Key, Val>::ArrayListDictionary(
        const ArrayListDictionary<Key, Val> &copyObj) {
    copy(copyObj);
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
ArrayListDictionary<Key, Val>& ArrayListDictionary<Key, Val>::operator=(
        const ArrayListDictionary<Key, Val> &rightObj) {
    if (this != &rightObj) {
        delete list;
        copy(rightObj);
    }
    return *this;
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
ArrayListDictionary<Key, Val>::~ArrayListDictionary() {
    delete list;
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
Val ArrayListDictionary<Key, Val>::binSearchIter(const Key &target) const {
    // TODO
   int first = 0;
   int last = list->getLength();
   int middle;

   while (first <= last) {
	   middle = (first + last)/2;
	   if (list->getElement(middle).k == target) {
		   return list->getElement(middle).v;
	   }
	   else if (list->getElement(middle).k > target) {
		   last = middle - 1;
	   }
	   else {
		   first = middle + 1;
	   }
   }

   throw -1;
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
Val ArrayListDictionary<Key, Val>::binSearchRec(const Key &target, int left,
        int right) const {
    // TODO

	int middle = (left + right)/2;
	if (left > right) {
		throw -1;
	}
	if (list->getElement(middle).k == target) {
	   return list->getElement(middle).v;
	}
	else if (list->getElement(middle).k > target) {
		return binSearchRec(target, left, middle-1);
	}
	else {
		return binSearchRec(target, middle+1, right);
	}

	throw -1;

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
void ArrayListDictionary<Key, Val>::clear() {
    list->clear();
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
void ArrayListDictionary<Key, Val>::copy(
        const ArrayListDictionary<Key, Val> &copyObj) {
    list = new ArrayList<Record>(*copyObj.list);
    searchHow = copyObj.searchHow;
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
Val ArrayListDictionary<Key, Val>::find(const Key &k) const {
    try {
        switch (searchHow) {
        case SearchImpl::SEQ_ITER:
            return seqSearchIter(k);
        case SearchImpl::SEQ_REC:
            return seqSearchRec(k, 0);
        case SearchImpl::BIN_ITER:
            return binSearchIter(k);
        case SearchImpl::BIN_REC:
            return binSearchRec(k, 0, list->getLength() - 1);
        }
    } catch (...) {
        throw std::string(
                "find: error, unsuccessful search, target key not found");
    }
    return 0;
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
void ArrayListDictionary<Key, Val>::insert(const Key &k, const Val &v) {
    list->append(Record(k, v));
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
void ArrayListDictionary<Key, Val>::remove(const Key &k) {
    bool flag = false;

    for (int i = 0; i < list->getLength(); i++) {
        if (list->getElement(i).k == k) {
            list->remove(i);
            flag = true;
            break;
        }
    }

    if (!flag) {
        throw std::string(
                "remove: error, unable to find record with matching key to remove");
    }
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
Val ArrayListDictionary<Key, Val>::seqSearchIter(const Key &target) const {
    // TODO

	for (int i=0; i<list->getLength(); i++) {
		if (list->getElement(i).k == target) {
			return list->getElement(i).v;
		} //if
	}
	throw -1;
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
Val ArrayListDictionary<Key, Val>::seqSearchRec(const Key &target,
        int i) const {
    // TODO
	if (i > list->getLength()) {
		throw -1;
	}
	if (list->getElement(i).k == target) {
		return list->getElement(i).v;
	}
	else {
		return seqSearchRec(target, i+1);
	}
	throw -1;
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
int ArrayListDictionary<Key, Val>::size() const {
    return list->getLength();
}
