#include <iostream>
#include <string>

// Base class
class BaseClass
{
   public:

   protected:
      template <typename Type> void wasabi(Type _input)
      {
         std::cout << "Base class received [" << _input << "]" << std::endl;
      }
};

class DerivedClass: public BaseClass
{
   public:
      void CallWasabi()
      {
         wasabi(_input);
      }

   protected:
      std::string _input = "DerivedClassString";
};

int main(void)
{
   DerivedClass derv;
   derv.CallWasabi();

   return 0;
}
