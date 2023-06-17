/*Given the code below

    #include <iostream>
    #include <concepts>
     
    template <typename T = int , unsigned int size = 2>
    class Point{
        friend std::ostream& operator<< <> (std::ostream&, const Point<T,size>&);
        T m_components[size];
    public :
        Point() = default;
        unsigned int get_size() const{
            return size;
        }
        void set_value(unsigned int index, T value){
            m_components[index] = value;
        }
    };
     
     
    template < typename T, unsigned int size> 
     std::ostream& operator<<(std::ostream& out, const Point<T,size>& operand){
        
        out << "Point : [ dimension :  " << size
            <<  ", components : " ;     
        for(size_t i{0}; i < size; ++i){
            out << operand.m_components[i] << " " ;
        }
        out << "]";
        
        return out;
    }
     
    class TinyType
    {
        public : 
            TinyType() = default;
            TinyType( int value) : m_wrapped_int(value){}
        private : 
        int m_wrapped_int{};
    };
     
     
    int main()
    {
        Point<TinyType,3> point_3d_tiny_types;
        point_3d_tiny_types.set_value(0,TinyType(10));
        point_3d_tiny_types.set_value(1,TinyType(20));
        point_3d_tiny_types.set_value(2,TinyType(30));
        std::cout << point_3d_tiny_types << std::endl;
     
        return 0;
    }

we know that it won't work mainly because TinyType doesn't have operator<< overloaded. But we also have other issues such as users being able to create instances of Point with std::string or const char* arguments which doesn't make any sense.

Your job is to use concepts to prevent bad uses for the Point class, and (hopefully) provide better error messages when the class is miss used.

You will constrain Point to work only for integral types, floating point values and anything that implicitly converts to double. The other requirement is that T should have operator<< overloaded.

Please give this your best shot. If after really trying, you still can't get around this, you can check our provided solution for clues.
Questions for this assignment

How does the source code for your solution look like? */

#include <iostream>
#include <concepts>
#include <type_traits>

// Concept to check if a type is an integral type
template <typename T>
concept Integral = std::is_integral_v<T>;

// Concept to check if a type is a floating-point type or implicitly convertible to double
template <typename T>
concept FloatingPoint = std::is_floating_point_v<T> || std::is_convertible_v<T, double>;

// Concept to check if a type has the operator<< overloaded
template <typename T, typename = void>
concept HasOutputOperator = false;

template <typename T>
concept HasOutputOperator<T, std::void_t<decltype(std::declval<std::ostream&>() << std::declval<T>())>> = true;

template <typename T = int, unsigned int size = 2>
class Point {
    static_assert(Integral<T> || FloatingPoint<T>, "T must be an integral type, floating-point type, or implicitly convertible to double");
    static_assert(HasOutputOperator<T>, "T must have operator<< overloaded");

    friend std::ostream& operator<<(std::ostream& out, const Point<T, size>&);
    T m_components[size];

public:
    Point() = default;

    unsigned int get_size() const {
        return size;
    }

    void set_value(unsigned int index, T value) {
        m_components[index] = value;
    }
};

template <typename T, unsigned int size>
std::ostream& operator<<(std::ostream& out, const Point<T, size>& operand) {
    out << "Point : [ dimension :  " << size
        << ", components : ";

    for (size_t i{0}; i < size; ++i) {
        out << operand.m_components[i] << " ";
    }

    out << "]";

    return out;
}

class TinyType {
public:
    TinyType() = default;
    TinyType(int value) : m_wrapped_int(value) {}

    friend std::ostream& operator<<(std::ostream& out, const TinyType& tiny) {
        return out << tiny.m_wrapped_int;
    }

private:
    int m_wrapped_int{};
};

int main() {
    Point<TinyType, 3> point_3d_tiny_types;
    point_3d_tiny_types.set_value(0, TinyType(10));
    point_3d_tiny_types.set_value(1, TinyType(20));
    point_3d_tiny_types.set_value(2, TinyType(30));

    std::cout << point_3d_tiny_types << std::endl;

    return 0;
}
