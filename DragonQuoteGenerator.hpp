#ifndef __DRAGON_QUOTE_GENERATOR_HPP
#define __DRAGON_QUOTE_GENERATOR_HPP
#include "Grammar.hpp"

class DragonQuoteGenerator : public Grammar
{
    DragonQuoteGenerator();

public:
    static DragonQuoteGenerator &getInstance();
};

#endif