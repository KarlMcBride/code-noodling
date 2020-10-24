#include <iostream>
#include <memory>

class rectangle
{
    public:
        rectangle(int width, int height): m_width(width), m_height(height), m_area(width * height) { }

        ~rectangle() { std::cout << "Deconstructor called (area " << m_area << ")" << std::endl; };

        int area()
        {
            return m_area;
        }

    private:
        int m_width;
        int m_height;
        int m_area;
};

int main()
{
    // Unique pointers - only a single pointer can point to the instance of the object.
    // Ownership can be transfered with move function.
    std::unique_ptr<rectangle> unique_ptr_rectangle_1(new rectangle(2, 2));
    std::cout << "unique_ptr_rectangle_1 area: " << unique_ptr_rectangle_1->area() << std::endl;

    std::unique_ptr<rectangle> unique_ptr_rectangle_2(new rectangle(3, 3));
    std::cout << "unique_ptr_rectangle_2 area: " << unique_ptr_rectangle_2->area() << std::endl;

    std::unique_ptr<rectangle> unique_ptr_rectangle_3;
    unique_ptr_rectangle_3 = std::move(unique_ptr_rectangle_2);
    std::cout << "unique_ptr_rectangle_3 area: " << unique_ptr_rectangle_3->area() << std::endl;


    // Shared pointers - more than one pointer can point to the instance of the object.
    // A reference counter will be maintained, and the object disposed when all references no longer exist.
    std::shared_ptr<rectangle> shared_ptr_rectangle_1(new rectangle(4, 4));
    std::cout << "shared_ptr_rectangle_1 area: " << shared_ptr_rectangle_1->area() << std::endl;
    std::cout << "use count: " << shared_ptr_rectangle_1.use_count() << std::endl;

    std::shared_ptr<rectangle> shared_ptr_rectangle_2 = shared_ptr_rectangle_1;
    std::cout << "shared_ptr_rectangle_2 area: " << shared_ptr_rectangle_1->area() << std::endl;
    std::cout << "use count: " << shared_ptr_rectangle_1.use_count() << std::endl;

    return 0;
}