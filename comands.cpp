/*#include "comands.h"

#include <iostream>
#include <string>
#include <vector>


int comands(int argc, char *argv[], std::string f1, size_t umbral, size_t cantgen, int seed){
    std::vector<int> terminal;
    std::string file;
    for (int i =1;i<argc;i++){
        if( (strcmp(argv[i], "-h")==0)|| (strcmp(argv[i], "--help")==0)){
                std::cout<<"--------------  HELP  ---------------"<<std::endl;
                std::cout<<"|DESCRIPTION.                         |"<<std::endl;
                std::cout<<"|                                     |"<<std::endl;
                std::cout<<"|In this program, a cellular automaton|"<<std::endl;
                std::cout<<"|will be implemented to,starting from |"<<std::endl;
                std::cout<<"|a map loaded with random pokémons,see|"<<std::endl;
                std::cout<<"|if any type wins over the others.    |"<<std::endl; 
                std::cout<<"|                                     |"<<std::endl;   
                std::cout<<"|OPTIONS.                             |"<<std::endl;
                std::cout<<"|                                     |"<<std::endl;
                std::cout<<"|-f o --file cities file name         |"<<std::endl;
                std::cout<<"|-u or --umbral when the variation    |"<<std::endl;
                std::cout<<"|reaches this value then the          |"<<std::endl;
                std::cout<<"|program finish                       |"<<std::endl;
                std::cout<<"|-g or --gen when the amount of       |"<<std::endl;
                std::cout<<"|generations reaches this value then  |"<<std::endl;
                std::cout<<"|the program finish                   |"<<std::endl;
                std::cout<<"|-o or --out 1->for amount of         |"<<std::endl;
                std::cout<<"|iterations and highest fitness,      |"<<std::endl;
                std::cout<<"|2->for amount of iterations and      |"<<std::endl;
                std::cout<<"|fitness average, 3->for amount of    |"<<std::endl;
                std::cout<<"|iterations and minimum fitness value |"<<std::endl;
                std::cout<<"|                                     |"<<std::endl;
                std::cout<<"--------------------------------------"<<std::endl;
        }
        if((strcmp(argv[i], "-f")) || (strcmp(argv[i], "--file"))){
            file = argv[i];
        }
        if((strcmp(argv[i], "-g")) || (strcmp(argv[i], "--gen"))){
            terminal.emplace_back(argv[i]);
        }
        
        if((strcmp(argv[i], "-u")) || (strcmp(argv[i], "--umbral"))){
            terminal.emplace_back(argv[i]);
        }
         if((strcmp(argv[i], "-o")) || (strcmp(argv[i], "--out"))){
            terminal.emplace_back(argv[i]);
        }
    }
    return 0;

}
*/