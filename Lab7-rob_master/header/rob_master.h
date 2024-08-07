#ifndef ROB_MASTER_H
#define ROB_MASTER_H

#include <iostream>
#include <vector>

struct house {
    unsigned int money;
    unsigned int maximum_amount;
};

class rob_master {
    public:
        const void input_information_and_calculate(std::istream& is);
        const void output_community(std::ostream& os) const;
        const void output_maximum_amount(std::ostream& os) const;
        rob_master();
        ~rob_master();
    private:
        std::vector<house> community;
};

#endif  // ROB_MASTER_H
