/*
 * polynomial.h
 *
 * Created: 11/2/2017 2:41:43 PM
 *  Author: eman samy
 */ 


#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
#include "GLCD.h"
#include <util/delay.h>

void polynomial_app(void);
float determinant(float [][12], float);
void cofactor(float [][12], float);
void transpose(float [][12], float [][12], float);

#endif /* POLYNOMIAL_H_ */