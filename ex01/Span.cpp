#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

Span::Span(): v_(0)
{
    std::cout << "Span Default Constructor Called" << std::endl;
}

Span::Span(unsigned int N)
{
    v_.reserve(N);
    // std::cout << "capa is: " << v_.capacity() << std::endl; //N is expected.
    // std::cout << "size is: " << v_.size()<< std::endl; //0 is expected.
    std::cout << "Span Parameterized Constructor Called" << std::endl;
}

//this won't copy the capacity.
Span::Span(const Span &other): v_(other.v_)
{
  // std::cout << "capa is: " << v_.capacity() << std::endl; //other.size() is
  // expected. std::cout << "size is: " << v_.size()<< std::endl; //other.size()
  // is expected.
  std::cout << "Span Copy Constructor Called" << std::endl;
}

Span &Span::operator=(const Span &other)
{
    if (this==&other)
        return  (*this);
    this->v_ = other.v_;
    // std::cout << "capa is: " << v_.capacity() << std::endl; //other.size() is
    // expected. std::cout << "size is: " << v_.size()<< std::endl;
    // //other.size() is expected.
    return (*this);
}

Span::~Span()
{
    std::cout << "Span Default Destructor Called" << std::endl;
}

void Span::addNumber(unsigned int m)
{
    if (v_.capacity()==v_.size())
        throw std::out_of_range("Already has max elements.");
    else
        v_.push_back(m);
}

unsigned int Span::shortestSpan(void){
    std::vector<unsigned int> tmp = v_;
    std::sort(tmp.begin(), tmp.end());
    unsigned int shortest_span;
    for (unsigned int i = 0; i < tmp.size() - 1; i++) {
      unsigned int span = tmp[i + 1] - tmp[i];
      if (shortest_span >= span)
        shortest_span = span;
    }
    return (shortest_span);
}

unsigned int Span::longestSpan(void){
    if (v_.size()<2)
        throw std::out_of_range("Element is zero or one, no distance can be found");

    std::vector<unsigned int>::iterator it_max = std::max_element(v_.begin(), v_.end());
    std::vector<unsigned int>::iterator it_min = std::min_element(v_.begin(), v_.end());
    return (it_max - it_min);
}

unsigned int Span::size()
{
    return (v_.size());
}

// the capacity of the vector is modified to size if the size and capacity of
// the vector are different.
std::vector<unsigned int> Span::getVector() const
{
    std::vector<unsigned int> v = v_;
    return v;
}

// this will add vector of unsinged int to span's vector, following the capacity
// of span's vector. Refer to addNumber().
void Span::addNumberSequense(const std::vector<unsigned int>::iterator start, const std::vector<unsigned int>::iterator end)
{
    std::vector<unsigned int>::iterator it = start;

    while (it!=end)
    {
        addNumber(*it);
        it++;
    }
}
