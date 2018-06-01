CXX = g++
CXXFLAGS = -Wall

proj4: Chair.o Sofa.o Pillow.o Furniture.o Catalog.o driver.cpp
	$(CXX) $(CXXFLAGS) Chair.o Sofa.o Pillow.o Furniture.o Catalog.o driver.cpp -o proj4

Catalog.o: Chair.o Sofa.o Pillow.o Furniture.o Catalog.h Catalog.cpp
	$(CXX) $(CXXFLAGS) -c Catalog.cpp

Chair.o: Chair.cpp Chair.h Pillow.o Furniture.o
	$(CXX) $(CXXFLAGS) -c Chair.cpp

Sofa.o: Sofa.cpp Sofa.h Pillow.o Furniture.o
	$(CXX) $(CXXFLAGS) -c Sofa.cpp

Pillow.o: Pillow.cpp Pillow.h
	$(CXX) $(CXXFLAGS) -c Pillow.cpp

Furniture.o: Furniture.cpp Furniture.h
	$(CXX) $(CXXFLAGS) -c Furniture.cpp

clean:
	rm *.o*
	rm *~ 

run:
	./proj4

run1:
	./proj4 proj4_data1.txt

run2:
	./proj4 proj4_data2.txt

run3:
	./proj4 proj4_data3.txt

val1:
	valgrind ./proj4 proj4_data1.txt

val2:
	valgrind ./proj4 proj4_data2.txt

val3:
	valgrind ./proj4 proj4_data3.txt