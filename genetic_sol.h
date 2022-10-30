#include <stdio.h>
#include <stdlib.h>


struct gen{
    int* moves;
    int n;
};

struct individuo{
    struct gen genes;
    int id;
};


