#include "linked_list.h"

#include <unordered_set>

const void linked_list::input_operation_and_output_result(std::istream& is, std::ostream& os) {
    char command;
    int parameter;
    while (is >> command) {
        switch (command) {
            case 'b':
                is >> parameter;
                insert_at_beginning(parameter);
                break;
            case 'e':
                is >> parameter;
                insert_at_end(parameter);
                break;
            case 'd':
                is >> parameter;
                delete_by_value(parameter);
                break;
            case 'r':
                reverse_list();
                break;
            case 'c':
                remove_duplicate();
                break;
            case 'p':
                output_list(os);
                break;
        }
    }
}

linked_list::linked_list(): head(nullptr) {}

linked_list::~linked_list() {
    while (this->head != nullptr) { // repeatedly clear next of the head node and delete it
        delete_head_node();
    }
}

const void linked_list::insert_at_beginning(const int& value) {
    node* n = new node;
    n->data = value;
    n->next = this->head;
    this->head = n;
}

const void linked_list::insert_at_end(const int& value) {
    node *n = new node, *end;
    n->data = value;
    n->next = nullptr;
    if (this->head == nullptr) {    // empty list
        this->head = n;
        return;
    }
    end = this->head;
    while (end->next != nullptr) {
        end = end->next;
    }
    end->next = n;
}

const void linked_list::delete_by_value(const int& value) {
    node *previous = nullptr, *current = this->head, *next;
    while (current != nullptr) {
        next = current->next;
        if (current->data == value) {           // found
            if (previous == nullptr) {          // found at head node
                this->head = next;
            }
            else {
                previous->next = current->next;
            }
            current->next = nullptr;            // clear next of the node and delete it
            delete current;
        }
        else {                                  // not found
            previous = current;                 // go to next node
        }
        current = next;                         // original next node
    }
}

const void linked_list::reverse_list() {
    node *previous = nullptr, *current = this->head, *next;
    while (current != nullptr) {
        next = current->next;
        current->next = previous;
        previous = current;         // go to next node
        current = next;
    }
    this->head = previous;          // refresh the head node
}

const void linked_list::remove_duplicate() {
    std::unordered_set<int> temp_set;
    node *temp_node = this->head, *end;
    int num_node = 0;
    while (temp_node != nullptr) {
        end = temp_node;                // store the end node
        temp_node = temp_node->next;
        num_node = num_node + 1;        // recode number of nodes
    }
    temp_node = this->head;
    for (int i = 0; i < num_node; i = i + 1) {
        if (temp_set.find(temp_node->data) == temp_set.end()) { // saw it first time
            temp_set.insert(temp_node->data);                   // keep it
            node* n = new node;                                 // insert at end but not call insert_at_end(...)
            n->data = temp_node->data;
            n->next = nullptr;
            end->next = n;
            end = n;
        }
        temp_node = temp_node->next;                            // go to next node
        delete_head_node();                                     // delete the head node
    }
}

const void linked_list::output_list(std::ostream& os) const {
    node* temp = this->head;
    while (temp != nullptr) {
        os << temp->data << " ";
        temp = temp->next;
    }
    os << std::endl;
}

const void linked_list::delete_head_node() {
    node* temp = this->head;
    this->head = this->head->next;
    temp->next = nullptr;
    delete temp;
}
