//
//  Header.h
//  rec07
//
//  Created by Rabiya Sharieff on 10/18/19.
//  Copyright © 2019 Rabiya Sharieff. All rights reserved.
//


#ifndef Registrar_hpp
#define Registrar_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

namespace BrooklynPoly {
    class Student;
    class Course;
    
    class Registrar {
        friend std::ostream& operator<<(std::ostream&, const Registrar&);
    public:
        Registrar();
        bool addCourse(const std::string&);
        bool addStudent(const std::string&);
        bool enrollStudentInCourse(const std::string& studentName,
                                   const std::string& courseName);
        bool cancelCourse(const std::string& courseName);
        void purge();
        
    private:
        size_t findStudent(const std::string&) const;
        size_t findCourse(const std::string&) const;
        
        std::vector<Course*> courses;
        std::vector<Student*> students;
    };
}

#endif /* Registrar_hpp */
