#ifndef LARGEST_SAME_PATH_FINDER_H
#define LARGEST_SAME_PATH_FINDER_H

#include <iostream>
#include <unordered_map>
#include <list>

struct vertex {
    char color;
    unsigned int distance;
};

class largest_same_path_finder {
    public:
        const void input_information_and_output_result(std::istream& is, std::ostream& os);
        const void output_adjacency_list(std::ostream& os) const;
        const void output_path(std::ostream& os) const;
        largest_same_path_finder();
        ~largest_same_path_finder();
    private:
        const void bfs(const unsigned int& from);
        const void set_path();
        std::unordered_map<unsigned int, std::list<unsigned int>> adjacency_list;
        std::unordered_map<unsigned int, vertex> vertex_to_capital, vertex_to_resort;
        std::list<unsigned int> path_to_capital, path_to_resort;
        unsigned int capital, resort;
};

#endif
