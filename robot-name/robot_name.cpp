#include "robot_name.h"
#include <string>
#include <memory>
#include <random>
#include <iostream>

namespace robot_name {

  // Robot functions
  robot::robot() {
    this->reset();
  }

  void robot::reset() {
    m_name = std::string();
    // Random functions
    std::random_device r;
    std::mt19937_64 gen(r());
    std::uniform_int_distribution<int> uniform_digit('0', '9');
    std::uniform_int_distribution<int> uniform_letter('A', 'Z');

    m_name.push_back(uniform_letter(gen));
    m_name.push_back(uniform_letter(gen));
    m_name.push_back(uniform_digit(gen));
    m_name.push_back(uniform_digit(gen));
    m_name.push_back(uniform_digit(gen));
    /*std::cout << m_name << std::endl;*/
}

  std::string robot::name() const{
    return m_name;
  }
}
