class A
{
public:
	int a1;
	void methodA();
private:
	int a2;
protected:
	int a3;
};

class B : public A
{
public:
	int b1;
	void methodB();
private:
	int b2;
protected:
	int b3;
};

class C : public B
{
public:
	int c1;
	void methodC();
private:
	int c2;
protected:
	int c3;
};