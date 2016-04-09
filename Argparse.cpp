#include "Argparse.h"

namespace argparse {
    void Namespace::set(const std::string& key, const std::string& val){
        string_values_[key] = val;
    }

    std::string Namespace::get(const std::string& key){
        return string_values_[key];
    }

    Namespace ArgumentParser::parse_args(const int argc, char**& argv) const {
        return Namespace();
    }

    Argument& ArgumentParser::add_argument(const std::string& arg){
        Argument argument;
        arguments_[arg] = argument;
        return arguments_[arg];
    }
}

