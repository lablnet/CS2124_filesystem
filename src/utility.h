//
// Created by Umer on 6/13/2021.
//

#ifndef ALPHAFILESYSTEM_UTILITY_H
#define ALPHAFILESYSTEM_UTILITY_H

#include <string>
#include <vector>

namespace lablnet {
    std::vector<std::string> split_string(std::string str, char delim = ' ')
    {
        std::vector<std::string> tokens;
        std::string temp;
        for(int i = 0; i < str.length(); i++){
            if (str[i] == delim) {
                tokens.push_back(temp);
                temp = "";
            } else {
                temp.push_back(str[i]);
            }
        }
        tokens.push_back(temp);
        return tokens;
    }

    std::string get_file_name(std::string path)
    {
        std::vector<std::string> tokens = lablnet::split_string(path, '.');
        std::string name = tokens[tokens.size() - 2];
        std::vector<std::string> tokens2 = lablnet::split_string(name, '/');
        return tokens2[tokens.size() - 1];
    }

    std::string get_file_ext(std::string path)
    {
        std::vector<std::string>  tokens = lablnet::split_string(path, '.');
        return tokens[tokens.size() - 1];
    }

    std::string get_path_name(std::string path)
    {
        std::vector<std::string>  tokens = lablnet::split_string(path, '/');
        return tokens[tokens.size() - 1];
    }

    std::string run_command(std::string cmd)
    {
        std::string result;

        // Run the command and get the output
        FILE *pipe = popen(cmd.c_str(), "r");
        if (pipe) {
            char buffer[256];
            while (!std::feof(pipe)) {
                if (fgets(buffer, 256, pipe) != nullptr)
                    result = result + buffer;
            }
            pclose(pipe);
        }
        return result;
    }

    long long int get_size(std::string path) {
        // std::stoll convert std::string into long.
        return std::stoll(lablnet::run_command("du -sb " + path + " | cut -f1"));
    }

    std::string get_last_modified(std::string path) {
        return lablnet::run_command("date -r " + path);
    }
}

#endif //ALPHAFILESYSTEM_UTILITY_H
