output:	main.o CDept.o CCourse.o CStudent.o
	g++ main.o CDept.o CCourse.o CStudent.o -o output
main.o: main.cpp CDept.hpp CCourse.hpp CStudent.hpp
	g++ -c main.cpp
CDept.o: CDept.cpp CDept.hpp
	g++ -c CDept.cpp
CCourse.o: CCourse.cpp CCourse.hpp
	g++ -c CCourse.cpp
CStudent.o: CStudent.cpp CStudent.hpp
	g++ -c CStudent.cpp
clean:
	rm *.o output