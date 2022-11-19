#include "reader.h"

std::vector<City *> reader::readCsv(std::string nameCsv)
 {
    std::string nombreArchivo = nameCsv;
    std::ifstream archivo(nombreArchivo.c_str());
    std::string line;
    std::vector<City*> cities;
    while (getline(archivo, line)) {/*recorre cada linea del texto*/
        std::vector<std::string> words;
        if (line[0]=='#'){
            continue;
        }
        int len= line.size();
        std::string newWord;
        int counter=0;
        for(const auto & letter:line){/*recorre cada letra por oración */
            if(letter!=',' && letter!='-' && letter!=' ' && counter<len-1){
                newWord+=letter;
                counter++;
            }
            else{
                counter++;
                if(counter== len){
                    newWord+=line[len-1];
                }
                words.emplace_back(newWord);/* cargamos las palabras por oración*/
                newWord="";
            }
        }
        cities.emplace_back(new City(stod(words[1]),stod(words[2])));
    }
    return cities;
}

  
/*
int main(int argc,char** argv)
{
    int counter;
    if(argc!=4)
        std::cout<<"No."<<std::endl;
    else
    {
        double variation;// umbral de variacion
        int genAmount;//cant de generaciones
        genAmount= std::stoi(argv[2]);
        variation= std::stod(argv[1]);
        readCsv(argv[0]);

    }
    return 0;
}
*/