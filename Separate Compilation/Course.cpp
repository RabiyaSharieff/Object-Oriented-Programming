//
//  main.cpp
//  Course
//
//  Created by Rabiya Sharieff on 10/18/19.
//  Copyright © 2019 Rabiya Sharieff. All rights reserved.
//

#include "Course.h"
#include "Student.h"

using namespace std;

namespace BrooklynPoly {
    // Course methods
    Course::Course(const string& courseName) : name(courseName) {}
    string Course::getName() const {
        return name;
    }
    void Course::addStudent(Student* student) { // EDIT THIS PLZ
        students.push_back(student);
    }
    void Course::removeStudentsFromCourse(){
        for (size_t i = 0; i < students.size(); i++) {
            students[i]->deleteCourse(this);
        }
        students.clear();
    }
    ostream& operator<<(ostream& os, const Course& rhs) {
        os << "   Course: " << rhs.name << endl;
        os << "      Students: " << endl;
        for (size_t i = 0; i < rhs.students.size(); i++) {
            os << "        " << rhs.students[i]->getName() << endl;
        }
        return os;
    }
}
