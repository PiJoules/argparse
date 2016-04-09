#include "Argparse.h"

namespace argparse {
    void Namespace::set(const std::string& key, const std::string& val){
        string_values_[key] = val;
    }

    const std::string& Namespace::get(const std::string& key){
        return string_values_[key];
    }

    Namespace ArgumentParser::parse_args(const int argc, char**& argv) const {
        Namespace ns;
        for (int i = 1; i < argc; i++){
            std::string val(argv[i]);
            std::string arg = positional_[i-1];
            ns.set(arg, val);
        }
        return ns;
    }

    Argument& ArgumentParser::add_argument(const std::string& arg){
        Argument argument;
        arguments_[arg] = argument;
        positional_.push_back(arg);
        return arguments_[arg];
    }
}

