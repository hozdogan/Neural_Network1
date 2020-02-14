#pragma once
#ifndef  PATTERN_H
#define  PATTERN_H

class Pattern
{
public:
	
	Pattern(float*, int);
	Pattern(int);
	float getInputElem(int);
	void setInputElem(int, float);
	float getOutputElem(int);
	void setOutputElem(int, float);
	float getNormElem(int);
	void setNormElem(int, float);
	int getSize();
	
private:
	int cid, Size;
	float desired, bias;
	float* Inputs;
	float* NormInputs;
	float* Outputs;


};

#endif // ! PATTERN_H