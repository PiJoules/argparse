#include "Argparse.h"
#include <cassert>
#include <iostream>

using namespace argparse;


int main(int argc, char* argv[]){
    ArgumentParser parser;

    parser.add_argument("first");

    Namespace args = parser.parse_args(argc, argv);
    std::cout << args.get("first") << std::endl;
    assert(args.get("first") == "arg1");

    return 0;
}

