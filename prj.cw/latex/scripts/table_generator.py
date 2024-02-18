/# table generator for Eratosthenes sieve visualization in LaTeX (maybe someday I'll write it in C++...)

def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True


def generate_latex_square(n):
    latex_code = "\\begin{center}\n\\begin{tabular}{"
    for _ in range(n):
        latex_code += "|c"
    latex_code += "|}\n\\hline\n"
    num = 1
    for i in range(1, n+1):
        for j in range(1, n+1):
            if is_prime(num):
                latex_code += str(num)
            else:
                latex_code += "\\textcolor{gray}{" + str(num) + "}"
            if j < n:
                latex_code += " & "
            num += 1
        latex_code += " \\\\\n\\hline\n" if i < n else " \\\\\n\\hline\n"
    latex_code += "\\end{tabular}\n\\end{center}"
    return latex_code

latex_code = generate_latex_square(10)
print(latex_code)
