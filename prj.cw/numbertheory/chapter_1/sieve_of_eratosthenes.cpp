#include "../numbertheory.hpp"

// Eratosthenes sieve (obtaining all prime numbers less than n)
std::vector<int64_t> NumberTheory::SieveOfEratosthenes(int64_t n) {
  std::vector<bool> isPrime(n + 1, true);
  std::vector<int64_t> primes;

  for (int p = 2; p * p <= n; p++) {
    if (isPrime[p] == true) {
      for (int64_t i = p * p; i <= n; i += p)
        isPrime[i] = false;
    }
  }

  for (int64_t p = 2; p <= n; p++) {
    if (isPrime[p])
      primes.push_back(p);
  }

  return primes;
}