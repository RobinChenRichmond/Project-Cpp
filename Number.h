#ifndef NUMBER_H
#define NUMBER_H

class Number
{
    protected:
      int decimal;

    public:

      Number();
      Number(int dec_value);
      
      // because this class can by used for polymorphism, make the
      // destructor virtual -- see, e.g.:
      // http://stackoverflow.com/questions/461203/when-to-use-virtual-destructors
      virtual ~Number();

      // pure virtual methods -- i.e., this class is abstract,
      // and these methods must be implemented by any extending class
      virtual int  getDecimalValue() = 0;
      virtual void setValue(int decimal_value) = 0;
};

#endif