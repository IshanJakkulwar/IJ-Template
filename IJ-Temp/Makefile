include $(shell git rev-parse --show-toplevel)/include/common.mk

SRC += $(wildcard src/*.cpp)
SRC += $(wildcard src/chassis/*.cpp)
SRC += $(wildcard src/pid/*.cpp)
SRC += $(wildcard src/odom/*.cpp)
SRC += $(wildcard src/sensors/*.cpp)

INCLUDE += -Iinclude
CXXFLAGS += -std=gnu++14