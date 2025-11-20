#ifndef MARKDOWN_CONVERTER_H
#define MARKDOWN_CONVERTER_H

#include <vector>
#include <string>

using namespace std;

// 文件处理接口
class IFileHandler {
public:
    virtual ~IFileHandler() = default;
    virtual vector<string> readLines(const string& filename) = 0;
    virtual bool writeToFile(const string& filename, const string& content) = 0;
    virtual void printToConsole(const string& content) = 0;
    virtual string getDirectory(const string& filename) = 0;
};

// Markdown解析接口
class IMarkdownParser {
public:
    virtual ~IMarkdownParser() = default;
    virtual string parseLine(const string& markdownLine) = 0;
};

// HTML生成接口
class IHtmlGenerator {
public:
    virtual ~IHtmlGenerator() = default;
    virtual string generateFullHtml(const vector<string>& parsedLines) = 0;
};

// 转换器类
class MarkdownConverter {
private:
    IFileHandler& fileHandler;
    IMarkdownParser& parser;
    IHtmlGenerator& generator;

public:
    MarkdownConverter(IFileHandler& fh, IMarkdownParser& p, IHtmlGenerator& g)
        : fileHandler(fh), parser(p), generator(g) {}

    bool convert(const string& inputFile, const string& outputFile, bool printToConsole = false);
};

#endif // MARKDOWN_CONVERTER_H
    
