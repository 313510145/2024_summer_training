#ifndef MINIMUM_ENERGY_FINDER_H
#define MINIMUM_ENERGY_FINDER_H

#include <iostream>
#include <map>
#include <list>

struct item {
    unsigned int weight, time;
};

class minimum_energy_finder {
    public:
        const void input_information(std::istream& is);
        const void calculate_minimum_energy();
        const void output_minimum_energy(std::ostream& os) const;
        minimum_energy_finder();
        ~minimum_energy_finder();
    private:
        std::map<double, std::list<item>> garage;               // auto-sort key
        unsigned int minimum_energy;
};

#endif
