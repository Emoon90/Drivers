/*
 * polynomial.c
 *
 * Created: 11/2/2017 2:41:16 PM
 *  Author: eman samy
 */ 

#include "polynomial.h"

float inverse[12][12];
static int k=3;
static int l=5;
void polynomial_app(void)
{
	float a[12][12],d,transpose_x[12][12],transpose_y[12][12],A[12][12],B[12][12],C[12][12],sum;
	float x[12]={1,2,3,4,5};
	float m_y[12]={2,4,6,8,10};	
	int i, j,c,exponent;
	long result=1;

	//printf("Matrix\n");
	for (i = 0;i < l; i++)
	{
		exponent=k-1;
		for (j = 0;j < k; j++)
		{
			exponent =k-1-j;
			if(exponent == 0)
			{
				result=1;
			}
			while (exponent != 0)
			{

				result *= x[i];
				--exponent;
			}

			a[i][k-1-j]=result;
			result=1;
		}

		
	}

	for (i = 0;i < l; i++) {
		for (j = 0;j < k; j++)
		{
			transpose_x[j][i] = a[i][j];
		}
	}
	

	for (i = 0;i < l; i++) {
		for (j = 0;j < 1; j++)
		{
			transpose_y[j][i] = m_y[i];
		}
	}
	
	for (c = 0; c < k; c++) {
		for (i = 0; i < k; i++) {
			for (j = 0; j < l; j++) {
				sum = sum + transpose_x[c][j]*a[j][i];
			}
			A[c][i] = sum;
			sum = 0;
		}
	}

	//printf("\nB=transpose_x *y \n");
	for (c = 0; c < k; c++) {
		for (i = 0; i <=1 ; i++) {
			for (j = 0; j < l; j++) {
				sum = sum + transpose_x[c][j]*m_y[j];
			}
			B[c][0] = sum;
			//lcd_fnum(0,16*(c+1),B[c][0],1,1,ON);

			sum = 0;
		}
	}

	d = determinant(A,k);
	if (d == 0)
		return 1;
	//printf("\nInverse of Entered Matrix is not possible\n");
	else
	cofactor(A, k);

	//printf("\nC=A*inverseB \n");
	for (c = 0; c < k; c++) {
		for (i = 0; i <= 1; i++) {
			for (j = 0; j < k; j++) {
				sum = sum + inverse[c][j]*B[j][i];
			}
			// printf("%.0f\t",sum);
			C[c][0] = sum;
			glcd_text57(1,1,"C",1,ON);
			lcd_fnum(0,16*(c+1),C[c][0],1,1,ON);
			sum = 0;
		}
		//printf("C[%d][1]=%f\t",c,C[c][1]);
		//printf("\n");
	}
	
}

/*For calculating Determinant of the Matrix */
float determinant(float a[12][12], float k)
{
	float s = 1, det = 0, b[12][12];
	int i, j, m, n, c;
	if (k == 1)
	{
		return (a[0][0]);
	}
	else
	{
		det = 0;
		for (c = 0; c < k; c++)
		{
			m = 0;
			n = 0;
			for (i = 0;i < k; i++)
			{
				for (j = 0 ;j < k; j++)
				{
					b[i][j] = 0;
					if (i != 0 && j != c)
					{
						b[m][n] = a[i][j];
						if (n < (k - 2))
						n++;
						else
						{
							n = 0;
							m++;
						}
					}
				}
			}
			det = det + s * (a[0][c] * determinant(b, k - 1));
			s = -1 * s;
		}
	}

	return (det);
}

void cofactor(float num[12][12], float f)
{
	float b[12][12], fac[12][12];
	int p, q, m, n, i, j;
	for (q = 0;q < f; q++)
	{
		for (p = 0;p < f; p++)
		{
			m = 0;
			n = 0;
			for (i = 0;i < f; i++)
			{
				for (j = 0;j < f; j++)
				{
					if (i != q && j != p)
					{
						b[m][n] = num[i][j];
						if (n < (f - 2))
						n++;
						else
						{
							n = 0;
							m++;
						}
					}
				}
			}
			fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
		}
	}
	transpose(num, fac, f);
}

/*Finding transpose of matrix*/
void transpose(float num[12][12], float fac[12][12], float r)
{
	int i, j;
	float b[12][12], multiply[12],d,sum;

	for (i = 0;i < r; i++)
	{
		for (j = 0;j < r; j++)
		{
			b[i][j] = fac[j][i];
		}
	}
	d = determinant(num, r);
	for (i = 0;i < r; i++)
	{
		for (j = 0;j < r; j++)
		{
			inverse[i][j] = b[i][j] / d;
		}
	}
	//printf("\n\n\nThe inverse of matrix is : \n");

	for (i = 0;i < r; i++)
	{
		for (j = 0;j < r; j++)
		{
		//	printf("\t%f", inverse[i][j]);
		}
		//printf("\n");
	}
}
