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


};

class Creature{

         
   private:
        Species theSpeci;
        int direction;
        int progcout;

   public:
        Creature(){
                direction=0;
                progcout=0;
                theSpeci=Species();

        }

        Creature(Species x){
                theSpeci=x;
                progcout=0;
                direction=0;
        }
   
        bool changeFace(int x){
                direction=x;
                if(direction==x)
                        return true;
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
