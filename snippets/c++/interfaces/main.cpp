#include <iostream>

// Base class
class Shape
{
    public:
        virtual int get_area() = 0;
        void set_width(int _width)
        {
            width = _width;
        }

        void set_height(int _height)
        {
            height = _height;
        }

    protected:
        int width;
        int height;
};

class Rectangle: public Shape
{
    public:
        int get_area()
        {
            return (width * height);
        }
};

class Triangle: public Shape
{
    public:
        int get_area()
        {
            return (width * height) / 2;
        }
};

int main(void)
{
    Rectangle rectangle;
    Triangle  triangle;

    rectangle.set_width(3);
    rectangle.set_height(5);

    std::cout << "Total rectangle area: " << rectangle.get_area() << std::endl;

    triangle.set_width(3);
    triangle.set_height(6);

    std::cout << "Total triangle area: " << triangle.get_area() << std::endl;

    return 0;
}