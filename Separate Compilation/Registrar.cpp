//
//  main.cpp
//  Registrar
//
//  Created by Rabiya Sharieff on 10/18/19.
//  Copyright © 2019 Rabiya Sharieff. All rights reserved.
//

#include "Registrar.h"
#include "Course.h"
#include "Student.h"

using namespace std;

namespace BrooklynPoly {
    // Registrar methods
    Registrar::Registrar() {}
    bool Registrar::addCourse(const string& name) {
        if (findCourse(name) != -1) {
            return false;
        }
        courses.push_back(new Course(name));
        return true;
    }
    bool Registrar::addStudent(const string & name) {
        if (findStudent(name) != -1) {
            return false;
        }
        students.push_back(new Student(name));
        return true;
    }
    bool Registrar::enrollStudentInCourse(const string& studentName
                                          , const string& courseName) {
        size_t studentIndex = findStudent(studentName);
        size_t courseIndex = findCourse(courseName);
        if (studentIndex == -1 || courseIndex == -1) {
            return false;
        }
        students[studentIndex]->addCourse(courses[courseIndex]);
        courses[courseIndex]->addStudent(students[studentIndex]);
        return true;
    }
    bool Registrar::cancelCourse(const string& courseName) {
        if (findCourse(courseName) == -1) {
            return false;
        }
        size_t courseIndex = findCourse(courseName);
        courses[courseIndex]->removeStudentsFromCourse();
        delete courses[courseIndex];
        courses.erase(courses.begin() + courseIndex);
        return true;
    }
    void Registrar::purge() {
        for (size_t i = 0; i < courses.size(); i++) {
            courses[i]->removeStudentsFromCourse();
            delete courses[i];
        }
        for (size_t i = 0; i < students.size(); i++) {
            delete students[i];
        }
        students.clear();
        courses.clear();
    }
    size_t Registrar::findStudent(const string& name) const {
        size_t studentIndex = -1;
        for (size_t i = 0; i < students.size(); i++) {
            if (students[i]->getName() == name) {
                studentIndex = i;
                break;
            }
        }
        return studentIndex;
    }
    size_t Registrar::findCourse(const string& name) const {
        size_t courseIndex = -1;
        for (size_t i = 0; i < courses.size(); i++) {
            if (courses[i]->getName() == name) {
                courseIndex = i;
                break;
            }
        }
        return courseIndex;
    }
    ostream& operator<<(ostream& os, const Registrar& rhs) {
        os << "Registrar's report" << endl;
        os << "Students:" << endl;
        for (size_t i = 0; i < rhs.students.size(); i++) {
            os << *rhs.students[i] << endl;
        }
        os << "Courses:" << endl;
        for (size_t i = 0; i < rhs.courses.size(); i++) {
            os << *rhs.courses[i] << endl;
        }
        return os;
    }
}

