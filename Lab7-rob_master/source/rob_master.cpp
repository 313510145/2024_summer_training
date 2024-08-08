#include "rob_master.h"

const void rob_master::input_information_and_calculate(std::istream& is) {
    house temp_house;
    while (is >> temp_house.money) {
        switch (this->community.size()) {
            case 0 ... 1:   // must start at 0 or 1
                temp_house.maximum_amount = temp_house.money;
                break;
            case 2:         // previous house must be 0
                temp_house.maximum_amount = this->community[0].maximum_amount + temp_house.money;
                break;
            default:        // compare the second last and the third last houses
                if (this->community[this->community.size() - 2].maximum_amount < this->community[this->community.size() - 3].maximum_amount) {
                    temp_house.maximum_amount = this->community[this->community.size() - 3].maximum_amount + temp_house.money;
                }
                else {
                    temp_house.maximum_amount = this->community[this->community.size() - 2].maximum_amount + temp_house.money;
                }
                break;
        }
        this->community.push_back(temp_house);
    }
}

const void rob_master::output_community(std::ostream& os) const {
    for (auto c: this->community) {
        os << "money: " << c.money
           << ", maximum amount: " << c.maximum_amount
           << std::endl;
    }
}

const void rob_master::output_maximum_amount(std::ostream& os) const {
    os << this->community[this->community.size() - 1].maximum_amount << std::endl;
}

rob_master::rob_master() {}

rob_master::~rob_master() {
    this->community.clear();
}
