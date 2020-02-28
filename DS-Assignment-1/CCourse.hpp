#ifndef CCourse_hpp
#define CCourse_hpp

#include <stdio.h>
class CStudent ;

class CCourse {
private:
    // --- add attributes here
  	char* name;
    int code;
    int capacity;
    CStudent** enrolled;
    int nbEnrolled;
  	friend class CStudent;

public:
    // --- add constr, distructor, memory management methods here
    CCourse(char* vname, int vcode) ;
    ~CCourse() ;
public:
    // --- add getters and setters here
    void enroll(CStudent* s);
  	void displayStudents();
		void displayInfo();
  	CStudent* getStudent(int ind);
  	void findBestStudent();
public:
    // --- add othe methods here
    float* calcAverages();
} ;
#endif
