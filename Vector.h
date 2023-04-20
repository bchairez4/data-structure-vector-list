/*****************************************************************************
*    Brian Chairez                                                           *
*    Goal: Manual implementation of std::vector using std::list              *
*    Advantages:                                                             *
*       -Fast operations: O(1) push_front(), push_back(), pop_front(),       *
*                          pop_back(), front() and back()                    *
*       -Built in list functions and size tracking are helpful               *
*    Disadvantages:                                                          *
*       -Lists are known for their poor reference locality                   *
*       -No way to conventionally access anything in the middle              *
*****************************************************************************/

#include <list>

template <class T>
class Vector {
    private:
        std::list<T> array_;

        typename std::list<T>::const_iterator search_(const int& index) const;
    public:
        Vector();
        Vector(const Vector<T>& other);
        Vector(const int& capacity, const T& data);
        ~Vector();
        T& operator=(const Vector<T>& other);
        T operator[](const int& i_index) const;
        T at(const int& i_index) const;
        T front() const;
        T back() const;
        void push_front(const T& data);
        void push_back(const T& data);
        void pop_front();
        void pop_back();
        void erase(const T& data);
        void clear();
        bool contains(const T& data) const;
        bool empty() const;
        int size() const;
};