# CS2124_filesystem
**CS2124 semester project**

The simulation of the file system aimed to understand the basics of how hash tables of
file systems work. There are many file systems like NTFS, EFI etc. But in this project we
build a (virtual) file system that will be simple enough. C++ will be used as reference
languages.

Online Demo: <a href="https://replit.com/@lablnet/CS2124filesystem#main.cpp" target="_blank">replit/@lablnet/CS2124filesystem</a>

### Installations
Clone this repo
```sh
git clone https://github.com/lablnet/CS2124_filesystem.git
```
This project work with every c++ compilers in Linux and MacOs:
1. Cmake
2. GNU G++
3. Clang

#### Build on GNU G++

```sh
g++ --std=c++17 main.cpp -lstdc++fs && ./a.out
```

#### Build on Clang

```sh 
clang++ --std=c++17 main.cpp -lstdc++fs && ./a.out
```

#### Build on Cmake

Build it
```sh
cmake .
```
```sh
make
```

Run
```sh
./AlphaFileSystem
```

## Goal
- To understand how file systems work underneath the hood.
- Understand Applications of Hash table and other data structure and algorithm.

## Requirements
1. This file system is able to write, read, copy, move, and delete files.
2. This file system allows you to create a folder.
3. The files and folder record should be read and written into the Hash table of the file
   system.
4. Merge the files and folder into one file so to called img file to behave as virtual file
   system (Optional)
5. GUI using QT C++ (Optional)

**There are two requirements options: if time is left and I found time then I will try my best to
   implement those as well.**
   

