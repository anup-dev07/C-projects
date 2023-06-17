/* You are given the map class

    template <typename T, typename P>
    struct Map
    {
    private : 
        friend std::ostream& operator<< <>  (std::ostream& out, const Map<T,P>& operand);
        T m_key;
        P m_value;
    public : 
        Map(T key, P value)
         : m_key(key), m_value(value)
        {}
    };
     
     
    template < typename T, typename P> 
     std::ostream& operator<<(std::ostream& out, const Map<T,P>& operand){
     
        out << "Map : [" << operand.m_key 
            << "," << operand.m_value << "]";
        return out;
    }

Notice that the output stream operator is implemented on the outside.

Your job to use C++20 concepts to constrain T to only be of an integral type and P to be of std::string type.

The code below

    Map<int, std::string> m1(11222,std::string{"Steve Murphy"}); // Works
    Map<long int,std::string> m2(22333,"Ahmed Malik"); // Works 
        

should compile just fine, but code below

    Map<double,unsigned int> m3(22.1,44555);

should fail to compile, stating that there are a few concept failures.

Please give this your best shot. If after really trying you still can't get around this, you can check the provided solution for clues.
Questions for this assignment

What does the source code for your solution look like? */

#include <iostream>
#include <concepts>
#include <string>

template <typename T, typename P>
struct Map {
private:
    T m_key;
    P m_value;

public:
    Map(T key, P value)
        : m_key(key), m_value(value) {}
};

template <typename T>
concept IntegralType = std::is_integral<T>::value;

template <typename P>
concept StringType = std::same_as<P, std::string>;

template <IntegralType T, StringType P>
std::ostream& operator<<(std::ostream& out, const Map<T, P>& operand) {
    out << "Map : [" << operand.m_key
        << "," << operand.m_value << "]";
    return out;
}

int main() {
    Map<int, std::string> m1(11222, std::string{"Steve Murphy"}); // Works
    Map<long int, std::string> m2(22333, "Ahmed Malik");          // Works

    // The following line will fail to compile due to type constraints
    // Map<double, unsigned int> m3(22.1, 44555);

    return 0;
}
