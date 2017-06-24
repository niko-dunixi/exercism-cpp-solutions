#ifndef robotz
#define robotz
#include <string>

namespace robot_name {
class robot {
public:
  robot();
  void reset();
  std::string name() const;

private:
  std::string m_name;
};
}
#endif
