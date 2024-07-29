#include "linked_list.h"

#include <fstream>

int main(int argc, char** argv) {
    linked_list* ll = new linked_list();
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
    ll->input_operation_and_output_result(input_file, output_file);
    delete ll;
    input_file.close();
    output_file.close();
    return 0;
}
