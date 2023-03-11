class MyClass
{
public:
    MyClass();

    MyClass(const MyClass& other);

    ~MyClass();

    friend void friendFunction(MyClass obj);
};



