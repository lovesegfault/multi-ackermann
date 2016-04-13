#include <iostream>
#include <boost/thread.hpp>

void foobar ()
{
    std::cout << "FOOBAR" << std::endl;
}
int main(int argc, char const *argv[]) {
    boost::thread foo;
    return 0;
}
