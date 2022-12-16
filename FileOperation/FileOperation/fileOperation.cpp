#include "fileOperation.h"

bool FileOperation::deleteAllWithoutAsking_ = false;

bool FileOperation::_delete(const fs::path& src) {
    try {
        if (!FileOperation::deleteAllWithoutAsking_) {
            for (const auto& entry :
                fs::directory_iterator(src)) {
                std::cout << "Path-->" << entry.path() << std::endl;
                if (fs::is_regular_file(entry)) {
                    if (FileOperation::_readOnly(entry)) {
                        switch (FileOperation::_whatToDoIfSrcIsReadOnly(entry)) {
                        case 1:
                            fs::remove(entry);
                            break;
                        case 2:
                            fs::remove(entry);
                            FileOperation::deleteAllWithoutAsking_ = true;
                        default: break;
                        }
                    }
                    else fs::remove(entry);
                }
                else {
                    if (fs::is_empty(entry)) {
                        fs::remove(entry);
                        break;
                    }
                    else _delete(entry);
                }
            }
            fs::remove(src);
            return true;
        }
        else fs::remove_all(src);
        return true;
    }
    catch (const error& ex) {
        std::cout << ex.what() << std::endl;
        return false;
    }
}

bool FileOperation::_copy(fs::path& src, fs::path& dest) {
    try {
        fs::copy(src, dest,
            fs::copy_options::recursive |
            fs::copy_options::skip_existing);
        return true;
    }
    catch (const error& ex) {
        std::cout << ex.what() << std::endl;
        return false;
    }
}

bool FileOperation::_readOnly(const fs::path& src)
{
    auto perms(fs::status(src).permissions());
    if (((perms & fs::perms::owner_write) != fs::perms::none) &&
        ((perms & fs::perms::group_write) != fs::perms::none) &&
        ((perms & fs::perms::others_write) != fs::perms::none))
        return false;
    return true;
}

bool FileOperation::_move(fs::path& src, fs::path& dest)
{
    if (_copy(src, dest)) {
        FileOperation::deleteAllWithoutAsking_ = true;
        return _delete(src);
    }
    return false;
}

size_t FileOperation::_whatToDoIfSrcIsReadOnly(const fs::path& src)
{
    size_t choice{ 0 };
    while (choice != 1 &&
        choice != 2 &&
        choice != 3) {
        std::cout << "File "
            << fs::path(src).filename()
            << " is read-only.\n"
            << "Please, choose what to do: \n  1 - Delete  2 - Delete for all  3 - Cancel ---> ";
        std::cin >> choice;
    }
    return choice;
}