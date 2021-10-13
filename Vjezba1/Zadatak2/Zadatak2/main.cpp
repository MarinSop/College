#include <iostream>
#include <time.h>
#include <iomanip>

struct Matrix
{
	int rows = 0;
	int cols = 0;
	float** arr;
};

void createMatrix(Matrix* mat)
{
	std::cout << "Upisi broj redova" << std::endl;
	std::cin >> mat->rows;
	std::cout << "Upisi broj stupaca" << std::endl;
	std::cin >> mat->cols;
	mat->arr = new float* [mat->rows];
	for (int i = 0; i < mat->rows; i++)
	{
		mat->arr[i] = new float[mat->cols];
	}
}

void inputMatrix(Matrix* mat)
{
	int a;
	int b;
	std::cout << "Unesi prvi broj raspona" << std::endl;
	std::cin >> a;
	std::cout << "Unesi drugi broj raspona" << std::endl;
	std::cin >> b;
	int max = a > b ? a : b;
	int min = a < b ? a : b;
	for (int i = 0; i < mat->rows; i++)
	{
		for (int j = 0; j < mat->cols; j++)
		{
			mat->arr[i][j] = rand() % (max+1-min)+min;
		}
	}

}

Matrix sumOfMatrix(Matrix* matA, Matrix* matB)
{
	if (matA->rows != matB->rows || matB->cols != matB->cols)
	{
		std::cout << "Impossible!" << std::endl;
		return *matA;
	}
	Matrix res;
	res.rows = matA->rows;
	res.cols = matA->cols;
	res.arr = new float* [matA->rows];
	for (int i = 0; i < matA->rows; i++)
	{
		res.arr[i] = new float[matA->cols];
	}
	for (int i = 0; i < matA->rows; i++)
	{
		for (int j = 0; j < matA->cols; j++)
		{
			res.arr[i][j] = matA->arr[i][j] + matB->arr[i][j];
		}
		std::cout << std::endl;
	}
	return res;
}

Matrix subtractionOfMatrix(Matrix* matA, Matrix* matB)
{
	if (matA->rows != matB->rows || matB->cols != matB->cols)
	{
		std::cout << "Impossible!" << std::endl;
		return *matA;
	}
	Matrix res;
	res.rows = matA->rows;
	res.cols = matA->cols;
	res.arr = new float* [matA->rows];
	for (int i = 0; i < matA->rows; i++)
	{
		res.arr[i] = new float[matA->cols];
	}
	for (int i = 0; i < matA->rows; i++)
	{
		for (int j = 0; j < matA->cols; j++)
		{
			res.arr[i][j] = matA->arr[i][j] - matB->arr[i][j];
		}
		std::cout << std::endl;
	}
	return res;
}


Matrix multiplicationMatrix(Matrix* matA, Matrix* matB)
{
	if (matA->cols != matB->rows)
	{
		std::cout << "Impossible!" << std::endl;
		return *matA;
	}
	Matrix res;
	res.cols = matB->cols;
	res.rows = matA->rows;
	res.arr = new float* [res.rows]; 
	for (int i = 0; i < res.rows; i++)
	{
		res.arr[i] = new float[res.cols];
	}
	for (int i = 0; i < matA->rows; i++) {
		for (int j = 0; j < matB->cols; j++) {
			res.arr[i][j] = 0;
			for (int k = 0; k < matA->cols; k++)
				res.arr[i][j] += matA->arr[i][k] * matB->arr[k][j];
		}
	}
	return res;
}

Matrix transposeMatrix(Matrix* mat)
{
	Matrix res;
	res.rows = mat->cols;
	res.cols = mat->rows;
	res.arr = new float* [res.rows];
	for (int i = 0; i < res.rows; i++)
	{
		res.arr[i] = new float[res.cols];
	}
	int x = 0;
	int y = 0;
	for (int i = 0; i < mat->cols; i++)
	{
		for (int j = 0; j < mat->rows; j++)
		{
			res.arr[x][y] = mat->arr[j][i];
			++y;
		}
		++x;
		y = 0;
	}
	return res;
}



void matrixOutput(Matrix* mat)
{
	for (int i = 0; i < mat->rows; i++)
	{
		for (int j = 0; j < mat->cols; j++)
		{
			std::cout.precision(4);
			std::cout << "[ " << std::fixed << mat->arr[i][j] << " ]  ";
		}
		std::cout << std::endl;
	}
}


int main()
{
	srand(time(NULL));
	std::cout << "MATRIX A" << std::endl;
	Matrix matA;
	createMatrix(&matA);
	inputMatrix(&matA);
	matrixOutput(&matA);

	std::cout << "MATRIX B" << std::endl;
	Matrix matB;
	createMatrix(&matB);
	inputMatrix(&matB);
	matrixOutput(&matB);

	std::cout << "--------SUM OF MATRIX's---------" << std::endl;
	Matrix sumMat = sumOfMatrix(&matA, &matB);
	matrixOutput(&sumMat);
	
	std::cout << "--------SUBTRACTION OF MATRIX's---------" << std::endl;
	Matrix subMat = subtractionOfMatrix(&matA, &matB);
	matrixOutput(&subMat);

	std::cout << "--------MULTIPLICATION OF MATRIX's---------" << std::endl;
	Matrix multMat = multiplicationMatrix(&matA, &matB);
	matrixOutput(&multMat);

	std::cout << "--------TRANSPOE MATRIX---------" << std::endl;
	Matrix transMat = transposeMatrix(&matA);
	matrixOutput(&transMat);


}