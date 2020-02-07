

# Callable objects

A callable object is an object that can be called like a function.

* A member function (pointer)
* A free function (pointer)
* A functor
* A lambda


`std::function` is a generalised pointer-tofunction that can reference any callable object.


```cpp
std::function< Return_Type (Parameter_List) >
```


# Cpp core guidelines

[Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md)


# Google C++ style guide

[Style guide](https://google.github.io/styleguide/cppguide.html)


# Design Patterns


[Book on design patterns by Erich Gamma](https://www.amazon.co.uk/Design-patterns-elements-reusable-object-oriented/dp/0201633612)


# Reasons why to use dynamic memory

1. It may be an optional object
2. We may not know the size of the object beforehand at compiletime.


# Error handling strategies

1. Ignore
2. Handle
3. Degrade (exceptions are typically used here)
4. Halt (asserts)


# The copy-swap idiom

It is a code pattern that achieves deep copy and deep assignment in a general way. This is sometimes called "The rule of three and a half".


The steps are:

1. Implement deep-copy constructor
2. Assignment operator must do a deep (and delete/free the previous attributes before deep copying of course)


```cpp
class SocketManager {

public:
    Socker_manager(IP_address addr, Port p);
    ~Socket_manager();
    Socket_manager(const Socket_manager& src);

    void send(const char* str);

private:

    IP_address ip { 0.x7F0000001 };
    Socket* socket { nullptr };

};

Socket_manager::Socket_manager(const Socket_manager& src) : ip { src.ip }, socket { nullptr } {


    if(src.socket) {

        socket = new Socket { src.socket };

        socket.open();
    }
} 


}

```

In addition to the copy constructor that does deep copy, we implement the assignment operator in the following way using the copy-swap idiom:


```cpp

Socket_manager::operator=(const Socket_manager& rhs){

    
    Socket_manager tmp { rhs };
    swap(*this, temp);

    return *this;
}

// OR, more efficiently:
// Attention!!! The rhs is passed by value!!
// Reason: stronger exception safety, and extra rule semantic for freee
Socket_manager& Socket_manager::operator=(const Socket_manager rhs){

    swap(*this, rhs);

    return *this;
}

void swap(Socket_manager& lhs, Socket_manager& rhs){

    using std::swap;
    swap(lhs.ip, rhs.ip);
    swap(lhs.socket, rhs.socket);
}

```



# Move constructor


```cpp



void func(int&& i); // receives an l-value
void func(const int&& i); // has no meaning


int&& v { some_func() }; // r-value reference

```

An example implementation of move constructor ( no more deep copy ). The move semantics.

If you're just using normal objects (without points or dynamically memory allocated resources) then you do not gain anything from using the move semantics.

```cpp

class SocketManager {

public:
    Socket_manager() = default; // needed
    Socker_manager(IP_address addr, Port p);
    ~Socket_manager();
    Socket_manager(const Socket_manager& src);
    Socket_manager(Socket_manager&& src);

    void send(const char* str);

    friend void swap(Socket_manager& rhs, Socket_manager& lhs);

private:

    IP_address ip { 0.x7F0000001 };
    Socket* socket { nullptr };

};

Socket_manager::Socket_manager(Socket_manager&& src) noexcept : Socket_manager { } {

    swap(*this, src);
} 

Socket_manager& Socket_manager::operator=(Socket_manager rhs){

    swap(*this, rhs);

    return *this;
}

void swap(Socket_manager& lhs, Socket_manager& rhs){

    using std::swap;
    swap(lhs.ip, rhs.ip);
    swap(lhs.socket, rhs.socket);
}


```

The `std::move`


```cpp

int main(){


    Socket_manager mgr = {0x23213};
    Socket_manager mgr2 = {0x4444};

    mgr2 = mgr1;            // mgr2 => mg1 (deep copy)

    mgr2 = std::move(mgr1); // mgr2 => mgr1
                            // mgr1 => empty (it has been initialised to an empty/default state - see move constructor)

}

```


Implementation and compiler behaviour

The rule of zero
```cpp

class ADT {
public:
    // Copy policy
}


class ADT {
public:
    // Copy policy
    ~ADT();
    ADT(const ADT& )    = default;
    ADT(ADT&&)          = default;
    ADT& operator=(const ADT&) = default;
    ADT& operator=(ADT&&)      = default;
}



class ADT {
public:
    // Move and Copy policy
    ~ADT();
    ADT(const ADT& )    = default;
    ADT(ADT&&)          = default;
    ADT& operator=(ADT) = default;
    friend void swap(ADT&, ADT&);
}


// Move but not copy
class ADT {
public:
    // Copy policy
    ~ADT(); // implement that
    ADT(const ADT& )            = delete;
    ADT(ADT&&) ; // implement that
    ADT& operator=(const ADT& ) = delete;
}
```