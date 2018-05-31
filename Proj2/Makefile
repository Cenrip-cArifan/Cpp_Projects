CXX = g++
CXXFLAGS = -Wall -g

proj2: Room.o Character.o Monster.o driver.cpp driver.h
	$(CXX) $(CXXFLAGS) Room.o Character.o Monster.o driver.cpp driver.h -o proj2

Character.o: Character.cpp Character.h
	$(CXX) $(CXXFLAGS) -c Character.cpp

Monster.o: Monster.cpp Monster.h
	 $(CXX) $(CXXFLAGS) -c Monster.cpp

Room.o: Room.cpp Room.h
	$(CXX) $(CXXFLAGS) -c Room.cpp

clean:
	rm *.o*
	rm *~ 

#Rules to test your projects
run1:
	./proj2 map1_data.txt

run2:
	./proj2 map2_data.txt

run3:
	./proj2 map3_data.txt
