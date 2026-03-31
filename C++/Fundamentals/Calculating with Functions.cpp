#include <stdexcept>
#include <type_traits>

template <typename T = int>
struct plus_t{
  T rhs;
  inline constexpr T operator()(T lhs) const noexcept { return lhs + rhs;  }
};
template <typename T = int> inline constexpr auto plus(T rhs) { return plus_t<T>{rhs}; }

template <typename T = int>
struct minus_t{
  T rhs;
  inline constexpr T operator()(T lhs) const noexcept { return lhs - rhs; }
};
template <typename T = int> inline constexpr auto minus(T rhs) { return minus_t<T>{rhs}; }

template <typename T = int>
struct times_t{
  T rhs;
  inline constexpr T operator()(T lhs) const noexcept { return lhs * rhs; }
};
template <typename T = int> inline constexpr auto times(T rhs) { return times_t<T>{rhs}; }

template <typename T = int>
struct divide_t{
  T rhs;
  inline constexpr T operator()(T lhs) const { if(lhs == 0) throw std::domain_error("Division by zero"); return lhs / rhs; }
};
template <typename T = int> inline constexpr auto divide(T rhs) { return divide_t<T>{rhs}; }
template <typename T = int> inline constexpr auto divided_by(T rhs) { return divide(rhs); }

template <typename Op, typename T>
using EnableIfOperationFor = std::enable_if_t<std::is_same_v<std::invoke_result_t<Op, T>, T>, T>;

template <typename T = int> inline constexpr T zero() { return 0; }
template <typename T = int> inline constexpr T one() { return 1; }
template <typename T = int> inline constexpr T two() { return 2; }
template <typename T = int> inline constexpr T three() { return 3; }
template <typename T = int> inline constexpr T four() { return 4; }
template <typename T = int> inline constexpr T five() { return 5; }
template <typename T = int> inline constexpr T six() { return 6; }
template <typename T = int> inline constexpr T seven() { return 7; }
template <typename T = int> inline constexpr T eight() { return 8; }
template <typename T = int> inline constexpr T nine() { return 9; }

template <typename Op, typename T = int> inline constexpr EnableIfOperationFor<Op, T> zero(Op op) { return op(0); }
template <typename Op, typename T = int> inline constexpr EnableIfOperationFor<Op, T> one(Op op) { return op(1); }
template <typename Op, typename T = int> inline constexpr EnableIfOperationFor<Op, T> two(Op op) { return op(2); }
template <typename Op, typename T = int> inline constexpr EnableIfOperationFor<Op, T> three(Op op) { return op(3); }
template <typename Op, typename T = int> inline constexpr EnableIfOperationFor<Op, T> four(Op op) { return op(4); }
template <typename Op, typename T = int> inline constexpr EnableIfOperationFor<Op, T> five(Op op) { return op(5); }
template <typename Op, typename T = int> inline constexpr EnableIfOperationFor<Op, T> six(Op op) { return op(6); }
template <typename Op, typename T = int> inline constexpr EnableIfOperationFor<Op, T> seven(Op op) { return op(7); }
template <typename Op, typename T = int> inline constexpr EnableIfOperationFor<Op, T> eight(Op op) { return op(8); }
template <typename Op, typename T = int> inline constexpr EnableIfOperationFor<Op, T> nine(Op op) { return op(9); }

#include <iostream>

int main()
{
  std::cout << five(minus(three())) << '\n';
  std::cout << six(times(five())) << '\n';
  std::cout << one(divided_by(one())) << '\n';
  std::cout << nine(plus(two())) << '\n';

  return EXIT_SUCCESS;
}

