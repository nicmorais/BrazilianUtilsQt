find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Test REQUIRED)

add_executable(testBrazilianUtilsQt
  main.cpp
  brasilianutilsqttest.h
  brasilianutilsqttest.cpp
)

target_link_libraries(testBrazilianUtilsQt 
PRIVATE
  Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Test
  BrazilianUtilsQt
)
