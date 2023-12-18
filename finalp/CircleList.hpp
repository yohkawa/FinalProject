#pragma once

template <typename T>
class CircleList {
    protected:
        // the current number of elements in the list
        unsigned length;

    public:
        // default constructor
        CircleList() : length(0) { }

        // destructor
        virtual ~CircleList() { }

        // Returns whatever the current element is
        virtual T getCurrent() const = 0;

        // Moves the current element to the next element in the cycle.
        // Returns whatever the new current element is.
        virtual T goNext() = 0;

        // add the argument to the end of the list
        virtual void append(const T&) = 0;

        // remove all elements in the list, resetting to the initial state
        virtual void clear() = 0;

        // return the current length of the list
        virtual unsigned getLength() const = 0;

};
