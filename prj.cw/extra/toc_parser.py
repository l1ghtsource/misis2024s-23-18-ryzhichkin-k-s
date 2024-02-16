import re


def parse_latex_toc(tex_file_path):
    toc = []
    in_toc = False
    with open(tex_file_path, 'r', encoding='utf-8') as file:
        for line in file:
            if line.strip() == '\\tableofcontents':
                in_toc = True
                continue
            if in_toc and line.strip() == '\\begin{document}':
                in_toc = False
                break
            if in_toc:
                match = re.match(r'\\(section|subsection|subsubsection)\*?{(.+?)}', line.strip())
                if match:
                    toc.append((len(match.group(1)), match.group(2)))
    return toc


def write_toc_to_txt(toc, output_file):
    with open(output_file, 'w', encoding='utf-8') as file:
        for level, title in toc:
            file.write('    ' * (level - 1) + title + '\n')


if __name__ == '__main__':
    latex_file_path = 'example.tex'
    output_txt_file = 'toc.txt'
    toc = parse_latex_toc(latex_file_path)
    write_toc_to_txt(toc, output_txt_file)