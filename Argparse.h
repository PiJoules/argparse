#ifndef ARGPARSE_H_
#define ARGPARSE_H_

#include <string>
#include <map>
#include <vector>

namespace argparse {
    class Namespace {
        private:
            std::map<std::string, std::string> string_values_;

        public:
            Namespace(){};

            void set(const std::string& key, const std::string& val);
            const std::string& get(const std::string& key);
            friend std::ostream& operator<<(std::ostream& out, const Namespace& ns);
    };

    class Argument {
        public:
            Argument(){}
    };

    class ArgumentParser {
        private:
            const std::string description_;
            std::map<std::string, Argument> arguments_;  // Positional args
            std::vector<std::string> positional_;  // Positional arg flags
            std::map<std::string, Argument> optional_;  // Optional args

        public:
            ArgumentParser(const std::string& description=""):description_(description){}

            Namespace parse_args(const int argc, char**& argv) const;
            Argument& add_argument(const std::string& arg);
    };
};

#endif
