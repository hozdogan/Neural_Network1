#include <iostream>
#include "Pattern.h"

using namespace std;

Pattern::Pattern(float* inputVector, int Size)
{
	this->Size = Size;
	Inputs = new float[Size];
	NormInputs = new float[Size];
	for (int i = 0; i < Size; i++)
	{
		this->Inputs[i] = inputVector[i];
	}
}
Pattern::Pattern(int Size)
{
	this->Size = Size;
	Inputs = new float[Size];
	Outputs = new float[Size];
	NormInputs = new float[Size];
}
float Pattern::getOutputElem(int index)
{
	return Outputs[index];
}
void Pattern::setOutputElem(int index, float elem)
{
	this->Outputs[index] = elem;
}
float Pattern::getInputElem(int index)
{
	return Inputs[index];
}
void Pattern::setInputElem(int index, float elem)
{
	this->Inputs[index] = elem;
}



float Pattern::getNormElem(int index)
{
	return NormInputs[index];
}
void Pattern::setNormElem(int index, float elem)
{
	this->NormInputs[index] = elem;
}
int Pattern::getSize()
{
	return Size;
}