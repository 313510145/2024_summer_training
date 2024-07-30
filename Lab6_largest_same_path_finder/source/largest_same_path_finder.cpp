#include "largest_same_path_finder.h"

#include <queue>

const void largest_same_path_finder::input_information_and_output_result(std::istream& is, std::ostream& os) {
    unsigned int num_city, num_query;
    unsigned int temp_a, temp_b;
    is >> num_city >> num_query >> this->capital >> this->resort;
    for (unsigned int i = 1; i < num_city; i = i + 1) {             // build adjacency list
        is >> temp_a >> temp_b;
        this->adjacency_list[temp_a].push_back(temp_b);
        this->adjacency_list[temp_b].push_back(temp_a);
    }
    for (unsigned int i = 0; i < num_query; i = i + 1) {
        is >> temp_a;                                               // input start point
        bfs(temp_a);                                                // do bfs
        set_path();                                                 // set path_to_capital and path_to_resort
        auto it_path_to_capital = path_to_capital.begin();
        auto it_path_to_resort = path_to_resort.begin();
        while (                                                     // find the first difference between two lists
            (++it_path_to_capital != path_to_capital.end()) &&      // start point is fixed and same
            (++it_path_to_resort != path_to_resort.end())
        ) {
            if ((*it_path_to_capital) != (*it_path_to_resort)) {
                break;
            }
        }
        os << *(--it_path_to_capital) << std::endl;                 // output the last identical value
    }
}

const void largest_same_path_finder::output_adjacency_list(std::ostream& os) const {
    os << "adjacency list\n";
    for (auto al: this->adjacency_list) {
        os << al.first << ":";
        for (auto al_adj: al.second) {
            os << " " << al_adj;
        }
        os << std::endl;
    }
}

const void largest_same_path_finder::output_path(std::ostream& os) const {
    os << "path to capital:";
    for (auto ptc: this->path_to_capital) {
        os << " " << ptc;
    }
    os << "\npath to resort:";
    for (auto ptr: this->path_to_resort) {
        os << " " << ptr;
    }
    os << std::endl;
}

largest_same_path_finder::largest_same_path_finder(): capital(0), resort(0) {}

largest_same_path_finder::~largest_same_path_finder() {
    adjacency_list = std::unordered_map<unsigned int, std::list<unsigned int>> ();
    vertex_to_capital = std::unordered_map<unsigned int, vertex> ();
    vertex_to_resort = std::unordered_map<unsigned int, vertex> ();
    path_to_capital = std::list<unsigned int> ();
    path_to_resort = std::list<unsigned int> ();
}

const void largest_same_path_finder::bfs(const unsigned int& from) {
    vertex initial_vertex;
    initial_vertex.color = 'w';                             // white
    initial_vertex.distance = 0xFFFFFFFF;                   // UINT_MAX
    for (auto al: adjacency_list) {                         // initialization
        vertex_to_capital[al.first] = initial_vertex;
        vertex_to_resort[al.first] = initial_vertex;
    }
    vertex_to_capital[from].color = 'g';                    // gray
    vertex_to_capital[from].distance = 0;                   // distance from start point
    std::queue<unsigned int> q;
    q.push(from);                                           // push and make it gray
    unsigned int temp;
    while (!q.empty()) {
        temp = q.front();
        for (auto q_adj: adjacency_list[temp]) {
            if (vertex_to_capital[q_adj].color == 'w') {    // white, not traversed
                vertex_to_capital[q_adj].color = 'g';       // gray
                vertex_to_capital[q_adj].distance = vertex_to_capital[temp].distance + 1;
                q.push(q_adj);                              // push and make it gray
            }
        }
        vertex_to_capital[temp].color = 'b';                // black
        q.pop();                                            // pop and make it black
    }
    vertex_to_resort[from].color = 'g';                     // gray
    vertex_to_resort[from].distance = 0;
    q.push(from);                                           // push and make it gray
    while (!q.empty()) {
        temp = q.front();
        for (auto q_adj: adjacency_list[temp]) {
            if (vertex_to_resort[q_adj].color == 'w') {     // white, not traversed
                vertex_to_resort[q_adj].color = 'g';        // gray
                vertex_to_resort[q_adj].distance = vertex_to_resort[temp].distance + 1;
                q.push(q_adj);                              // push and make it gray
            }
        }
        vertex_to_resort[temp].color = 'b';                 // black
        q.pop();                                            // push and make it black
    }
}

const void largest_same_path_finder::set_path() {
    unsigned int current_vertex_capital, current_vertex_resort;
    path_to_capital = std::list<unsigned int> ();                           // clear path
    path_to_resort = std::list<unsigned int> ();
    current_vertex_capital = capital;                                       // backtrack
    current_vertex_resort = resort;
    path_to_capital.push_front(current_vertex_capital);                     // for while loop and UINT limit
    path_to_resort.push_front(current_vertex_resort);
    while (vertex_to_capital[current_vertex_capital].distance > 0) {
        for (auto capital_adj: adjacency_list[current_vertex_capital]) {    // adjacent vertex and closer to start point
            if (vertex_to_capital[capital_adj].distance == vertex_to_capital[current_vertex_capital].distance - 1) {
                path_to_capital.push_front(capital_adj);
                current_vertex_capital = capital_adj;                       // update current vertex
                break;
            }
        }
    }
    while (vertex_to_resort[current_vertex_resort].distance > 0) {
        for (auto resort_adj: adjacency_list[current_vertex_resort]) {      // adjacent vertex and closer to start point
            if (vertex_to_resort[resort_adj].distance == vertex_to_resort[current_vertex_resort].distance - 1) {
                path_to_resort.push_front(resort_adj);
                current_vertex_resort = resort_adj;                         // update current vertex
                break;
            }
        }
    }
}
