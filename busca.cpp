#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <stdlib.h>

#define vector_size 10
using namespace std;


int buscaBinariaRecursiva(int vetor[], int incio, int fim, int item){
    int i = (incio + fim) / 2;

    if (incio > fim) {
        return -1;
    }

    if (vetor[i] == item) {
        return i;
    }

    if (vetor[i] < item) {
        return buscaBinariaRecursiva(vetor, i + 1, fim, item);
    } else { 
        return buscaBinariaRecursiva(vetor, incio, i - 1, item);
    }
}

int busca_sequencial(int vetor[], int item, int tam)
{
    int m = 0;
    while(m < tam)
    {
        if(vetor[m] == item)
        {
            return m;
        }
        m++;
    }
    return -1;
}

void preencherVetor(int vetor_1[50], int vetor_2[100], int vetor_3[150], int vetor_4[200], int vetor_5[250], int vetor_6[300]){
    for (int i = 0; i < 50; i++){
        vetor_1[i] = rand()%51;
    }

    for (int i = 0; i < 100; i++){
        vetor_2[i] = rand()%101;
    }

    for (int i = 0; i < 150; i++){
        vetor_3[i] = rand()%151;
    }

    for (int i = 0; i < 200; i++){
        vetor_4[i] = rand()%201;
    }

    for (int i = 0; i < 250; i++){
        vetor_5[i] = rand()%251;
    }

    for (int i = 0; i < 300; i++){
        vetor_6[i] = rand()%301;
    }
}


int main(int argc, char const *argv[]){ 
    
    int vetor_1[50], vetor_2[100], vetor_3[150], vetor_4[200], vetor_5[250], vetor_6[300];

    preencherVetor(vetor_1, vetor_2, vetor_3, vetor_4, vetor_5, vetor_6);

    double total_binario[1000];
    double media = 0;

    vector<chrono::nanoseconds> times_binarario(1000);

    for (int i = 1; i <= 1000; i++) {
        auto start = chrono::high_resolution_clock::now();
        
        buscaBinariaRecursiva(vetor_5, 0, 250 - 1, 225);
        
        auto end =  chrono::high_resolution_clock::now();

        double elapsedtime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        // cout << "Elapsed time in nanoseconds : "
        // << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        // << " ns" << endl;

       // times_binarario.push_back(chrono::nanoseconds(elapsedtime));

        total_binario[i] = elapsedtime;
        media += total_binario[i];
    }

    std::sort(times_binarario.begin(), times_binarario.end());
    cout << "Media Binaria: " << media/1000 << " ns " << endl;
   

    double total_sequencial[1000];    
    for(int i = 1; i <= 1000; i++) {
        auto start = chrono::high_resolution_clock::now();
       
        busca_sequencial(vetor_5, 250, 225);
       
        auto end =  chrono::high_resolution_clock::now();

        double elapsedtime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        total_sequencial[i] = elapsedtime;
        media += total_sequencial[i];
    }

    cout << "Media Sequencial: " << media/1000 << " ns " << endl;

    return EXIT_SUCCESS;

}
