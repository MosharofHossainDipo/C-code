#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    const string dataTypes[] = {"int", "float", "double", "char", "bool", "void"};

    const string keywords[] = {"if", "else", "for", "while", "do", "switch", "case", "default","return", "break", "continue" };

    int dataTypeCount = sizeof(dataTypes) / sizeof(dataTypes[0]);
    int keywordCount = sizeof(keywords) / sizeof(keywords[0]);

    ifstream file("example.cpp");
    if (!file.is_open()) {
        cerr << "Error: Could not open file 'example.cpp'" << endl;
        return 1;
    }

    int totalKeywordCount = 0, totalDataTypeCount = 0;
    string word;

    while (file >> word) {
        for (int i = 0; i < dataTypeCount; i++) {
            if (word == dataTypes[i]) {
                totalDataTypeCount++;
                break;
            }
        }

        for (int i = 0; i < keywordCount; i++) {
            if (word == keywords[i]) {
                totalKeywordCount++;
                break;
            }
        }
    }

    file.close();
    cout << "Total keywords: " << totalKeywordCount << endl;
    cout << "Total data types: " << totalDataTypeCount << endl;

    return 0;
}
