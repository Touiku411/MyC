#include <iostream>
#include <cstring>
#include <fstream>
using namespace::std;

// reads in a C++ program from a cpp file, and put it to the array program
void load(char(*program)[256], int& numLines);

// deletes the comment beginning with "//" from sourceLine if any
void delComment(char sourceLine[]);

// deletes all string constants from sourceLine
void delStrConsts(char sourceLine[]);

// deletes all character constants from sourceLine
void delCharConsts(char sourceLine[]);

// extracts all identifiers from sourceLine, and put them into the array identifiers
void extractIdentifiers(char sourceLine[], char identifiers[][32], int& numIdentifiers);

// stores all non-keyword strings in the array identifiers into a text file
void store(char (*identifiers)[32], int numIdentifiers);

// returns true if and only if str is a C++ keyword
bool keyword(char str[]);

// returns true if and only if identifiers[ pos ] belongs to identifiers[ 0 .. pos-1 ]
bool duplicate(char (*identifiers)[32], int pos);

const char keywords[][20] = { "auto", "break", "case", "char", "const",
                                "continue", "default", "define","do", "double",
                                "else", "enum", "extern", "float", "for",
                                "goto", "if", "int", "long", "register",
                                "return", "short", "signed", "sizeof",
                                "static", "struct", "switch", "typedef",
                                "union", "unsigned", "void", "volatile",
                                "while", "bool", "catch", "class",
                                "const_cast", "delete", "dynamic_cast",
                                "explicit", "false", "friend", "inline",
                                "mutable", "namespace", "new", "operator",
                                "private", "protected", "public",
                                "reinterpret_cast", "static_cast", "template",
                                "this", "throw", "true", "try", "typeid",
                                "typename", "using", "virtual", "include" };

void print(char (*program)[256], int numLines) {
    for (size_t i = 0; i < numLines; ++i) {
        for (size_t j = 0; j < strlen(program[i]); ++j) {
            cout << program[i][j];
        }
        cout << endl;
    }
}
void print2(char (*program)[32], int numLines) {
    for (size_t i = 0; i < numLines; ++i) {
        for (size_t j = 0; j < strlen(program[i]); ++j) {
            cout << program[i][j];
        }
        cout << endl;
    }
}
int main()
{
    char (*program)[256] = new char[500][256];
    int numLines = 0;

    // reads in a C++ program from a cpp file, and put it to the array program
    load(program, numLines);
    //print(program, numLines);
    char (*identifiers)[32] = new char[500][32];
    int numIdentifiers = 0;

    for (int i = 0; i < numLines; i++)
    {
        delComment(program[i]); // deletes the comment beginning with "//" from program[ i ]
        delStrConsts(program[i]); // deletes all string constants from program[ i ]
        delCharConsts(program[i]); // deletes all character constants from program[ i ]

        if (strcmp(program[i], "") != 0)
            extractIdentifiers(program[i], identifiers, numIdentifiers);
        // extracts all identifiers from program[ i ], and put them into the array identifiers
    }
    print(program, numLines);
    print2(identifiers, numIdentifiers);
    // stores all non-keyword strings in the array identifiers into a text file
    store(identifiers, numIdentifiers);
    delete[] program;
    delete[] identifiers;

}
void load(char(*program)[256], int& numLines)
{
    ifstream inFile("test4.cpp", ios::in);
    if (!inFile.is_open()) {
        cout << "File could not be opened\n";
        //system("pause");
        return;
    }
    while (inFile.getline(program[numLines], 256)) {
        numLines++;
    }
    inFile.close();
}

void delComment(char sourceLine[])
{
    size_t length = strlen(sourceLine);
    if (length > 1)
        for (size_t i = 0; i < length - 1; i++)
            if (sourceLine[i] == '/' && sourceLine[i + 1] == '/')
            {
                sourceLine[i] = '\0';
                return;
            }
}

void delStrConsts(char sourceLine[])
{
    size_t length = strlen(sourceLine);
    bool findfirst = false;
    bool findsecond = false;
    size_t pos1;
    size_t pos2;
    if (length > 1) {
        for (size_t i = 0; i < length; ++i) {
            if (sourceLine[i] == '"' && sourceLine[i - 1] == '\'' && sourceLine[i + 1] == '\'') {
                continue;
            }
            if (findfirst && sourceLine[i] == '\\') {
                i++;
                continue;
            }
            if (!findfirst) {
                if (sourceLine[i] == '"') {
                    findfirst = true;
                    pos1 = i;
                    continue;
                }
            }
            if (sourceLine[i] == '"') {
                findsecond = true;
                pos2 = i;
            }
            if (findfirst && findsecond) {
                for (size_t k = pos1; k <= pos2; ++k) {
                    sourceLine[k] = ' ';
                }
                findfirst = false;
                findsecond = false;
            }
        }
    }
}

void delCharConsts(char sourceLine[])
{
    size_t length = strlen(sourceLine);
    bool findfirst = false;
    bool findsecond = false;
    size_t pos1;
    size_t pos2;
    if (length > 1) {
        for (size_t i = 0; i < length; ++i) {
            if (findfirst && sourceLine[i] == '\\') {
                i++;
                continue;
            }
            if (!findfirst) {
                if (sourceLine[i] == '\'') {
                    findfirst = true;
                    pos1 = i;
                    continue;
                }
            }
            if (sourceLine[i] == '\'') {
                findsecond = true;
                pos2 = i;
            }
            if (findfirst && findsecond) {
                for (size_t k = pos1; k <= pos2; ++k) {
                    sourceLine[k] = ' ';
                }
                findfirst = false;
                findsecond = false;
            }
        }
    }
}

void extractIdentifiers(char sourceLine[], char identifiers[][32], int& numIdentifiers)
{
    size_t length = strlen(sourceLine);
    string str;
    for (size_t i = 0; i < length; ++i) {
        if (isalnum(sourceLine[i]) || sourceLine[i] == '_') {
            str += sourceLine[i];
        }
        else {
            if (!str.empty()) {
                for (size_t k = 0; k < str.length(); ++k) {
                    identifiers[numIdentifiers][k] = str[k];
                }
                identifiers[numIdentifiers][str.length()] = '\0';
                numIdentifiers++;
                str.clear();
            }
        }
    }
    if (!str.empty()) {
        for (size_t k = 0; k < str.length(); ++k) {
            identifiers[numIdentifiers][k] = str[k];
        }
        identifiers[numIdentifiers][str.length()] = '\0';
        numIdentifiers++;
        str.clear();
    }
}
//把非關鍵字的輸出到identifiers.txt
void store(char (*identifiers)[32], int numIdentifiers)
{
    ofstream outFile("identifiers.txt", ios::out);
    if (outFile.fail()) {
        cout << "存檔失敗\n";
        /*   system("pause");*/
        return;
    }
    for (size_t i = 0; i < numIdentifiers; ++i) {
        if (!keyword(identifiers[i]) && !duplicate(identifiers, i) && !isdigit(identifiers[i][0])) {
            outFile << identifiers[i] << endl;
        }
    }
    outFile.close();
}

bool keyword(char str[])
{
    size_t numKeywords = sizeof(keywords) / 20;
    for (size_t i = 0; i < numKeywords; i++)
        if (strcmp(keywords[i], str) == 0)
            return true;

    return false;
}

bool duplicate(char (*identifiers)[32], int pos)
{
    for (int i = 0; i < pos; i++)
        if (strcmp(identifiers[i], identifiers[pos]) == 0)
            return true;

    return false;
}
