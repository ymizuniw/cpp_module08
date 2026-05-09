#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <set>

void ex_vector(void)
{
    std::cout << "\033[33m" << "====EX_VECTOR====" << "\033[0m" << std::endl;
    {
        std::vector<int> v;
        for (size_t i=0; i<5;i++)
            v.push_back(i);
        std::vector<int>::iterator it;
        std::cout << "\nExpect: 3" << std::endl;
        it = easyfind(v, 3);
        std::cout << "Actual: ";
        std::cout << *it <<  std::endl;
    }
    std::vector<int> v;
    try{
        std::vector<int> v;
        for (size_t i=0; i<5;i++)
            v.push_back(i);
        std::vector<int>::iterator it;
        std::cout << "\nExpect: std::exception" << std::endl;
        std::cout << "Actual: ";
        it = easyfind(v, 100);
    } catch(const std::exception &e){
        std::cout << e.what() << std::endl;
    }
}

void ex_set(void)
{
    std::cout << "\033[33m" << "====EX_SET====" << "\033[0m" << std::endl;

    {
        std::set<int> s;
        for (size_t i=0;i<5;i++)
            s.insert(i);
        std::set<int>::iterator it;
        std::cout << "\nExpect: 3" << std::endl;
        it = easyfind(s, 3);
        std::cout << "Actual: ";
        std::cout << *it <<  std::endl;
    }
    {
        std::set<int> s;
        for (size_t i=0;i<5;i++)
            s.insert(i);
        std::set<int>::iterator it;
        std::cout << "\nExpect: std::exception" << std::endl;
        std::cout << "Actual: ";
        try{
            it = easyfind(s, 100);
        } catch(const std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
}

void ex_list(void)
{
    std::cout << "\033[33m" << "====EX_LIST====" << "\033[0m" << std::endl;

    {
        std::list<int> l;
        for (size_t i=0;i<5;i++)
            l.push_back(i);
        std::list<int>::iterator it;
        std::cout << "\nExpect: 3" << std::endl;
        it = easyfind(l, 3);
        std::cout << "Actual: ";
        std::cout << *it <<  std::endl;
    }
    {
        std::list<int> l;
        for (size_t i=0;i<5;i++)
            l.push_back(i);
        std::list<int>::iterator it;
        std::cout << "\nExpect: std::exception" << std::endl;
        std::cout << "Actual: ";
        try{
            it = easyfind(l, 100);
        } catch(const std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
}

int main(void)
{
    ex_vector();
    ex_set();
    ex_list();
    return (0);
}
