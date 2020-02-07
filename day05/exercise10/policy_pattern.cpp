#include <iostream>



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