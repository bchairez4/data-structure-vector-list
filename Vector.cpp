#include "Vector.h"

/*****************************************************************************
    Constructors/ Destructor
*****************************************************************************/
template <class T>
Vector<T>::Vector() {}

template <class T>
Vector<T>::Vector(const int& capacity, const T& data) : array_(capacity, data) {}

template <class T>
Vector<T>::Vector(const Vector<T>& other) : array_(other.array_) {}

template <class T>
Vector<T>::~Vector() {
    array_.clear();
}

/*****************************************************************************
    Operator Overload
*****************************************************************************/
template <class T>
T& Vector<T>::operator=(const Vector<T>& other) {
    array_ = other.array_;
}

//WARNING: Undefined behavior when array is empty or if given index not within range of array
template <class T>
T Vector<T>::operator[](const int& i_index) const {
    typename std::list<T>::const_iterator it = search_(i_index);

    return (*it);
}

/*****************************************************************************
    Data Modification
*****************************************************************************/
template <class T>
void Vector<T>::push_front(const T& data) {
    array_.push_front(data);
}

template <class T>
void Vector<T>::push_back(const T& data) {
    array_.push_back(data);
}

template <class T>
void Vector<T>::pop_front() {
    if (!empty()) {
        array_.pop_front();
    }
}

template <class T>
void Vector<T>::pop_back() {
    if (!empty()) {
        array_.pop_back();
    }
}

template <class T>
void Vector<T>::erase(const T& data) {
    if (!contains(data)) {
        return;
    }

    typename std::list<T>::iterator it = array_.begin();
    for (; it != array_.end(); ++it) {
        if ((*it) == data) {
            break;
        }
    }

    array_.erase(it);
}

template <class T>
void Vector<T>::clear() {
    array_.clear();
}

/*****************************************************************************
    Data Observation
*****************************************************************************/
//WARNING: Undefined behavior when array is empty or if given index not within range of array
template <class T>
T Vector<T>::at(const int& i_index) const {
    typename std::list<T>::const_iterator it = search_(i_index);

    return (*it);
}

//WARNING: Undefined behavior when array is empty
template <class T>
T Vector<T>::front() const {
    return array_.front();
}

//WARNING: Undefined behavior when array is empty
template <class T>
T Vector<T>::back() const {
    return array_.back();
}

template <class T>
bool Vector<T>::contains(const T& data) const {
    if (empty()) {
        return false;
    }
    
    for (typename std::list<T>::const_iterator it = array_.begin(); it != array_.end(); ++it) {
        if ((*it) == data) {
            return true;
        }
    }
    
    return false;
}

template <class T>
bool Vector<T>::empty() const {
    return array_.empty();
}

template <class T>
int Vector<T>::size() const {
    return array_.size();
}

/*****************************************************************************
    Private Functions
*****************************************************************************/
template <class T>
typename std::list<T>::const_iterator Vector<T>::search_(const int& index) const {
    //Keep track of how far to venture into the array since lists dont have a direct access method
    int i = 0;
    typename std::list<T>::const_iterator it = array_.begin();

    //Stop once you reach the desired index or the end
    for (; ((it != array_.end()) && (i < index)); ++it) {
        i++;
    }

    return it;
}