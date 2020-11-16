#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maze[5][6] =
    {
        {2, 2, 2, 2, 2, 0},
        {0, 0, 2, 0, 0, 0},
        {3, 2, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}};

vector<string> *findCheese(int x, int y)
{
    if (!((x >= 0) && (x <= 5) && (y >= 0) && (y <= 4)))
    {
        return nullptr;
    }
    // Mouse inside laberynth
    else if ((maze[y][x] == 0) || (maze[y][x] == 1))
    {
        return nullptr;
    }
    else if (maze[y][x] == 3)
    {
        // Mouse found cheese
        vector<string> *result = new vector<string>();
        result->insert(result->begin(), "(" + to_string(x) + "," + to_string(y) + ")");
        return result;
    }
    else
    { // (maze[y][x] == 2)
        maze[y][x] = 1;
        // Mouse must try to find cheese by moving
        // Look by moving up
        vector<string> *resultUp = findCheese(x, y - 1);
        if (resultUp != nullptr)
        {
            resultUp->insert(resultUp->begin(), "(" + to_string(x) + "," + to_string(y) + ")");
            return resultUp;
        }
        // If cheese not found try moving right
        vector<string> *resultRight = findCheese(x + 1, y);
        if (resultRight != nullptr)
        {
            resultRight->insert(resultRight->begin(), "(" + to_string(x) + "," + to_string(y) + ")");
            return resultRight;
        }
        // If cheese not found try moving left
        vector<string> *resultLeft = findCheese(x - 1, y);
        if (resultLeft != nullptr)
        {
            resultLeft->insert(resultLeft->begin(), "(" + to_string(x) + "," + to_string(y) + ")");
            return resultLeft;
        }
        // If cheese not found try moving down
        vector<string> *resultDown = findCheese(x, y + 1);
        if (resultDown != nullptr)
        {
            resultDown->insert(resultDown->begin(), "(" + to_string(x) + "," + to_string(y) + ")");
            return resultDown;
        }
        return nullptr;
    }
}

int main()
{
    vector<string> *route = findCheese(0, 0);
    if (route == nullptr)
    {
        cout << "Cheese not found :(" << endl;
    }
    else
    {
        for (string step : *route)
        {
            cout << "Next step : " << step << endl;
        }
    }
}