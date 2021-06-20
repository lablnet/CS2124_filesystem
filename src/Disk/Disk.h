//
// Created by Umer on 6/11/2021.
//

#ifndef ALPHAFILESYSTEM_DISK_H
#define ALPHAFILESYSTEM_DISK_H

#include "../utility.h"
#include "../HashTable/HashTable.cpp"
#include <filesystem>
#include <string>

namespace lablnet {

    class FileMeta {
    public:
        lablnet::FileType type = lablnet::NONE;
        std::string name;
        std::string last_mod;
        long long size; // in bytes.
        std::string mime;
        std::string extension;


    };

    class Disk {
    private:
        HashTable<std::string, FileMeta> table;
        struct stat s;
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
