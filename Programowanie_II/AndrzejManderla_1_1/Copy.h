class WithCopy 
{
public:
    int* ptr;
    WithCopy();
    WithCopy(const WithCopy& other);
    ~WithCopy();
};

class WithoutCopy
{
public:
    int* ptr;
    WithoutCopy();
};