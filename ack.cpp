#include <iostream>
#include <gmpxx.h>
#include <sstream>

mpz_class ackermann(mpz_class i, mpz_class n);


int main(int argc, char *argv[]) {
    for (long m = 1; m >= 0; ++m) {
#pragma omp parallel for
        for (long n = 0; n <= 10; ++n) {
            std::stringstream buf;
            buf << "A(" << m << ", " << n << ") = " <<
            ackermann(m, n).get_str(10) << "\n";
            std::cout << buf.rdbuf();
        }
        }
}


mpz_class ackermann(mpz_class i, mpz_class n) {
    mpz_class next[i.get_ui() + 1];
    mpz_class goal[i.get_ui() + 1];
    mpz_class value = 0;
    for (mpz_class count = 0; mpz_cmp_ui(count.get_mpz_t(), i.get_ui()) != 0; count++) {
        next[count.get_ui()] = 0;
    }
    for (mpz_class count = 0; mpz_cmp_ui(count.get_mpz_t(), i.get_ui()) != 0; count++) {
        goal[count.get_ui()] = 1;
    }
    goal[i.get_ui()] = -1;
    mpz_class pholder; //For use as intermediate
    mpz_add_ui(pholder.get_mpz_t(), n.get_mpz_t(), 1);
    while (mpz_cmp(next[i.get_ui()].get_mpz_t(), pholder.get_mpz_t()) != 0) {
        mpz_add_ui(value.get_mpz_t(), next[0].get_mpz_t(), 1);
        bool transferring = true;
        mpz_class current = 0;
        while (transferring) {
            if (mpz_cmp(next[current.get_ui()].get_mpz_t(), goal[current.get_ui()].get_mpz_t()) == 0) {
                goal[current.get_ui()] = value;
            }
            else {
                transferring = false;
            }
            next[current.get_ui()] += 1;
            current += 1;
        }
    }
    return value;
}
