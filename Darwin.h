#ifndef Darwin_h
#define Darwin_h
#include <iostream> // istream, ostream
#include <vector>




using namespace std;
class Species{

   private:
        string name;
        vector < vector <int> > move;
	
   public:
	/*This is the basiic constructor for the Species class
	We fix the default constructor by using the trick we loosed in classi
	*/
	//First method
         Species(string x="."){
                name=x;
        }

	/*We add the instructors here. If it is one of the non-action commands then we use the a negative one for the default */
        //Second method
	void addInstruction(int x,int y=-1){
                vector<int> temp;
                temp.push_back(x);
                temp.push_back(y);
                move.push_back(temp);
        }
	/*Returns the name of the species*/
       //Third method
	 string thename(){
                return name;
        }
	/*Returns the instructions that have been placed in the vector. This was created for checking purposes, but it is probably 
	somewhere in the code.*/
	//Fourth method
	string theInstruction(signed int x){
		if(x>=move.size())
			return "That Instruction has not been entered or is unknown.";
		int temp = move[x][0];
		switch(temp){
			case 0:
				return "Hop "+to_string(move[x][1]);
			case 1:
				return "Left "+to_string(move[x][1]);
			case 2:
				return "Right "+to_string(move[x][1]);
			case 3:
				return "Infect "+to_string(move[x][1]);	
			case 4:
				return "If_Empty "+to_string(move[x][1]);
			case 5:
				return "If_Wall "+to_string(move[x][1]);
			case 6:
				return "If_Rand "+to_string(move[x][1]);
			case 7:
				return "If_Enemy "+to_string(move[x][1]);
			case 8:
				return "Go "+to_string(move[x][1]);
			default:
				return "That Instruction has not been entered or is unknown.";

		}
		return "If you are here something horrible has happened!";
	}
	/*Returns the actual instruction. We use numbers to keep track of everything.*/
	//Fifth method
	int instret(int i){
		if(move.empty())
			return -1;		
		return move[i][0];
	}
	/*We return where the instruction jumps*/
	//Sixth method
	int instructjump(int i){
		if(move.empty())
			return -1;
		return move[i][1];

	}
	/*Prints the name*/
	//Seventh method
	void printit(){
		cout<<name;
	}


};

class Creature{

         
   private:
        Species theSpeci;
        int direction;
        int progcout;
	int turn;

   public:

	/*Creature constroctor, we give it a Species if we aren't given a species we use the default species,and the default
	direction is set to the west*/
        //Eighth method
	Creature(Species x=Species(), int y=0){
                theSpeci=x;
                progcout=0;
                direction=y;
		turn=0;
        }
   	/*We change the direction of the Creature*/
	//Ninth method
        bool changeFace(int x){
		if(x==0 || x==1 || x==2 || x==3){
                	direction=x;
                	if(direction==x)
                        	return true;
			else return false;
		}
		else
			return false;
        }
	/*Infects the species with the species given*/
	//Tenth method
        bool infected(Species x=Species()){
                theSpeci=x;
                progcout=0;

                if(theSpeci.thename().compare(x.thename()) == 0 && progcout == 0)
                        return true;
                else
                        return false; 
        }
	/*The direction the creature is facing*/
	//Eleventh method
	string theDirection(){
		switch(direction){
			case 0:
				return "West";
			case 1:
				return "North";
			case 2:
				return "East";
			case 3:
				return "South";
			default:
				return "That is not a direction";
		}
		return "If you are here you have a problem";

	} 
	/*Returns the number of the current prognum*/
	//12th method
	int prognum(){
		return progcout;
	}
	/*Returns the Species*/
	//13th method
	Species whtCreat(){
		return theSpeci;
	} 
	/*Updates the current prognum*/
	//14th method
	void pronum(){
		progcout++;
	}
	/*Updates the prognum, this is used we have to jump to a different command*/
	//15th method
	void updat(int x){
		progcout=x;
	}
	/*What the current turn*/
	//16th method
	int whtrn(){
		return turn;	
	}
	/*Increments the current turn. I am not sure whether turn or progcout are  the same thing.*/
	//17th method
	void incturn(){
		turn++;
	}
	/*Calls the Species print function*/
	//18th method
	void callprint(){
		theSpeci.printit();
	}
};


class World{

      private:
        vector<vector<Creature> > theWorld;
 
   public: 
	/*Sets the world map*/
	//19th method
        World(int height=0, int width=0){
	Species x;
	vector<Creature> temp2(height,Creature(x));
	for(int i=0;i<width;i++){
		theWorld.push_back(temp2);
	}

    }
	//Used this at first but checking the results were difficult, not sure why, don't have time to figure out.
	/*string theMap(){
		int x=theWorld.size();
		int y=theWorld[0].size();
		string map="";
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				map+=theWorld[i][j].whtCreat().thename();
			}
			map+="\n";
		}
		return map;	

	}*/
	/*Used to check the Width*/
	//20th method
	int theSizeW(){
		return theWorld.size();
	}
	/*Used to check the Height*/
	//21th method
	int theSizeH(){
		return theWorld[0].size();
	}
	/*Sets a given Creature on the map, gien coordinates and direction*/
	//22th method
	void setCreat(Creature z,int dir, int x, int y){
		theWorld[x][y].infected(z.whtCreat());
		theWorld[x][y].changeFace(dir);
	}
	/*Get the species name of the give coordinates*/
	//23th method
	string getName(int x, int y){
		return theWorld[x][y].whtCreat().thename();
	}
	/*Get the actual creature at the given coordinates*/
	//24th method
	Creature getCreatu(int x, int y){
		return theWorld[x][y];

	}
	/*Take a turn at the given coordinates*/
	//25th method
	void takeTurn(unsigned int x,unsigned int y){
		//The instruction that is to be performed
		int instruction=theWorld[x][y].whtCreat().instret(theWorld[x][y].prognum());
		//This is where we are suppose to jump to if we are suppose to.
		//int jump=theWorld[x][y].whtCreat().instructjump(theWorld[x][y].prognum());
		if(instruction==0){
			string face=theWorld[x][y].theDirection();
			theWorld[x][y].pronum();
			theWorld[x][y].incturn();
			if(face=="West" && (y>0) && theWorld[x][y-1].whtCreat().thename()=="."){
				theWorld[x][y-1]=theWorld[x][y];
				theWorld[x][y].infected();
			}else if(face=="East" && (y<theWorld[x].size()-1)&& theWorld[x][y+1].whtCreat().thename()=="."){
				theWorld[x][y+1]=theWorld[x][y];
				theWorld[x][y].infected();
			}else if(face=="North" && (x>0)&&theWorld[x-1][y].whtCreat().thename()=="."){
				theWorld[x-1][y]=theWorld[x][y];
				theWorld[x][y].infected();
			}else if(face=="South" && (x<theWorld.size()-1)&&theWorld[x+1][y].whtCreat().thename()=="."){
				theWorld[x+1][y]=theWorld[x][y];
				theWorld[x][y].infected();
			}else{
			}
		}else if(instruction==1){
			string face=theWorld[x][y].theDirection();
			theWorld[x][y].pronum();
			theWorld[x][y].incturn();
			if(face=="West"){
                                theWorld[x][y].changeFace(3);
                        }else if(face=="East"){
                                theWorld[x][y].changeFace(1);
                        }else if(face=="North"){
                                theWorld[x][y].changeFace(0);
                        }else if(face=="South"){
                                theWorld[x][y].changeFace(2);
                        }	
		}else if(instruction==2){
			string face=theWorld[x][y].theDirection();
                        theWorld[x][y].pronum();
			theWorld[x][y].incturn();
                        if(face=="West"){
                                theWorld[x][y].changeFace(1);
                        }else if(face=="East"){
                                theWorld[x][y].changeFace(3);
                        }else if(face=="North"){
                                theWorld[x][y].changeFace(2);
                        }else if(face=="South"){
                                theWorld[x][y].changeFace(0);
                        }    
		}else if(instruction==3){
			string face=theWorld[x][y].theDirection();
                        theWorld[x][y].pronum();
			theWorld[x][y].incturn();
                        if(face=="West" && (y>0)){
                                theWorld[x][y-1].infected(theWorld[x][y].whtCreat());
                        }else if(face=="East"&& (y<theWorld[x].size()-1)){
                                theWorld[x][y+1].infected(theWorld[x][y].whtCreat());
                        }else if(face=="North" && x>0){
                                theWorld[x-1][y].infected(theWorld[x][y].whtCreat());
                        }else if(face=="South" && (x<theWorld.size()-1)){
                                theWorld[x+1][y].infected(theWorld[x][y].whtCreat());
                        }    
		}else if(instruction==4){
			string face=theWorld[x][y].theDirection();
			if(face=="West" && (y>0) && (theWorld[x][y-1].whtCreat().thename()==".")){
				theWorld[x][y].updat(theWorld[x][y].whtCreat().instructjump(theWorld[x][y].prognum()));
                        }else if(face=="East"&& (y<theWorld[x].size()-1) && (theWorld[x][y+1].whtCreat().thename()==".")){
				theWorld[x][y].updat(theWorld[x][y].whtCreat().instructjump(theWorld[x][y].prognum()));
                        }else if(face=="North" && (x>0) && (theWorld[x-1][y].whtCreat().thename()==".")){
				theWorld[x][y].updat(theWorld[x][y].whtCreat().instructjump(theWorld[x][y].prognum()));
                        }else if(face=="South"&& (x<theWorld.size()-1) && (theWorld[x+1][y].whtCreat().thename()==".")){
				 theWorld[x][y].updat(theWorld[x][y].whtCreat().instructjump(theWorld[x][y].prognum()));
                        }else{
				theWorld[x][y].pronum();
			}
				
		}else if(instruction ==5){
			string face = theWorld[x][y].theDirection();
			if(face=="West" && y==0){
				theWorld[x][y].updat(theWorld[x][y].whtCreat().instructjump(theWorld[x][y].prognum()));
			}else if(face=="East" && y==theWorld[x].size()-1){
				theWorld[x][y].updat(theWorld[x][y].whtCreat().instructjump(theWorld[x][y].prognum()));
			}else if(face=="North" && x==0){
				theWorld[x][y].updat(theWorld[x][y].whtCreat().instructjump(theWorld[x][y].prognum()));
			}else if(face=="South" && x==theWorld.size()){
				theWorld[x][y].updat(theWorld[x][y].whtCreat().instructjump(theWorld[x][y].prognum()));
			}else{
				theWorld[x][y].pronum();
			}
		}else if(instruction ==6){
			int i=rand();
			if((i % 2)!=0){
				theWorld[x][y].updat(theWorld[x][y].whtCreat().instructjump(theWorld[x][y].prognum()));
			}else{
				theWorld[x][y].pronum();	
			}
		}else if(instruction == 7){
			string face = theWorld[x][y].theDirection();
		        if(face == "West" && y>0 && theWorld[x][y-1].whtCreat().thename()!="." && theWorld[x][y-1].whtCreat().thename()!=theWorld[x][y].whtCreat().thename()){
				theWorld[x][y].updat(theWorld[x][y].whtCreat().instructjump(theWorld[x][y].prognum()));
                        }else if(face =="East" && y<theWorld[x].size()-1 && theWorld[x][y+1].whtCreat().thename()!="." && theWorld[x][y+1].whtCreat().thename()!=theWorld[x][y].whtCreat().thename()){
				theWorld[x][y].updat(theWorld[x][y].whtCreat().instructjump(theWorld[x][y].prognum()));
                        }else if(face == "North" && x>0 && theWorld[x-1][y].whtCreat().thename()!="." && theWorld[x-1][y].whtCreat().thename()!=theWorld[x][y].whtCreat().thename()){
				theWorld[x][y].updat(theWorld[x][y].whtCreat().instructjump(theWorld[x][y].prognum()));
                        }else if(face == "South" && x<theWorld.size()-1 && theWorld[x+1][y].whtCreat().thename()!="." && theWorld[x+1][y].whtCreat().thename()!=theWorld[x][y].whtCreat().thename()){
				theWorld[x][y].updat(theWorld[x][y].whtCreat().instructjump(theWorld[x][y].prognum()));
                        }else{
				theWorld[x][y].pronum();
				}
		}else if(instruction ==8){
			theWorld[x][y].updat(theWorld[x][y].whtCreat().instructjump(theWorld[x][y].prognum()));
		}else {
			theWorld[x][y].incturn();
		}
	}
};
#endif
