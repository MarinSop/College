#include <iostream>
#include <time.h>
#include <iomanip>

struct Matrix
{
	int rows = 0;
	int cols = 0;
	float** arr;

	void createMatrix()
	{
		std::cout << "Upisi broj redova" << std::endl;
		std::cin >> rows;
		std::cout << "Upisi broj stupaca" << std::endl;
		std::cin >> cols;
		arr = new float* [rows];
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new float[cols];
		}
	}

	void inputMatrix()
	{
		int a;
		int b;
		std::cout << "Unesi prvi broj raspona" << std::endl;
		std::cin >> a;
		std::cout << "Unesi drugi broj raspona" << std::endl;
		std::cin >> b;
		int max = a > b ? a : b;
		int min = a < b ? a : b;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i][j] = rand() % (max + 1 - min) + min;
			}
		}

	}

	Matrix sumOfMatrix(Matrix* matB)
	{
		if (rows != matB->rows || matB->cols != matB->cols)
		{
			std::cout << "Impossible!" << std::endl;
			return Matrix();
		}
		Matrix res;
		res.rows = rows;
		res.cols = cols;
		res.arr = new float* [rows];
		for (int i = 0; i < rows; i++)
		{
			res.arr[i] = new float[cols];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				res.arr[i][j] = arr[i][j] + matB->arr[i][j];
			}
			std::cout << std::endl;
		}
		return res;
	}

	Matrix subtractionOfMatrix( Matrix* matB)
	{
		if (rows != matB->rows || matB->cols != matB->cols)
		{
			std::cout << "Impossible!" << std::endl;
			return Matrix();
		}
		Matrix res;
		res.rows = rows;
		res.cols = cols;
		res.arr = new float* [rows];
		for (int i = 0; i < rows; i++)
		{
			res.arr[i] = new float[cols];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				res.arr[i][j] = arr[i][j] - matB->arr[i][j];
			}
			std::cout << std::endl;
		}
		return res;
	}


	Matrix multiplicationMatrix( Matrix* matB)
	{
		if (cols != matB->rows)
		{
			std::cout << "Impossible!" << std::endl;
			return Matrix();
		}
		Matrix res;
		res.cols = matB->cols;
		res.rows = rows;
		res.arr = new float* [res.rows];
		for (int i = 0; i < res.rows; i++)
		{
			res.arr[i] = new float[res.cols];
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < matB->cols; j++) {
				res.arr[i][j] = 0;
				for (int k = 0; k < cols; k++)
					res.arr[i][j] += arr[i][k] * matB->arr[k][j];
			}
		}
		return res;
	}

	Matrix transposeMatrix()
	{
		Matrix res;
		res.rows = cols;
		res.cols = rows;
		res.arr = new float* [res.rows];
		for (int i = 0; i < res.rows; i++)
		{
			res.arr[i] = new float[res.cols];
		}
		int x = 0;
		int y = 0;
		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				res.arr[x][y] = arr[j][i];
				++y;
			}
			++x;
			y = 0;
		}
		return res;
	}



	void matrixOutput()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				std::cout.precision(4);
				std::cout << "[ " << std::fixed << arr[i][j] << " ]  ";
			}
			std::cout << std::endl;
		}
	}
};


int main()
{
	srand(time(NULL));
	std::cout << "MATRIX A" << std::endl;
	Matrix matA;
	matA.createMatrix();
	matA.inputMatrix();
	matA.matrixOutput();

	std::cout << "MATRIX B" << std::endl;
	Matrix matB;
	matB.createMatrix();
	matB.inputMatrix();
	matB.matrixOutput();

	std::cout << "--------SUM OF MATRIX's---------" << std::endl;
	Matrix sumMat = matA.sumOfMatrix(&matB);
	sumMat.matrixOutput();
	
	std::cout << "--------SUBTRACTION OF MATRIX's---------" << std::endl;
	Matrix subMat = matA.subtractionOfMatrix(&matB);
	subMat.matrixOutput();

	std::cout << "--------MULTIPLICATION OF MATRIX's---------" << std::endl;
	Matrix multMat = matA.multiplicationMatrix(&matB);
	multMat.matrixOutput();

	std::cout << "--------TRANSPOE MATRIX---------" << std::endl;
	Matrix transMat = matA.transposeMatrix();
	transMat.matrixOutput();


}