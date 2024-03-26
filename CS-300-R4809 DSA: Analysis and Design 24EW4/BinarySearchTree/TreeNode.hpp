#ifndef TREENODE_HPP
#define TREENODE_HPP

#include "Course.hpp"

class TreeNode {
public:
    Course course;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Course course, TreeNode* left = nullptr, TreeNode* right = nullptr)
        : course(std::move(course)), left(left), right(right) {}
};

#endif 
