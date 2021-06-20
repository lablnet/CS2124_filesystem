#include <iostream>
#include "./src/Disk/Disk.h"

int main() {
    lablnet::Disk disk;
    //disk = lablnet::deserialize_object();
    disk.copy("./src", "./temp/src");
    disk.printDiskTable();

    //  lablnet::serialize_object(disk);
    std::cout << "Hello, AlphaFileSystem!" << std::endl;
    return 0;
}
