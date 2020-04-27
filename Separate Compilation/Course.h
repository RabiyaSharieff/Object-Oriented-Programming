//
//  Course.h
//  rec07
//
//  Created by Rabiya Sharieff on 10/18/19.
//  Copyright © 2019 Rabiya Sharieff. All rights reserved.
//

#ifndef Course_hpp
#define Course_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

namespace BrooklynPoly {
    class Student;
    
    class Course {
        friend std::ostream& operator<<(std::ostream&, const Course&);
    public:
        Course(const std::string& courseName);
        std::string getName() const;
        void addStudent(Student*);
        void removeStudentsFromCourse();
    private:
        std::string name;
        std::vector<Student*> students;
    };
}
#endif /* Course_hpp */
