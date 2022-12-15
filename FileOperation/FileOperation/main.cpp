#include <fstream>
#include <iostream>
#include <filesystem>
#include <Windows.h>

namespace fs = std::filesystem;
typedef fs::filesystem_error error;

bool _delete(const fs::path& src) {
    try {
        if (fs::exists(src)) {
            for (const auto& entry :
                fs::directory_iterator(src)) {
                if (fs::is_directory(entry)) // folder read-only
                    _delete(entry.path());
                else
                    _deleteFile(entry.path());
            }
            fs::remove(src);
            return true;
        }
    }
    catch (const error& ex) {
        std::cout << ex.what() << std::endl;
        return false;
    }
}

bool _deleteFile(const fs::path& src) {
    try {
        if (fs::exists(src)) {
            if 
            }
        fs::remove_all(src);
        return true;
    }
    catch (const error& ex) {
        std::cout << ex.what() << std::endl;
        return false;
    }
}

bool _copy(fs::path& src, fs::path& dest) {
    try {
        if (fs::exists(dest)) {
            std::cout << "Folder already exists.   \n           \
                        Overwrite:          press 0\n           \
                        Overwrite for all:  press 1\n           \
                        Rename:             press 2\n           \
                        Cancel:             press 3\n           ";
            size_t choice{ 0 };
            switch (choice) {
            case 0:
                fs::copy(src, dest, fs::copy_options::overwrite_existing);
                break;
            case 1:
                fs::copy(src, dest, fs::copy_options::overwrite_existing |
                    fs::copy_options::recursive |
                    fs::copy_options::skip_existing);
                break;
            case 2:
            {char newName[40]{};
            while (newName == "") {
                std::cout << "Enter new name: ";
                std::cin >> newName;
            }}
                break;
            case 3: break;
            default: break;
            }
        }
        else fs::copy(src, dest);
        return true;
    }
    catch (const error& ex) {
        std::cout << ex.what() << std::endl;
        return false;
    }
}

bool _copyFile(fs::path& src, fs::path& dest) {
    try {
        if (fs::exists(dest)) {
            std::cout << "File already exists.   \n           \
                        Overwrite:              press 0\n           \
                        Overwrite for all:      press 1\n           \
                        Rename:                 press 2\n           \
                        Cancel:                 press 3\n           ";
            size_t choice{ 0 };
            switch (choice) {
            case 0:
                fs::copy(src, dest, fs::copy_options::overwrite_existing);
                break;
            case 1:
               // fs::copy(src, dest, fs::copy_options::overwrite_existing | ///////////////// make static variable as a flag "DELETE ALL?"
               // fs::copy_options::recursive |
               // fs::copy_options::skip_existing);
                break;
            case 2:
            {char newName[40]{};
            while (newName == "") {
                std::cout << "Enter new name: ";
                std::cin >> newName;
            }}
                break;
            case 3: break;
            default: break;
            }
        }
        else fs::copy_file(src, dest);
        return true;
    }
    catch (const error& ex) {
        std::cout << ex.what() << std::endl;
        return false;
    }
}

//bool _move(fs::path& src, fs::path& dest) {
//    if (_copy(src, dest))
//        return _delete(src);
//        return false;
//}

//bool _moveFile(fs::path& src, fs::path& dest) {
//    if (_copyFile(src, dest))
//        return _delete(src);
//    return false;
//}

bool _readOnly (fs::path &src)
{
    auto perms(fs::status(src).permissions());
    if (((perms & fs::perms::owner_write) == fs::perms::none)    ||
        ((perms & fs::perms::group_write) == fs::perms::none)    ||
        ((perms & fs::perms::others_write) == fs::perms::none))
        return false;
    return true;
}

int main()
{
    setlocale(LC_ALL, "Ru");
 /*   fs::path src = "C:\\Users\\user8\\source\\repos\\TOP-Academy\\FileOperation\\FileOperation\\Testfolder\\1\\1_2\\1_2_1.txt";
    fs::path dest = "C:\\Users\\user8\\source\\repos\\TOP-Academy\\FileOperation\\FileOperation\\Testfolder\\3\\3_1\\1_2_1.txt";
    demo_perms(fs::status(src).permissions()); */
    
    //_move(src, dest);
    
}