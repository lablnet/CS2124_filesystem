//
// Created by Umer on 6/13/2021.
//

#ifndef ALPHAFILESYSTEM_UTILITY_H
#define ALPHAFILESYSTEM_UTILITY_H

namespace lablnet {
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
