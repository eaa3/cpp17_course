// This program just displays a string and exits, variation 1
#include <iostream>

struct X{
    int i;
    double d;
    char c;
};

struct Inner {

    union {

        int arr[2];
        char bytes[8];

    };

};

class Position {

public:

    Position(double azi, double elev) : rho{azi}, theta{elev} {}
private:

    double rho { 90.0 };
    double theta { 90.0 };
};

int main() { 

    X x{ .i = 1, .d = 2.0 };
    
    Position p1 {180.0, 180.0};


    // Inner inner {char(0x0), char(0x0), char(0x0), char(0x1), 
    //              char(0x0), char(0x0), char(0x0), char(0x2)};

    Inner inner {1, 2};

    for(int i {0}; i < 8; i++){

        std::cout << inner.bytes[i] << " " << std::endl;
    }

    return 0; 
}
