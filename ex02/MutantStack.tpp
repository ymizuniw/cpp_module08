#include "MutantStack.hpp"
#include <deque>
#include <iostream>

template <typename T, class Container>
MutantStack<T, Container>::MutantStack() {
  std::cout << "MutantStack DefaultConstructor Called" << std::endl;
}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container> &other)
    : c(other.c) {
  std::cout << "MutantStack CopyConstructor Called" << std::endl;
}

template <typename T, class Container>
MutantStack<T, Container> &
MutantStack<T, Container>::operator=(const MutantStack<T, Container> &other) {
  if (this == &other)
    return (*this);
  c = other.c;
  return (*this);
}

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack() {
  std::cout << "MutantStack Destructor Called" << std::endl;
}

template <typename T, class Container> T &MutantStack<T, Container>::top() {
  return (c.back());
}

template <typename T, class Container>
T &MutantStack<T, Container>::top() const {
  return (c.back());
}

template <typename T, class Container>
bool MutantStack<T, Container>::empty() const {
  return (c.empty());
}

template <typename T, class Container>
void MutantStack<T, Container>::push(T n) {
  c.push_back(n);
}

template <typename T, class Container> void MutantStack<T, Container>::pop() {
  c.pop_back();
}

template <typename T, class Container>
typename Container::size_type MutantStack<T, Container>::size() const {
  return (c.size());
}

template <class T, class Container>
bool operator==(const MutantStack<T, Container> &x,
                const MutantStack<T, Container> &y) {
  bool lh_small =
      std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
  bool rh_small =
      std::lexicographical_compare(y.begin(), y.end(), x.begin(), x.end());
  if (!lh_small && !rh_small)
    return (true);
  return (false);
}

template <typename T, class Container>
bool operator!=(const MutantStack<T, Container> &x,
                const MutantStack<T, Container> &y) {
  bool lh_small =
      std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
  bool rh_small =
      std::lexicographical_compare(y.begin(), y.end(), x.begin(), x.end());
  if (lh_small || rh_small)
    return (true);
  return (false);
}

template <typename T, class Container>
bool operator<(const MutantStack<T, Container> &x,
               const MutantStack<T, Container> &y) {
  return (std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
}

template <typename T, class Container>
bool operator<=(const MutantStack<T, Container> &x,
                const MutantStack<T, Container> &y) {
  bool rh_small =
      std::lexicographical_compare(y.begin(), y.end(), x.begin(), x.end());
  if (!rh_small)
    return (true);
  return (false);
}

template <typename T, class Container>
bool operator>(const MutantStack<T, Container> &x,
               const MutantStack<T, Container> &y) {
  return (std::lexicographical_compare(y.begin(), y.end(), x.begin(), x.end()));
}

template <typename T, class Container>
bool operator>=(const MutantStack<T, Container> &x,
                const MutantStack<T, Container> &y) {
  bool lh_small =
      std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
  if (!lh_small)
    return (true);
  return (false);
}

template <typename T, class Container>
typename MutantStack<T, Container>::const_iterator_type
MutantStack<T, Container>::begin() const {
  return (c.begin());
}

template <typename T, class Container>
typename MutantStack<T, Container>::iterator_type
MutantStack<T, Container>::begin() {
  return (c.begin());
}

template <typename T, class Container>
typename MutantStack<T, Container>::const_iterator_type
MutantStack<T, Container>::end() const {
  return (c.end());
}

template <typename T, class Container>
typename MutantStack<T, Container>::iterator_type
MutantStack<T, Container>::end() {
  return (c.end());
}

template <typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator_type
MutantStack<T, Container>::rbegin() const {
  return (c.rbegin());
}

template <typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator_type
MutantStack<T, Container>::rbegin() {
  return (c.rbegin());
}

template <typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator_type
MutantStack<T, Container>::rend() const {
  return (c.rend());
}

template <typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator_type
MutantStack<T, Container>::rend() {
  return (c.rend());
}
