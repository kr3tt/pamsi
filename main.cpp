#include <iostream>
#include <cstdlib>
#include <time.h>

#include "MergeSort.hpp"
#include "Introsort.hpp"
#include "Quicksort.hpp"

int main() {

    int n = 1000000;

    int **tab;

    tab = new int*[100];
    for(int i = 0; i < 100; ++i)
    {
        tab[i] = new int[n];
    }

//    uzupelnienie 100 tablic liczbami z przedzialu 0-100
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < n; j++)
        {
            tab[i][j] = rand() % 100;
        }
    }

    //    w jakim % jest posortowana?
    for(int i = 0; i < 100; ++i)
    {
//        Quicksort(tab[i], 0, (n*99.7/100)-1);
    }

//   ----------------------- quicksort -----------------------

    int **tabQuick;

    tabQuick = new int*[100];
    for(int i = 0; i < 100; ++i)
    {
        tabQuick[i] = new int[n];
    }

//    uzupelnienie 100 tablic liczbami z tab
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < n; j++)
        {
            tabQuick[i][j] = tab[i][j];
        }
    }


    //    wywolanie i mierzenie czasu sortowania quickSort
    clock_t startQuick = clock();
    //%%%%%%%%%%//
    for(int i = 0; i < 100; ++i)
    {
        Quicksort(tabQuick[i], 0, n-1);
    }
    //%%%%%%%%%%//
    clock_t stopQuick = clock();

// --------------------- mergesort -----------------------------

    int **pomMerge;
    int **tabMerge;

    pomMerge = new int*[100];
    tabMerge = new int*[100];
    for(int i = 0; i < 100; ++i)
    {
        pomMerge[i] = new int[n];
        tabMerge[i] = new int[n];
    }

//    uzupelnienie 100 tablic liczbami z przedzialu 0-100
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < n; j++)
        {
            pomMerge[i][j] = 0;
            tabMerge[i][j] = tab[i][j];
        }
    }

//    wywolanie i mierzenie czasu sortowania
    clock_t startMerge = clock();
    for(int i = 0; i < 100; ++i)
    {
        MergeSort(tabMerge[i], pomMerge[i], 0, n-1);
    }
    clock_t stopMerge = clock();

//    ------------------ INTROSORT ----------------

    int **tabIntro;

    tabIntro = new int*[100];
    for(int i = 0; i < 100; ++i)
    {
        tabIntro[i] = new int[n];
    }


//    uzupelnienie 100 tablic liczbami z przedzialu 0-100
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < n; j++)
        {
            tabIntro[i][j] = tab[i][j];
        }
    }

//    wywolanie i mierzenie czasu sortowania
    clock_t startIntro = clock();
    //%%%%%%%%%%//
    for(int i = 0; i < 100; ++i)
    {
        IntroSort(tabIntro[i], n-1);
    }
    //%%%%%%%%%%//
    clock_t stopIntro = clock();

    //  -------------- obliczanie czasu ------------------

//    QuickSort
    double elapsedQuick = (double) (stopQuick - startQuick) / CLOCKS_PER_SEC;
    std::cout << "**QUICKSORT** time elapsed: " << elapsedQuick << std::endl;

//    MergeSort
    double elapsedMerge = (double) (stopMerge - startMerge) / CLOCKS_PER_SEC;
    std::cout << "**MERGESORT** time elapsed: " << elapsedMerge << std::endl;

//    IntroSort
    double elapsedIntro = (double) (stopIntro - startIntro) / CLOCKS_PER_SEC;
    std::cout << "**INTROSORT** time elapsed: " << elapsedIntro << std::endl;

// -------------- zwalnianie pamieci --------------------------

    for(int i = 0; i < 100; ++i)
        delete[] tab[i];
    delete[] tab;

    for(int i = 0; i < 100; ++i)
        delete[] tabQuick[i];
    delete[] tabQuick;

    for(int i = 0; i < 100; ++i)
    {
        delete[] tabMerge[i];
        delete[] pomMerge[i];
    }
    delete[] tabMerge;
    delete[] pomMerge;

    for(int i = 0; i < 100; ++i)
        delete[] tabIntro[i];
    delete[] tabIntro;

    return 0;
}


//    // sprawdzenie czy tablica jest posortowana
//    for(int i = 0; i < 100; i++)
//    {
//        for(int j = 0; j < n; j++)
//        {
//            std::cout << tabQuick[i][j] << std::endl;
//        }
//    }
