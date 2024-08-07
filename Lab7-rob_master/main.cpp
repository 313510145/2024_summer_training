#include "rob_master.h"

#include <fstream>

int main(int argc, char** argv) {
    rob_master* rm = new rob_master();
    std::ifstream input_file(argv[1]);
    if (!input_file) {
        std::cout << "Cannot open the input file!\n";
        exit(-1);
    }
    rm->input_information_and_calculate(input_file);
    input_file.close();
    std::ofstream output_file(argv[2]);
    if (!output_file) {
        std::cout << "Connot open the output file!\n";
        exit(-1);
    }
    rm->output_maximum_amount(output_file);
    delete rm;
    output_file.close();
    return 0;
}
