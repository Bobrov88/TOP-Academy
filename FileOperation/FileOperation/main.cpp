#include "fileOperation.h"



int main()
{
    setlocale(LC_ALL, "Ru");

    fs::path src = "Testfolder";

    /*
    
    CREATE "TESTFOLDER" IN THE SAME FOLDER AS MAIN.CPP IS
    AND PUT SOME FILES AMD FOLDERS INTO THIS FOLDER 
    THEN TEST...... 
    
    
    */

    fs::create_directory("Testfolder2");
    fs::create_directory("Testfolder3");
    fs::path dest = "Testfolder2";
    fs::path temp = "TestFolder3";

    FileOperation::_copy(src, dest);
    FileOperation::_move(dest, temp);

    FileOperation::deleteAllWithoutAsking_ = false;
    FileOperation::_delete(src);
    
    //_move(src, dest);
    
}