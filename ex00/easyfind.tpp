/*
    It will return last iterator got by end() when no occurrence of target is found.
*/

#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T &cont, int target){
    typename T::iterator it = std::find(cont.begin(), cont.end(), target);
    if (it==cont.end())
        throw std::exception();
    return (it);
}
