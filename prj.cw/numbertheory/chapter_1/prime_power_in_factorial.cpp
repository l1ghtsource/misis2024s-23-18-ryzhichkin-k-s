#include "../numbertheory.hpp"

int64_t NumberTheory::PrimePowerInFactorial(int64_t n, int64_t p) {
	int64_t res = 0;
	if (IsPrime(p, "sqrt")) {
		while (n) {
			n /= p;
			res += n;
		}
		return res;
	}
	else {
		throw std::invalid_argument("p should be a prime number");
	}
}