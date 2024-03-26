#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "TreeNode.hpp"

class BinarySearchTree {
private:
    TreeNode* root;
    void inOrderTraversal(TreeNode* node) const;
    TreeNode* insertTreeNode(TreeNode* node, const Course& course);
    const TreeNode* searchTreeNode(TreeNode* node, const std::string& courseNumber) const;
    void deleteTree(TreeNode* node);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insertCourse(const Course& course);
    void printCourseList() const;
    void printCourseInformation(const std::string& courseNumber) const;
};

#endif 
