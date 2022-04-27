cmake_minimum_required ( VERSION 3.14 )
project ( lgrey )

find_path ( ARGS_HXX_INCLUDE args.hxx REQUIRED PATHS . )
find_path ( AIXLOG_HPP_INCLUDE aixlog.hpp REQUIRED PATHS . )

add_executable ( lgreylist
  src/main.cc
)

target_compile_features( lgreylist PUBLIC cxx_std_17 )
target_compile_options( lgreylist PRIVATE -Wall -Wextra -Wconversion  )
target_include_directories ( lgreylist PUBLIC ext/headerfu/include )
