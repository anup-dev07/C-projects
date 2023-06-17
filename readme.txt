In this solution, we include the necessary headers <type_traits> and <string> for the type traits and std::string usage.

Inside the Map class, we use std::is_integral<T>::value to check if T is an integral type, and std::is_same<P, std::string>::value to check if P is the same as std::string. If any of these assertions fail, a static assertion will trigger a compilation error with the provided error message.

In the main() function, we demonstrate the usage of the Map class by creating instances m1 and m2, which satisfy the type restrictions and will compile successfully. The commented line with m3 will fail to compile due to violating the type restrictions.

By using type traits and static assertions, we ensure that keys can only be of integral type and values can only be of std::string type, providing compile-time safety and appropriate error messages when the restrictions are not met.