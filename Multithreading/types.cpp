#include <iostream>
#include <thread>

// 2. Lambda Function
// Example

/* int main()
{

    std::thread t([](int x)
                  {
        while(x-- > 0){
            std::cout << x << std::endl;
        } }, 10);
    t.join();

    return 0;
} */

// 3. Functor (Fucntion Object)

/* class Base
{
public:
    void operator()(int x)
    {
        while (x-- > 0)
        {
            std::cout << x << std::endl;
        }
    }
};

int main()
{
    std::thread t((Base()), 10);
    t.join();
    return 0;
} */

// 4. Non-static member function

/* class Base
{
public:
    void run(int x)
    {
        while (x-- > 0)
        {
            std::cout << x << std::endl;
        }
    }
};

int main()
{
    Base b;
    std::thread t(&Base::run, &b, 10);
    t.join();
    return 0;
} */

// 5. Staic member function

class Base
{
public:
    static void run(int x)
    {
        while (x-- > 0)
        {
            std::cout << x << std::endl;
        }
    }
};

int main()
{
    Base b;
    std::thread t(&Base::run, 10);
    t.join();
    return 0;
}