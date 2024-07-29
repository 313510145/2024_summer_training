#include "min_energy_finder.h"

#include <fstream>

int main(int argc, char** argv) {
    min_energy_finder* mef = new min_energy_finder();
    std::ifstream input_file;
    std::ofstream output_file;
    input_file.open(argv[1]);
    if (!input_file) {
        std::cout << "Cannot open the input file!\n";
        exit(-1);
    }
    mef->input_information(input_file);
    input_file.close();
    mef->calculate_min_energy();
    output_file.open(argv[2]);
    if (!output_file) {
        std::cout << "Cannot open the output file!\n";
        exit(-1);
    }
    mef->output_min_energy(output_file);
    delete mef;
    output_file.close();
    return 0;
}
