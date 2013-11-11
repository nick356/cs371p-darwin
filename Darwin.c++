 
#include <cassert> // assert
#include <cstdlib> // rand, srand
#include <iostream> // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include <vector>
#include "Darwin.h"



using namespace std;


class Darwin{

   private:	
	int turn;
	World map;	
   public:
	Darwin(int turns, World themap){
		turn=turns;
		map=themap;
	}

	void runGame(){
		int tempturn=0;
		while(tempturn<=9 && tempturn<turn){
			cout<<"Turn = "<<tempturn<<"."<<endl;
			cout<<"  ";

			for(int i=0;i<map.theSizeW();i++){
				for(int j=0;j<map.theSizeH();j++){
					while(map.getCreatu(i,j).whtrn()<tempturn){
						
						map.takeTurn(i,j);
					}

				}

			}
			for(int i=0;i<map.theSizeH();i++)
				cout<<i;

			cout<<endl;
	
			for(int i=0;i<map.theSizeW();i++){
				cout<<i<<" ";
				for(int j=0;j<map.theSizeH();j++){
					map.getCreatu(i,j).callprint();
				}
				cout<<endl;
			}
			cout<<endl;
			tempturn++;
		}
		while(tempturn>=10 && tempturn<turn){
			if(tempturn%100==0){
				cout<<"Turn = "<<tempturn<<"."<<endl;
                        	cout<<"  ";
			}
			
			for(int i=0;i<map.theSizeW();i++){
                                for(int j=0;j<map.theSizeH();j++){
                                        while(map.getCreatu(i,j).whtrn()<tempturn && map.getCreatu(i,j).whtCreat().thename()!="."){		
						map.takeTurn(i,j);
                                        }

                                }

                        }
			
			if(tempturn%100==0){
	                        for(int i=0;i<map.theSizeH();i++)
        	                        cout<<i;

				cout<<endl;
                        	for(int i=0;i<map.theSizeW();i++){
                                	cout<<i<<" ";
                                	for(int j=0;j<map.theSizeH();j++){
                                        	map.getCreatu(i,j).callprint();
                                	}
                                	cout<<endl;
                        	}
                        	cout<<endl;
			}
			tempturn++;
		}
	}
};
