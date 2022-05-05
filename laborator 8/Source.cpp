#include <iostream>
#include <string>
#include <fstream>
#include <utility> //for pair
#include <map> //for map
#include<queue>

using namespace std;
ifstream file("file.in");
map <string, int> Words;
//functie de afisarea map-ului
using namespace std;
class Compara
{
public:
    bool operator()(pair<string, int>& v1, pair<string, int>& v2) const  //cele cu prioritate mai mare le extragem primele
    {
        if (v1.second != v2.second)
        {
            return v1.second < v2.second;
        }
        if (v1.second == v2.second)
        {
            if (v1.first.compare(v2.first) > 0)
                return 1; // extrag prima data daca alea  cu prioritate mai mare,
            return 0;
        }
    }
};

class Cmp
{
public:
    bool operator()(pair<string, int>& v1, pair<string, int>& v2) const  //cele cu prioritate mai mare le extragem primele
    {
        if (v1.first.length() < v2.first.length())
            return 1;
        else return 0;
    }
};
int main()
{
    ///citire din fisier
    string text;
    getline(file, text);
    cout << text << endl;

    string separator = "? ,!.";
    cout << "Lungimea sirului: " << text.length() << endl;
    //text[0]='M';
    string vect[100];
    int poz1 = 0, poz2 = 0, k = 0, gasit;
    ///transformam din litera mare in litara mica
    for (int i = 0; i < text.length(); i++)
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = text[i] - 'A' + 'a';
    ///separare in cuvinte
    for (int i = 0; i < text.length(); i++)
    {
        gasit = separator.find(text[i]);
        if (gasit != -1)
        {
            if (poz1 < i)
            {
                vect[k].assign(text, poz1, i - poz1);
                k++;
            }
            poz1 = i + 1;
        }
    }

    ///cream map ul
    for (int l = 0; l < k; l++)
    {
        if (Words.find(vect[l]) == Words.end())
            Words[vect[l]] = 1;
        else
            Words[vect[l]]++;
    }
    //afisare map
    map<string, int>::iterator it;
    for (it = Words.begin(); it != Words.end(); it++)
        cout << it->first << " : " << it->second << endl;

    //coada cu prioritate
    priority_queue<pair<string, int>, vector<pair<string, int>>, Compara> sort_queue;
    map<string, int>::iterator it1;
    for (it1 = Words.begin(); it1 != Words.end(); it1++)
        sort_queue.push({ it1->first, it1->second });

    cout << endl;
    cout << "DUPA SORTARE: " << endl;
    cout << endl;

    //Print the words after they are sorted
    while (sort_queue.size())
    {
        pair<string, int> aux = sort_queue.top();
        cout << aux.first << " => " << aux.second << endl;
        sort_queue.pop();
    }

    //sortared dupa lungime cuvant
    priority_queue<pair<string, int>, vector<pair<string, int>>, Cmp> sort_lungime;
    map<string, int>::iterator it3;
    for (it3 = Words.begin(); it3 != Words.end(); it3++)
        sort_lungime.push({ it3->first, it3->second });

    cout << endl;
    cout << "DUPA SORTARE LUNGIME: " << endl;
    cout << endl;

    //Print the words after they are sorted
    while (sort_lungime.size())
    {
        pair<string, int> aux = sort_lungime.top();
        cout << aux.first << " => " << aux.second << endl;
        sort_lungime.pop();
    }

    return 0;
}