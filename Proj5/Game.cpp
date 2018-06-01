#include "Game.h"
#include <time.h>

using namespace std;


//Constructor for Game

Game::Game(string f_pokemon, string f_myPokemon){

  srand(time(NULL));
  m_pokemonFile = f_pokemon;
  m_myPokemonFile = f_myPokemon;
  getPokeDex();
  getMyPokemon();
  mainMenu();

}

//Name: getPokeDex
//Precondition: m_pokemonFile must exist
//Postcondition: populates the pokeDex (pokemon encyclopedia) from a file

void Game::getPokeDex(){
  
  ifstream fin(m_pokemonFile.c_str());
  string num, cpMin, cpMax, rarity;
  string name;

  while(fin >> num){
    fin >> name;
    fin >> cpMin;
    fin >> cpMax;
    fin >> rarity;

    m_pokeDex.push_back(PokeDex(atoi(num.c_str()), name, atoi(cpMin.c_str()), atoi(cpMax.c_str()), atoi(rarity.c_str())));
    }
  
  fin.close();
  
}

//Name: getMyPokemon
//Precondition: m_myPokemonFile  must exist
//Postcondition: populates the MyPokemon (My caught Pokemon) from a file

void Game::getMyPokemon(){

  ifstream mine(m_myPokemonFile.c_str());
  string num, cp, hp, rarity;
  string name;

  while(mine >> num){
    mine >> name;
    mine >> cp;
    mine >> hp;
    mine >> rarity;

    m_myPokemon.push_back(MyPokemon(atoi(num.c_str()), name, atoi(cp.c_str()), atoi(hp.c_str()), atoi(rarity.c_str())));
  }
  mine.close();
}

//Name: printMyPokemon
//Precondition: m_myPokemon must be populated
//Postcondition: prints all pokemon in m_myPokemon

void Game::printMyPokemon(){


  //if m_myPokemon vector is empty output a message
  //else output the pokemon, with it's number,name, combant points,
  //hit points and rarity
  //outputs using ostream overloading operator<< from MyPokemon.h
  if(m_myPokemon.size() == 0){
    cout << "You have not caught any pokemon." << endl;
  }
  else{
    for(unsigned int i = 0; i < m_myPokemon.size(); ++i){
      cout << " " << setw(3) << right << i << ". ";
      m_myPokemon[i] << cout;
    } 
  }
}

//Name: printMyPokeDex
//Precondition: m_myPokeDex must be populated
//Postcondition: prints all pokemon in m_myPokeDex (all 151)

void Game::printPokeDex(){

  //outputs each Pokemon object in proj5_pokeDex.txt
  //outputs using ostream overloading operator<<from Pokedex.h
  for(unsigned int i = 0; i < m_pokeDex.size(); ++i){
    m_pokeDex[i] << cout;
  }

}

// Name: catchPokemon
// Pre-condition: Requires vectors to be populated
// Post-condition: Prompts user for rarity (1-5) user would like to capture
//          Based on rarity (1=65%, 2=45%, 3=25%, 4=10%, 5=1%) tries to find a random
 //          Pokemon based on that rarity.
 //          If a Pokemon is found, calls foundPokemon

void Game::catchPokemon(){

  int rareType;
  
  //do-while loop: while the rarity of the Pokemon is from 1 to 5, 
  //catch pokemon of that rarity choice. Rarity is dependent on a specific
  //percent chance. call foundPokemon() function and if caught output name of
  //the pokemon 
  //else output message when pokemon of that rarity is not found

  do{
    cout << "What type of Pokémon qould you like to try and catch?:" << endl
	 << "1. Very Common (Very High Probability)" << endl
	 << "2. Common (High Probability)" << endl
	 << "3. Uncommon (Normal Probability)" << endl
	 << "4. Rare (Low Probability)" << endl
	 << "5. Ultra rare (Extremely Low Probability)" << endl;
    
    cin >> rareType;

    int randProb = rand() % 100 + 1;

    switch(rareType){
    case 1:
      if(randProb >= 1 && randProb <= 65){
	foundPokemon(rareType);
	cout << "You start to search." << endl
             << "Congrats! You found a " << m_myPokemon[(int)m_myPokemon.size()-1].GetName() << endl;
      }
      else{
	cout << "Sorry couldn't find Pokémon of Rarity 1" << endl;
      }
      break;
    case 2:
      if(randProb >= 1 && randProb <= 45){
	foundPokemon(rareType);
	cout << "You start to search." << endl
             << "Congrats! You found a " << m_myPokemon[(int)m_myPokemon.size()-1].GetName() << endl;
      }
      else{
        cout << "Sorry couldn't find Pokémon of Rarity 2" << endl;
      }
      break;
    case 3:
      if(randProb >= 1 && randProb <= 25){
	foundPokemon(rareType);
	cout << "You start to search." << endl
             << "Congrats! You found a " << m_myPokemon[(int)m_myPokemon.size()-1].GetName() << endl;
      }
      else{
        cout << "Sorry couldn't find Pokémon of Rarity 3" << endl;
      }
      break;
    case 4:
      if(randProb >= 1 && randProb <= 10){
	foundPokemon(rareType);
	cout << "You start to search." << endl
             << "Congrats! You found a " << m_myPokemon[(int)m_myPokemon.size()-1].GetName() << endl;
      }
      else{
        cout << "Sorry couldn't find Pokémon of Rarity 4" << endl;
      }
      break;
    case 5:
      if(randProb == 1){
	foundPokemon(rareType);
	cout << "You start to search." << endl
             << "Congrats! You found a " << m_myPokemon[(int)m_myPokemon.size()-1].GetName() << endl;
      }
      else{
        cout << "Sorry couldn't find Pokémon of Rarity 5" << endl;
      }
      break;
    }
  }while(rareType < 1 || rareType > 5);

}

// Name: foundPokemon ()
// Pre-condition: After a Pokemon is found, rarity is passed to this function
// Post-condition: Using rarity, the pokeDex is randomly searched for
//                 a matching rarity
//                 After an appropriate Pokemon is found
//                 Adds new Pokemon to user's m_myPokemon

void Game::foundPokemon(int rarity){

  //Put Pokemon of a specific rarity (1-5) in a vector of integers
  //if the rarity of the pokemon inputted matches (1-5) push that pokemon in
  //the vector rarePokemon

  vector<int> rarePokemon;
  for(unsigned int i = 0; i < m_pokeDex.size(); i++){
    if(m_pokeDex[i].GetRarity() == rarity){
      rarePokemon.push_back(i);
    }
  }

  srand(time(NULL));


  //find pokemon randomly depending on their rarity

  int randIndex = rand() % rarePokemon.size();

  //Create new PokeDex object that puts Pokemon based on rarity in object
  //get random combat points of that pokemon by randomizing combat points of that
  //pokemon between its original combat min & combat max ponts
  //Hit points of that Pokemon is 10% of the randomly calculated combat points
  
  //push the pokemon found into m_myPokemon vector
  PokeDex selectPokemon = m_pokeDex[rarePokemon[randIndex]];
  int randCPMin = selectPokemon.GetCPMin();
  int randCPMax = selectPokemon.GetCPMax();
  int randCP = rand() % (randCPMax - 1) + (randCPMin + 1);
  int calcHP = .10 * randCP;
  m_myPokemon.push_back(MyPokemon(selectPokemon.GetNum(), selectPokemon.GetName(), randCP, calcHP, selectPokemon.GetRarity()));

}


// Name: mainMenu
// Pre-condition: None
// Post-condition: Calls a variety of functions based on user

void Game::mainMenu(){
  
  int choice;
  
  do{
    cout << "What would you like to do?:" << endl
	 << "1. See the PokeDex" << endl
	 << "2. See your collection" << endl
	 << "3. Search for a new Pokemon" << endl
	 << "4. Battle Your Pokemon" << endl
	 << "5. Train your Pokemon" << endl
	 << "6. Exit" << endl;
    
    cin >> choice;

    switch(choice){
    case 1:
      printPokeDex();
      break;
    case 2:
      printMyPokemon();
      break;
    case 3:
      catchPokemon();
      break;
    case 4:
      battlePokemon();
      break;
    case 5:
      trainPokemon();
      break;
    case 6:
      exitPokemon();
      break;
    }

  }while(choice != 6);

}

// Name: battlePokemon
// Pre-condition: Allows user to choose 5 pokemon to send to arena from myPokemon
//                Adds user chosen pokemon to the user's Tstack
//                Has the computer randomly add 5 pokemon to send to arena
//                from pokeDex. Has to convert to myPokemon format
// Post-condition: Winner continues to next round. Compare CP. Tstack pops.
//                 Winner is the one who still has Pokemon left at end.

void Game::battlePokemon(){

  //Create 2 Stack objects: one for user & other for computer
  Tstack<MyPokemon, NUM_ARENA> compStack, userStack;
   
  string myFive = "";
  unsigned int myChoice;
 
  srand(time(NULL));
  
  PokeDex newPoke;

  vector<MyPokemon> myChosenOnes =  m_myPokemon;

  //if there is no pokemon caught or pokemon caught are fewer than 5
  //ouutput message
  //else put 5 random enemy Pokemon to battle in compStack Stack.

  if(myChosenOnes.size() == 0 || myChosenOnes.size() < 5){
  cout << "Sorry you cannot battle with no or fewer than 5 pokemon" << endl;
  }
  else{

    for(int i = 0; i < NUM_ARENA; i++){
      int enemyRand = rand() % m_pokeDex.size();
      int enemyCPMin = m_pokeDex[enemyRand].GetCPMin();
      int enemyCPMax = m_pokeDex[enemyRand].GetCPMax();
      int randCP = rand() % (enemyCPMax - 1) + (enemyCPMin + 1);
      int calcHP = .10 * randCP;
    
      newPoke = PokeDex(m_pokeDex[enemyRand].GetNum(), m_pokeDex[enemyRand].GetName(), enemyCPMin, enemyCPMax, m_pokeDex[enemyRand].GetRarity());
    
      MyPokemon ePoke = MyPokemon(newPoke.GetNum(), newPoke.GetName(), randCP, calcHP, newPoke.GetRarity());
    
      compStack.push(ePoke);
    
    }
  
    //do-while loop: while Pokemon in stack are less than max of Stack keep
    //asking user for POkemon to put in stack until stack is full
    
    do{
    
      for(unsigned int i = 0; i < myChosenOnes.size(); ++i){
	cout << " " << setw(3) << right << i << ". ";
	myChosenOnes[i] << cout;
      } 
      cout << "Which of your Pokémon would you like to use?:" << endl;
      cin >> myChoice;
      
      while(myChoice < 0 || myChoice >= myChosenOnes.size()){

	for(unsigned int i = 0; i < myChosenOnes.size(); ++i){
	  cout << " " << setw(3) << right << i << ". ";
	  myChosenOnes[i] << cout;
	}
	cout << "Which of your Pokémon would you like to use?:" << endl;
	cin >> myChoice;
      }

      myFive += myChosenOnes[myChoice].GetName() + ", ";
    
      userStack.push(myChosenOnes[myChoice]);

      myChosenOnes.erase(myChosenOnes.begin() + myChoice);

      
    }while(userStack.getSize() < NUM_ARENA);
    
    //output name of pokemon selected and put into userStack

    cout << myFive << endl;
    int numFights = 1;

    //while userStack & compStack are not empty keep fighting to the next round
    //with Pokemon from Stack
    //Battle is won by who has higher CP than the other
    //if user Pokemon wins the battle, output user won round of the fight
    //else user Pokemon lost the battle, output user lost round of the fight

    while(!userStack.isEmpty() && !compStack.isEmpty()){
    
      MyPokemon userPoke = userStack.peek();
      MyPokemon compPoke = compStack.peek();
      cout << "You are going to fight a " << compPoke.GetName() << endl  
	   << "The enemy has a CP of " << compPoke.GetCP() << endl
	   << "Fight " << numFights << endl
	   << userPoke.GetName() << " vs. " << compPoke.GetName() << endl
	   << userPoke.GetCP() << " vs. " << compPoke.GetCP() << endl;
      if(userPoke.GetCP() > compPoke.GetCP()){
	cout << "You won the Fight " << numFights << endl;
	compStack.pop();
      }
      else{
	cout << "You lost the Fight " << numFights << endl;
	userStack.pop();
      } 
      numFights++;
    }
    
    //if computer stack has no more pokemon ,User wins the arena battle
    //else, User lost the arena battle

    if(compStack.isEmpty()){
      cout << "You won the arena!" << endl;
    }
    else{
      cout << "You lost the arena!" << endl;
    }
  }
}

// Name: saveMyPokemon
// Pre-condition: Uses m_myPokemon
// Post-condition: Saves a file with each Pokemon with number, name, CP, HP, rarity

void Game::trainPokemon(){

  unsigned int trainChoice;

  //If the m_myPokemon vector is empty, output message
  //else, Ask user which pokemon he wants to train
  //call Train() function and updates that Pokemon's combat point
  //output new CP of that Pokemon

  if(m_myPokemon.size() == 0){
    cout << "There are no Pokemon to train" << endl;
  }
  else{
    do{
      cout << "Which of your pokemon would you like to use?:" << endl;
      for(unsigned int i = 0; i < m_myPokemon.size(); i++){
	cout << setw(3) << right << i << ". ";
	m_myPokemon[i] << cout;
      }
     
      cin >> trainChoice;
    }while(trainChoice < 0 || trainChoice >= m_myPokemon.size());

    m_myPokemon[trainChoice].Train();

    cout << "Your " << m_myPokemon[trainChoice].GetName() << " trained." << endl
	 << "Your CP is now " << m_myPokemon[trainChoice].GetCP() << endl; 
  }
}


// Name: saveMyPokemon
// Pre-condition: Uses m_myPokemon
// Post-condition: Saves a file with each Pokemon with number, name, CP, HP, rarity


void Game::saveMyPokemon(){

  ofstream saveFile;

  saveFile.open("proj5_myPokemon.txt");
  
  for(unsigned int i = 0; i < m_myPokemon.size(); ++i){
    saveFile << " " << setw(8) << left << m_myPokemon[i].GetNum() << setw(12) << left << m_myPokemon[i].GetName() << setw(8) << left << m_myPokemon[i].GetCP() << setw(8) << left << m_myPokemon[i].GetHP() << m_myPokemon[i].GetRarity() << endl;
  }
  saveFile.close();
}

// Name: exitPokemon
// Pre-condition: From main menu, user selects 6
// Post-condition: Calls saveMyPokemon and exits application

void Game::exitPokemon(){

  saveMyPokemon();
  cout << "File Saved" << endl
       << "Thank you for playing Pokémon UMBC" << endl;

}

