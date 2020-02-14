#pragma once
#ifndef  __NEURAL_NETWORK__H
#define __NEURAL_NETWORK__H
#define E 2.71828

class Pattern2D
{

public:
	void setDesiredValue(float);
	Pattern2D(float, float);
	Pattern2D() {};
	float getX();
	float getY();
	void setX(float X);
	void setY(float Y);
	void setBias(float);
	int getClassID();
	float getDesiredValue();
	float getBias();
	void setClassID(int id);
private:
	int cid;
	float desired,X,Y,bias;

};
class Perceptron
{

public:
	float sgn_activation_function(float);
	float bipolar_sigmoid_function(float);
	float bipolar_sigmoid_function_derive(float);
	float s_sapma(int*, int);

};
class Renk
{
public:
	Renk(int, int, int);
	int getRed();
	int getGreen();
	int getBlue();

private:
	int Red,Green,Blue;


};




#endif // ! __NEURAL_NETWORK__H
