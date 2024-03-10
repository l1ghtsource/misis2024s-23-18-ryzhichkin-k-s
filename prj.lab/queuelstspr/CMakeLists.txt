add_library(queuelstspr queuelstspr.cpp queuelstspr.hpp)
target_link_libraries(queuelstspr complex)
set_property(TARGET queuelstspr PROPERTY CXX_STANDARD 20)
target_include_directories(queuelstspr PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)