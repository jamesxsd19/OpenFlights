# Executable names:
EXE = project
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = main.o Graph.o Edge.o Node.o

OBJS += cs225/ColorSpace/ColorSpace.o cs225/ColorSpace/Comparison.o cs225/ColorSpace/Conversion.o

# Generated files
# CLEAN_RM = gridtest-actual.png test_result_*.kd

# Use the cs225 makefile template:
include cs225/make/cs225.mk
