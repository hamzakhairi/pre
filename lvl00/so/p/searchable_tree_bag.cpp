
#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag()
{}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other)
    : tree_bag(other)
{}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other)
{
    if (this != &other)
        tree_bag::operator=(other);
    return *this;
}

searchable_tree_bag::~searchable_tree_bag()
{}

bool searchable_tree_bag::search(node *n, int value) const
{
    if (!n)
        return false;
    if (value < n->value)
        return search(n->l, value);
    return search(n->r, value);
}

bool searchable_tree_bag::has(int value) const
{
    return search(tree, value);
}


