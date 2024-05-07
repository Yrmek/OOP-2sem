//Дана вещественная квадратная матрица А порядка n.Составить функцию для
//получения матрицы B = А + А2 + А4 + А8

#include <iostream>
#include <time.h>
#include <iomanip>
#include <vector>

using namespace std;

void print_matrix(vector<vector<int>> matrix, int matrix_size)
{
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			cout << "|" << setw(3) << matrix[i][j] << "|";
		}
		cout << endl;
	}
}

void fill_matrix(vector<vector<int>>& matrix, int matrix_size)
{
	srand(time(NULL));
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			matrix[i][j] = rand() % 2;
		}
	}
	cout << "Entry matrix :" << endl;
	print_matrix(matrix, matrix_size);
}

vector<vector<int>> multiply_matrix(vector<vector<int>>matrix, int matrix_size)
{
	int sum = 0;
	vector<vector<int>> temp_matrix(matrix_size, vector<int>(matrix_size));

	for (int j = 0; j < matrix_size; j++)
	{
		for (int i = 0; i < matrix_size; i++)
		{
			sum = 0;
			for (int k = 0; k < matrix_size; k++)
			{
				sum += matrix[j][k] * matrix[k][i];
			}
			temp_matrix[j][i] = sum;
		}
	}
	return temp_matrix;
}

vector<vector<int>> matrix_pow(vector<vector<int>> matrix, int matrix_size, int power)
{
	int k_iter = log2(power);
	for (int i = 0; i < k_iter; i++)
	{
		matrix = multiply_matrix(matrix, matrix_size);
	}
	return matrix;
}

vector<vector<int>> sum_matrix(vector<vector<int>> matrix_1, vector<vector<int>> matrix_2, int matrix_size)
{
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			matrix_1[i][j] = matrix_1[i][j] + matrix_2[i][j];
		}
	}
	return matrix_1;
}

vector<vector<int>> get_result_matrix(vector<vector<int>> matrix, int matrix_size)
{
	return sum_matrix(sum_matrix(matrix_pow(matrix, matrix_size, 2), matrix, matrix_size), sum_matrix(matrix_pow(matrix, matrix_size, 4), matrix_pow(matrix, matrix_size, 8), matrix_size), matrix_size);
}

void main()
{
	int matrix_size = 0;
	cout << "enter a matrix size:" << endl;
	cin >> matrix_size;

	vector<vector<int>> matrix (matrix_size, vector<int>(matrix_size));
	
	fill_matrix(matrix, matrix_size);
	matrix = get_result_matrix(matrix, matrix_size);
	cout << "final matrix :" << endl;
	print_matrix(matrix, matrix_size);

}