


#include <iostream>
#include <string>
using namespace std;


int nScreanWisth = 120;
int nScreanHeight = 40

float fPlayerX = 0.0f;
float fPlayerY = 0.0f;
float fPlayerA = 0.0f;

int nMapHeight = 16;
int nMapWidth = 16;

float fOFV = 3.14159/4;

int main()
{
    std::string map;
    map += L"################";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"################";

    //game loop
    while(1)
    {
        for(int x = 0; x < nScreanWisth; x++)
        {
            //for each column calculate the projected ray angle into map
        }
    }
    return 0
}