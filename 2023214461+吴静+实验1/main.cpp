#include "markdownConverter.h"
#include "fileHandler.cpp"
#include "markdownParser.cpp"
#include "htmlGenerator.cpp"
#include "converter.cpp"
#include <iostream>

using namespace std;

int main() {
    // 创建具体实例
    FileHandler fileHandler;
    MarkdownParser parser;
    HtmlGenerator generator;
    MarkdownConverter converter(fileHandler, parser, generator);
    
    string inputFilename = "test.md";
    string outputFilename = "test.html";
    
    if (converter.convert(inputFilename, outputFilename, false)) { 
        cout << "转换成功！" << endl;
    } else {
        cerr << "转换失败。" << endl;
        return 1;
    }

    return 0;
}
    
