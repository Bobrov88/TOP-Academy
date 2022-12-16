#pragma once
#include <fstream>
#include <iostream>
#include <filesystem>
#include <Windows.h>

namespace fs = std::filesystem;
typedef fs::filesystem_error error;

class FileOperation {
public:
	static bool deleteAllWithoutAsking_;
public:
    static bool _delete(const fs::path&);
    static bool _copy(fs::path&, fs::path&);
    static bool _readOnly(const fs::path&);
    static bool _move(fs::path&, fs::path&);
    static size_t _whatToDoIfSrcIsReadOnly(const fs::path&);
};

