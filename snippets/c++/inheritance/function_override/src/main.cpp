#include <iostream>

class Father
{
    public:
        virtual ~Father() {}

        void start()
        {
            this->init();
        };

        virtual void init () const
        {
            std::cout << "I'm the father" << std::endl;
        };
};

class Child: public Father
{
    void init() const override
    {
        std::cout << "I'm the child" << std::endl;
    };
};

int main()
{
    Father father;
    father.start();

    Child child;
    child.start();

    return 0;
}