#include "BinarySearchTree.hpp"
#include <iostream>

//Used the structure from the BST assignment
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    deleteTree(root);
}

void BinarySearchTree::deleteTree(TreeNode* node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void BinarySearchTree::insertCourse(const Course& course) {
    root = insertTreeNode(root, course);
}

TreeNode* BinarySearchTree::insertTreeNode(TreeNode* node, const Course& course) {
    if (node == nullptr) {
        return new TreeNode(course);
    }
    if (course.courseNumber < node->course.courseNumber) {
        node->left = insertTreeNode(node->left, course);
    } else if (course.courseNumber > node->course.courseNumber) {
        node->right = insertTreeNode(node->right, course);
    }
    return node;
}

const TreeNode* BinarySearchTree::searchTreeNode(TreeNode* node, const std::string& courseNumber) const {
    if (node == nullptr || node->course.courseNumber == courseNumber) {
        return node;
    }
    if (courseNumber < node->course.courseNumber) {
        return searchTreeNode(node->left, courseNumber);
    } else {
        return searchTreeNode(node->right, courseNumber);
    }
}

void BinarySearchTree::printCourseList() const {
    inOrderTraversal(root);
}

void BinarySearchTree::inOrderTraversal(TreeNode* node) const {
    if (node != nullptr) {
        inOrderTraversal(node->left);
        std::cout << node->course.courseNumber << " " << node->course.title << std::endl;
        inOrderTraversal(node->right);
    }
}

void BinarySearchTree::printCourseInformation(const std::string& courseNumber) const {
    const TreeNode* node = searchTreeNode(root, courseNumber);
    //add a check for error catching
    if (node == nullptr) {
        std::cout << "Course not found: " << courseNumber << std::endl;
        return;
    }
    std::cout << "Course Number: " << node->course.courseNumber << "\nTitle: " << node->course.title << "\nPrerequisites: ";
    if (node->course.prerequisites.empty()) {
        std::cout << "None";
    } else {
        for (const auto& prereq : node->course.prerequisites) {
            std::cout << prereq << " ";
        }
    }
    std::cout << std::endl;
}
