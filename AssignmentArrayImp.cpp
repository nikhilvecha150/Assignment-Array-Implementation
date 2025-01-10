#include <iostream>
#include <vector>
using namespace std;

// represent a non-zero structure
struct Element {
    int r_o_w;
    int c_o_l;
    int vals;
};

// operations of sparse matrix
class SparseMatrix_101 {
private:
    int rows_1, cols_11;
    vector<Element> elements; // storing elements which are not zero

public:

    SparseMatrix_101(int r, int c) : rows_1(r), cols_11(c) {}

    // Adding non-zero values
    void addElement(int r, int c, int val) {
        if (val != 0) {
            elements.push_back({r, c, val});
        }
    }

    // Display function
    void display_102() {
        cout << "Sparse Representation (r_o_w, c_o_l, vals):" << endl;
        for (const auto &e : elements) {
            cout << "(" << e.r_o_w << ", " << e.c_o_l << ", " << e.vals << ")" << endl;
        }
    }

    // return to full matrix
    void displayFullMatrix_103() {
        vector<vector<int>> fullMatrix(rows_1, vector<int>(cols_11, 0));

        for (const auto &e : elements) {
            fullMatrix[e.r_o_w][e.c_o_l] = e.vals;
        }

        cout << "Full Matrix:" << endl;
        for (const auto &row : fullMatrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int row_12, cols_12, num_Ele;

    // Get matrix length
    cout << "Enter the number of rows in the matrix: ";
    cin >> row_12;
    cout << "Enter the number of columns in the matrix: ";
    cin >> cols_12;


    SparseMatrix_101 sm(row_12, cols_12);

    // non-zero values from the user
    cout << "Enter the number of non-zero elements: ";
    cin >> num_Ele;

    // Get each non-zero element from the user
    cout << "Enter the non-zero elements in the format (row, col, value):" << endl;
    for (int i = 0; i < num_Ele; i++) {
        int r, c, val;
        cout << "Element " << i + 1 << ": ";
        cin >> r >> c >> val;

        // values being added to sparse matrix
        sm.addElement(r, c, val);
    }

    // showing sparse matrix
    sm.display_102();

    // showing full matrix
    sm.displayFullMatrix_103();

    return 0;
}
