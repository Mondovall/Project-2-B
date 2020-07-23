// Project 2B | Group 2:  James Ta, Shawn Nitchman, Timothy Hoang.

#include "Node.h"

int main() {
    binaryTree x;

    std::string stringToEncode = "Spaghetti";
    std::string stringToEncode2 = "pneumonoultramicroscopicsilicovolcanoconiosis";
    std::string code = ".___ ._ __ . ... .. ... _ .... . _... . ... _";
    std::string code2 = "... .... ._ .__ _. ._. .._ ._.. . ...";
    std::string code3 = "_ .. __ .. ... _ .... . _... ___ ... ...";

    //  _._. ___ __ .__. .._ _ . ._.
    //  ... _._. .. . _. _._. .

    std::cout << "Techincal requirement 1:\n";
    std::cout << "Display the Binary Tree follow the In Order traversal method" << std::endl;
    std::cout << x.getTree(x.getRoot());
    std::cout << std::endl;

    std::cout << "Technical requirement 2: Encode test." << std::endl;
    x.encodeSearchString(stringToEncode, x.getRoot());
    x.encodeSearchString(stringToEncode2, x.getRoot());

    std::cout << "Technical requirement 3: Decode test." << std::endl;
    x.decodeSearchString(code);
    x.decodeSearchString(code2);
    x.decodeSearchString(code3);

    return 0;
}