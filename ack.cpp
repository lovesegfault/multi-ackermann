#include <iostream>
#include <gmpxx.h>


mpz_class ackermann(mpz_class m, mpz_class n);

mpz_class ack(mpz_class i, mpz_class n);

long acker(long i, long n);

int main(int argc, char *argv[]) {
    //std::cout << ackermann(3, 1).get_str(10);
    std::cout << acker(3, 5);
    /*
    for (mpz_class m = 1; mpz_cmp_ui(m.get_mpz_t(), 0) >= 0; ++m) {
        for (mpz_class n = 0; mpz_cmp_ui(n.get_mpz_t(), 10) <= 0; ++n) {//n<= 10
            std::cout << "A(" << m.get_str(10) << ", " << n.get_str(10) << ") = " << ackermann(m, n).get_str(10) <<
            std::endl;
        }
    }*/
}

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


long acker(long i, long n) {
    long next[i + 1] = {0};
    long goal[i + 1] = {0}; //What the fuck happens here??
    long value = 0;
    std::fill_n(goal, i - 1, 1);
    goal[i] = -1;
    //std::cout<<(goal[i]);
    while (next[i] != n + 1) {
        value = next[0] + 1;
        bool tranferring = true;
        long current = 0;
        while (tranferring) {
            if (next[current] == goal[current]) {
                goal[current] = value;
            }
            else {
                tranferring = false;
            }
            next[current] += 1;
            current += 1;
        }
    }
    return value;
}


mpz_class ack(mpz_class i, mpz_class n) {
    mpz_class next[i.get_ui() + 1] = {0};
    mpz_class goal[i.get_ui()] = {1};
    mpz_class value;
    goal[i.get_ui()] = -1;
    while (mpz_cmp(next[i.get_ui()].get_mpz_t(), n.get_mpz_t()) != 0) {
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
