#include <iostream>
#include <gmpxx.h>

mpz_class ackermann(mpz_class m, mpz_class n);


int main(int argc, char *argv[]) {

    for (mpz_class m = 1; mpz_cmp_ui(m.get_mpz_t(), 0) >= 0; ++m) {
        for (mpz_class n = 0; mpz_cmp_ui(n.get_mpz_t(), 10) <= 0; ++n) {//n<= 10
            std::cout << "A(" << m.get_str(10) << ", " << n.get_str(10) << ") = " << ackermann(m, n).get_str(10) <<
            std::endl;
        }
    }
}

//TODO: Get the god damn clears working
mpz_class ackermann(mpz_class m, mpz_class n) {
    if (mpz_cmp_ui(m.get_mpz_t(), 0) == 0) {
        std::cout << "Route 1: m = " << m.get_str(10) << ", n= " << n.get_str(10) << std::endl;
        mpz_class z;
        mpz_add_ui(z.get_mpz_t(), n.get_mpz_t(), 1);
        //mpz_clears(m.get_mpz_t(), n.get_mpz_t());
        return z;
    }
    else if (mpz_cmp_ui(n.get_mpz_t(), 0) == 0) {
        //mpz_clear(n.get_mpz_t());
        std::cout << "Route 2: m = " << m.get_str(10) << ", n= " << n.get_str(10) << std::endl;
        mpz_class z;
        mpz_sub_ui(z.get_mpz_t(), m.get_mpz_t(), 1);
        //mpz_clear(m.get_mpz_t());
        return (ackermann(z, 1));
    }
    else {
        std::cout << "Route 3: m = " << m.get_str(10) << ", n= " << n.get_str(10) << std::endl;
        mpz_class z;
        mpz_sub_ui(z.get_mpz_t(), n.get_mpz_t(), 1);
        //mpz_clear(n.get_mpz_t());
        mpz_class y;
        mpz_sub_ui(y.get_mpz_t(), m.get_mpz_t(), 1);
        return (ackermann(y, ackermann(m, z)));
    }
}