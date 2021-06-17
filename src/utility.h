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

    std::string get_file_ext(std::string path)
    {
        std::string tokens = lablnet::split_string(path, '.');
        return tokens[tokens.size() - 1];
    }

    std::string get_path_name(std::string path)
    {
        std::string tokens = lablnet::split_string(path, '/');
        return tokens[tokens.size() - 1];
    }

    long long int get_size(std::string path)
    {
        long long result = -1;

        // Command to get size.
        std::string cmd = "du -sb " + path + " | cut -f1";

        // Run the command and get the output
        FILE *pipe = popen(cmd.c_str(), "r");
        if (pipe) {
            char buffer[256];
            while (!std::feof(pipe)) {
                if (fgets(buffer, 256, pipe) != nullptr)
                    result = result + std::atoll(buffer);
            }
            pclose(pipe);
        }
        return result;
    }
}

#endif //ALPHAFILESYSTEM_UTILITY_H
