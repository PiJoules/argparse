#ifndef ARGPARSE_H_
#define ARGPARSE_H_

#include <string>
#include <map>

namespace argparse {
    class Type {
        
    };

    class Namespace {
        private:
            std::map<std::string, Type> values_;

        public:
            Namespace(){};

            void set(std::string key, std::string val);
    };

    class ArgumentParser {
        private:
            const std::string description_;

        public:
            ArgumentParser(const std::string& description=""):description_(description){}

            void parse_args(const int argc, char**& argv);
    };
};

#endif
