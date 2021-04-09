#include <fstream>

int main(int argc, char** argv)
{
    std::string new_program = "#include <iostream>\n\nint main(int argc, char** argv)\n{\n\tstd::cout << " 
        "\"Hello World\" << std::endl;\n\treturn 0;\n}";
    std::ofstream fout("test.cpp");
    fout << new_program;
    return 0;
}