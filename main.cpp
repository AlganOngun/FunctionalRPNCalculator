#include <fplus/fplus.hpp>
#include <iostream>
#include <string>
#include <vector>

template<typename T> T getline_from_cin(const std::string& message) {
  T temp;
  std::cout << message;
  std::getline(std::cin, temp);
  return temp;
}

auto plus_operator(const std::vector<int>& container) {
  return fplus::fwd::apply(
      container,
      fplus::fwd::reverse(),
      fplus::fwd::tail(),
      fplus::fwd::tail(),
      fplus::fwd::reverse(),
      fplus::fwd::append_elem(container[container.size() - 2] + fplus::last(container)));
}

auto minus_operator(const std::vector<int>& container) {
  return fplus::fwd::apply(
      container,
      fplus::fwd::reverse(),
      fplus::fwd::tail(),
      fplus::fwd::tail(),
      fplus::fwd::reverse(),
      fplus::fwd::append_elem(container[container.size() - 2] - fplus::last(container)));
}

auto multiply_operator(const std::vector<int>& container) {
  return fplus::fwd::apply(
      container,
      fplus::fwd::reverse(),
      fplus::fwd::tail(),
      fplus::fwd::tail(),
      fplus::fwd::reverse(),
      fplus::fwd::append_elem(container[container.size() - 2] * fplus::last(container)));
}

auto division_operator(const std::vector<int>& container) {
  return fplus::fwd::apply(
      container,
      fplus::fwd::reverse(),
      fplus::fwd::tail(),
      fplus::fwd::tail(),
      fplus::fwd::reverse(),
      fplus::fwd::append_elem(container[container.size() - 2] / fplus::last(container)));
}

auto parse(const std::vector<int>&& acc, const std::string& x) -> std::vector<int> {
  if (x == "+") return plus_operator(acc);
  else if (x == "-") return minus_operator(acc);
  else if (x == "*") return multiply_operator(acc);
  else if (x == "/") return division_operator(acc);
  else if (std::stoi(x)) return fplus::append(acc, {std::stoi(x)});
  return {0};
}

auto calculate(const std::vector<std::string>& tokens) {
  return fplus::last(fplus::fold_left(parse, std::vector<int> {}, tokens));
}

int main() {
  const auto input {getline_from_cin<std::string>("RPN Notation: ")};
  const auto tokens {fplus::split_by_token(std::string(" "), false, input)};
  const auto result {calculate(tokens)};

  std::cout << "\"" << input << " = " << result << "\"" << std::endl;
}
