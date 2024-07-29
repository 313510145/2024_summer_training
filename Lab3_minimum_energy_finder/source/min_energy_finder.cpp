#include "min_energy_finder.h"

#include <algorithm>

const void min_energy_finder::input_information(std::istream& is) {
    unsigned int num_item;
    item temp_item;
    std::list<item> temp_list;
    is >> num_item;
    for (unsigned int i = 0; i < num_item; i = i + 1) {
        is >> temp_item.weight;
        temp_list.push_back(temp_item);
    }
    for (auto tl: temp_list) {
        is >> tl.time;
        this->garage[static_cast<double>(tl.weight) / tl.time].push_back(tl);   // sorted by weight / time
    }
    temp_list = std::list<item> ();
}

const void min_energy_finder::calculate_min_energy() {
    unsigned int total_weight = 0;
    for (auto g: this->garage) {                                                // g: groups w/ same weight per time
        for (auto g_item: g.second) {                                           // g_item: items in each group, sequence is nothing
            this->min_energy = this->min_energy + total_weight * g_item.time;
            total_weight = total_weight + g_item.weight;
        }
    }
}

const void min_energy_finder::output_min_energy(std::ostream& os) const {
    os << this->min_energy;
}

min_energy_finder::min_energy_finder() {}

min_energy_finder::~min_energy_finder() {
    this->garage = std::map<double, std::list<item>> ();
}
