#include <stack>

#include "MutantStack.hpp"
#include <iostream>

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>() {
  std::cout << "MutantStack DefaultConstructor Called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other)
    : std::stack<T>(other){
  std::cout << "MutantStack CopyConstructor Called" << std::endl;
}

template <typename T>
MutantStack<T> &
MutantStack<T>::operator=(const MutantStack<T> &other) {
  if (this == &other)
    return (*this);
  *this->c = other.c;
  return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {
  std::cout << "MutantStack Destructor Called" << std::endl;
}

template <typename T>
    typename MutantStack<T>::const_iterator_type MutantStack<T>::begin() const{
      return (this->c.begin());
    }

  template <typename T>
    typename  MutantStack<T>::iterator_type MutantStack<T>::begin(){
      return (this->c.begin());
    }
template <typename T>
    typename  MutantStack<T>::const_iterator_type MutantStack<T>::end() const{
      return (this->c.end());
    }
template <typename T>
    typename  MutantStack<T>::iterator_type MutantStack<T>::end(){
return (this->c.end());
    }

template <typename T>
    typename  MutantStack<T>::const_reverse_iterator_type MutantStack<T>::rbegin() const{
      return (this->c.rbegin());
    }
template <typename T>
    typename  MutantStack<T>::reverse_iterator_type MutantStack<T>::rbegin(){
            return (this->c.rbegin());
    }
template <typename T>
    typename  MutantStack<T>::const_reverse_iterator_type MutantStack<T>::rend() const{
      return (this->c.rend());
    }
template <typename T>
    typename  MutantStack<T>::reverse_iterator_type MutantStack<T>::rend(){
            return (this->c.rbegin());
    }
