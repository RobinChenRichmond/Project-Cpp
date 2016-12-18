#include "Number.h"

// implementation of default constructor -- just set the int value to 0
Number::Number() : decimal(0) {}

// implemenation of non-default constructor -- set int value using given value
Number::Number(int dec_value) : decimal(dec_value) {}

Number::~Number() {}