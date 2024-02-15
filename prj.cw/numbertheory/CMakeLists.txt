add_library(numbertheory numbertheory.hpp 
chapter_1/divisors.cpp
chapter_1/euclide.cpp
chapter_1/prime_power_in_factorial.cpp
chapter_1/sieve_of_eratosthenes.cpp
chapter_2/check_sum_of_squares.cpp
chapter_2/euler_func.cpp
chapter_2/linear_congruences.cpp
chapter_2/linear_congruences.cpp
chapter_3/fib.cpp
chapter_4/primitive_roots.cpp
chapter_4/quadratic_residue.cpp
chapter_4/square_free.cpp
chapter_5/rho_pollard.cpp
chapter_6/prime_tests.cpp
other/all_about.cpp
other/extended_euclidean_result.hpp
other/diophantus_result.hpp
)
set_property(TARGET numbertheory PROPERTY CXX_STANDARD 20)
target_include_directories(numbertheory PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS numbertheory)