# main.tex table of contents parser, which puts this table of contents into readme.md (maybe someday I'll write it in C++...)

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


def write_toc_to_md(toc, readme_file_path):
    with open(readme_file_path, 'r', encoding='utf-8') as file:
        readme_content = file.read()

    toc_md = 'Текущая структура:\n\n'
    for level, title in toc:
        toc_md += '    ' * (level - 1) + '- ' + title + '\n'

    updated_readme_content = re.sub(r'Текущая структура:\n\n(?:.*\n)*', toc_md, readme_content)

    with open(readme_file_path, 'w', encoding='utf-8') as file:
        file.write(updated_readme_content)


if __name__ == '__main__':
    latex_file_path = r'..\main.tex'
    readme_file_path = r'..\..\readme.md'
    toc = parse_latex_toc(latex_file_path)
    write_toc_to_md(toc, readme_file_path)