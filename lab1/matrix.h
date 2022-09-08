#ifndef MATRIX
#define MATRIX

#define OK 0
#define ERROR_READING_LINES 1
#define ERROR_READING_ROWS 2
#define ERROR_SIZE_MUST_BE_POSITIVE 3
#define ERROR_READING_MATRIX_ELEMS 4
#define ERROR_READING_NUMBER 5
#define ERROR_NUMBER_OUT_OF_RANGE 6
#define ELEMENT_ALREADY_EXISTS 7

namespace matrix {

const char ERROR_DESCRIPTION[5][100] =
{
    "OK",
    "Error reading lines",
    "Error reading rows",
    "Error size must be positive",
    "Error reading matrix elems"
};

struct NodeLine
{
    int rowNumber;
    int data;
    NodeLine *next;

    NodeLine(int, int, NodeLine*);

   ~NodeLine(); 
};

struct NodeMatrix
{
    int lineNumber;
    NodeLine *data;
    NodeMatrix *next;

    NodeMatrix(int, NodeMatrix*);

    ~NodeMatrix();
};

struct Matrix
{
    int lines;
    int rows;
    
    NodeMatrix *data;

    Matrix(int, int);
    
    ~Matrix();  
};

int readMatrix(Matrix*& matrix);

struct Result
{
    int len;
    double* data;

    Result(int);

    ~Result();
};

Result* countResult(Matrix* matrix);

void print(Matrix* matrix, Result* result);

} // namespace matrix

#endif

