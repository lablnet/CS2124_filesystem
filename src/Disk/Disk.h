//
// Created by Umer on 6/11/2021.
//

#ifndef ALPHAFILESYSTEM_DISK_H
#define ALPHAFILESYSTEM_DISK_H

#include "../utility.h"
#include "../HashTable/HashTable.cpp"
#include "../Mime/Mime.h"
#include <filesystem>
#include <string>

namespace lablnet {

    class FileMeta {
    public:
        lablnet::FileType type = lablnet::NONE;
        std::string name;
        std::string last_mod;
        long long int size; // in bytes.
        std::string mime;
        std::string extension;
    };

    class Disk {
    private:
        HashTable<std::string, lablnet::FileMeta> table;
    public:

        void copy(std::string from, std::string to) {
            lablnet::FileType type = lablnet::get_type(from);
            if (type != lablnet::NONE) {
                // std::filesystem::copy(from, to);
                std::string filename = lablnet::get_path_name(from);
                long long int size = lablnet::get_size(from);
                std::string ext = lablnet::get_file_ext(from);
                std::string last_mod = lablnet::get_last_modified(from);
                auto *meta = new lablnet::FileMeta();
                meta->size = size;
                meta->type = type;
                meta->name = filename;
                meta->last_mod = last_mod;
                if (type == lablnet::_FILE) {
                    meta->extension = lablnet::get_file_ext(from);
                    meta->mime = MimeTypes::get(meta->extension);
                }
               this->table.insert(filename, *meta);
            }
        }

        void move() {
            // todo
        }

        void remove(std::string path) {
            lablnet::FileType type = lablnet::get_type(path);
            if (type != lablnet::NONE) {
                std::string filename = lablnet::get_file_name(path);
                this->table.erase(filename);
            }
        }

        void printDiskTable()
        {

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
