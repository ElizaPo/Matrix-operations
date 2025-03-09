#include <iostream>
#include <string>
using namespace std;

struct Matrix {
    size_t n;
    string data;
};

struct Position {
    size_t i;
    size_t j;
};

size_t get_index(const Position& p, size_t n) {
    return p.i*n+p.j;
}

Position get_position(size_t index, size_t n) {
    size_t i = index / n;
    size_t j = index % n;
    return Position {i, j};
}

bool is_valid_value(char ch) {
    return ((ch>='a' and ch<='z') or (ch>='A' and ch<='Z'));
}

bool is_valid_size(const Matrix& matrix) {
    if (matrix.n*matrix.n==matrix.data.size()) {
        return true;
    }
    return false;
}

bool is_valid_matrix(const Matrix& matrix) {
    if (not is_valid_size(matrix)) {
        return false;
    }
    for(size_t i=0;i<matrix.data.size();++i) {
        if (not is_valid_value(matrix.data[i])) {
            return false;
        }
    }
    return true;
}

void show(const Matrix& matrix) {
    for(size_t i=0;i<matrix.data.size();++i) {
        if (i>0 and i % matrix.n == 0) {
            cout<<std::endl;
        }
        cout<<matrix.data[i];
    }
}



Matrix T(Matrix m) {
    for (size_t i=0; i<m.n; ++i) {
        for (size_t j=i+1; j<m.n; ++j) {
            size_t a_index=get_index({i, j}, m.n);
            size_t b_index=get_index({j, i}, m.n);
            if (a_index != b_index) {
                char tmp = m.data[a_index];
                m.data[a_index]=m.data[b_index];
                m.data[b_index]=tmp;
            }
        }
    }
    return m;
}

Matrix D(Matrix m) {
    for (size_t i=0; i<m.n; ++i) {
        for (size_t j=0; j<m.n-i-1; ++j) {
            size_t a_index=get_index({i, j}, m.n);
            size_t b_index=get_index({m.n-j-1, m.n-i-1}, m.n);
            if (a_index != b_index) {
                char tmp = m.data[a_index];
                m.data[a_index]=m.data[b_index];
                m.data[b_index]=tmp;
            }
        }
    }
    return m;
}

Matrix H(Matrix m) {
    for (size_t i=0; i<m.n; ++i) {
        for (size_t j=0; j<m.n/2; ++j) {
            size_t a_index=get_index({i, j}, m.n);
            size_t b_index=get_index({i, m.n-j-1}, m.n);
            if (a_index != b_index) {
                char tmp = m.data[a_index];
                m.data[a_index]=m.data[b_index];
                m.data[b_index]=tmp;
            }
        }
    }
    return m;
}

Matrix V(Matrix m) {
    for (size_t i=0; i<m.n/2; ++i) {
        for (size_t j=0; j<m.n; ++j) {
            size_t a_index=get_index({i, j}, m.n);
            size_t b_index=get_index({m.n-i-1, j}, m.n);
            if (a_index != b_index) {
                char tmp = m.data[a_index];
                m.data[a_index]=m.data[b_index];
                m.data[b_index]=tmp;
            }
        }
    }
    return m;
}

Matrix A(const Matrix& m) {
    Matrix res=m;
    for (size_t i=0; i<m.n; ++i) {
        for (size_t j=0; j<m.n; ++j) {
            size_t a_index=get_index({i, j}, m.n);
            size_t b_index=get_index({j, m.n-i-1}, m.n);
            res.data[b_index]=m.data[a_index];
        }
    }
    return res;
}

Matrix B(const Matrix& m) {
    Matrix res=m;
    for (size_t i=0; i<m.n; ++i) {
        for (size_t j=0; j<m.n; ++j) {
            size_t a_index=get_index({i, j}, m.n);
            size_t b_index=get_index({m.n-i-1, m.n-j-1}, m.n);
            res.data[b_index]=m.data[a_index];
        }
    }
    return res;
}

Matrix C(const Matrix& m) {
    Matrix res=m;
    for (size_t i=0; i<m.n; ++i) {
        for (size_t j=0; j<m.n; ++j) {
            size_t a_index=get_index({i, j}, m.n);
            size_t b_index=get_index({m.n-j-1, i}, m.n);
            res.data[b_index]=m.data[a_index];
        }
    }
    return res;
}

Matrix X(const Matrix& m) {
    return C(m);
}

Matrix Y(const Matrix& m) {
    return B(m);
}

Matrix Z(const Matrix& m) {
    return A(m);
}

bool is_cmd_valid(char ch) {
    return ch=='T' or ch=='D' or ch=='H' or ch=='V' or
           ch=='A' or ch=='B' or ch=='C' or
           ch=='X' or ch=='Y' or ch =='Z';
}

bool is_cmds_valid(const string& cmd) {
    for (size_t i=0; i<cmd.size() and cmd[i]!='&'; ++i) {
        if (not is_cmd_valid(cmd[i])) {
            return false;
        }
    }
    return true;
}

bool read_test_data(Matrix& matrix, string& commands) {
    size_t matrix_dimension;
    cin>>matrix_dimension;
    string s;
    getline(cin, s);

    if (matrix_dimension>300) {
        cout<<"Error bad value matrix dimension ["<<matrix_dimension<<"]"<<endl;
        return false;
    }

    matrix.n=matrix_dimension;
    matrix.data.clear();
    for(size_t i=0; i<matrix_dimension; ++i) {
        string matrix_raw;
        getline(cin, matrix_raw);
        matrix.data+=matrix_raw;
    }
    if (not is_valid_matrix(matrix)) {
        cout<<"invalide matrix data"<<endl;
        return false;
    }

    commands.clear();
    getline(cin, commands);
    return is_cmds_valid(commands);
}

Matrix transformation(const Matrix& matrix, const string& cmds) {
    Matrix res=matrix;
    if (not is_valid_matrix(matrix)) {
        return Matrix{0,""};
    }
    if (not is_cmds_valid(cmds)) {
        return Matrix{0,""};
    }
    for (size_t i=0;i<cmds.size() and cmds[i]!='&'; ++i) {
        switch(cmds[i]) {
            case 'A':
            {
                res=A(res);
                break;
            }
            case 'B':
            {
                res=B(res);
                break;
            }
            case 'C':
            {
                res=C(res);
                break;
            }
            case 'D':
            {
                res=D(res);
                break;
            }
            case 'H':
            {
                res=H(res);
                break;
            }
            case 'T':
            {
                res=T(res);
                break;
            }
            case 'V':
            {
                res=V(res);
                break;
            }
            case 'X':
            {
                res=X(res);
                break;
            }
            case 'Y':
            {
                res=Y(res);
                break;
            }
            case 'Z':
            {
                res=Z(res);
                break;
            }
            default:
            {
                cout<<"Error unknown cmd"<<endl;
                return Matrix{0,""};
            }
        }
    }
    return res;
}

int main() {
    size_t numTests;
    cin>>numTests;

    if (numTests>20) {
       cout<<"Error tests count ["<<numTests<<"]"<<endl;
        return 1;
    }

    Matrix* matrixs = new Matrix[numTests];
    string* commands = new string[numTests];

    for(size_t tests_counter=0; tests_counter<numTests; ++tests_counter) {
        if (not read_test_data(matrixs[tests_counter], commands[tests_counter])) {
            cout<<"data read error for test ["<<tests_counter+1<<"]"<<endl;
            return 2;
        }
    }

    for(size_t tests_counter=0; tests_counter<numTests; ++tests_counter) {
        auto res = transformation(matrixs[tests_counter], commands[tests_counter]);
        show(res);
        cout<<endl;
    }

    delete [] matrixs;
    matrixs = NULL;

    delete [] commands;
    commands = NULL;

    return 0;
}
