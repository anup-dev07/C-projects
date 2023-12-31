/* Considering the code below

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
     
    template < typename T, unsigned int size> inline
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

What's the reason for the thrown compiler error */

#include <iostream>
#include <concepts>

template <typename T = int, unsigned int size = 2>
class Point {
    template <typename U, unsigned int S>
    friend std::ostream& operator<<(std::ostream&, const Point<U, S>&);
    
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
inline std::ostream& operator<<(std::ostream& out, const Point<T, size>& operand) {
    out << "Point : [ dimension :  " << size
        << ", components : ";
        
    for (size_t i {0}; i < size; ++i) {
        out << operand.m_components[i] << " ";
    }
    
    out << "]";
    
    return out;
}

class TinyType {
public:
    TinyType() = default;
    TinyType(int value) : m_wrapped_int(value) {}
    
private:
    int m_wrapped_int {};
};

int main() {
    Point<TinyType, 3> point_3d_tiny_types;
    point_3d_tiny_types.set_value(0, TinyType(10));
    point_3d_tiny_types.set_value(1, TinyType(20));
    point_3d_tiny_types.set_value(2, TinyType(30));
    
    std::cout << point_3d_tiny_types << std::endl;
    
    return 0;
}
