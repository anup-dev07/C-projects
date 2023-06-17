/*You are give the class

    template <typename T, typename P>
    struct Map
    {
    private : 
     
        T m_key;
        P m_value;
    public : 
        Map(T key, P value)
         : m_key(key), m_value(value)
        {}
    };

Your job is to plug in necessary type traits and static asserts to make sure that

    keys can only be of integral type

    values can only be of std::string type

Code like below

    	Map<int, std::string> m1(11222,std::string{"Steve Murphy"}); 
    	Map<long int,std::string> m2(22333,"Ahmed Malik");

should compile just fine

But something like

    Map<double,unsigned int> m3(22.1,44555);

Should fail to compile and throw errors like

    xxx\main.cpp:7:28: error: static assertion failed: Keys can only be of integral type
        7 |         static_assert(SOME_STANDARD_STATIC_ASSERT,"Keys can only be of integral type");
          |                       ~~~~~^~~~~~~~~~~~~~~~
    xxx\main.cpp:7:28: note: 'SOME_STANDARD_STATIC_ASSERT' evaluates to false
    xxx\main.cpp:8:28: error: static assertion failed: Values can only be of std::string type
        8 |         static_assert(SOME_STANDARD_STATIC_ASSERT,"Values can only be of std::string type");

Please give this your best shot. If after really trying, you still can't get around this, you can check our solution for clues.
Questions for this assignment

How does the source code for your solution look like ? */

#include <type_traits>
#include <string>

template <typename T, typename P>
struct Map {
private:
    static_assert(std::is_integral<T>::value, "Keys can only be of integral type");
    static_assert(std::is_same<P, std::string>::value, "Values can only be of std::string type");

    T m_key;
    P m_value;

public:
    Map(T key, P value)
        : m_key(key), m_value(value) {}
};

int main() {
    Map<int, std::string> m1(11222, std::string{"Steve Murphy"});
    Map<long int, std::string> m2(22333, "Ahmed Malik");

    // The following line will fail to compile due to type restrictions
    // Map<double, unsigned int> m3(22.1, 44555);

    return 0;
}
