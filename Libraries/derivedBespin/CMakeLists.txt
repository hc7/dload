cmake_minimum_required(VERSION 3.9)
project(derivedBespin
        VERSION 0.0.1
        DESCRIPTION "Greetings from derived Bespin")

set(CMAKE_CXX_STANDARD 17)


include_directories(
	../../API/
)

add_library(derivedBespin SHARED
	../../API/IPlanet.h
	Bespin1.h
	Bespin1.cpp
)
