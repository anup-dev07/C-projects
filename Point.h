/*We have a point class template as shown below : 

    template <typename T = int , unsigned int size = 2>
    class Point{
        T m_components[size];
    public :
        unsigned int get_size() const{
            return size;
        }
        void set_value(unsigned int index, T value){
            m_components[index] = value;
        }
    };

Your job is to write an output stream insertion operator, in such a way that we can use our point class like below

        Point<int,3> point_3d;
        point_3d.set_value(0,10);
        point_3d.set_value(1,20);
        point_3d.set_value(2,30);
        std::cout << point_3d << std::endl;

and this should print something like

Point : [ dimension :  3, components : 10 20 30 ]

You are free to use any of the methods  described in the last lecture, (I would even recommend trying them all). Please know that you can't add more public methods to the point class as is.

I would recommend splitting your code into different files. A common way would be to have three files

    point.h

    point.cpp

    main.cpp

and the main.cpp file would be where you try out your operator to get the desired output.
Questions for this assignment

How does the source code for your solution look like ?*/

#ifndef POINT_H
#define POINT_H

#include <iostream>

template <typename T = int, unsigned int size = 2>
class Point {
    T m_components[size];

public:
    unsigned int get_size() const {
        return size;
    }

    void set_value(unsigned int index, T value) {
        m_components[index] = value;
    }

    // Forward declaration of the operator<< function
    template <typename U, unsigned int n>
    friend std::ostream& operator<<(std::ostream& os, const Point<U, n>& point);
};

// Definition of operator<< for Point class
template <typename T, unsigned int size>
std::ostream& operator<<(std::ostream& os, const Point<T, size>& point) {
    os << "Point : [ dimension : " << size << ", components :";
    for (unsigned int i = 0; i < size; ++i) {
        os << " " << point.m_components[i];
    }
    os << " ]";
    return os;
}

#endif  // POINT_H

