class Animal
{
    public:
        // Factory Method
        static Animal *create_animal(int choice);
        virtual void make_noise() = 0;
};

class Bird : public Animal
{
    public:
        void make_noise()
        {
            std::cout << "Bird: chirp" << std::endl;
        }
};

class Cat : public Animal
{
    public:
        void make_noise()
        {
            std::cout << "Cat: meow" << std::endl;
        }
};

class Dog : public Animal
{
    public:
        void make_noise()
        {
            std::cout << "Dog: bark" << std::endl;
        }
};

Animal *Animal::create_animal(int choice)
{
    if (choice == 1)
    {
        return new Cat;
    }
    else if (choice == 2)
    {
        return new Dog;
    }
    else
    {
        return new Bird;
    }
}