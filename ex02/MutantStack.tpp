/*
https://cpprefjp.github.io/reference/stack/stack.html

stack  はコンテナアダプタであり、LIFO (last-in first-out)
の動作――コンテナの一方から要素が挿入され、挿入された側から要素を取り出す――を実現する目的で設計されている。要素をコンテナの
back()  側から挿入し、同じく  back()  側から取り出す。

stack
は、所定のメンバ関数を持つコンテナのオブジェクトを内部実装として用いており、標準のコンテナ、もしくは独自に実装したコンテナを指定することができる。
このコンテナに必要な要件は、以下のメンバ関数を持つことである。

back()
push_back()
pop_back()
この要件を満たすものとしては  vector  、 deque  、 list  があり、デフォルトでは
deque  が使用される。

stack
は2つのテンプレートパラメータを持つ。各テンプレートパラメータの意味は以下の通りである。

T : 格納される要素の型
Container : 要素へのアクセス・保存に用いる内部実装のコンテナクラス
namespace std {
  template <class T, class Container = deque<T>>
  class stack;
}

メンバ関数
(constructor) 	コンストラクタ
(destructor) 	デストラクタ
operator= 	代入
top 	次の要素へアクセスする
empty 	要素が空であるかを確認する
size 	要素数を取得する
push 	要素を追加する
pop 	次の要素を削除する

protectedメンバ変数
c 	 Container

メンバ型
名前	説明	対応バージョン
container_type 	 Container
value_type 	 Container::value_type
size_type 	 Container::size_type

非メンバ関数

operator== 	等値比較
operator!= 	非等値比較
operator< 	左辺が右辺より小さいかの判定を行う
operator<= 	左辺が右辺以下かの判定を行う
operator> 	左辺が右辺より大きいかの判定を行う
operator>= 	左辺が右辺以上かの判定を行
*/

#include <deque>

template<typename T, class Container = std::deque<T>>
class MutantStack:{
    private:
      typename Container container_type;

    protected:
      typename Container c;

    public:
      typename Container container_type;
      typename Container::value_type value_type;
      typename Container::size_type size_type;
      MutantStack();
      MutantStack(const MutantStack &other);
      MutantStack &operator=(const MutantStack &other);
      ~MutantStack();
      typename T &top() const;
      typename T &top();
      typename T &empty() const;
      void push();
      void pop();
      typename Container::size_type size() const;
      // iterator
      typename Container::iterator it;
}

template<typename T, class Container>
MutantStack::MutantStack(){
    std::cout << "MutantStack DefaultConstructor Called" << std::endl;
}

template<typename T, class Container>
MutantStack::MutantStack(const MutantStack &other): c(other.c){
    std::cout << "MutantStack CopyConstructor Called" << std::endl;
}

template<typename T, class Container>
MutantStack &MutantStack::operator=(const MutantStack &other){
    if (this==&other)
        return (*this);
    *this = other;
    return (*this);
}

template<typename T, class Container>
MutantStack::~MutantStack(){
    std::cout << "MutantStack Destructor Called" << std::endl;
}

template<typename T, class Container>
T &MutantStack::top(){
    return (c.back());
}

template<typename T, class Container>
T &MutantStack::top() const{
    return (c.back());
}

template<typename T, class Container>
bool MutantStack::empty() const{
    return (c.empty());
}

template<typename T, class Container>
void MutantStack::push(){
    c.push_back();
}

template<typename T, class Container>
void MutantStack::pop(){
    c.pop_back();
}

template<typename T, class Container>
Container::size_type Container::size_type MutantStack::size(){
    c.size();
}

template <class T, class Container>
bool MutantStack::operator==(const MutantStack<T, Container>& x, const MutantStack<T, Container>& y){
  bool lh_small = std::lexicographical_compare(x.it.begin(), x.it.end(),
                                               y.it.begin(), y.it.end());
  bool rh_small = std::lexicographical_compare(y.it.begin(), y.it.end(),
                                               x.it.begin(), x.it.end());
  if (!lh_small && !rh_small)
    return (true);
  return (false);
}

template<typename T, class Container>
bool MutantStack::operator!=(const MutantStack<T, Container>& x, const MutantStack<T, Container>& y){
  bool lh_small = std::lexicographical_compare(x.it.begin(), x.it.end(),
                                               y.it.begin(), y.it.end());
  bool rh_small = std::lexicographical_compare(y.it.begin(), y.it.end(),
                                               x.it.begin(), x.it.end());
  if (lh_small || rh_small)
    return (true);
  return (false);
}

template<typename T, class Container>
bool MutantStack::operator<(const MutantStack<T, Container>& x, const MutantStack<T, Container>& y){
  return (std::lexicographical_compare(x.it.begin(), x.it.end(), y.it.begin(),
                                       y.it.end()));
}

template<typename T, class Container>
bool MutantStack::operator<=(const MutantStack<T, Container>& x, const MutantStack<T, Container>& y){
  bool rh_small = std::lexicographical_compare(y.it.begin(), y.it.end(),
                                               x.it.begin(), x.it.end());
  if (!rh_small)
    return (true);
  return (false);
}

template<typename T, class Container>
bool MutantStack::operator>(const MutantStack<T, Container>& x, const MutantStack<T, Container>& y){
  return (std::lexicographical_compare(y.it.begin(), y.it.end(), x.it.begin(),
                                       x.it.end()));
}

template<typename T, class Container>
bool MutantStack::operator>=(const MutantStack<T, Container>& x, const MutantStack<T, Container>& y){
  bool lh_small = std::lexicographical_compare(x.it.begin(), x.it.end(),
                                               y.it.begin(), y.it.end());
  if (!lh_small)
    return (true);
  return (false);
}
