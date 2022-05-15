#include <iostream>
#include <map>
#include "Map.h"
using namespace std;

int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    cout << endl;
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    cout << endl;
    m.Set(666, "lil nas x");
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    cout << "am facut get" << endl;
    const char* aici;
    m.Get(10, aici);
    cout << aici << endl;


    Map<int, const char*> g;
    g[10] = "C++";
    g[20] = "test";
    g[30] = "Poo";
    cout << m.Includes(g) << endl;
    return 0;
}