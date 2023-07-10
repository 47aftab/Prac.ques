#include <iostream>
using namespace std;
class Relation {
private:
    int matrix[10][10];
    int rows;
    int columns;
public:
    Relation() {
        rows = 0;
        columns = 0;
    }

    void readMatrix() {
        cout << "Enter the number of rows: ";
        cin >> rows;
        cout << "Enter the number of columns: ";
        cin >> columns;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cin >> matrix[i][j];
            }
            cout<<endl;
        }
    }

    void displayMatrix() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool isSymmetric() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] != matrix[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isReflexive() {
        for (int i = 0; i < rows; i++) {
            if (matrix[i][i] != 1) {
                return false;
            }
        }
        return true;
    }

    bool isTransitive() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == 1) {
                    for (int m = 0; m < columns; m++) {
                        if (matrix[j][m] == 1 && matrix[i][m] != 1) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    bool isAntisymmetric() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == 1 && matrix[j][i] == 1 && i != j) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isEquivalenceRelation() {
        return isReflexive() && isSymmetric() && isTransitive();
    }

    bool isPartialOrderRelation() {
        return isReflexive() && isAntisymmetric() && isTransitive();
    }
};

int main() {
    Relation relation;
    relation.readMatrix();
    relation.displayMatrix();

    if (relation.isSymmetric()) {
        cout << "The relation is symmetric." << endl;
    } else {
        cout << "The relation is not symmetric." << endl;
    }

    if (relation.isReflexive()) {
        cout << "The relation is reflexive." << endl;
    } else {
        cout << "The relation is not reflexive." << endl;
    }

    if (relation.isTransitive()) {
        cout << "The relation is transitive." << endl;
    } else {
        cout << "The relation is not transitive." << endl;
    }

    if (relation.isAntisymmetric()) {
        cout << "The relation is antisymmetric." << endl;
    } else {
        cout << "The relation is not antisymmetric." << endl;
    }

    if (relation.isEquivalenceRelation()) {
        cout << "The relation is an equivalence relation." << endl;
    } else {
        cout << "The relation is not an equivalence relation." << endl;
    }

    if (relation.isPartialOrderRelation()) {
        cout << "The relation is a partial order relation." << endl;
    } else {
        cout << "The relation is not a partial order relation." << endl;
    }

    return 0;
}

