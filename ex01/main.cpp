#include "Span.hpp"
#include <iostream>
#include <vector>

int test_ocf(void)
{
    std::vector<unsigned int>sequense(4);
    unsigned int i = 0;
    unsigned int size = sequense.size();
    while(i<size)
    {
        sequense[i] = i;
        i++;
    }
    std::cout << "\n\033[31m" << "====Orthodox Canononical Form====" << "\033[0m" << std::endl;
    {
        std::cout << "\n====Default Constructor====" << std::endl;
        Span sp = Span();
    }
    std::cout << "\n====Copy Constructor====" << std::endl;
    {
        Span sp1 = Span(5);
        sp1.addNumberSequense(sequense.begin(), sequense.end());
        Span sp2(sp1);
        std::vector<unsigned int> v1 = sp1.getVector();
        std::vector<unsigned int> v2 = sp2.getVector();
        for (unsigned int i=0;i<v1.size();i++)
        {
            if (v1[i]!=v2[i])
            {
                std::cout << "Copy Constructor from sp1 to sp2 failed!" << std::endl;
                return (1);
            }
        }
    }
    std::cout << "\n====Copy Assignment Operator====" << std::endl;
    {
        Span sp1(sequense.size());
        sp1.addNumberSequense(sequense.begin(), sequense.end());
        Span sp2 = sp1;
        std::vector<unsigned int> v1 = sp1.getVector();
        std::vector<unsigned int> v2 = sp2.getVector();
        for (unsigned int i=0;i<v1.size();i++)
        {
            if (v1[i]!=v2[i])
            {
                std::cout << "Copy assignment from sp1 to sp2 failed!" << std::endl;
                return (1);
            }
        }
    }
    return (0);
}

int main(void)
{
    if (test_ocf())
        return (1);
    return (0);
}
