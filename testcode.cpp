// NMAX = valoarea maximă a lui n
// MMAX = valoarea maximă a lui m

void fill(int i, int j, int n, int m, int puzzle[NMAX][MMAX], int answer[NMAX][MMAX]) {
    int addLin[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int addCol[] = {0, 1, 1, 1, 0, -1, -1, -1};

    // Numărăm vecinii cu mină:
    answer[i][j] = 0;
    for (int k = 0; k < 8; k++) {
        int x = i + addLin[k], y = j + addCol[k];
        if (!(0 <= x && x < n && 0 <= y && y < m))
            continue;
        if (puzzle[x][y] == -1)
            answer[i][j]++;
    }

    if (answer[i][j] > 0) // Suntem pe marginea zonei active.
        return; // Vizităm pozițiile periculoase, dar nu ne expandăm din ele.

    for (int k = 0; k < 8; k++) {
        int x = i + addLin[k], y = j + addCol[k];
        if (!(0 <= x && x < n && 0 <= y && y < m))
            continue;
        if (answer[x][y] == -2) // Dacă n-am vizitat celula:
            fill(x, y, n, m, puzzle, answer);
    }
}

void buildAnswer(int n, int m, int puzzle[NMAX][MMAX], int l, int c, int answer[NMAX][MMAX]) {
    int addLin[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int addCol[] = {0, 1, 1, 1, 0, -1, -1, -1};

    if (puzzle[l][c] == -1)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                answer[i][j] = puzzle[i][j];
    else {
        // Numărăm vecinii cu mină:
        int cnt = 0;
        for (int k = 0; k < 8; k++) {
            int x = l + addLin[k], y = c + addCol[k];
            if (!(0 <= x && x < n && 0 <= y && y < m))
                continue;
            if (puzzle[x][y] == -1)
                cnt++;
        }

        if (cnt) { // Dacă zona este periculoasă:
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    answer[i][j] = -2;
            answer[l][c] = cnt;
        }
        else {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    answer[i][j] = -2;
            fill(l, c, n, m, puzzle, answer);
        }
    }
}

