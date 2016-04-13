#include <iostream>
#include <boost/multiprecision/gmp.hpp>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>


using namespace boost::multiprecision;

mpz_int ackermann(mpz_int m, mpz_int n);



int main(int argc, char* argv[])
{
    // int coreCount = boost::thread::hardware_concurrency();

    for (mpz_int m = 0; m >= 0; ++m)
    {
        for(mpz_int n = 0; n <= 10; ++n)
        {
            std::cout << "A(" << m << ", " << n << ") = " << ackermann(m, n) << std::endl;
        }
    }
}

mpz_int ackermann(mpz_int m, mpz_int n) {
    if(m==0) {
        return n+1;
    }
    if(m>0 && n ==0) {
        return(ackermann(m-1, 1));
    }
    else{
        return(ackermann(m-1, ackermann(m, n-1)));
    }
}