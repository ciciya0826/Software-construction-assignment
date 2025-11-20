#include "markdownConverter.h"
#include <string>

using namespace std;

class MarkdownParser : public IMarkdownParser {
public:
    string parseLine(const string& markdownLine) override {
        if (markdownLine.empty()) {
            return "";
        }

        if (markdownLine.substr(0, 4) == "### ") {
            return "<h3>" + markdownLine.substr(4) + "</h3>";
        }
        if (markdownLine.substr(0, 3) == "## ") {
            return "<h2>" + markdownLine.substr(3) + "</h2>";
        }
        if (markdownLine.substr(0, 2) == "# ") {
            return "<h1>" + markdownLine.substr(2) + "</h1>";
        }

        string result = processFormatting(markdownLine);
        result = processLineBreaks(result);
        
        return "<p>" + result + "</p>";
    }

private:
    string processFormatting(const string& line) {
        string result = line;
        
        //¼Ó´Ö
        int start = 0;
        while ((start = (int)result.find("**", start)) != -1) {
            int end = (int)result.find("**", start + 2);
            if (end == -1) break;

            result.replace(end, 2, "</strong>");
            result.replace(start, 2, "<strong>");
            
            start = end + 9;
        }

        //Ð±Ìå
        start = 0;
        while ((start = (int)result.find("*", start)) != -1) {
            bool inStrong = false;
            for (int i = 0; i < start; i++) {
                if (i + 8 <= result.size() && result.substr(i, 8) == "<strong>") {
                    inStrong = true;
                }
                if (i + 9 <= result.size() && result.substr(i, 9) == "</strong>") {
                    inStrong = false;
                }
            }
            
            if (inStrong) {
                start++;
                continue;
            }
            
            int end = (int)result.find("*", start + 1);
            if (end == -1) break;
            
            result.replace(end, 1, "</em>");
            result.replace(start, 1, "<em>");
            
            start = end + 5;
        }

        return result;
    }

    //»»ÐÐ
    string processLineBreaks(const string& line) {
        string result = line;
        if (result.length() >= 2) {
            int last = result.length() - 1;
            int secondLast = result.length() - 2;
            if (result[secondLast] == ' ' && result[last] == ' ') {
                result = result.substr(0, secondLast) + "<br>";
            }
        }
        return result;
    }
};
    
