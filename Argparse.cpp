#include "Argparse.h"
#include <stdlib.h>
#include <iostream>

namespace argparse {
    /**
     * Namespace
     */
    void Namespace::set(const std::string& key, const std::string& val){
        string_values_[key] = val;
    }

    const std::string& Namespace::get(const std::string& key){
        return string_values_[key];
    }

    std::ostream& operator<<(std::ostream& out, const Namespace& ns){
        out << "{" << std::endl;
        for (auto& pair : ns.string_values_){
            out << "\t" << pair.first << ": " << pair.second << std::endl;
        }
        out << "}" << std::endl;
        return out;
    }


    /**
     * Argumentparser
     */
    Namespace ArgumentParser::parse_args(const int argc, char**& argv) const {
        Namespace ns;

        bool prev_was_opt_flag = false;  // If previous arg was an optional flag
        std::string opt_arg_flag;

        for (int i = 1; i < argc; i++){
            std::string val(argv[i]);

            // Check if argument starts with --
            if (val.find("--") == 0 && !prev_was_opt_flag){
                // Optional arg flag
                std::string optional_arg = val.substr(2);
                
                // Check if this optional_arg exists
                if (optional_.find(optional_arg) == optional_.end()){
                    std::cerr << "Unknown optional argument '" << val << "'." << std::endl;
                    exit(EXIT_FAILURE);
                }

                // Indicate the next argument will be the actual optional arg
                prev_was_opt_flag = true;
                opt_arg_flag = optional_arg;
            }
            else if (prev_was_opt_flag){
                ns.set(opt_arg_flag, val);

                // Reset flag
                prev_was_opt_flag = false;
            }
            else {
                // Positional arg
                std::string arg = positional_[i-1];
                ns.set(arg, val);
            }
        }
        return ns;
    }

    Argument& ArgumentParser::add_argument(const std::string& arg){
        Argument argument;

        // Check if argument starts with --
        if (arg.find("--") == 0){
            // Adding optional arg
            std::string trimmed_arg = arg.substr(2);
            optional_[trimmed_arg] = argument;
            return optional_[trimmed_arg];
        }
        else {
            // Adding positional arg
            arguments_[arg] = argument;
            positional_.push_back(arg);
            return arguments_[arg];
        }
    }
}

