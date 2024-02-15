#include "../numbertheory.hpp"

int64_t NumberTheory::PrimePowerInFactorial(int64_t n, int64_t p) {
	int64_t result = 0;
	if (IsPrime(p, "sqrt")) {
		while (n) {
			n /= p;
			result += n;
		}
		return result;
	}
	else {
		throw std::invalid_argument("p should be a prime number");
	}
}