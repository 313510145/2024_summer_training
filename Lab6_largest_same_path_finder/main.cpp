#include "largest_same_path_finder.h"

#include <fstream>

int main(int argc, char** argv) {
    largest_same_path_finder* lspf = new largest_same_path_finder();
    std::ifstream input_file(argv[1]);
    std::ofstream output_file(argv[2]);
    if (!input_file) {
        std::cout << "Cannot open the input file!\n";
        exit(-1);
    }
    if (!output_file) {
        std::cout << "Cannot open the output file!\n";
        exit(-1);
    }
    lspf->input_information_and_output_result(input_file, output_file);
    delete lspf;
    input_file.close();
    output_file.close();
    return 0;
}
