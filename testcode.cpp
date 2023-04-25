#include <bits/stdc++.h>
using namespace std;

const int NMAX = 101;
// 2 * (NMAX - 1) = valoarea maximă a lui n

int n, p;
int lgA1, A1[NMAX], lgB1, B1[NMAX]; // A, B
int lgA2, A2[NMAX], lgB2, B2[NMAX]; // A', B'

int main() {
    cin >> n >> p;
    if (!(n >= 4 && n % 4 == 0 && 1 <= p && p <= n / 2)) {
        cout << "date invalide\n";
        return 0;
    }

    lgA1 = lgB1 = n / 2;
    for (int i = 1, j = 1; i <= n / 4; i++, j += 2) {
        A1[i] = j;
        B1[i] = j + 1;
    }
    for (int i = n / 4 + 1, j = n / 2 + 2; i <= n / 2; i++, j += 2) {
        A1[i] = j;
        B1[i] = j - 1;
    }
    cout << "A: "; for (int i = 1; i <= lgA1; i++) cout << A1[i] << ' '; cout << '\n';
    cout << "B: "; for (int i = 1; i <= lgB1; i++) cout << B1[i] << ' '; cout << '\n';

    if (p % 2) {
        cout << "partitie inexistenta\n";
        return 0;
    }
    if (p / 2 % 2) {
        for (int i = 1; i <= lgA1; i++)
            if (A1[i] != p / 2)
                A2[++lgA2] = A1[i];
        for (int i = 1; i <= lgB1; i++)
            if (B1[i] == p)
                B2[++lgB2] = p / 2;
            else
                B2[++lgB2] = B1[i];
    }
    else {
        A2[++lgA2] = 2;
        for (int i = 2; i <= lgA1; i++)
            if (A1[i] != p / 2 + 1)
                A2[++lgA2] = A1[i];
        B2[++lgB2] = 1;
        for (int i = 2; i <= lgB1; i++)
            if (B1[i] == p)
                B2[++lgB2] = p / 2 + 1;
            else
                B2[++lgB2] = B1[i];
    }
    cout << "A': "; for (int i = 1; i <= lgA2; i++) cout << A2[i] << ' '; cout << '\n';
    cout << "B': "; for (int i = 1; i <= lgB2; i++) cout << B2[i] << ' '; cout << '\n';
    return 0;
}


