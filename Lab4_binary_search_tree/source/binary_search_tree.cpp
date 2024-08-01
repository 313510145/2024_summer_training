#include "binary_search_tree.h"

const void binary_search_tree::input_operation_and_output_result(std::istream& is, std::ostream& os) {
    char command; 
    int parameter, high;
    while (is >> command) {
        switch (command) {
            case 'i':
                is >> parameter;
                insert_node(parameter);
                break;
            case 's':
                is >> parameter;
                search_value(os, parameter);
                break;
            case 'm':
                output_max_min(os);
                break;
            case 'r':
                is >> parameter >> high;
                os << "nodes in range [" << parameter << ", " << high << "]: ";
                output_range_query(os, parameter, high, this->root);
                os << std::endl;
                break;
            case 't':
                os << "pre-order: ";
                recursive_pre_order(os, this->root);
                os << "\nin-order: ";
                recursive_in_order(os, this->root);
                os << "\npost-order: ";
                recursive_post_order(os, this->root);
                os << std::endl;
                break;
            case 'p':
                os << "in-order: ";
                recursive_in_order(os, this->root);
                os << std::endl;
                break;
        }
    }
}

const void binary_search_tree::search_value(std::ostream& os, const int& value) const {
    node* temp = this->root;
    os << "search " << value << ": ";
    while (temp != nullptr) {
        if (temp->data == value) {      // equal, found
            os << "found\n";
            return;
        }
        else if (value < temp->data) {  // smaller, go left
            temp = temp->left;
        }
        else {                          // larger, go right
            temp = temp->right;
        }
    }
    os << "not found\n";                // leaf touched, not found
}

const void binary_search_tree::output_max_min(std::ostream& os) const {
    node *max_ptr = this->root, *min_ptr = this->root;
    while (min_ptr->left != nullptr) {  // repeatedly go left
        min_ptr = min_ptr->left;
    }
    while (max_ptr->right != nullptr) { // repeatedly go right
        max_ptr = max_ptr->right;
    }
    os << "max: " << max_ptr->data << ", min: " << min_ptr->data << std::endl;
}

const void binary_search_tree::output_range_query(std::ostream& os, const int& low, const int& high, node* n) const {
    if (n == nullptr) {
        return;
    }
    output_range_query(os, low, high, n->left);     // in-order output values in range
    if (n->data >= low && n->data <= high) {
        os << n->data << " ";
    }
    output_range_query(os, low, high, n->right);
}

const void binary_search_tree::recursive_pre_order(std::ostream& os, node* n) const {
    if (n == nullptr) {
        return;
    }
    os << n->data << " ";
    recursive_pre_order(os, n->left);
    recursive_pre_order(os, n->right);
}

const void binary_search_tree::recursive_in_order(std::ostream& os, node* n) const {
    if (n == nullptr) {
        return;
    }
    recursive_in_order(os, n->left);
    os << n->data << " ";
    recursive_in_order(os, n->right);
}

const void binary_search_tree::recursive_post_order(std::ostream& os, node* n) const {
    if (n == nullptr) {
        return;
    }
    recursive_post_order(os, n->left);
    recursive_post_order(os, n->right);
    os << n->data << " ";
}

binary_search_tree::binary_search_tree(): root(nullptr) {}

binary_search_tree::~binary_search_tree() {
    delete_all_node(this->root);
}

const void binary_search_tree::insert_node(const int& value) {
    node *n = new node, *temp;
    n->data = value;
    n->left = nullptr;
    n->right = nullptr;
    if (this->root == nullptr) {            // empty tree
        this->root = n;
        return;
    }
    temp = this->root;
    while (true) {
        if (value < temp->data) {           // smaller, go left
            if (temp->left == nullptr) {
                temp->left = n;
                break;
            }
            else {
                temp = temp->left;
            }
        }
        else if (value > temp->data) {      // larger, go right
            if (temp->right == nullptr) {
                temp->right = n;
                break;
            }
            else {
                temp = temp->right;
            }
        }
        else {                              // equal, no action
            break;
        }
    }
}

const void binary_search_tree::delete_all_node(node* n) {
    if (n == nullptr) {
        return;
    }
    delete_all_node(n->left);   // recursively clear left and right of the leaf node and delete it
    delete_all_node(n->right);
    n->left = nullptr;
    n->right = nullptr;
    delete n;
}
