#include "iostream"
#include "string"


struct MyStruct
{
    uint32_t int_ = 0;
    uint16_t short_ = 0;
};

int main()
{
    std::string x;
    std::cin >> x;

    uint64_t y = std::stoull(x);
    uint32_t z = std::stoul(x);

    MyStruct my;
    my.int_ = y > UINT32_MAX ? UINT32_MAX : y;  //  C4244.

    my.short_ = y > UINT16_MAX ? UINT16_MAX : y; // C4244 too.

    my.short_ = z > UINT16_MAX ? UINT16_MAX : z; // OK.


    // uint64_t y > my.int_, uint32_t z > short_.
    // Why only one "warning C4244". 
    // Just y(uint64_t) bigger z(uint32_t)??
}
