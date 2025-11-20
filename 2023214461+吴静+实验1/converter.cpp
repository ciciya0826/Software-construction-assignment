#include "markdownConverter.h"
#include <iostream>

using namespace std;

bool MarkdownConverter::convert(const string& inputFile, const string& outputFile, bool printToConsole) {
    // 读取文件
    cout << "输入文件: " << inputFile << endl;
    vector<string> markdownLines = fileHandler.readLines(inputFile);
    if (markdownLines.empty()) {
        cerr << "没有读取到任何内容或文件不存在" << endl;
        return false;
    }

    // 解析内容
    cout << "正在转换内容..." << endl;
    vector<string> parsedLines;
    for (const string& line : markdownLines) {
        string parsedLine = parser.parseLine(line);
        if (!parsedLine.empty()) {
            parsedLines.push_back(parsedLine);
        }
    }

    string htmlContent = generator.generateFullHtml(parsedLines);

    // 输出处理
    string outputPath = outputFile;
    string outputDir = fileHandler.getDirectory(inputFile);
    if (outputDir != ".") {
        outputPath = outputDir + "/" + outputFile;
    }
    cout << "输出文件: " << outputPath << endl;

    // 写入文件
    cout << "正在写入文件..." << endl;
    bool writeSuccess = fileHandler.writeToFile(outputPath, htmlContent);

    if (printToConsole) {
        fileHandler.printToConsole(htmlContent);
    }

    return writeSuccess;
}
    
