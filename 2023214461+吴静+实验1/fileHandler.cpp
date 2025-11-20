#include "markdownConverter.h"
#include <fstream>
#include <iostream>

using namespace std;

class FileHandler : public IFileHandler {
public:
    vector<string> readLines(const string& filename) override {
        ifstream inputFile(filename);
        vector<string> lines;

        if (!inputFile.is_open()) {
            cerr << "错误，无法打开输入文件: " << filename << endl;
            return lines;
        }

        string currentLine;
        while (getline(inputFile, currentLine)) {
            lines.push_back(currentLine);
        }

        inputFile.close();
        return lines;
    }

    bool writeToFile(const string& filename, const string& content) override {
        ofstream outputFile(filename);

        if (!outputFile.is_open()) {
            cerr << "错误，无法打开输出文件: " << filename << endl;
            return false;
        }

        outputFile << content;
        outputFile.close();
        return true;
    }

    void printToConsole(const string& content) override {
        cout << content << endl;
    }

    string getDirectory(const string& filename) override {
        size_t pos = filename.find_last_of("/\\");
        if (pos == string::npos) {
            return ".";  // 当前目录
        }
        return filename.substr(0, pos);
    }
};
    
