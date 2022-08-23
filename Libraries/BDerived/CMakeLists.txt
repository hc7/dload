cmake_minimum_required(VERSION 3.9)
project(BDerived
        VERSION 0.0.1
        DESCRIPTION "Greetings from derived Bespin")

set(CMAKE_CXX_STANDARD 17)


include_directories(
	../../API/
)

add_library(BDerived SHARED
	../../API/IPlanet.h
	../../API/Bespin.h
	BDerived.h
	BDerived.cpp
	
)
