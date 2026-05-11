#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <deque>
template <typename T, class Container = std::deque<T> > class MutantStack {
protected:
  Container c;

public:
  typedef Container container_type;
  typedef typename Container::value_type value_type;
  typedef typename Container::size_type size_type;
  typedef typename Container::const_iterator const_iterator_type;
  typedef typename Container::iterator iterator_type;
  typedef
      typename Container::const_reverse_iterator const_reverse_iterator_type;
  typedef typename Container::reverse_iterator reverse_iterator_type;
  MutantStack<T, Container>();
  MutantStack<T, Container>(const MutantStack<T, Container> &other);
  MutantStack<T, Container> &operator=(const MutantStack<T, Container> &other);
  ~MutantStack();
  T &top() const;
  T &top();
  bool empty() const;
  void push(T n);
  void pop();
  size_type size() const;
  // typename Container::iterator it;
  /*
    iterator functions for those are defined out of this class such as operator
    functions to use iterators of Container c.
    these operator use begin(), end().
  */
  const_iterator_type begin() const;
  iterator_type begin();
  const_iterator_type end() const;
  iterator_type end();
  const_reverse_iterator_type rbegin() const;
  reverse_iterator_type rbegin();
  const_reverse_iterator_type rend() const;
  reverse_iterator_type rend();
};

#include "MutantStack.tpp"

#endif
