#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}
void stat(const double A[], int N, double B[]) {
    double sum = 0.0, sumSquaredDiff = 0.0, product = 1.0, sumReciprocal = 0.0;
    double maxVal = A[0], minVal = A[0];

    for (int i = 0; i < N; ++i) {
        sum += A[i];
        sumSquaredDiff += pow(A[i], 2);
        product *= A[i];
        sumReciprocal += 1 / A[i];

        if (A[i] > maxVal) {
            maxVal = A[i];
        }

        if (A[i] < minVal) {
            minVal = A[i];
        }
    }
    double mean = sum / N;
    double standardDeviation = sqrt((sumSquaredDiff / N) - pow(mean, 2));
    double geometricMean = pow(product, 1.0 / N);
    double harmonicMean = N / sumReciprocal;
    B[0] = mean;
    B[1] = standardDeviation;
    B[2] = geometricMean;
    B[3] = harmonicMean;
    B[4] = maxVal;
    B[5] = minVal;
}