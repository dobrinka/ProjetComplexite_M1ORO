#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <ctime>
#include "ProblemMaxSomme.h"
#define N 4


using namespace std;

clock_t start, end, total;



int main(int argc, char *argv[])
{
    clock_t tStart = clock();
    vector<int> Somme;
    //int sum = 0;
    // int T [5] = {6, -2, 7, 4, 12};

    //int S [4] =0;


//    int N = atoi(argv[1]);
    int maxInt = N*4;
    std::vector<int> t;
    bool indPos = false;
    //srand(time(NULL));
    //struct timeval tbegin, tend;
    //double texec = 0;
   // gettimeofday(&tbegin, NULL);
    //int conf=0;
    // Création du tableau
    //int cpt = 0;
    for (int i = 0; i < N; i++)
    {
        // Génération aléatoire d'un entier
        int v = rand() % maxInt + 1;

        // Vérification de sa présence
        std::vector<int>::iterator it;
        it = find(t.begin(), t.end(), v);

        // Traitement en fonction de sa présence
        if (it != t.end())
        {
            bool fin = false;

            // Génération d'une nouvelle valeur
            while (!fin)
            {
                v = rand() % maxInt + 1;
                std::vector<int>::iterator it2;
                it2 = find(t.begin(), t.end(), v);

                if (it2 == t.end())
                fin = true;
                //conf++;

            }
        }

        // Définition aléatoire du signe de v
        double p = rand()/(double)(RAND_MAX + 1);
        if (-p > 0.5)
        {
            std::vector<int>::iterator it3;
            it3 = std::find(t.begin(), t.end(), v);
            if(it3 == t.end())
                t.push_back(-v);
            else
                t.push_back(v);
        }
        else
        {
            if (!indPos)
            indPos = true;

            t.push_back(v);
        }

        // Garantie de la présence d'au moins un entier positif
        if (i == N-1)
        {
            if (!indPos)
            {
                t[i] = t[i] * -1;
            }
        }

    }



        ProblemMaxSomme maxS = ProblemMaxSomme(t);


        cout<< "resultat algo1 = "<< maxS.algo1() <<endl;
        maxS.afficherTableau();

        //cout<< "Time taken: "<< ((clock() - tStart)/CLOCKS_PER_SEC)<<endl;
        //return 0;

        cout<< "resultat algo2 = "<< maxS.algo2() <<endl;
        maxS.afficherTableau();
        cout<< "resultat algo3 = "<< maxS.algo3(0,N-1) <<endl;
        maxS.afficherTableau();
        cout<< "resultat algo4 = "<< maxS.algo4() <<endl;
        maxS.afficherTableau();



}
