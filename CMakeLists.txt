cmake_minimum_required(VERSION 3.8)
project(CatalogueEntrees)
set(CMAKE_CXX_STANDARD 11 )
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -static-libstdc++ -g")

set(SOURCE_FILES interface.cpp Trajet.cpp TrajetSimple.cpp TabTrajets.cpp TrajetCompose.cpp Catalogue.cpp )
add_executable(tp2 ${SOURCE_FILES} )