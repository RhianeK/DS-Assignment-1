#include <iostream>
#include <cstdlib>
#include "CStudent.hpp"
#include "CCourse.hpp"
#include "CDept.hpp"

using namespace std;
// test the cstudent class
void TestStudent()
{
    
}

// test the ccourse class
void TestCourse()
{
    cout<<"1";
    CStudent person((char*)"Harry",169);
    cout<<"2";
    CCourse cs((char*)"Algo", 256);
    cout<<"3";
    cs.enroll(&person);
    

// main function to test the depart functionalities
int main(int argc, const char * argv[])
{
    // Test the CStudent class
    TestStudent() ;

    // Test the CCourse class
    TestCourse() ;

    // Create one dept with some default courses and students
    // CDept CSDepartment;

    // // Then display all the students and all the courses
    // CSDepartment.displayStudents();
    // CSDepartment.displayCourses();

    // Display the courses taken by a student with index 2
        //---- do it here ----

    // Find the best student in a particular course

    // Display the student info and his/her Total average score
        //---- do it here ----

    // Create one dept with some default courses and students
        //---- do it here ----

    // Find the courses taken by a prticular student
        //---- do it here ----

    // Create a new course and it to the department offering
        //---- do it here ----

    // Register 2 students in a newly created course
        //---- do it here ----

    // Display the updated list of all courses offered
        //---- do it here ----

    // Register 2 students in a newly created course
        //---- do it here ----

    // Enter the grades of these 2 students in the new course
        //---- do it here ----

    cout << "\n---- I am done ---- Au revoir ----\n\n";
    return 0;
}
