#include <iostream>
#include <fstream>
#include <filesystem>
int main(){
    std::string path = "test.txt";
    std::ifstream test_file(path);

    if (std::filesysten::exists(path) && test_file.is_open()){
        std::cout << "works" << std::endl;

    }
    else {
        std::cout << "NOT " << std::endl;
    }
    return 0;
}
