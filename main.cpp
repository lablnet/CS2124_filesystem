#include <iostream>
#include "./src/Disk/Disk.h"

int main()
{
    unsigned int choice{};
    std::string filename{}, data{};
    std::ofstream file;
    lablnet::Disk disk;
    disk = lablnet::deserialize_object();

    while(true) {
        std::cout << "Choose from the option: " << "\n"
                  << "1). for create new file.\n"
                  << "2). for copy file.\n"
                  << "3). for move file.\n"
                  << "4). for delete file.\n"
                  << "5). for search file.\n"
                  << "6). for print hash table.\n"
                  << "7). for exit."
                  << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter filename you want to create: \n";
                std::cin >> filename;
                file.open("./temp/"+filename+".txt",std::ios::out);
                if(file) {
                    std::cin.ignore();
                    std::cout << "Enter the content you want to write?\n";
                    std::getline (std::cin, data);
                    file << data;
                    file.close();
                    disk.copy("./temp/" + filename + ".txt", "../temp");
                    lablnet::serialize_object(disk);
                }
                break;
            case 2:
                std::cout << "Enter file or directory to copy: \n";
                std::cin >> filename;
                disk.copy(filename, "../temp");
                lablnet::serialize_object(disk);
                filename = {};
                break;
            case 3:
                std::cout << "Enter file or directory to move: \n";
                std::cin >> filename;
                disk.move(filename, "../temp");
                lablnet::serialize_object(disk);
                filename = {};
                break;
            case 4:
                std::cout << "Enter file or directory to delete: \n";
                std::cin >> filename;
                disk.remove(filename);
                lablnet::serialize_object(disk);
                filename = {};
                break;
            case 5:
                std::cout << "Enter file or directory to search: \n";
                std::cin >> filename;
                disk.search(filename);
                filename = {};
                break;
            case 6:
                disk.showTable();
                break;
            case 7:
                exit(0);
            default:
                std::cout << "Please choose valid option\n";
        }
        std::cin.ignore();
    }
    return 0;
}
