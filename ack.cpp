#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>


using bigInt = boost::multiprecision::gmp_int;
bigInt ackermann (bigInt m, bigInt n)
{
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
int main(int argc, char* argv[])
{
    // int coreCount = boost::thread::hardware_concurrency();

    for (bigInt m = 0; m >= 0; ++m)
    {
        for(bigInt n = 0; n <= 10; ++n)
        {
            std::cout << "A(" << m << ", " << n << ") = " << ackermann(m, n) << std::endl;
        }
    }
}
