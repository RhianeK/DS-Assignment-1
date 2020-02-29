#include <iostream>
#include <cstdlib>
#include "CStudent.hpp"
#include "CCourse.hpp"
#include "CDept.hpp"

using namespace std;
// test the cstudent class
void TestStudent()
{
  cout<<"\nTESTING CSTUDENT CLASS:\n";
  CStudent s((char*)"Harry", 169);
  CCourse c((char*)"Stuff I", 205);
  s.enroll(&c);
  c.enroll(&s);
  c.displayInfo();
  s.displayCourses();
  s.displayInfo();
  s.setExamGrade(0,0,100);
  s.setExamGrade(0,1,99);
  s.setExamGrade(0,2,60);
  s.setExamGrade(0,3,12);
  s.setExamGrade(0,4,98);
  CCourse d((char*)"Stuff II", 305);
  s.enroll(&d);
  d.enroll(&s);
  int scores[] = {20,99,71,83,91};
  s.setCourseGrades(1,scores);
  s.displayCourses();
  float* avgs = s.calcAverages();
  for(int i=0; i<s.getnbCourses(); i++)
    {
      cout<<avgs[i]<<endl;
    }
}

// test the ccourse class
void TestCourse()
{
    //creating a student and a class and enrolling the student in the class
    cout<<"\nTESTING THE CCOURSE CLASS:"<<endl;
    CStudent person((char*)"Harry",169);
    CCourse cs((char*)"Algo", 256);
        //enrolling the student in the course
    cs.enroll(&person);
    person.enroll(&cs);

    //displaying the info of the created course
    cs.displayInfo();

    //creating 2 more students to enroll in the cs course
    CStudent person1((char*)"Mark",125);
    CStudent person2((char*)"Susan",173);
    cs.enroll(&person1);
    person1.enroll(&cs);
    cs.enroll(&person2);
    person2.enroll(&cs);


    //displaying the students enrolled in the course
    cout<<"The students in the course: "<<endl;
    cs.displayStudents();

    //testing the getStudent method, that returns a pointer to the student at the given index
    CStudent* a = cs.getStudent(1);
    cout<<"The student at this index is: "<<endl;
    a->displayInfo();
    
    //testing the calcAverages method
    int scores[] = {91,85,87,93,75};
    int scores1[] = {91,85,87,93,90};
    int scores2[] = {98,89,99,94,86};
    person.setCourseGrades(0, scores);
    person1.setCourseGrades(0, scores1);
    person2.setCourseGrades(0, scores2);

    float* averages = cs.calcAverages();

    int nb = cs.getnbEnrolled();
    for(int i=0; i<nb;i++){
        cout<<averages[i]<<endl;
    }
    //testing the findBestStudent method
    cs.findBestStudent();

}  

// main function to test the depart functionalities
int main(int argc, const char * argv[])
{
    // Test the CStudent class
    TestStudent() ;

    // Test the CCourse class
    TestCourse() ;

    // Create one dept with some default courses and students
    CDept csDepartment;

    // // Then display all the students and all the courses
    cout<<"\n THIS IS THE NEW CS DEPARTMENT\n"<<endl;
    csDepartment.displayStudents();
    cout<<"\n";
    csDepartment.displayCourses();

    // Display the courses taken by a student with index 2
    cout<<"\nCourses of student 2: \n";
    csDepartment.getStudent(2)->displayCourses();

    // Find the best student in a particular course
    cout<<"\nBest student in course 2:"<<endl;
    csDepartment.bestStudentInCourse(csDepartment.getCourse(2));

    // Display the student info and his/her Total average score
    CStudent* cst = csDepartment.getStudent(1);
    cst->displayInfo();
    float* av = cst->calcAverages();
    if(av!=NULL){
        int cstotal = 0;
        for(int i=0; i<cst->getnbCourses(); i++){
            cstotal += av[i];
        }
        cout<<"Total average score of the student is "<<cstotal/cst->getnbCourses()<<endl;
    }
    else{cout<<"this student has no courses"<<endl;}
    // Find the best student in the Department
    cout<<"\nBest student in the department is: \n"<<endl;
    CStudent* cst2 =csDepartment.findBestinDept();
    if(cst2!=NULL){
        cst2->displayInfo();
        float* av2 = cst2->calcAverages();
        int cs2otal = 0;
        for(int i=0; i<cst2->getnbCourses(); i++){
            cs2otal += av2[i];
        }
        cout<<"Total average score of the student is "<<cs2otal/cst2->getnbCourses()<<endl;
    } else{cout<<"no student qualifies"<<endl;}
    // Create a new course and add it to the department offering
    csDepartment.addCourse((char*)"Intro to CS", 101);

    // Register 2 students in a newly created course
    int m = 0;
    for(int i=0; i<csDepartment.getTotalStudents(); i++){
        if(m >=2){break;}
        if(csDepartment.enroll(csDepartment.getStudent(i), csDepartment.getCourse(csDepartment.getTotalCourses()-1))){
            csDepartment.enroll(csDepartment.getStudent(i), csDepartment.getCourse(csDepartment.getTotalCourses()-1));
            m++;
        }
    }

    // Display the updated list of all courses offered
    cout<<"\nUpdated list of courses offered in the CS Department:"<<endl;
    csDepartment.displayCourses();

    // Enter the grades of these 2 students in the new course
    srand(time(0));
    for(int i=0; i<csDepartment.getTotalStudents(); i++){
        if(csDepartment.getStudent(i)->alreadyEnrolled(csDepartment.getCourse(csDepartment.getTotalCourses()-1))){
            int sc[] = {rand()%101,rand()%101,rand()%101,rand()%101,rand()%101};
            csDepartment.getStudent(i)->setCourseGrades(csDepartment.getStudent(i)->getnbCourses()-1, sc);
        }
    }

    cout << "\n---- I am done ---- Au revoir ----\n\n";
    return 0;
}
