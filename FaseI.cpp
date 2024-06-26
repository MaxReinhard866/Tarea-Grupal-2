#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;
struct WordInfo {
    string translation;
    string functionality;
};


map<string, WordInfo> predefinedWords = {
    {"asm", {"ensamblador", "Instrucción para insertar lenguaje ensamblador en C++"}},
    {"auto", {"auto", "Tipo de variable deducido automáticamente por el compilador"}},
    {"bool", {"bool", "Tipo de dato booleano (verdadero o falso)"}},
    {"break", {"romper", "Instrucción para salir de un bucle"}},
    {"case", {"caso", "Etiqueta para un caso en una declaración switch"}},
    {"catch", {"capturar", "Bloque para manejar excepciones"}},
    {"char", {"caracter", "Tipo de dato para un solo carácter"}},
   
};


void addWordToFile(const string& word, const string& translation, const string& functionality) {
    ofstream outFile("words.txt", ios::app);
    if (!outFile.is_open()) {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return;
    }
    outFile << word << "," << translation << "," << functionality << endl;
    outFile.close();
    cout << "Palabra agregada correctamente." << endl;
}


void listWordsFromFile() {
    ifstream inFile("words.txt");
    if (!inFile.is_open()) {
        cout << "No hay palabras almacenadas." << endl;
        return;
    }
    cout << "Listado de palabras:" << endl;
    string line;
    while (getline(inFile, line)) {
        size_t pos1 = line.find(",");
        size_t pos2 = line.rfind(",");
        string word = line.substr(0, pos1);
        string translation = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string functionality = line.substr(pos2 + 1);
        cout << "Palabra: " << word << ", Traducción: " << translation << ", Funcionalidad: " << functionality << endl;
    }
    inFile.close();
}


void addPredefinedWordsToFile() {
    ofstream outFile("words.txt", ios::app);
    if (!outFile.is_open()) {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return;
    }
    for (const auto& entry : predefinedWords) {
        outFile << entry.first << "," << entry.second.translation << "," << entry.second.functionality << endl;
    }
    outFile.close();
    cout << "Palabras predefinidas agregadas al archivo." << endl;
}

int main() {
    
    addPredefinedWordsToFile();

    int choice;
    string word, translation, functionality;

    while (true) {
        cout << "Seleccione una opción:" << endl;
        cout << "1. Agregar palabra" << endl;
        cout << "2. Listar palabras" << endl;
        cout << "3. Salir" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Ingrese la palabra: ";
                cin >> word;
                cout << "Ingrese la traducción: ";
                cin >> translation;
                cout << "Ingrese la funcionalidad: ";
                cin.ignore();
                getline(cin, functionality);
                addWordToFile(word, translation, functionality);
                break;
            case 2:
                listWordsFromFile();
                break;
            case 3:
                cout << "Saliendo del programa." << endl;
                return 0;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    }

    return 0;
}
