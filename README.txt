In this solution, we define the Point class template in the point.h header file. We add the operator<< function as a friend of the Point class so that it can access the private members of Point. Then, we define the operator<< function outside of the class, which allows us to customize the output behavior for Point objects.

In the main.cpp file, we include the point.h header and demonstrate the usage of the operator<< by creating a Point<int, 3> object and printing it using std::cout.

By separating the code into multiple files, it allows for better organization and modularity. The point.cpp file is not necessary in this case since the template definitions are in the header file, but you can add it if needed for more complex implementations.