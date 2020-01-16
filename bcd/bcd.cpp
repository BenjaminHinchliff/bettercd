// bcd.cpp : Defines the entry point for the application.
//

#include <string>
#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

int main(int argc, const char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Invalid arguments: must include path" << '\n';
        return 1;
    }
    std::string target{ argv[1] };
    try {
        fs::current_path(target);
    }
    catch (const fs::filesystem_error&) {
        std::cout << "Exact file not found... looking for matches..." << '\n';
        std::vector<fs::path> matches{};
        for (const auto& file : fs::directory_iterator("."))
        {
            if (file.is_directory() && file.path().filename().string().find(target) != std::string::npos)
            {
                matches.push_back(file.path());
            }
        }
        std::cout << "matches:" << '\n';
        for (int i = 0; i < matches.size(); ++i) {
            std::cout << i + 1 << ") " << matches[i].filename().string() << '\n';
        }
        // get user input with invalid input handling
        int selection = 0;
        while (!selection)
        {
            std::cout << "Enter the number of your selection: ";
            int num;
            std::cin >> num;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cout << "Invalid input" << '\n';
            }
            else if (0 < num && num <= matches.size())
            {
                selection = num;
            }
            else
            {
                std::cout << "Number out of range" << '\n';
            }
            std::cin.ignore(32767, '\n');
        }
        fs::current_path(matches[selection - 1i64]);
    }
    return 0;
}
