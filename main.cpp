#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

double a1, b1, a2, b2;
double T;
int N;

double t[100001];
double v[100001];
double k[100001];

double get_nextV(double t) {
    return (v[0] - (a2/b2)) * cos(sqrt(a1 * a2) * t) -
                ((k[0] - (a1/b1)) * sqrt(a2) * b1 * sin(sqrt(a2 * a1) * t)) / (b2 * sqrt(a1)) + (a2/b2);
}

double get_nextK(double t) {
    return ((v[0] - (a2/b2)) * sqrt(a1) * b2 * sin(sqrt(a2 * a1) * t)) / (b1 * sqrt(a2)) +
                (k[0] - (a1/b1)) * cos(sqrt(a1 * a2) * t) + (a1/b1);
}

double get_T_from_K(double k) {

}

int main() {
    cin >> v[0];
    cin >> k[0];
    cin >> a1 >> b1 >> a2 >> b2;
    cin >> T;
    cin >> N;
    for (int i = 0; i <= N; i ++) {
        t[i] = T / N * i;
        if (i >= 1) {
            v[i] = get_nextV(t[i]);
            k[i] = get_nextK(t[i]);
        }
    }

    ofstream line1;
    line1.open ("line1.dat");
    for (int i = 0; i <= N; i ++) {
        line1 << t[i] << ' ' << v[i] << '\n';
    }
    line1.close();

    ofstream line2;
    line2.open ("line2.dat");
    for (int i = 0; i <= N; i ++) {
        line2 << t[i] << ' ' << k[i] << '\n';
    }
    line2.close();

    FILE* pipe = popen("gnuplot -persist", "w");
    fprintf(pipe, "plot [0: %f] 'line1.dat' using 1:2 title 'v(t)' with lines, \\\n'line2.dat' using 1:2 title 'k(t)' with lines\n", T);
    fflush(pipe);
    return 0;
}
