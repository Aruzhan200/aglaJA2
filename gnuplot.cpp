#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    double x[1001], y[10001];
    for (int i = 1; i <= n; i ++) {
        cin >> x[i] >> y[i];
    }
    FILE* pipe = popen("gnuplot -persist", "w");
    fprintf(pipe, "%s\n", "plot [-20: 20] [-20: 20] '-' using 1:2 title 'lines' with lines");
    for (int i = 0; i < n; i ++) {
        fprintf(pipe, "%f %f\n", x[i], y[i]);
    }
    fprintf(pipe, "%s\n", "e");
    fflush(pipe);
    return 0;
}
