#include <iostream>
#include <gmpxx.h>
#include <stdlib.h>
#include <libltdl/lt_system.h>

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
        //std::cout << "Route 1: m = " << m.get_str(10) << ", n= " << n.get_str(10) << std::endl;
        mpz_class z;
        mpz_add_ui(z.get_mpz_t(), n.get_mpz_t(), 1);
        return z;
    }
    else if (mpz_cmp_ui(n.get_mpz_t(), 0) == 0) {
        //std::cout << "Route 2: m = " << m.get_str(10) << ", n= " << n.get_str(10) << std::endl;
        mpz_class z;
        mpz_sub_ui(z.get_mpz_t(), m.get_mpz_t(), 1);
        return (ackermann(z, 1));
    }
    else {
        //std::cout << "Route 3: m = " << m.get_str(10) << ", n= " << n.get_str(10) << std::endl;
        mpz_class z;
        mpz_sub_ui(z.get_mpz_t(), n.get_mpz_t(), 1);
        mpz_class y;
        mpz_sub_ui(y.get_mpz_t(), m.get_mpz_t(), 1);
        return (ackermann(y, ackermann(m, z)));
    }
}

int ack_nonrecursive(int m, int n, int *status) {
    int *value = NULL;
    size_t size = 0;

    for (; ;) {
        if (m == 0) {
            n++;
            if (size-- == 0) {
                *status = EXIT_SUCCESS;
                break;
            }
            m = value[size];
            continue;
        }

        if (n == 0) {
            m--;
            n = 1;
            continue;
        }

        size_t index = size++;
        if ((size & index) == 0) {
            if (size >= SIZE_MAX / sizeof *value) {
                *status = EXIT_FAILURE;
                break;
            }

            void *temp = realloc(value, (2 * size + 1) * sizeof *value);
            if (temp == NULL) {
                *status = EXIT_FAILURE;
                break;
            }

            value = temp;
        }

        value[index] = m - 1;
        n--;
    }

    free(value);
    return n;
}