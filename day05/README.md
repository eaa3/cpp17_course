# Templates


* [Cpp Insights](https://cppinsights.io/) : play around with templates and investigate what the compiler would generate.
* Blog: https://blog.feabhas.com/
* [Sutter "Template function specialisation"](https://blog.feabhas.com/2014/09/template-specialisation/)
* Dimov Abrahams example: https://stackoverflow.com/questions/14786008/function-template-specialization-and-the-abrahams-dimov-example


## Function templates

Example

```cpp

template <typename T>
void min(T a, T b){

    return a < b? a : b;
}


```


## Templated r-value references

```cpp
// 1) writeen template function, 2) passing by r-value reference, 3) we use std::forward
template <typename T>
void Pipe::push(T&& in){

    // If it is an l-value, then it becomes T&, thus it stays as an l-value
    // If it is an r-value, then it stays T&&, thus it stays as an r-value.
    elem_ = std::forward<T>(in);

}

```

Design tip:

When writting a library, we should design it from outside to the inside implementation.


```cpp
template <typename T>
class AT{
public:

    ADT(const T&) {}
};


template <typename T>
ADT<T> make_adt(T&& param)
{
    return ADT { std::forward<T>(param) };
}

template <>
ADT<const char*> make_adt(const char* param)
{
    return ADT { std::forward<const char*>(param) };
}

// Or simply using a template deduction guide (type inference guide)


template <typename T>
ADT(T) -> ADT<T>;

ADT(const char*) -> ADT<const char*>;


```

## Template deduction guide


```cpp

template <typename T>
class AT{
public:

    ADT(const T&) {}
};


// Or simply using a template deduction guide (type inference guide)


template <typename T>
ADT(T) -> ADT<T>;

ADT(const char*) -> ADT<const char*>;

```


## User defined literals

Have look at the notes.


## Template class specialisation (Explicit specialisation)

```cpp
template <typename T>
class Min {

public:
    decltype(auto) get_min(T a, T b){

        return (a < b)? a : b;
    }

};


template<>
class Min<const char*>{

public:
    const char* get_min(const char* a, const char* b){

        return (strcmp(a,b) < 0)? a : b;
    }
}

```


## Partial specialisation

For all pointer types

```cpp
template<typename T>
class Min<T*>{

public:
    T* get_min(T* a, T* b){

        return (*a < *b)? a : b;
    }
}

```


## Proxy pattern


Forms of proxy:


1. Remote proxy: the client makes calls to a proxy, the call is communicated via the network and executed remotely. The results are then returned
2. Virtual proxy: uses a cache
3. Protection proxy: we can implement checks.


## Variadic templates


```cpp
template <typename... T>
void var_func(T... param);


template <typename... Param_Ty> Secure_reource(Param_Ty&&... param) : resource {std::forward<Param_Ty>(param)};


```

## Final example template proxy: the policy pattern


```cpp

class Implementation {

public:

    void read() { }
    void write() { }
};


class Another {

public:

    void read([[ maybe_unused ]] int val = 0) { }
    void write() { }
    bool is_ok();
};


// Defines a policy that must be complied
template <typename Server_Ty>
class Client {

public:
    void read();
    void write();


    template <typename U, typename T>
    friend void connect(Client<U>& client, T& srv);

private:


    Server_Ty* server { nullptr };




};

template <typename U, typename T>
void connect(Client<U>& client, T& srv){

    client.server = &srv;
}


int main() {

    Client<Another> client { };
    Another another { };

    connect(client, another);

}

```


## Curiously recurring template pattern

see crp.cpp


## Readings



Feabhas C++ Guidelines