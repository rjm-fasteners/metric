// AutomatiseBaseFormat.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
using namespace std;
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

ifstream read;
fstream temp;

void formatFromAcomba() {
    if (read.is_open()) {
        std::string line;
        while (getline(read, line)) {
            if ((!line.find("Vis Mauricie inc.;;;;;;;;;;")))
            {
                temp << "";
                getline(read, line);
                getline(read, line);
                getline(read, line);
                getline(read, line);
                getline(read, line);
            }
            else if (!line.empty()) {
                if (!line.find(";;;;;;7"))
                    temp << "";
                else if (!line.find(";;;;;;;;;;"))
                    temp << "";
                else if (!line.find(";;;;;;;;Page 1 de 1;;"))
                    temp << "";
                else
                    temp << line;
            }
        }
        if (read.eof())
        {
            read.seekg(EOF);
            temp.unget();

        }
        cout << "Formatting DONE. You can close the console. Formatted file is in temp.csv" << endl;
    }
    else {
        std::cerr << "Error: coudn't open file\n";
    }
}

void formatFromMcMaster() {
    if (read.is_open()) {
        char ch = '1';
        char ich = '1';
        while (read.get(ch)) {
            if (ch == ' ') {
                ich = read.get();
                /* CONDITION SI TROUVE class... */
                if (ich == 'c') {
                    ich = read.get();
                    if (ich == 'l') {
                        ich = read.get();
                        if (ich == 'a') {
                            ich = read.get();
                            if (ich == 's') {
                                ich = read.get();
                                if (ich == 's') {
                                    while (ich != '>') {
                                        ich = read.get();
                                        if (ich == '>') read.unget();
                                    }
                                }
                                else {
                                    read.unget();
                                }
                            }
                            else {
                                read.unget();
                            }
                        }
                        else {
                            read.unget();
                        }
                    }
                    else {
                        read.unget();
                    }
                }

                /* CONDITION SI TROUVE data-mce... */
                else if (ich == 'd') {
                    ich = read.get();
                    if (ich == 'a') {
                        ich = read.get();
                        if (ich == 't') {
                            ich = read.get();
                            if (ich == 'a') {
                                ich = read.get();
                                if (ich == '-') {
                                    ich = read.get();
                                    if (ich == 'm') {
                                        while (ich != '>') {
                                            ich = read.get();
                                            if (ich == '>') read.unget();
                                        }
                                    }
                                    else {
                                        read.unget();
                                    }
                                }
                                else {
                                    read.unget();
                                }
                            }
                            else {
                                read.unget();
                            }
                        }
                        else {
                            read.unget();
                        }
                    }
                }
                else {
                    read.unget();
                }
            }
            else {
                temp << ch;
            }
            
            if (ch == ' ') {
                temp << ch;
            }
        }
        if (read.eof())
        {
            read.seekg(EOF);
            temp.unget();

        }
        cout << "Formatting DONE. You can close the console. Formatted file is in temp.csv" << endl;
    }
    else {
        std::cerr << "Error: coudn't open file\n";
    }
}

string newline = "";
void deleteCrap(string &line, size_t position) {
    newline = "";
    size_t pos2 = line.find('>');
    newline += line.substr(0, position - 1);
    newline += line.substr(pos2, line.length());
    line = newline;
    temp << newline << endl;
}

void formatTester() {
    if (read.is_open()) {
        string line = "";
        string delete_class = "class";
        string delete_data_mce = "data-mce";
        size_t pos_class = 0;
        size_t pos_data_mce = 0;
        while (getline(read, line)) {
            pos_class = line.find(delete_class);
            pos_data_mce = line.find(delete_data_mce);
            while (pos_class != std::string::npos || pos_data_mce != std::string::npos) {
                if (pos_class != std::string::npos) {
                    deleteCrap(line, pos_class);
                    /* size_t is_clean = newline.find(delete_class);
                     if (is_clean != std::string::npos) {
                         pos2 = line.find('>', pos2+1);
                         newline2 += newline.substr(0, is_clean - 1);
                         int a = newline.length();
                         newline2 += newline.substr(pos2, 59);
                         temp << newline2 << endl;
                     }
                     else {
                         is_clean = newline.find(delete_data_mce);
                         if (is_clean != std::string::npos) {
                             temp << "FOUND SECOND EHHEHEHEHE" << endl;
                         }
                     } */
                }
                else if (pos_data_mce != std::string::npos) {
                    deleteCrap(line, pos_data_mce);
                }
                else {
                    temp << line << endl;
                }
                pos_class = newline.find(delete_class);
                pos_data_mce = newline.find(delete_data_mce);
            }

            /*
            pos_class = newline.find(delete_class);
            pos_data_mce = newline.find(delete_data_mce);
            if (pos_data_mce != std::string::npos) {
                deleteCrap(line, pos_data_mce);
            }*/
        }
        if (read.eof())
        {
            read.seekg(EOF);
            temp.unget();

        }
        cout << "Formatting DONE. You can close the console. Formatted file is in temp.csv" << endl;
    }
    else {
        cerr << "Error: coudn't open file\n";
    }
}

int main()
{
    setlocale(LC_ALL, "");

    #pragma region Clearing the file
    ofstream ofs;
    ofs.open("temp.csv", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    #pragma endregion

    read.open("Format de base.csv");
    temp.open("temp.csv");

    int choix = 0;

    do {
        cout << "1) Formatter les donnees d'AcombaX \n2) Formatter les donnees de McMaster \n3) TEST ONLY PURPOSES" << endl;
        cout << "Votre choix : ";
        cin >> choix;
    } while (choix < 1 || choix > 3);

    cout << endl << "Loading..." << endl << endl;

    if (choix == 1) {
        formatFromAcomba();
    }
    else if (choix == 2) {
        formatFromMcMaster();
    }
    else if (choix == 3) {
        formatTester();
    }

    read.close();
    temp.close();
}

