#include "anagram_dictionary.h"

#include <algorithm>

const void anagram_dictionary::input_string_and_group(std::istream& is) {
    std::string current_line;
    while (getline(is, current_line, ',')) {
        std::string temp, sorted_temp;
        for (char c: current_line) {                    // parser
            if (c == '\"' || c == '[' || c == ']') {
                continue;
            }
            temp.push_back(c);
        }
        sorted_temp = temp;
        sort(sorted_temp.begin(), sorted_temp.end());   // sort and group
        this->group[sorted_temp].push_back(temp);
    }
}

const void anagram_dictionary::output_group(std::ostream& os) const {
    for (auto g: this->group) {
        if (*(g.second.begin()) == "") {
            os << "empty line.";
        }
        for (std::string word: g.second) {
            os << word << " ";
        }
        os << std::endl;
    }
}

anagram_dictionary::anagram_dictionary() {}

anagram_dictionary::~anagram_dictionary() {
    this->group = std::unordered_map<std::string, std::list<std::string>> ();
}
