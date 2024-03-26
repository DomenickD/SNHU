#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include <vector>

class Course {
public:
    std::string courseNumber;
    std::string title;
    std::vector<std::string> prerequisites;

    Course() = default;
    Course(std::string courseNumber, std::string title, std::vector<std::string> prerequisites)
        : courseNumber(std::move(courseNumber)), title(std::move(title)), prerequisites(std::move(prerequisites)) {}
};

#endif 
