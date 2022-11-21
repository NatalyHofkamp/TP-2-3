#include "../include/Reader.h"

std::vector<City *> reader::readCsv(std::string nameCsv)
 {
    std::string nombreArchivo = nameCsv;
    std::ifstream archivo(nombreArchivo.c_str());
    std::string line;
    std::vector<City*> cities;
    while (getline(archivo, line)) {
        std::vector<std::string> words;
        if (line[0]=='#'){
            continue;
        }
        int len= line.size();
        std::string newWord;
        int counter=0;
        for(const auto & letter:line){
            if(letter!=',' && letter!='-' && letter!=' ' && counter<len-1){
                newWord+=letter;
                counter++;
            }
            else{
                counter++;
                if(counter== len){
                    newWord+=line[len-1];
                }
                words.emplace_back(newWord);
                newWord="";
            }
        }
        cities.emplace_back(new City(stod(words[1]),stod(words[2])));
    }
    return cities;
}
