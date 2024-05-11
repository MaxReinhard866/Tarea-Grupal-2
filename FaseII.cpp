#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


map<string, string> dictionary = {
    {"int", "entero"},
    {"float", "flotante"},
    {"double", "doble"},
    {"string", "cadena"},
    {"cout", "cout"},
    {"cin", "cin"},
    {"if", "si"},
    {"else", "sino"},
    {"for", "para"},
    {"while", "mientras"},
    {"return", "retorno"}
  
};


string translateLine(const string& line) {
    stringstream ss(line);
    stringstream translatedLine;
    string word;

    while (ss >> word) {
       
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());

       
        auto it = dictionary.find(word);
        if (it != dictionary.end()) {
            translatedLine << it->second << " ";
        } else {
            translatedLine << word << " ";
        }
    }

    return translatedLine.str();
}

int main() {
    cout << "Ingrese el código C++ a traducir (presione Ctrl+D para finalizar la entrada):" << endl;
    
  
    stringstream cppCodeStream;
    string line;
    while (getline(cin, line)) {
        cppCodeStream << line << endl;
    }
    string cppCode = cppCodeStream.str();

   
    stringstream translatedCodeStream;
    stringstream codeStream(cppCode);
    while (getline(codeStream, line)) {
        string translatedLine = translateLine(line);
        translatedCodeStream << translatedLine << endl;
    }

   
    cout << "Código traducido:" << endl;
    cout << translatedCodeStream.str();

    return 0;
}
