#include "Argparse.h"
#include <cassert>
#include <iostream>

using namespace argparse;
using namespace std;


int main(int argc, char* argv[]){
    ArgumentParser parser;

    parser.add_argument("first");
    parser.add_argument("--opt1");
    parser.add_argument("-o", "--opt2");

    Namespace args = parser.parse_args(argc, argv);

    // Assertions
    assert(args.get("first") == "arg1");
    assert(args.get("opt1") == "opt1_arg");
    assert(args.get("opt2") == "opt2_arg");

    return 0;
}

