#include "minimum_energy_finder.h"

const void minimum_energy_finder::input_information_and_calculate(std::istream& is) {
    unsigned int num_item;
    std::list<item> temp_list;
    is >> num_item;
    for (unsigned int i = 0; i < num_item; i = i + 1) {
        item temp_item;
        is >> temp_item.weight;
        temp_list.push_back(temp_item);
    }
    for (auto tl: temp_list) {
        is >> tl.time;
        this->garage[static_cast<double>(tl.weight) / tl.time].push_back(tl);   // sorted by weight / time
    }
    temp_list = std::list<item> ();
    this->calculate_minimum_energy();
}

const void minimum_energy_finder::output_minimum_energy(std::ostream& os) const {
    os << this->minimum_energy;
}

const void minimum_energy_finder::calculate_minimum_energy() {
    unsigned int total_weight = 0;
    for (auto g: this->garage) {        // g: groups w/ same weight per time
        for (auto g_item: g.second) {   // g_item: items in each group, sequence is nothing
            this->minimum_energy = this->minimum_energy + total_weight * g_item.time;
            total_weight = total_weight + g_item.weight;
        }
    }
}

minimum_energy_finder::minimum_energy_finder(): minimum_energy(0) {}

minimum_energy_finder::~minimum_energy_finder() {
    this->garage.clear();
}
