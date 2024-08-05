#ifndef ROB_MASTER_H
#define ROB_MASTER_H

#include <iostream>
#include <vector>

struct house {
    unsigned int money;
    unsigned int maximum_amount, previous_house;
};

class rob_master {
    public:
        const void input_information(std::istream& is);
        const void output_community(std::ostream& os) const;
        const void output_path(std::ostream& os) const;
        const void output_maximum_amount(std::ostream& os) const;
        rob_master();
        ~rob_master();
    private:
        std::vector<house> community;
};

#endif  // ROB_MASTER_H
