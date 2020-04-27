//
//  Header.h
//  rec07
//
//  Created by Rabiya Sharieff on 10/18/19.
//  Copyright © 2019 Rabiya Sharieff. All rights reserved.
//


#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

namespace BrooklynPoly {
    class Course;
    
    class Student {
        friend std::ostream& operator<<(std::ostream& os, const Student& stu);
    public:
        Student(const std::string& name);
        std::string getName() const;
        void addCourse(Course*);
        void deleteCourse(Course*);
    private:
        std::string name;
        std::vector<Course*> courses;
    };
}
#endif /* Student_hpp */
