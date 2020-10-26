#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cerr << "Use: showfile filename" << std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);

    if(!file)
    {
        std::cerr << "An error occurred when opening the file "
             << argv[1] << std::endl;
        return 2;
    }

    char line[80];
    int  cnt = 0;
    while(file.getline(line, 80))
    {
        std::cout << line << std::endl;
        if(++cnt == 20)
        {
            cnt = 0;
            std::cout << "\n\t ---- <return> to continue ---- " << std::endl;
            std::cin.sync(); std::cin.get();
        }
    }
    if(!file.eof())
    {
        std::cerr << "Error reading the file "
             << argv[1] << std::endl;
        return 3;
    }

    return 0;
}
