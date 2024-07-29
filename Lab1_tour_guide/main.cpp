#include "tour_guide.h"

#include <fstream>

int main(int argc, char** argv) {
    tour_guide* tg = new tour_guide();
    std::ifstream input_file;
    std::ofstream output_file;
    input_file.open(argv[1]);
    if (!input_file) {
        std::cout << "Cannot open the input file!\n";
        exit(-1);
    }
    tg->input_toured_track_and_tour(input_file);
    input_file.close();
    output_file.open(argv[2]);
    if (!output_file) {
        std::cout << "Cannot open the output file!\n";
        exit(-1);
    }
    tg->output_tour_track(output_file);
    delete tg;
    output_file.close();
    return 0;
}
