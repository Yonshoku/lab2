#include <iostream>

using namespace std;

void printOptions() {
    cout << "1 - Заполнить матрицу снаружи по часовой стрелке" << endl;
    cout << "2 - Заполнить матрицу снаружи против часовой стрелки" << endl;
    cout << "3 - Заполнить матрицу изнутри по часовой стрелке" << endl;
    cout << "4 - Заполнить матрицу изнутри против часовой стрелки" << endl;
}


int main() {
    int input;

    printOptions();
    cin >> input;

    while (input > 0 and input < 5) {
        int n, m, level, index, i, j, temp;

        cout << "Введите ширину и высоту матрицы" << endl;
        cin >> m >> n;

        while (n <= 0 or m <= 0) {
            cout << "Некорректные данные. Пожалуйста, попробуйте ещё раз" << endl;
            cin >> m >> n;
        }

        int matrix[n][m];
        int numbers[n * m];

        cout << "Введите числа" << endl;
        for (int i = 0; i < n * m; i++) {
            cin >> numbers[i];
        }

        // Clockwise outside and counterclockwise inside
        if (input == 1 or input == 4) {
            level = 0; index = 0;
            i = 0; j = 1;

            if (input == 4) { // Reverse
                for (int i = 0; i < n * m / 2; i++) {
                    temp = numbers[i];
                    numbers[i] = numbers[n * m - i - 1];
                    numbers[n * m - i - 1] = temp;
                }
            }

            while (index < n * m) {
                
                // Fill upper line 
                for (int j = level - 1; j < m - level; j++) {
                    if (j < 0) continue;
                    
                    matrix[level][j] = numbers[index];
                    index++;
                } 
                
                // Fill right line
                if (index < n * m) {
                    for (int i = level + 1; i < n - level; i++) {
                        matrix[i][m - level - 1] = numbers[index];
                        index++;
                    }
                } 
                
                // Fill bottom line
                if (index < n * m) {
                    for (int j = m - level - 2; j >= level; j--) {
                        matrix[n - level - 1][j] = numbers[index];
                        index++;
                    }
                }
                
                // Fill left line
                if (index < n * m) {
                    for (int i = n - level - 2; i > level + 1; i--) {
                        matrix[i][level] = numbers[index];
                        index++;
                    }
                } 
                
                level += 1;
            }

            // Print 
            cout << endl;
            cout << "Результат:" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
            
            cout << endl;
            cout << endl;

        // Counterclockwise outside and clockwise inside
        } else if (input == 2 or input == 3) {
            index = 0; level = 0;
            i = 0; j = 0;

            if (input == 3) { // Reverse 
                for (int i = 0; i < n * m / 2; i++) {
                    temp = numbers[i];
                    numbers[i] = numbers[n * m - i - 1];
                    numbers[n * m - i - 1] = temp;
                }
            }

            while (index < n * m) {
                
                // Fill upper line 
                for (int j = m - level - 1; j > level - 1; j--) {
                    if (j < 0) continue;
                    
                    matrix[level][j] = numbers[index];
                    index++; } 
                
                // Fill left line
                if (index < n * m) {
                    for (int i = level + 1; i < n - level; i++) {
                        matrix[i][level] = numbers[index];
                        index++;
                    }
                } 
                
                // Fill bottom line
                if (index < n * m) {
                    for (int j = level + 1; j < m - level; j++) {
                        matrix[n - level - 1][j] = numbers[index];
                        index++;
                    }
                }
                
                // Fill right line
                if (index < n * m) {
                    for (int i = n - level - 2; i > level; i--) {
                        matrix[i][m - level - 1] = numbers[index];
                        index++;
                    }
                } 
                
                level += 1;
            }
            
            // Print 
            cout << endl;
            cout << "Результат:" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
            
            cout << endl;
            cout << endl;
        }

        printOptions();
        cin >> input;
    }
    
    return 0;
}
