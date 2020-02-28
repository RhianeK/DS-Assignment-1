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
    int *enrolled;
    int nbEnrolled;
    
public:
    // --- add constr, distructor, memory management methods here
    CCourse(char* vname, int vcode) ;
    ~CCourse() ;
 
public:
    // --- add getters and setters here
    
public:
    // --- add othe methods here
    void displayInfo(CCourse c); //should it be a pointer?
    
} ;
#endif
