#include "matrix.h"

#include <iostream>
#include <climits>

using namespace matrix;

Matrix::Matrix(int lines, int rows)
    : lines(lines)
    , rows(rows)
{
   data = nullptr;
}

NodeMatrix::NodeMatrix(int lineNumber, NodeMatrix* next)
    : lineNumber(lineNumber)
    , next(next)
{
    next = nullptr;
    data = nullptr;
}

NodeLine::NodeLine(int rowNumber, int data, NodeLine* next)
    : rowNumber(rowNumber)
    , data(data)
    , next(next) 
{ }

Result::Result(int len)
    :len(len)
{
    data = new double[len];
    for (int i = 0; i < len; ++i) {
        data[i] = 0;
    }
}

Result::~Result() {
    delete[] data;
}

NodeLine::~NodeLine() {
    if (next) {
        next->~NodeLine();
    }
}

NodeMatrix::~NodeMatrix() {
    if (data) {
        data->~NodeLine();
    }
    if (next) {
        next->~NodeMatrix();
    }
}

Matrix::~Matrix() {
    if (data) {
        data->~NodeMatrix();
    }
}


int readLinesRows(int& lines, int& rows) 
{
    std::cout << "Enter lines count\n";
    std::cin >> lines;
    if (!std::cin.good()) {
        return ERROR_READING_LINES;
    }
    if (lines <= 0) {
        return ERROR_SIZE_MUST_BE_POSITIVE;
    }
    std::cout << "Enter rows count\n";
    std::cin >> rows;
    if (!std::cin.good()) {
        return ERROR_READING_ROWS;
    }
    if (rows <= 0) {
        return ERROR_SIZE_MUST_BE_POSITIVE;
    }
    return OK;
}

int readInt(int& what, int min = INT_MIN, int max = INT_MAX)
{
    std::cin >> what;
    if (!std::cin.good()) {
        return ERROR_READING_NUMBER;
    }
    if (!(min <= what && what <= max)) {
        std::cout << "You enter (" << what << ") which is not in [" << min << ", " << max << "]\n";
        return ERROR_NUMBER_OUT_OF_RANGE;
    }
    return OK;
}

int readElement(int& line, int& row, int& val, int line_max, int row_max) {
    std::cout << "Enter line of new element\n";
    int codeError = readInt(line, 0, line_max);
    if (codeError == ERROR_READING_NUMBER) {
        return ERROR_READING_NUMBER;
    }
    if (codeError == ERROR_NUMBER_OUT_OF_RANGE) {
        return ERROR_NUMBER_OUT_OF_RANGE;
    }
    std::cout << "Enter row of new element\n";
    codeError = readInt(row, 0, row_max);
    if (codeError == ERROR_READING_NUMBER) {
        return ERROR_READING_NUMBER;
    }
    if (codeError == ERROR_NUMBER_OUT_OF_RANGE) {
        return ERROR_NUMBER_OUT_OF_RANGE;
    }
    std::cout << "Enter value of new element\n";
    codeError = readInt(val);
    if (codeError == ERROR_READING_NUMBER) {
        return ERROR_READING_NUMBER;
    }
    return OK;
}

int insert(Matrix& matrix, int line, int row, int val)
{
    NodeMatrix* myLine = matrix.data;
    NodeMatrix* prevLine = nullptr;
    while (myLine) {
        if (myLine->lineNumber >= line) {
            break;
        }
        prevLine = myLine;
        myLine = myLine->next;
    }
    if (!(myLine && myLine->lineNumber == line)) {
        NodeMatrix* newLine = new NodeMatrix(line, myLine);
        if (!prevLine) {
            matrix.data = newLine;
        } else {
            prevLine->next = newLine;
        }
        myLine = newLine;
    } // now actual line in myLine
    
    NodeLine* myRow = myLine->data;
    NodeLine* prevRow = nullptr;
    while (myRow) {
        if (myRow->rowNumber >= row) {
            break;
        }
        prevRow = myRow;
        myRow = myRow->next;
    } 
    if (!(myRow && myRow->rowNumber == row)) {
        NodeLine* newRow = new NodeLine(row, val, myRow);
        if (!prevRow) {
            myLine->data = newRow;
        } else {
            prevRow->next = newRow;
        }
    } else {
        return ELEMENT_ALREADY_EXISTS;
    }
    return OK;
}

int readElems(Matrix& matrix)
{
    while(true) {
        std::cout << "Enter 0 to finish input\n";
        std::cout << "Enter 1 to write new element\n";
        int choise;
        int codeError = readInt(choise, 0, 1);
        if (codeError == ERROR_READING_NUMBER) {
            return ERROR_READING_MATRIX_ELEMS;
        }
        if (codeError == ERROR_NUMBER_OUT_OF_RANGE) {
            continue;
        }
        if (choise == 0) {
            break;
        }
        int line, row, val;
        codeError = readElement(line, row, val, matrix.lines - 1, matrix.rows - 1);
        if (codeError == ERROR_READING_NUMBER) {
            return ERROR_READING_MATRIX_ELEMS;
        }
        if (codeError == ERROR_NUMBER_OUT_OF_RANGE) {
            continue;
        }
        codeError = insert(matrix, line, row, val);
        if (codeError == ELEMENT_ALREADY_EXISTS) {
            std::cout << "Number at this position already exists!\n";
            continue;
        }
        std::cout << "Element " << val << " inserted at (" << line << ", " << row << ")\n";
    }
    return OK;
}
        
int matrix::readMatrix(Matrix*& matrix)
{
    int lines, rows;
    int codeError = readLinesRows(lines, rows);
    if (codeError) {
        return codeError;
    }
    matrix = new Matrix(lines, rows);
    codeError = readElems(*matrix);
    if (codeError) {
        return codeError;
    }
    return OK;
}

Result* matrix::countResult(Matrix* matrix)
{
    Result* result = new Result(matrix->lines);
    NodeMatrix* nowLine = matrix->data;
    long long minCi = 0;
    long long maxCi = 0;
    bool empty = 1;
    while (nowLine) {
        long long Ci = 0;
        NodeLine* elem = nowLine->data;
        while (elem) {
            Ci += elem->data;
            elem = elem->next;
        }
        if (empty == 1) {
            empty = 0;
            minCi = maxCi = Ci;
        } else {
            minCi = std::min(minCi, Ci);
            maxCi = std::max(maxCi, Ci);
        }
        result->data[nowLine->lineNumber] = Ci;
        nowLine = nowLine->next;
    }
    for (int i = 0; i < matrix->lines; ++i) {
        if (minCi == maxCi) {
            result->data[i] = -1;
        } else {
            result->data[i] = (result->data[i] - minCi) / (double)(maxCi - minCi);
        }
    }
    return result;
}

void printLine(NodeMatrix* line, int rows) {
    int nowRowId = 0;
    NodeLine* nowRow = nullptr;
    if (line) {
        nowRow = line->data;
    }
    while (nowRow) {
        while(nowRowId < nowRow->rowNumber) {
            std::cout << "0 ";
            ++nowRowId;
        }
        std::cout << nowRow->data << " ";
        ++nowRowId;
        nowRow = nowRow->next;
    }
    while (nowRowId < rows) {
        std::cout << "0 ";
        ++nowRowId;
    }
    std::cout << '\n';
}

void matrix::print(Matrix* matrix, Result* result)
{
    std::cout << "Matrix:\n";
    int nowLineId = 0;
    NodeMatrix *nowLine = matrix->data;
    while (nowLine) {
        while (nowLineId < nowLine->lineNumber) {
            printLine(nullptr, matrix->rows);
            ++nowLineId;
        }
        printLine(nowLine, matrix->rows);
        nowLine = nowLine->next;
        ++nowLineId;
    }
    while (nowLineId < matrix->lines) {
        printLine(nullptr, matrix->rows);
        ++nowLineId;
    }
    std::cout << "Vector B:\n";
    for (int i = 0; i < result->len; ++i) {
        if (result->data[i] < -0.5) { // answer >= 0. -1 if dividing by zero
            std::cout << "nan ";
        } else {
            std::cout << result->data[i] << " ";
        }
    }
    std::cout << std::endl;
}

