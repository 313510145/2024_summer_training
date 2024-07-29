#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

struct node {
    int data;
    node* left;
    node* right;
};

class binary_search_tree {
    public:
        const void input_operation_and_output_result(std::istream& is, std::ostream& os);
        binary_search_tree();
        ~binary_search_tree();
    private:
        node* root;
        const void insert_node(const int& value);
        const void search_value(std::ostream& os, const int& value) const;
        const void output_max_min(std::ostream& os) const;
        const void output_range_query(std::ostream& os, const int& low, const int& high, node* n) const;
        const void recursive_pre_order(std::ostream& os, node* n) const;
        const void recursive_in_order(std::ostream& os, node* n) const;
        const void recursive_post_order(std::ostream& os, node* n) const;
        const void delete_all_node(node* n);
};

#endif
