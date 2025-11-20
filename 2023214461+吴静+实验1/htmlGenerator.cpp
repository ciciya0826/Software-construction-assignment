#include "markdownConverter.h"
#include <vector>
#include <string>

using namespace std;

class HtmlGenerator : public IHtmlGenerator {
public:
    string generateFullHtml(const vector<string>& parsedLines) override {
        string fullContent = "<!DOCTYPE html>\n<html>\n<head>\n";
        fullContent += "<meta charset=\"UTF-8\">\n";
        fullContent += "<title>Markdown Result</title>\n";
        fullContent += "</head>\n<body>\n";
        
        for (const string& line : parsedLines) {
            if (!line.empty()) {
                fullContent += line + "\n";
            }
        }
        
        fullContent += "</body>\n</html>";
        return fullContent;
    }
};
    
