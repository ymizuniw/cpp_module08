#include "Span.hpp"
#include <exception>
#include <iostream>
#include <vector>

int test_ocf(void)
{
  // sequense: capacity 5, size 3
  std::vector<unsigned int> sequense;
  sequense.reserve(5);
  for (unsigned int i = 0; i < sequense.capacity() - 2; i++)
    sequense.push_back(i);

  std::cout << "\n\033[33m" << "====Orthodox Canononical Form====" << "\033[0m"
            << std::endl;
  {
    std::cout << "\n====Default Constructor====" << std::endl;
    Span sp = Span();
  }
    std::cout << "\n====Copy Constructor====" << std::endl;
    {
      // sp1: capacity 5, size 0;
      Span sp1 = Span(5);
      sp1.addNumberSequense(sequense.begin(), sequense.end());
      // sp2: capacity 3, size 3;
      Span sp2(sp1);
      std::vector<unsigned int> v1 = sp1.getVector();
      std::vector<unsigned int> v2 = sp2.getVector();
      //   if (v2.capacity() != 3)
      //     throw std::exception();
      //   if (v1.capacity() != 3)
      //     throw std::exception();
      //   if (sequense.size() != v1.size() || sequense.size() != v2.size())
      //     throw std::exception();
      for (unsigned int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
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

int test_basic_function(void) {
  std::cout << "\n\033[33m====Test Basic Function====\033[0m\n" << std::endl;
  {
    unsigned int size = 10000;
    Span sp1 = Span(size);
    std::vector<unsigned int> seq(size);
    for (size_t i = 0; i < size; i++)
      seq[i] = i;
    sp1.addNumberSequense(seq.begin(), seq.end());
    unsigned shortest_span = sp1.shortestSpan();
    unsigned longest_span = sp1.longestSpan();
    if (!(shortest_span == 1 && longest_span == size - 1)) {
      std::cout << "shortest_span: " << shortest_span
                << "\nlongest_span: " << longest_span << std::endl;
      return (1);
    }
  }
  return (0);
}

int test_out_of_cpacity(void) {
  int exception_occurred = 0;
  std::cout << "\n\033[33m====Test Out of Capacity====\033[0m" << std::endl;
  {
    std::cout << "\n<test with empty span>" << std::endl;
    try {
      Span sp2 = Span(0);
      sp2.addNumber(1);
    } catch (const std::exception &e) {
      exception_occurred = 1;
      std::cout << "\nException: " << e.what() << std::endl;
    }
    if (exception_occurred == 0) {
      return (1);
    }
  }
  {
    std::cout << "\n<test with sized span>" << std::endl;
    try {
      size_t size = 3;
      Span sp3 = Span(3);
      for (size_t i = 0; i < size; i++)
        sp3.addNumber(i);
      sp3.addNumber(1);
    } catch (const std::exception &e) {
      exception_occurred = 1;
      std::cout << "\nException: " << e.what() << "\n" << std::endl;
    }
    if (exception_occurred == 0) {
      return (1);
    }
  }
  return (0);
}

int main(void)
{
    if (test_ocf())
        return (1);
    if (test_basic_function())
      return (1);
    if (test_out_of_cpacity())
      return (1);
    return (0);
}
