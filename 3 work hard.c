struct Matrix
{
    float ** matrix;
    int n;
    int m;
};

Matrix newMatrix(int N, int M)
{
    Matrix m;
    m.matrix = new float*[N];
    for (int i = 0; i < N; ++i)    
        m.matrix[i] = new float[M];
    m.n = N;
    m.m = M;
    return m;
}
// удаление
void deleteMatrix(Matrix& m)
{
    for (int i = 0; i < m.n; ++i)
        delete[] m.matrix[i];
    delete[] m.matrix;
    m.matrix = nullptr;
    m.n = 0;
    m.m = 0;
}
// максимальный элемент матрицы
float max(const Matrix& m)
{
    float max = m.matrix[0][0];
    for (int i = 0; i < m.n; ++i)
        for (int j = 0; j < m.m; ++j)
            if (m.matrix[i][j] >= max)
                max = m.matrix[i][j];      
    return max;
}
// минимальный элемент
float min(const Matrix& m)
{
    float min = m.matrix[0][0];
    for (int i = 0; i < m.n; ++i)
        for (int j = 0; j < m.m; ++j)
            if (m.matrix[i][j] <= min)
                min = m.matrix[i][j];
    return min;
}

// копия матрицы
Matrix copy(const Matrix& m)
{
    Matrix copymatr = newMatrix(m.n, m.m);
    for (int i = 0; i < m.n; ++i)
        for (int j = 0; j < m.m; ++j)
            copymatr.matrix[i][j] = m.matrix[i][j];
    return copymatr;
}
// транспонирование матрицы 
void transpose(const Matrix& m)
{
    for (int i = 0; i < m.n; ++i)
        for (int j = i + 1; j < m.m; ++j)
            std::swap(m.matrix[i][j], m.matrix[j][i]);
}
// перемножение матриц
Matrix operator*(const Matrix& m, const Matrix& m1)
{
    Matrix pr = newMatrix(m.n, m1.m);
    for (int i = 0; i < m.n; i++)
        for (int j = 0; j < m1.m; j++)
            for (int k = 0; k < m1.n; k++)
                pr.matrix[i][j] += m.matrix[i][k] * m1.matrix[k][j];
    return pr;
}
// умножение матрица на число 
Matrix operator*(const Matrix& m, float n)
{
    for (int i = 0; i < m.n; ++i)
        for (int j = 0; j < m.n; ++j)        
            m.matrix[i][j] *= n;
    return m;
}
// сложение матриц
Matrix operator+(const Matrix& m, const Matrix& m1)
{
    Matrix sum = newMatrix(m.n, m1.m);
    for (int i = 0; i < m.n; i++)
        for (int j = 0; j < m1.m; j++)         
                sum.matrix[i][j] = m.matrix[i][j] + m1.matrix[i][j];
    return sum;
}