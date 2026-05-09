#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span{
    private:
        std::vector<unsigned int> v_;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
        void addNumber(unsigned int m);
        unsigned int shortestSpan();
        unsigned int longestSpan();
        void addNumberSequense(const std::vector<unsigned int>::iterator start, const std::vector<unsigned int>::iterator end);
        unsigned int size();
        std::vector<unsigned int> getVector() const;
};

#endif
