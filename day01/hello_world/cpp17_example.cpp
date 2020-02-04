// This program just displays a string and exits, variation 1
#include <iostream>


template <class T>
T sum(T a, T b){
    return a + b;
}


template <class T>
class Test {

public:

    Test(T val) : val_(val) {

    }

    T get_val(){

        return val_;

    }

private:

    T val_;


};


// class nullptr_t {
//     public:
//         template <typename T>
//         operator T*() { return static_cast<T*>(0); }
// };

#define NULL_PTR 0

void func(int a) {
    std::cout << "Int func call: " << a << std::endl;
}

void func(int* a) {

    std::cout << "Int pointer func call: " << a << std::endl;
}


// Probing the memory map

// Memory: .data
int global_var {10} ; // an initialised global variable

// Memory: .bss
int global_var2; // unitialised global variable 
int global_zero {0}; // zero-initialised global variable 


// Memory: .const
static const int constant {99};

// Memory: .data
static int static_var {1200};



int main() { 

    // Memory: stack/register
    int automatic_var {777}; // Automatic/Local variable
    int automatic_var2; // An unitialised automatic/local variable

    // 
    static int automatic_static_var {555}; // Automatic/local static variable



    std::cout << "An initialised global var: " << global_var << std::endl;
    std::cout << "An uninitialised global var: " << global_var2 << std::endl;
    std::cout << "A zero initialised global var: " << global_zero << std::endl;
    std::cout << "A constant variable: " << constant << std::endl;
    std::cout << "A global static variable: " << static_var << std::endl;
    std::cout << "An automatic variable: " << automatic_var << std::endl;
    std::cout << "An unitialised automatic variable: " << automatic_var2 << std::endl;
    std::cout << "A static automatic: " << automatic_static_var << std::endl;

    std::cout << " ------------------------------------------------- " << std::endl;

    std::cout << "uninit_data " << &global_var2 << std::endl;
    std::cout << "init_data " << &global_var << std::endl;
    std::cout << "zero_data " << &global_zero << std::endl;
    std::cout << "const_data " << &constant << std::endl;
    std::cout << "global_static_data " << &static_var << std::endl;
    std::cout << "automatic_data " << &automatic_var << std::endl;
    std::cout << "uninit_automatic_data " << &automatic_var2 << std::endl;
    std::cout << "automatic_static_data " << &automatic_static_var << std::endl;
    std::cout << "main " << reinterpret_cast<int*>(main) << std::endl;



    Test test(33);
    
    std::cout<< "Hello World!" << std::endl; 

    std::cout << "Test01: " << sum(10,3) << std::endl;

    std::cout << "Test02: " << test.get_val() << std::endl;


    //func(NULL);       // Error here (ambiguous)
    func(nullptr);
    func(NULL_PTR);



    
    return 0; 
}
