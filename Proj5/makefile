CXX = g++
CXXFLAGS = -Wall

proj5: PokeDex.o MyPokemon.o Game.o driver.cpp Tstack.h
	$(CXX) $(CXXFLAGS) MyPokemon.o PokeDex.o Game.o Tstack.h driver.cpp -o proj5

Game.o: Game.h Game.cpp PokeDex.o MyPokemon.o Tstack.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

PokeDex.o: PokeDex.cpp PokeDex.h 
	$(CXX) $(CXXFLAGS) -c PokeDex.cpp

MyPokemon.o: MyPokemon.cpp MyPokemon.h
	 $(CXX) $(CXXFLAGS) -c MyPokemon.cpp

clean:
	rm *.o*
	rm *~ 

run:
	./proj5

run1:
	./proj5 proj5_pokeDex.txt proj5_myPokemon.txt
