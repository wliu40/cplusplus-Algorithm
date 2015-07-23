/*
C++ std::pair 与 std::make_pair

std::pair主要的作用是将两个数据组合成一个数据，两个数据可以是同一类型或者不同类型。
例如std::pair<int,float> 或者 std：：pair<double,double>等。

pair实质上是一个结构体，其主要的两个成员变量是first和second，这两个变量可以直接使用。初始化一个pair可以使用构造函数，
也可以使用std::make_pair函数，make_pair函数的定义如下：
template pair make_pair(T1 a, T2 b) { return pair(a, b); }

一般make_pair都使用在需要pair做参数的位置，可以直接调用make_pair生成pair对象。 
另一个使用的方面就是pair可以接受隐式的类型转换，这样可以获得更高的灵活度。但是这样会出现如下问题：例如有如下两个定义：
std::pair<int, float>(1, 1.1);

std::make_pair(1, 1.1);

其中第一个的second变量是float类型，而make_pair函数会将second变量都转换成double类型。这个问题在编程是需要引起注意。
下面是一段pair与make_pair的例子程序：
*/
  #include <iostream>
  #include <utility>
  #include <string>
  using namespace std;

  int main () {
  pair <string,double> product1 ("tomatoes",3.25);
  pair <string,double> product2;
  pair <string,double> product3;
  
  product2.first = "lightbulbs";     // type of first is string
  product2.second = 0.99;            // type of second is double
  
  product3 = make_pair ("shoes",20.0);
  
  cout << "The price of " << product1.first << " is $" << product1.second << "\n";
  cout << "The price of " << product2.first << " is $" << product2.second << "\n";
  cout << "The price of " << product3.first << " is $" << product3.second << "\n";
  return 0;
}

/*
其运行结果如下：
  The price of tomatoes is $3.25
  The price of lightbulbs is $0.99
  The price of shoes is $20

为了更好的了解pair与make_pair的机制，下面是其定义：
*/
  TEMPLATE STRUCT pair
  template<class _Ty1,class _Ty2> struct pair
  {   // store a pair of values
    typedef pair<_Ty1, _Ty2> _Myt;
    typedef _Ty1 first_type;
    typedef _Ty2 second_type;
    
    pair(): first(_Ty1()), second(_Ty2())
    {    // construct from defaults
    }
    
    pair(const _Ty1& _Val1, const _Ty2& _Val2): first(_Val1), second(_Val2)
    {    // construct from specified values
    }
  
    template<class _Other1,
    class _Other2>
    pair(const pair<_Other1, _Other2>& _Right): first(_Right.first), second(_Right.second)
    {    // construct from compatible pair
    }
  
    void swap(_Myt& _Right)
    {    // exchange contents with _Right
      std::swap(first, _Right.first);
      std::swap(second, _Right.second);
    }
  
    _Ty1 first;    // the first stored value
    _Ty2 second;    // the second stored value
  };
   
    
  template<class _Ty1,class _Ty2> inline
  pair<_Ty1, _Ty2> make_pair(_Ty1 _Val1, _Ty2 _Val2)
  {    // return pair composed from arguments
      return (pair<_Ty1, _Ty2>(_Val1, _Val2));
  }
