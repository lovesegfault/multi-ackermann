#include <iostream>
#include <boost/multiprecision/gmp.hpp>


using namespace boost::multiprecision;

mpz_int ackermann(mpz_int m, mpz_int n);


int main(int argc, char *argv[]) {
    // int coreCount = boost::thread::hardware_concurrency();
    /*
    for (mpz_int m = 4; m >= 0; ++m) {
        for (mpz_int n = 0; n <= 10; ++n) {
            ackermann(m, n);
            std::cout << "A(" << m << ", " << n << ")" << std::endl;
        }
    }*/
    std::cout << ackermann(4, 2) << std::endl; //Currently breaks life
}

mpz_int ackermann(mpz_int m, mpz_int n) {
    if (m == 0) {
        //std::cout << "Route 1: m = " << m << ", n= " << n << std::endl;
        return n + 1;
    }
    if (n == 0) {
        //std::cout << "Route 2: m = " << m << ", n= " << n << std::endl;
        return (ackermann(m - 1, 1));
    }
    //std::cout << "Route 3: m = " << m << ", n= " << n << std::endl;
    return (ackermann(m - 1, ackermann(m, n - 1)));
}