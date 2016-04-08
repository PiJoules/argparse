#include "Argparse.h"

using namespace argparse;


int main(int argc, char* argv[]){
    ArgumentParser parser;

    parser.add_argument("first");

    Namespace args = parser.parse_args(argc, argv);

    return 0;
}

