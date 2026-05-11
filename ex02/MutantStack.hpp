#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>{
  typedef typename std::stack<T>::container_type container_type;
  typedef typename container_type::value_type value_type;
  typedef typename container_type::size_type size_type;
  typedef typename container_type::const_iterator const_iterator_type;
  typedef typename container_type::iterator iterator_type;
  typedef
      typename container_type::const_reverse_iterator const_reverse_iterator_type;
  typedef typename container_type::reverse_iterator reverse_iterator_type;
  public:
    MutantStack<T>();
    MutantStack<T>(const MutantStack<T> &other);
    MutantStack<T> &operator=(const MutantStack<T> &other);
    ~MutantStack();
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
