#include <iostream>
#include <gmpxx.h>

mpz_class ackermann(mpz_class i, mpz_class n);


int main(int argc, char *argv[]) {

    for (mpz_class m = 1; mpz_cmp_ui(m.get_mpz_t(), 0) >= 0; ++m) {
        for (mpz_class n = 0; mpz_cmp_ui(n.get_mpz_t(), 10) <= 0; ++n) {//n<= 10
            std::cout << "A(" << m.get_str(10) << ", " << n.get_str(10) << ") = " << ackermann(m, n).get_str(10) <<
            std::endl;
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
