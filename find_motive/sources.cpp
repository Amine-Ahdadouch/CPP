#include <fstream>
#include "sources.h"

int motive(char *path, char *motive)
{
    std::ifstream file;
    file.open(path);

    if (file.fail())
    {
        std::cout << "The file " << path << " could not be opened.\n";
        return 1;
    }
    std::string str;
    int count = 0;

    while (file >> str)
    {
        if (str.find(motive) != -1)
        {
            count++;
        }
    }
    std::cout << "The file " << path << " contains " << count << " words containing the motive " << motive << "\n";
    return 0;
}