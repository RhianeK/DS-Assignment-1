#ifndef CStudent_hpp
#define CStudent_hpp
#include <string>
#include <stdio.h>

class CCourse;

 class CStudent {
 private:
     // --- add attributes here
 	char* name;
 	int id;
 	int maxCourses;
 	CCourse** courses; //array of pointers to the courses the student has chosen
 	int nbCourses;
 	int** grades; //double pointer to dynamic 2D array. courses have NBEXAMS exams. so NBEXAMS cols and maxCourses rows
 	friend class CCourse;
  friend class CDept;

 public: //Memory management methods
     // --- constr, desctructor add Memory management methods here
     CStudent(char* vname, int vid) ;
     ~CStudent() ;

 public:
     // --- add getters and setters here
 	void enroll(CCourse *c);
 	void displayCourses();
  void displayInfo();
 public:
     // --- add grades methods here
 	void setExamGrade(int ci, int ei, int score);
  void setCourseGrades(int ci, int* scores);
 public:
     // --- add other methods here
	float* calcAverages();
  int getCourseIndex(int icode);
  bool alreadyEnrolled(CCourse* pc);



} ;

#endif
