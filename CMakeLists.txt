cmake_minimum_required( VERSION 3.14 )
project ( lgrey )

find_path ( ARGS_HXX_INCLUDE args.hxx REQUIRED PATHS . )
find_path ( AIXLOG_HPP_INCLUDE aixlog.hpp REQUIRED PATHS . )

add_executable ( lgrey
  src/main.cc
)

target_compile_features( lgrey PUBLIC c_std_17 )
target_include_directories ( lgrey PUBLIC
  ${ARGS_HXX_INCLUDE}
  ${AIXLOG_HPP_INCLUDE}
)
target_compile_options( lgrey PRIVATE -Wall -Wextra -Wconversion -Werror )
