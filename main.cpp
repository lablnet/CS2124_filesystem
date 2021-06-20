#include <iostream>
#include "./src/Disk/Disk.h"

int main() {
    lablnet::Disk disk;
    disk.copy("./src", "./temp/src");


    std::cout << "Hello, AlphaFileSystem!" << std::endl;
    return 0;
}
