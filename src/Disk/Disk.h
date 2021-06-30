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
    public:
            HashTable<std::string, lablnet::FileMeta> table;
            std::vector<std::string> paths;

        void copy(const std::string& from, const std::string& to = "./temp/") {
            lablnet::FileType type = lablnet::get_type(from);
            if (type != lablnet::NONE) {
                // std::filesystem::copy(from, to);
                std::string filename;

                if (type == FOLDER)
                    filename = lablnet::get_path_name(from);
                else
                    filename = lablnet::get_file_name(from);

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

               this->paths.push_back(from);
               this->table.insert(filename, *meta);

               return;
            }
            std::cout << "\nUnable to copy, no such file or directory\n";
        }

        void move(const std::string& from, const std::string& to = "./temp/") {
            this->copy(from , to);
        }

        void remove(std::string path) {
            lablnet::FileType type = lablnet::get_type(path);
            if (type != lablnet::NONE) {
                std::string filename;

                if (type == FOLDER)
                    filename = lablnet::get_path_name(path);
                else
                    filename = lablnet::get_file_name(path);
                this->table.erase(filename);
                this->paths.erase(std::remove(paths.begin(), paths.end(), path), paths.end());
            }
        }

        void search(std::string path) {
            lablnet::FileType type = lablnet::get_type(path);
            if (type != lablnet::NONE) {
                std::string filename;

                if (type == FOLDER)
                    filename = lablnet::get_path_name(path);
                else
                    filename = lablnet::get_file_name(path);

                int hash = this->table.getHash(filename);
                if (hash != -1) {
                    auto temp = this->table.table[hash];
                    std::string type;
                    if (temp.value.type == lablnet::_FILE)
                        type = "FILE";
                    else
                        type = "DIR";
                    VariadicTable<int, std::string, std::string, std::string, std::string, std::string, std::string> vt({"hash", "filename", "size", "last_mod", "mime", "extension", "type"});
                    vt.addRow(temp.hash, temp.value.name, lablnet::bytes_to_human_readable(temp.value.size), temp.value.last_mod, temp.value.mime, temp.value.extension, type);
                    vt.print(std::cout);
                    std::cout << std::endl;
                    return;
                }
            }
            std::cout << "\nSorry, no such file or directory!\n";
        }

        void showTable() const
        {
            int size = this->table.capacity;
            VariadicTable<int, std::string, std::string, std::string, std::string, std::string, std::string> vt({"hash", "filename", "size", "last_mod", "mime", "extension", "type"});

            for (int i = 0; i < size; i++) {
                if (this->table.table[i].hash != -1) {
                    auto temp = this->table.table[i].value;
                    std::string type;
                    if (temp.type == lablnet::_FILE)
                        type = "FILE";
                    else
                        type = "DIR";

                    vt.addRow(this->table.table[i].hash, temp.name,
                              lablnet::bytes_to_human_readable(temp.size),
                              temp.last_mod, temp.mime, temp.extension, type);
                }
            }

            vt.print(std::cout);
            std::cout << std::endl;
        }

        void getInfo() {
            // todo
        }
    };

    void serialize_object(Disk d){
        std::filesystem::remove("./data.txt");
        std::ofstream file;
        file.open("./data.txt",std::ios::out);
        if(file && !d.paths.empty()) {
            std::string data;
            for (int i = 0; i < d.paths.size(); i++) {
                data = data + d.paths[i] + "\n";
            }
            file << data;
            file.close();
        }
    }

    Disk deserialize_object(){
        Disk d;
        std::ifstream file;
        file.open("./data.txt", std::ios::in);
        if(file) {
            std::string data;
            while (std::getline (file, data)) {
                d.copy(data, data);
            }
            file.close();
        }
        return d;
    }
}

#endif //ALPHAFILESYSTEM_DISK_H
