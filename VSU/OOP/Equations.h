#include <iostream>

class Root {
protected:
	double* coefs;
	double* roots;
	bool is_massive = 0;

	virtual void root() = 0;
public:
	Root();
	Root(double, double);
	Root(double, double, double);
	~Root();

	double* getCoefs();
	double* getRoots();
	void setCoefs(double *);

	virtual std::string getAnswer() = 0;
	virtual void input() = 0;
	virtual std::string to_string() = 0;
};

class Linear : public Root {
	void root();
public:
	Linear();
	Linear(double, double);
 
	std::string getAnswer();
	void input();
	std::string to_string();
};

class Square : public Root {
	void root();
public:
	Square();
	Square(double, double, double); 

	std::string getAnswer();
	void input();
	std::string to_string();
};