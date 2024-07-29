#include "anagram_dictionary.h"

#include <fstream>

int main(int argc, char** argv) {
    anagram_dictionary* ad = new anagram_dictionary();
    std::ifstream input_file;
    std::ofstream output_file;
    input_file.open(argv[1]);
    if (!input_file) {
        std::cout << "Cannot open the input file!\n";
        exit(-1);
    }
    ad->input_string_and_group(input_file);
    input_file.close();
    output_file.open(argv[2]);
    if (!output_file) {
        std::cout << "Cannot open the output file!\n";
        exit(-1);
    }
    ad->output_group(output_file);
    delete ad;
    output_file.close();
    return 0;
}
