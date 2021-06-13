//
// Created by Umer on 6/11/2021.
//

#ifndef ALPHAFILESYSTEM_DISK_H
#define ALPHAFILESYSTEM_DISK_H

#include "../HashTable/HashTable.cpp"
#include <filesystem>
#include <string>

namespace lablnet {
    enum FileType {
        FOLDER, FILE
    };

    class FileMeta {
    public:
        FileType type;
        std::string name;
        std::string last_mod;
        long long size; // in bytes.

    };

    class Disk {
    private:
        HashTable<std::string, FileMeta> table;
    public:
        void copy(std::string from, std::string to) {
            std::filesystem::copy(from, to);
            // get file/folder name and size.
            // and other meta too.
        }

        void move() {
            // todo
        }

        void remove() {
            // todo
        }

        void getInfo() {
            // todo
        }

        void showTable() {
            // todo
        }
    };
}

#endif //ALPHAFILESYSTEM_DISK_H
