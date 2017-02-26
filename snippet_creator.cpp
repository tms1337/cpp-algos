#include <iostream>
#include <string>
#include <regex>

using namespace std;

#define QUOTATION_SIGN "\""

int main() {
    string text = "";

    while(!cin.eof()) {
        string line;
        getline(cin, line);
        // line = regex_replace( line, regex(QUOTATION_SIGN), string("\\\"") );

        text += QUOTATION_SIGN;
        text += line;
        text += QUOTATION_SIGN;
        text += "\n";
    }

    cout << endl << endl;
    cout << text << endl;

    return 0;
}