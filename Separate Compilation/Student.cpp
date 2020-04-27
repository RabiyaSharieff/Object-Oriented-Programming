//
//  main.cpp
//  Student
//
//  Created by Rabiya Sharieff on 10/18/19.
//  Copyright © 2019 Rabiya Sharieff. All rights reserved.
//

#include <stdio.h>
#include "Student.h"
#include "Course.h"
#include <string>

using namespace std;

namespace BrooklynPoly {
    // Student methods
    Student::Student(const string& name) : name(name) {}
    string Student::getName() const {
        return name;
    }
    void Student::addCourse(Course* course) {
        courses.push_back(course);
    }
    void Student::deleteCourse(Course* course) { 
        size_t courseIndex = -1;
        for (size_t i = 0; i < courses.size(); i++) {
            if (courses[i] == course) {
                courseIndex = i;
                break;
            }
        }
        if (courseIndex == -1) {
            return;
        }
        courses.erase(courses.begin() + courseIndex);
    }
    ostream& operator<<(ostream& os, const Student& stu) {
        os << "Student: " << stu.name << endl;
        os << "Courses: " << endl;
        for (size_t i = 0; i < stu.courses.size(); i++) {
            os << " " << stu.courses[i]->getName() << endl;
        }
        return os;
    }
}
