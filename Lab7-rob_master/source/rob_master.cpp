#include "rob_master.h"

#include <stack>

const void rob_master::input_information(std::istream& is) {
    house temp_house;
    while (is >> temp_house.money) {
        switch (this->community.size()) {
            case 0 ... 1:   // must start at 0 or 1
                temp_house.maximum_amount = temp_house.money;
                temp_house.previous_house = 0xFFFFFFFF;
                break;
            case 2:         // previous house must be 0
                temp_house.maximum_amount = this->community[0].maximum_amount + temp_house.money;
                temp_house.previous_house = 0;
                break;
            default:        // compare the second last and the third last houses
                if (this->community[this->community.size() - 2].maximum_amount <= this->community[this->community.size() - 3].maximum_amount) {
                    temp_house.maximum_amount = this->community[this->community.size() - 3].maximum_amount + temp_house.money;
                    temp_house.previous_house = this->community.size() - 3;
                }           // if maximum amounts are the same, choose the later one
                else {
                    temp_house.maximum_amount = this->community[this->community.size() - 2].maximum_amount + temp_house.money;
                    temp_house.previous_house = this->community.size() - 2;
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
           << ", previous house: " << c.previous_house
           << std::endl;
    }
}

const void rob_master::output_path(std::ostream& os) const {
    std::stack<unsigned int> sequence;
    unsigned int position = this->community.size() - 1;
    sequence.push(position);
    while (position > 1) {
        position = this->community[position].previous_house;
        sequence.push(position);
    }
    os << sequence.top();
    sequence.pop();
    while (!sequence.empty()) {
        os << " -> " << sequence.top();
        sequence.pop();
    }
    os << std::endl;
}

const void rob_master::output_maximum_amount(std::ostream& os) const {
    os << this->community[this->community.size() - 1].maximum_amount << std::endl;
}

rob_master::rob_master() {}

rob_master::~rob_master() {
    community = std::vector<house> ();
}
