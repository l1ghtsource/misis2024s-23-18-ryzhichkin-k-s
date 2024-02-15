#include "..\numbertheory.hpp"

vector<int> factorize(int N) {
    vector<int> result;
    for (int i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            result.push_back(i);
            N /= i;
        }
    }
    if (N != 1) {
        result.push_back(N);
    }
    return result;
}

