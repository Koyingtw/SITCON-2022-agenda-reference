#include "testlib.h"
#include <bits/stdc++.h>

const long long MAXN = (int)1e15;
const int MAXM[] = {(int)1e9, (int)1e6, (int)1e6, (int)1e9};
const int MAXW = (int)1e5;

int n, m;
int w[7];


int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int group = validator.group()[0] - '0';

    long long n = inf.readLong(1, MAXN);
    inf.readSpace();
    int m = inf.readInt(1, MAXM[group], "m");
    inf.readEoln();

    for (int i = 0; i < 7; i++) {
        w[i] = inf.readInt(0, MAXW, "w");
        if (i != 6)
            inf.readSpace();
        else
            inf.readEoln();

        if (group == 1)
            ensure(w[i] == 1);
    }
    
    inf.readEof();
}