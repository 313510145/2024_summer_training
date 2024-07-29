#ifndef MIN_ENERGY_FINDER_H
#define MIN_ENERGY_FINDER_H

#include <iostream>
#include <map>
#include <list>

struct item {
    unsigned int weight, time;
};

class min_energy_finder {
    public:
        const void input_information(std::istream& is);
        const void calculate_min_energy();
        const void output_min_energy(std::ostream& os) const;
        min_energy_finder();
        ~min_energy_finder();
    private:
        std::map<double, std::list<item>> garage;               // auto-sort key
        unsigned int min_energy;
};

#endif
