#########################################################
# File: Standard Makefile Template for 162
# Description: Makefile for Final Project
#########################################################

# CXX Compiler
CXX = g++

# CXXFLAGS compile flags.
# -std=c++0x Language Version 
CXXFLAGS = -std=c++0x

# -Wall turns on all warnings
CXXFLAGS += -Wall

# -pedantic-errors strictly enforces the standard
CXXFLAGS += -pedantic-errors

# -g turns on debug information 
CXXFLAGS += -g

####################
###   Variables  ###
####################

# SRCS source files. 

SRC1 = main.cpp
SRC2 = location.cpp
SRC3 = player.cpp
SRC4 = city.cpp
SRC5 = playGame.cpp
SRC6 = inventory.cpp
SRC7 = store.cpp
SRC8 = jungle.cpp
SRC9 = village.cpp
SRC10 = ruins.cpp
SRC11 = cave.cpp
SRC12 =lostCity.cpp

SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5} ${SRC6} ${SRC7} ${SRC8} ${SRC9} ${SRC10} ${SRC11} ${SRC12}

# HEADERS is a standard name for the header files. 

HEADER1 = 
HEADER2 = 
HEADER3 = 
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3}

# These will be your executable names. 
PROG1 = 
PROG2 = 
PROG3 = 
PROGS = ${PROG1}# ${PROG2} ${PROG3}

# This is the name of your document(s). 
# Edit as needed.
#DOC = program5Design.pdf

# Name of Compressed File
#TAR = program2.tar.bz2

#####################
### BUILD SECTION ###
#####################

# Typing 'make' in terminal calls the first build available.
# In this case, default.
default:
	${CXX} ${SRCS}${HEADERS} -o prog5

# Typing 'make all' in terminal calls this build.
all:
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG1}

# Typing 'make tar' in terminal calls this build.
# This creates a compressed file for submission.
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} ${DOC} makefile

# Typing 'make clean' calls this build.
# It's designed to clean up the folder.
# Be careful with this, edit as needed.
clean: 
	rm -f ${PROGS} *.o *~

