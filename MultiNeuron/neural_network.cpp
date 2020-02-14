#include "neural_network.h"


#include <iostream>
using namespace std;

Pattern2D::Pattern2D(float x, float y)
{
	this->X = x;
	this->Y = y;
	

}
void Pattern2D::setDesiredValue(float d)
{
	desired = d;
}
float Pattern2D::getX()
{
	return X;
}
void Pattern2D::setX(float X)
{
	this->X = X;
}
void Pattern2D::setY(float Y)
{
	this->Y = Y;
}
float Pattern2D::getY()
{
	return Y;
}
float Pattern2D::getBias()
{
	return bias;
}
void Pattern2D::setBias(float bias)
{
	this->bias = bias;
}
float Pattern2D::getDesiredValue()
{
	return desired;
}
void Pattern2D::setClassID(int id)
{
	this->cid = id;
}
int Pattern2D::getClassID()
{
	return cid;
}
///perceptron class

float Perceptron::sgn_activation_function(float net)
{
	if (net < 0)
	{
		return -1.0f;
	}
	else if (net > 0)
	{
		return 1.0f;
	}
}
float Perceptron::s_sapma(int* a, int argc)
{
	int ort, sum = 0, ortsum = 0;
	for (int i = 0; i < argc; i++)
	{
		sum += a[i];
	}
	ort = sum / argc;
	for (int i = 0; i < argc; i++)
	{
		ortsum += (a[i]-ort)*(a[i]-ort);
	}
	ortsum = ortsum / (argc);
	return sqrt(ortsum);

}
float Perceptron::bipolar_sigmoid_function(float net)
{
	return tanhf(net);
}
float Perceptron::bipolar_sigmoid_function_derive(float net)
{
	return (1 - (net * net))/2;
	
}



Renk::Renk(int r, int g, int b)
{
	this->Red = r;
	this->Green = g;
	this->Blue = b;
}
int Renk::getRed()
{
	return Red;
}
int Renk::getGreen(){
	return Green;
}
int Renk::getBlue() {
	return Blue;
}




