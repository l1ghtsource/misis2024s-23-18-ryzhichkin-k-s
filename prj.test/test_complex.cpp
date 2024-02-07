#include <complex/complex.hpp>
#include <complex/complex.cpp>

bool testParse(const std::string& str) {
  std::istringstream istrm(str);
  Complex z;
  istrm >> z;

  if (istrm.good()) {
    std::cout << "Read success: " << str << " -> " << z << std::endl;
  }
  else {
    std::cout << "Read error: " << str << " -> " << z << std::endl;
  }
  return istrm.good();
}

void test_output(const std::string& operand1, const std::string& operand2, const std::string& operator_, const Complex& ans, const Complex& correct_ans, const std::string& status) {
  std::cout << "Test: " << operand1 << " " << operator_ << " " << operand2 << " " << "Answer: " << ans << " " << "Correct answer: " << correct_ans << " " << "Status: " << status << std::endl;
}

void test_output(const std::string& operand1, const std::string& operand2, const std::string& operator_, const std::string& ans, const std::string& correct_ans, const std::string& status) {
  std::cout << "Test: " << operand1 << " " << operator_ << " " << operand2 << " " << "Answer: " << ans << " " << "Correct answer: " << correct_ans << " " << "Status: " << status << std::endl;
}

void test_output(const std::string& deg_sym, const std::string& operand, std::vector<Complex>& ans, std::vector<Complex>& correct_ans, const std::string& status) {
  std::cout << "Test: " << "Root " << deg_sym << " degrees of " << operand << " " << "Answer: ";
  for (Complex& z : ans) {
    std::cout << z << " ";
  }
  std::cout << "Correct answer: ";
  for (Complex& z : correct_ans) {
    std::cout << z << " ";
  }
  std::cout << "Status: " << status << std::endl;
}

void test_output(const std::string& deg_sym, const std::string& operand, const std::string& ans, const std::string& correct_ans, const std::string& error) {
  std::cout << "Test: " << "Root " << deg_sym << " degrees of " << operand << " " << "Answer: " << ans << " " << "Correct answer : " << correct_ans << " " << "Status: " << error << std::endl;
}

void test_output(const std::string& operand, const double& ans, const double& correct_ans, const std::string& status) {
  std::cout << "Test: " << "Arg of " << operand << " " << "Answer: " << ans << " " << "Correct answer: " << correct_ans << " " << "Status: " << status << std::endl;
}

void test_output(const std::string& operand, const std::string& ans, const std::string& correct_ans, const std::string& status) {
  std::cout << "Test: " << "Arg of " << operand << " " << "Answer: " << ans << " " << "Correct answer: " << correct_ans << " " << "Status: " << status << std::endl;
}

void test_output(const Complex& operand, const double& ans, const double& correct_ans, const std::string& status) {
  std::cout << "Test: " << "Modulus of " << operand << " " << "Answer: " << ans << " " << "Correct answer: " << correct_ans << " " << "Status: " << status << std::endl;
}

int main() {
  std::vector<std::string> test_data_parse = { "{1, 2.3}", "{2.2, 3}", "{4, 0}", "{0, 4}", "{0, 0}", "{0}", "{5}", "{8.9, 9", "9", "8.9, 9", "8.9, 9}" };
  std::vector<Complex> complex_test_data = { {1, 2.3}, {2.2, 3}, {4, 0}, {0, 4}, {0, 0} };
  int parse_num_tests = (int)test_data_parse.size();

  std::vector<Complex> complex_nums;

  for (int num_test = 0; num_test < parse_num_tests; ++num_test) {
    std::string current_data = test_data_parse[num_test];
    if (testParse(current_data)) {
      complex_nums.push_back(complex_test_data[num_test]);
    }
  }

  Complex z1 = complex_nums[0];
  Complex z2 = complex_nums[1];
  Complex z3 = complex_nums[2];
  Complex z4 = complex_nums[3];
  Complex z5 = complex_nums[4];

  const double alpha = 11;
  std::string alpha_sym = "11";

  const int deg = 5;
  std::string deg_sym = "5";

  std::string nan = "None";

  Complex res1_check_sum_of_2_complex = z1 + z2;
  Complex ans1 = { 3.2, 5.3 };
  std::string status1 = is_equal_complex(res1_check_sum_of_2_complex, ans1) ? "OK" : "WRONG";

  test_output(test_data_parse[0], test_data_parse[1], "+", res1_check_sum_of_2_complex, ans1, status1);

  Complex res2_check_difference_of_2_complex = z2 - z1;
  Complex ans2 = { 1.2, 0.7 };
  std::string status2 = is_equal_complex(res2_check_difference_of_2_complex, ans2) ? "OK" : "WRONG";

  test_output(test_data_parse[1], test_data_parse[0], "-", res2_check_difference_of_2_complex, ans2, status2);

  Complex res3_check_product_of_2_complex = z1 * z2;
  Complex ans3 = { -4.7, 8.06 };
  std::string status3 = is_equal_complex(res3_check_product_of_2_complex, ans3) ? "OK" : "WRONG";

  test_output(test_data_parse[0], test_data_parse[1], "*", res3_check_product_of_2_complex, ans3, status3);

  Complex res4_check_quotient_of_2_complex = z1 / z2;
  Complex ans4 = { 0.657514, 0.148844 };
  std::string status4 = is_equal_complex(res4_check_quotient_of_2_complex, ans4) ? "OK" : "WRONG";

  test_output(test_data_parse[0], test_data_parse[1], "/", res4_check_quotient_of_2_complex, ans4, status4);

  try {
    Complex res5_check_quotient_of_2_complex = z1 / z5;
  }
  catch (std::string& error) {
    test_output(test_data_parse[0], test_data_parse[4], "/", nan, nan, error);
  }

  Complex res6_check_sum_of_complex_and_real = z1 + alpha;
  Complex ans6 = { 12, 2.3 };
  std::string status6 = is_equal_complex(res6_check_sum_of_complex_and_real, ans6) ? "OK" : "WRONG";

  test_output(test_data_parse[0], alpha_sym, "+", res6_check_sum_of_complex_and_real, ans6, status6);

  Complex res7_check_difference_of_complex_and_real = z1 - alpha;
  Complex ans7 = { -10, 2.3 };
  std::string status7 = is_equal_complex(res7_check_difference_of_complex_and_real, ans7) ? "OK" : "WRONG";

  test_output(test_data_parse[0], alpha_sym, "-", res7_check_difference_of_complex_and_real, ans7, status7);

  Complex res8_check_product_of_complex_and_real = z1 * alpha;
  Complex ans8 = { 11, 25.3 };
  std::string status8 = is_equal_complex(res8_check_product_of_complex_and_real, ans8) ? "OK" : "WRONG";

  test_output(test_data_parse[0], alpha_sym, "*", res8_check_product_of_complex_and_real, ans8, status8);

  Complex res9_check_quotient_of_complex_and_real = z1 / alpha;
  Complex ans9 = { 0.0909091, 0.209091 };
  std::string status9 = is_equal_complex(res9_check_quotient_of_complex_and_real, ans9) ? "OK" : "WRONG";

  test_output(test_data_parse[0], alpha_sym, "/", res9_check_quotient_of_complex_and_real, ans9, status9);

  try {
    Complex res10_check_quotient_of_complex_and_real = z1 / 0;
  }
  catch (std::string error) {
    test_output(test_data_parse[0], "0", "/", nan, nan, error);
  }

  Complex res11_check_degree_of_complex = degree(z1, deg);
  Complex ans11 = { 88.0205, -45.8066 };
  std::string status11 = is_equal_complex(res11_check_degree_of_complex, ans11) ? "OK" : "WRONG";

  test_output(test_data_parse[0], deg_sym, "^", res11_check_degree_of_complex, ans11, status11);

  try {
    Complex res12_check_degree_of_complex = degree(z5, 0);
  }
  catch (std::string error) {
    test_output(test_data_parse[4], "0", "^", nan, nan, error);
  }

  Complex res13_check_degree_of_complex = degree(z1, 0);
  Complex ans13 = { 1, 0 };
  std::string status13 = is_equal_complex(res13_check_degree_of_complex, ans13) ? "OK" : "WRONG";

  test_output(test_data_parse[0], "0", "^", res13_check_degree_of_complex, ans13, status13);

  std::vector<Complex> res14_check_root_of_complex = root(z1, deg);
  std::vector<Complex> ans14 = { {1.16965, 0.276501}, {0.0984752, 1.19785}, {-1.10879, 0.463811}, {-0.783747, -0.911199}, {0.62441, -1.02696} };
  std::string status14 = is_equal_vector(res14_check_root_of_complex, ans14) ? "OK" : "WRONG";

  test_output(deg_sym, test_data_parse[0], res14_check_root_of_complex, ans14, status14);

  try {
    std::vector<Complex> res15_check_root_of_complex = root(z1, -1);
  }
  catch (std::string error) {
    test_output("-1", test_data_parse[0], nan, nan, error);
  }

  try {
    std::vector<Complex> res16_check_root_of_complex = root(z1, 0);
  }
  catch (std::string error) {
    test_output("0", test_data_parse[0], nan, nan, error);
  }

  double res17_check_arg_of_complex = arg(z1);
  double ans17 = 1.16067;
  std::string status17 = is_equal(res17_check_arg_of_complex, ans17) ? "OK" : "WRONG";

  test_output(test_data_parse[0], res17_check_arg_of_complex, ans17, status17);

  try {
    double res18_check_arg_of_complex = arg(z5);
  }
  catch (std::string error) {
    test_output(test_data_parse[4], nan, nan, error);
  }

  double res19_check_modulus_of_complex = modulus(z1);
  double ans19 = 2.50799;
  std::string status19 = is_equal(res19_check_modulus_of_complex, ans19) ? "OK" : "WRONG";

  test_output(complex_nums[0], res19_check_modulus_of_complex, ans19, status19);

  std::vector<std::string> statuses = { status1, status2, status3, status4, status6, status7, status8, status9, status11, status13, status14, status17, status19 };
  std::string all_tests_is_ok = (std::all_of(statuses.cbegin(), statuses.cend(), [](std::string status) { return status == "OK"; })) ? "All tests passed :)" : "Not all tests passed :(";

  std::cout << all_tests_is_ok;

  return 0;
}