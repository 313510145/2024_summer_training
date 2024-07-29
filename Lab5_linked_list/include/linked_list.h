#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

struct node {
    int data;
    node* next;
};

class linked_list {
    public:
        const void input_operation_and_output_result(std::istream& is, std::ostream& os);
        linked_list();
        ~linked_list();
    private:
        node* head;
        const void insert_at_beginning(const int& value);
        const void insert_at_end(const int& value);
        const void delete_by_value(const int& value);
        const void reverse_list();
        const void remove_duplicate();
        const void output_list(std::ostream& os) const;
        const void delete_head_node();
};

#endif
