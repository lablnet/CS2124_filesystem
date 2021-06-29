//
// Created by Umer on 6/13/2021.
//

#ifndef ALPHAFILESYSTEM_UTILITY_H
#define ALPHAFILESYSTEM_UTILITY_H

#include <sys/stat.h>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>


namespace lablnet {

    enum FileType {
        FOLDER, _FILE, NONE
    };


    FileType get_type(std::string path)
    {
        struct stat s;
        if (stat(path.c_str(), &s) == 0)
        {
            if (s.st_mode & S_IFDIR) return FOLDER;
            else if (s.st_mode & S_IFREG) return _FILE;
        }
        return NONE;
    }

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
        return tokens2[tokens.size() - 2];
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

    std::string trim(std::string str)
    {
        std::string::iterator end_pos = std::remove(str.begin(), str.end(), '\n');
        str.erase(end_pos, str.end());
        return str;

    }
    std::string get_last_modified(std::string path) {
        std::string last_mod = lablnet::run_command("date -r " + path);
        return lablnet::trim(last_mod);
    }

    std::string bytes_to_human_readable(long long int bytes)
    {
        std::vector<std::string> suffix = {"B", "KB", "MB", "GB", "TB", "PB"};
        int i = 0;
        double d_btyes = bytes;
        if (bytes > 1024) {
            for (i = 0; (bytes / 1024) > 0 && i<suffix.size()-1; i++, bytes /= 1024)
                d_btyes = bytes / 1024.0;
        }

        d_btyes = std::ceil(d_btyes * 100.0) / 100.0;
        return std::to_string(d_btyes) + " " + suffix[i];
    }
}

#endif //ALPHAFILESYSTEM_UTILITY_H
