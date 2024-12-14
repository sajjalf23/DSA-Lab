#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void erase(vector<vector<int>>& ar, int r, int c, int i, int j) {
    if (i < 0 || i >= r || j < 0 || j >= c || ar[i][j] == 0) {
        return;
    }
    ar[i][j] = 0;
    
    erase(ar, r, c, i + 1, j); 
    erase(ar, r, c, i - 1, j);
    
    erase(ar, r, c, i, j + 1);  
    erase(ar, r, c, i, j - 1); 
}

int main() {
    ifstream inputFile("input_0.txt");



    if (!inputFile.is_open()) {


        cout << " Unable to open input file!" << endl;
        return 1;


    }

    int rows, cols, startRow, startCol;

    inputFile >> rows >> cols;

    inputFile >> startRow >> startCol;

    vector<vector<int>> image(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < cols; ++j) {
            inputFile >> image[i][j];
        }

    }

    inputFile.close();

    erase(image, rows, cols, startRow, startCol);

    for (const auto& row : image) {

        for (const auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
        
    }

    return 0;
}
