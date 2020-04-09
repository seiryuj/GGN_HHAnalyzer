#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

int main()
{
    string path = "./hand_history/";
    string line;
    int handCnt = 0;

    vector<string> fileList;

    //ifstream myfile("./GG20200402-0718 - RushAndCash401 - 0.1 - 0.25 - 6max.txt");
    for (const auto & entry : fs::directory_iterator(path))
    {
        string tmp = entry.path();
        if(tmp.find(".txt") != string::npos)
        {
            fileList.push_back(tmp);
        }
    }

    for (int i=0;i < fileList.size();i++)
    {
        ifstream myFile(fileList[i]);
        while(myFile.good())
        {
            getline(myFile, line);
            if(!line.size())
                handCnt++;
        }
    }

    handCnt = handCnt - fileList.size();
    handCnt = handCnt/2;

    cout << handCnt << endl;

    return 0;
}