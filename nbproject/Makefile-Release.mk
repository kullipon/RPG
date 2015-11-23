#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Enemie.o \
	${OBJECTDIR}/Flamme.o \
	${OBJECTDIR}/Guerrier.o \
	${OBJECTDIR}/Hache.o \
	${OBJECTDIR}/Joueur.o \
	${OBJECTDIR}/Mage.o \
	${OBJECTDIR}/Map.o \
	${OBJECTDIR}/ObAttaquer.o \
	${OBJECTDIR}/PersonnageBase.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/local/lib -lsfml-graphics-d -lsfml-window-d -lsfml-system-d -lsfml-audio-d -lsfml-network-d

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rpg

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rpg: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rpg ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Enemie.o: Enemie.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Enemie.o Enemie.cpp

${OBJECTDIR}/Flamme.o: Flamme.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Flamme.o Flamme.cpp

${OBJECTDIR}/Guerrier.o: Guerrier.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Guerrier.o Guerrier.cpp

${OBJECTDIR}/Hache.o: Hache.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Hache.o Hache.cpp

${OBJECTDIR}/Joueur.o: Joueur.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Joueur.o Joueur.cpp

${OBJECTDIR}/Mage.o: Mage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mage.o Mage.cpp

${OBJECTDIR}/Map.o: Map.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Map.o Map.cpp

${OBJECTDIR}/ObAttaquer.o: ObAttaquer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ObAttaquer.o ObAttaquer.cpp

${OBJECTDIR}/PersonnageBase.o: PersonnageBase.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PersonnageBase.o PersonnageBase.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/local/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rpg

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
