#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <deque>

template <typename T, class Container = std::deque<T> > class MutantStack {
protected:
  Container c;

public:
  Container container_type;
  typename Container::value_type value_type;
  typename Container::size_type size_type;
  MutantStack<T, Container>();
  MutantStack<T, Container>(const MutantStack<T, Container> &other);
  MutantStack<T, Container> &operator=(const MutantStack<T, Container> &other);
  ~MutantStack();
  T &top() const;
  T &top();
  bool empty() const;
  void push(T n);
  void pop();
  typename Container::size_type size() const;
  typename Container::iterator it;
};

#include "MutantStack.tpp"

#endif
