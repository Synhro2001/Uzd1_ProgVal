#define _CRT_SECURE_NO_DEPRECATE 
#include <windows.h> 
#include <cstdio> 
#include <cstdlib> 
#include <ctime> 
#include <iostream>


using namespace std;



int mostFreqNum(int array[], int N) {
    int maxCnt = 0, maxVal = 0;
    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = i + 1; j < N; j++) {
            if (array[i] == array[j])
                count++;
        }
        if (count > maxCnt) {
            maxCnt = count;
            maxVal = array[i];

        }
    }
    return maxVal;
}

void RandomArray(int A[], int N)
{
    srand(time(0)); // автоматическая рандомизация
    for (int i = 0; i < N; i++) A[i] = 1 + rand() % 10;
}

void ShowArray(int A[], int N, int FreqNum) {

    for (int i = 0; i < N; i++) {

        if (A[i] == FreqNum) A[i] = 0;

        printf("%d ", A[i], i % 10 == 9 ? "\r\n" : " ");
    }
    if (N % 10) printf("\n");
}

int main()
{
    int n, * a; // * показывает значение переменной по заданному адресу
    cout << "Please enter amount of number in array = "; cin >> n;

    a = new int[n];
    RandomArray(a, n);
    ShowArray(a, n, mostFreqNum(a, n));
    return 0;


}

