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
         Species(string x=" "){
                name=x;
        }

        void addInstruction(int x,int y){
                vector<int> temp;
                temp.push_back(x);
                temp.push_back(y);
                move.push_back(temp);
        }

        string thename(){
                return name;
        }
	
	string theInstruction(int x){
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


};

class Creature{

         
   private:
        Species theSpeci;
        int direction;
        int progcout;

   public:

        Creature(Species x=Species(), int y=0){
                theSpeci=x;
                progcout=0;
                direction=y;
        }
   
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

        bool infected(Species x){
                theSpeci=x;
                progcout=0;

                if(theSpeci.thename().compare(x.thename()) == 0 && progcout == 0)
                        return true;
                else
                        return false; 
        }

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

	int prognum(){
		return progcout;
	}

	Species whtCreat(){
		return theSpeci;
	} 
};


class World{

      private:
        vector<vector<Creature> > theWorld;
        
   public:      
        World(int height, int width){
        vector<Creature> temp2 (width,Creature());
//      theWorld(height);       
//
        vector<vector<Creature> > theWorld(height,temp2);
    }

};
#endif
