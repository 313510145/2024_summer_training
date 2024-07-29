#ifndef ANAGRAM_DICTIONARY_H
#define ANAGRAM_DICTIONARY_H

#include <unordered_map>
#include <string>
#include <list>
#include <iostream>

class anagram_dictionary {
    public:
        const void input_string_and_group(std::istream& is);
        const void output_group(std::ostream& os) const;
        anagram_dictionary();
        ~anagram_dictionary();
    private:
        std::unordered_map<std::string, std::list<std::string>> group;
};

#endif
