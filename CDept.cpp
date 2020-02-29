#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constants.h"
#include "CDept.hpp"
#include "CCourse.hpp"
#include "CStudent.hpp"
using namespace std;

CDept::CDept()
{
    students = new CStudent*[MAXNBST];
    courses = new CCourse*[MAXNBCR];
    nbStudents = 0;
    nbCourses = 0;
    createStudents() ;
    createCourses() ;
    enrollStudentsInCourses() ;
    createDefaultGrades() ;
}

CDept::~CDept() {
    // -- do it here --
    delete [] students;
    delete [] courses;
}

//getter for a student from the array students
CStudent* CDept::getStudent(int index)
{
    if(index>=0 && index < nbStudents){
        return students[index];
    }
    return NULL ; 
}

//getter for a course from the array courses
CCourse* CDept::getCourse(int index)
{
    if(index>=0 && index < nbCourses){
        return courses[index];
    }
    return NULL ; 
}

void CDept::createStudents() {
    char* stNames[] = {(char*)"Bill", (char*)"Alex", (char*)"Bob", (char*)"Ana", (char*)"Lilya",
        (char*)"Julie", (char*)"Chris", (char*)"Stef", (char*)"Max", (char*)"Ray"} ;
    int stCodes[]   = {105, 115, 125, 135, 145, 155, 165, 175, 185, 195} ;

    // Let's create 5 students,
    nbStudents= 5 ;
    for(int st= 0; st<nbStudents; st++) students[st] = new CStudent(stNames[st], stCodes[st]) ;
}

void CDept::createCourses() {
    char* crNames[] = {(char*)"CSO", (char*)"OS", (char*)"DB", (char*)"D. Math", (char*)"Software Eng",
        (char*)"logic", (char*)"AI", (char*)"Algo", (char*)"NLP", (char*)"Prog 1"} ;
    int crCodes[]   = {106, 116, 126, 206, 216, 226, 306, 316, 326, 406} ;

    // Let's create 5 courses,
    if(nbCourses==0){
      nbCourses= 5 ;
      for(int cr= 0; cr<nbCourses; cr++) courses[cr] = new CCourse(crNames[cr], crCodes[cr]) ;
    }
}

//enrolls random nos of students in random courses
void CDept::enrollStudentsInCourses()
{
  srand((unsigned int)time(0));
  bool a;
  for(int s=0; s<nbStudents; s++)
  {
    CStudent* st = students[s];
    for(int nbc=0; nbc<rand()%st->maxCourses; nbc++)
    {
      do{
        a = enroll(st, courses[rand()%nbCourses]);
      }while(!a);
    }
  }
}

//gives the students random grades
void CDept::createDefaultGrades()
{
  // Use current time as seed for random generator
    srand((unsigned int)time(0));
    for(int s=0; s<nbStudents; s++){
        
        CStudent* st = students[s];
        for(int c=0; c<st->nbCourses;c++){
            for(int i=0; i<NBEXAMS; i++){
                st->grades[c][i] = rand()%101;
            }
        }
    }
}

//adds a student to the array of students in the department
bool CDept::addStudent(char* n, int c) {
  if(nbStudents<MAXNBST){
    students[nbStudents] = new CStudent(n, c);
    nbStudents++;
    return true;
  }
  return false ;
}

//adds a course to the array of courses in the dept
bool CDept::addCourse(char* n, int c) {
  if(nbCourses<MAXNBCR){
    courses[nbCourses] = new CCourse(n, c);
    nbCourses++;
    return true;
  }
  return false ;
}

//enrolls specified student in specified course
bool CDept::enroll(CStudent* ps, CCourse* pc) {
    // -- do it here --
    if(ps->maxCourses > ps->nbCourses && pc->capacity > pc->nbEnrolled && !ps->alreadyEnrolled(pc))
      {
        ps->enroll(pc);
        pc->enroll(ps);
        return true;
      }
    return false ; //or return false
}

//displays info of all students in the department
void CDept::displayStudents() {

  for(int s=0; s<nbStudents; s++){
    students[s]->displayInfo();
  }
}

//displays info of all courses in the department
void CDept::displayCourses() {
  for(int c=0; c<nbCourses; c++){
    courses[c]->displayInfo();
  }
}

//receives an array of grades which are assigned to the grades 2D array of the student under that course
void CDept::enterStudentGrades(CStudent* ps, CCourse* pc, int* gr) {
    if (ps->alreadyEnrolled(pc)){ //to check if the student is enrolled in soecified course
        int i = ps->getCourseIndex(pc->code);
        for(int g=0; g<NBEXAMS; g++){
            ps->grades[i][g] = gr[g];
        }
    }
}

//displays the specified studet's courses
void CDept::coursesofStudent(CStudent* ps){
    ps->displayCourses();
}

//finds the best student in the specified course
void CDept::bestStudentInCourse(CCourse* pc){
    pc->findBestStudent();
}

//finds best student in the whole department
CStudent* CDept::findBestinDept(){
  float max = 0;
  int ind=-1;
  for(int s=0; s<nbStudents; s++){
    CStudent* st = students[s];
    if (st->nbCourses >= 3){
      float* allgrades = st->calcAverages();
      float total = 0;
      float av = 0;
      for(int g=0; g<st->nbCourses; g++){
        total += allgrades[g];
        av = total/st->nbCourses;
      }
    if(av > max){
      max = av;
      ind = s;
      }
    }
  }
  if(ind>=0){
    return students[ind];}
  return NULL;
}

//getter for private attribute nbCourses
int CDept::getTotalCourses(){
    return nbCourses;
}

//getter for private attribute nbStudents
int CDept::getTotalStudents(){
    return nbStudents;
}
