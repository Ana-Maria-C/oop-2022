#pragma once
class Sort
{

    int* v;               // vector de int uri alocat dinamic
    int count;      // nr de elemnte din vector
public:

    Sort(int count, int min, int max);
    Sort(int count, int* v);
    Sort(int count, ...);
    Sort(const char* sir);

    void InsertSort(bool ascendent);

    void QuickSort(bool ascendent);

    void BubbleSort(bool ascendent);

    void Print();

    int GetElementsCount();

    int GetElementFromIndex(int index);

};