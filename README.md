# A fast, multithreaded, C++  Ackermann calculator

This is not really meant to have any use, I just thought it would be cool to
 make. It's still very much a WIP, so don't expect the title claims to be true
 necessarily, check the TODO category down below to make sure.

Using the recursive implementation of the Ackermann function the stack gets
blown pretty quickly, so I have opted for an iterative approach instead this,
however, brings other limitations to the table. The need to deal with arrays
 means *true* arbitrary precision can't be achieved, since array declarations
only accept up to unsigned long as size determinator, not mpz_t or mpz_class.
What this means is that fundamentally this will be limited in some aspects to
64-bit integers, this may have a solution eventually, but right now I have no
clue how to fix it.

## Files

*   `ack.cpp` - The main file containing the calculator

## Dependencies

*   [GMP](https://gmplib.org/)

## TODO

*   Have a simple Ackermann base code - :white_check_mark:
*   Implement arbitrary precision - :white_check_mark:
*   Implement parallelism - :x:
*   Optimize code - :x:

<sub>:white_check_mark: - Done, :clock4: - On the works,  :x: - To do</sub>
