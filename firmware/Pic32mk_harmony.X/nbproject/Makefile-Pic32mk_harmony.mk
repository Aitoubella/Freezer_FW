#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-Pic32mk_harmony.mk)" "nbproject/Makefile-local-Pic32mk_harmony.mk"
include nbproject/Makefile-local-Pic32mk_harmony.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=Pic32mk_harmony
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Pic32mk_harmony.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Pic32mk_harmony.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/config/Pic32mk_harmony/peripheral/rtcc/plib_rtcc.c ../src/main.c ../src/config/Pic32mk_harmony/peripheral/evic/plib_evic.c ../src/config/Pic32mk_harmony/exceptions.c ../src/config/Pic32mk_harmony/initialization.c ../src/config/Pic32mk_harmony/stdio/xc32_monitor.c ../src/config/Pic32mk_harmony/peripheral/gpio/plib_gpio.c ../src/config/Pic32mk_harmony/peripheral/clk/plib_clk.c ../src/config/Pic32mk_harmony/interrupts.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/121480287/plib_rtcc.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/121865462/plib_evic.o ${OBJECTDIR}/_ext/1253356837/exceptions.o ${OBJECTDIR}/_ext/1253356837/initialization.o ${OBJECTDIR}/_ext/1977552469/xc32_monitor.o ${OBJECTDIR}/_ext/121811634/plib_gpio.o ${OBJECTDIR}/_ext/134613955/plib_clk.o ${OBJECTDIR}/_ext/1253356837/interrupts.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/121480287/plib_rtcc.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/121865462/plib_evic.o.d ${OBJECTDIR}/_ext/1253356837/exceptions.o.d ${OBJECTDIR}/_ext/1253356837/initialization.o.d ${OBJECTDIR}/_ext/1977552469/xc32_monitor.o.d ${OBJECTDIR}/_ext/121811634/plib_gpio.o.d ${OBJECTDIR}/_ext/134613955/plib_clk.o.d ${OBJECTDIR}/_ext/1253356837/interrupts.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/121480287/plib_rtcc.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/121865462/plib_evic.o ${OBJECTDIR}/_ext/1253356837/exceptions.o ${OBJECTDIR}/_ext/1253356837/initialization.o ${OBJECTDIR}/_ext/1977552469/xc32_monitor.o ${OBJECTDIR}/_ext/121811634/plib_gpio.o ${OBJECTDIR}/_ext/134613955/plib_clk.o ${OBJECTDIR}/_ext/1253356837/interrupts.o

# Source Files
SOURCEFILES=../src/config/Pic32mk_harmony/peripheral/rtcc/plib_rtcc.c ../src/main.c ../src/config/Pic32mk_harmony/peripheral/evic/plib_evic.c ../src/config/Pic32mk_harmony/exceptions.c ../src/config/Pic32mk_harmony/initialization.c ../src/config/Pic32mk_harmony/stdio/xc32_monitor.c ../src/config/Pic32mk_harmony/peripheral/gpio/plib_gpio.c ../src/config/Pic32mk_harmony/peripheral/clk/plib_clk.c ../src/config/Pic32mk_harmony/interrupts.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-Pic32mk_harmony.mk ${DISTDIR}/Pic32mk_harmony.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MK1024GPD064
MP_LINKER_FILE_OPTION=,--script="..\src\config\Pic32mk_harmony\p32MK1024GPD064.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/121480287/plib_rtcc.o: ../src/config/Pic32mk_harmony/peripheral/rtcc/plib_rtcc.c  .generated_files/flags/Pic32mk_harmony/773444f9576b75b1c86d00d5e66960cecf23a87 .generated_files/flags/Pic32mk_harmony/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/121480287" 
	@${RM} ${OBJECTDIR}/_ext/121480287/plib_rtcc.o.d 
	@${RM} ${OBJECTDIR}/_ext/121480287/plib_rtcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/Pic32mk_harmony" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/121480287/plib_rtcc.o.d" -o ${OBJECTDIR}/_ext/121480287/plib_rtcc.o ../src/config/Pic32mk_harmony/peripheral/rtcc/plib_rtcc.c    -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/Pic32mk_harmony/b054074348c58d583fe27bb6e8deb9d01146fb07 .generated_files/flags/Pic32mk_harmony/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/Pic32mk_harmony" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/121865462/plib_evic.o: ../src/config/Pic32mk_harmony/peripheral/evic/plib_evic.c  .generated_files/flags/Pic32mk_harmony/8fe00b9c939fc3cfef8e0b4424040bc81f592e35 .generated_files/flags/Pic32mk_harmony/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/121865462" 
	@${RM} ${OBJECTDIR}/_ext/121865462/plib_evic.o.d 
	@${RM} ${OBJECTDIR}/_ext/121865462/plib_evic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/Pic32mk_harmony" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/121865462/plib_evic.o.d" -o ${OBJECTDIR}/_ext/121865462/plib_evic.o ../src/config/Pic32mk_harmony/peripheral/evic/plib_evic.c    -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1253356837/exceptions.o: ../src/config/Pic32mk_harmony/exceptions.c  .generated_files/flags/Pic32mk_harmony/73b1da6bb1c07c293750e6c9c9d5d9906d58e51 .generated_files/flags/Pic32mk_harmony/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1253356837" 
	@${RM} ${OBJECTDIR}/_ext/1253356837/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1253356837/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/Pic32mk_harmony" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1253356837/exceptions.o.d" -o ${OBJECTDIR}/_ext/1253356837/exceptions.o ../src/config/Pic32mk_harmony/exceptions.c    -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1253356837/initialization.o: ../src/config/Pic32mk_harmony/initialization.c  .generated_files/flags/Pic32mk_harmony/a3f994233440a32ef6c83f33d74156776a43d16b .generated_files/flags/Pic32mk_harmony/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1253356837" 
	@${RM} ${OBJECTDIR}/_ext/1253356837/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1253356837/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/Pic32mk_harmony" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1253356837/initialization.o.d" -o ${OBJECTDIR}/_ext/1253356837/initialization.o ../src/config/Pic32mk_harmony/initialization.c    -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1977552469/xc32_monitor.o: ../src/config/Pic32mk_harmony/stdio/xc32_monitor.c  .generated_files/flags/Pic32mk_harmony/9dc1ff9a1089b9ea1b66b38812dce2ca72301ea3 .generated_files/flags/Pic32mk_harmony/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1977552469" 
	@${RM} ${OBJECTDIR}/_ext/1977552469/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1977552469/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/Pic32mk_harmony" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1977552469/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/1977552469/xc32_monitor.o ../src/config/Pic32mk_harmony/stdio/xc32_monitor.c    -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/121811634/plib_gpio.o: ../src/config/Pic32mk_harmony/peripheral/gpio/plib_gpio.c  .generated_files/flags/Pic32mk_harmony/c5129c5937d3cfcf2a3c7d7c9f02a7b69136f160 .generated_files/flags/Pic32mk_harmony/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/121811634" 
	@${RM} ${OBJECTDIR}/_ext/121811634/plib_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/121811634/plib_gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/Pic32mk_harmony" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/121811634/plib_gpio.o.d" -o ${OBJECTDIR}/_ext/121811634/plib_gpio.o ../src/config/Pic32mk_harmony/peripheral/gpio/plib_gpio.c    -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/134613955/plib_clk.o: ../src/config/Pic32mk_harmony/peripheral/clk/plib_clk.c  .generated_files/flags/Pic32mk_harmony/a6ddcb05c49f34882df777b4220b5552fa3efebe .generated_files/flags/Pic32mk_harmony/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/134613955" 
	@${RM} ${OBJECTDIR}/_ext/134613955/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/134613955/plib_clk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/Pic32mk_harmony" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/134613955/plib_clk.o.d" -o ${OBJECTDIR}/_ext/134613955/plib_clk.o ../src/config/Pic32mk_harmony/peripheral/clk/plib_clk.c    -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1253356837/interrupts.o: ../src/config/Pic32mk_harmony/interrupts.c  .generated_files/flags/Pic32mk_harmony/20764af2c5279c9b452bbd9ebf39c9811f869b11 .generated_files/flags/Pic32mk_harmony/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1253356837" 
	@${RM} ${OBJECTDIR}/_ext/1253356837/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1253356837/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/Pic32mk_harmony" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1253356837/interrupts.o.d" -o ${OBJECTDIR}/_ext/1253356837/interrupts.o ../src/config/Pic32mk_harmony/interrupts.c    -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/121480287/plib_rtcc.o: ../src/config/Pic32mk_harmony/peripheral/rtcc/plib_rtcc.c  .generated_files/flags/Pic32mk_harmony/585ab61b9ac9c0c2c3fcf27e9088b1ec9dde3007 .generated_files/flags/Pic32mk_harmony/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/121480287" 
	@${RM} ${OBJECTDIR}/_ext/121480287/plib_rtcc.o.d 
	@${RM} ${OBJECTDIR}/_ext/121480287/plib_rtcc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/Pic32mk_harmony" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/121480287/plib_rtcc.o.d" -o ${OBJECTDIR}/_ext/121480287/plib_rtcc.o ../src/config/Pic32mk_harmony/peripheral/rtcc/plib_rtcc.c    -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/Pic32mk_harmony/f42b26e4d39a3d0df5ba4fe6df8988ba24debf8c .generated_files/flags/Pic32mk_harmony/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/Pic32mk_harmony" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/121865462/plib_evic.o: ../src/config/Pic32mk_harmony/peripheral/evic/plib_evic.c  .generated_files/flags/Pic32mk_harmony/ac33e84eb5909d62c3922a32ecf84a1fb3c52b71 .generated_files/flags/Pic32mk_harmony/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/121865462" 
	@${RM} ${OBJECTDIR}/_ext/121865462/plib_evic.o.d 
	@${RM} ${OBJECTDIR}/_ext/121865462/plib_evic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/Pic32mk_harmony" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/121865462/plib_evic.o.d" -o ${OBJECTDIR}/_ext/121865462/plib_evic.o ../src/config/Pic32mk_harmony/peripheral/evic/plib_evic.c    -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1253356837/exceptions.o: ../src/config/Pic32mk_harmony/exceptions.c  .generated_files/flags/Pic32mk_harmony/edf786076505bc454dcd7f64fb08a759c10e3eec .generated_files/flags/Pic32mk_harmony/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1253356837" 
	@${RM} ${OBJECTDIR}/_ext/1253356837/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1253356837/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/Pic32mk_harmony" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1253356837/exceptions.o.d" -o ${OBJECTDIR}/_ext/1253356837/exceptions.o ../src/config/Pic32mk_harmony/exceptions.c    -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1253356837/initialization.o: ../src/config/Pic32mk_harmony/initialization.c  .generated_files/flags/Pic32mk_harmony/b72c75b9df123df19b9654e4fe539825da87707d .generated_files/flags/Pic32mk_harmony/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1253356837" 
	@${RM} ${OBJECTDIR}/_ext/1253356837/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1253356837/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/Pic32mk_harmony" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1253356837/initialization.o.d" -o ${OBJECTDIR}/_ext/1253356837/initialization.o ../src/config/Pic32mk_harmony/initialization.c    -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1977552469/xc32_monitor.o: ../src/config/Pic32mk_harmony/stdio/xc32_monitor.c  .generated_files/flags/Pic32mk_harmony/9f26639990d78644751aab88bed0e6be84e58bf2 .generated_files/flags/Pic32mk_harmony/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1977552469" 
	@${RM} ${OBJECTDIR}/_ext/1977552469/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1977552469/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/Pic32mk_harmony" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1977552469/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/1977552469/xc32_monitor.o ../src/config/Pic32mk_harmony/stdio/xc32_monitor.c    -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/121811634/plib_gpio.o: ../src/config/Pic32mk_harmony/peripheral/gpio/plib_gpio.c  .generated_files/flags/Pic32mk_harmony/353646f4e6a596ce55c992359d30b0c5bea9435b .generated_files/flags/Pic32mk_harmony/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/121811634" 
	@${RM} ${OBJECTDIR}/_ext/121811634/plib_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/121811634/plib_gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/Pic32mk_harmony" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/121811634/plib_gpio.o.d" -o ${OBJECTDIR}/_ext/121811634/plib_gpio.o ../src/config/Pic32mk_harmony/peripheral/gpio/plib_gpio.c    -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/134613955/plib_clk.o: ../src/config/Pic32mk_harmony/peripheral/clk/plib_clk.c  .generated_files/flags/Pic32mk_harmony/c52fc44ac5e7329c15f66f82225641f647e09b7f .generated_files/flags/Pic32mk_harmony/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/134613955" 
	@${RM} ${OBJECTDIR}/_ext/134613955/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/134613955/plib_clk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/Pic32mk_harmony" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/134613955/plib_clk.o.d" -o ${OBJECTDIR}/_ext/134613955/plib_clk.o ../src/config/Pic32mk_harmony/peripheral/clk/plib_clk.c    -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1253356837/interrupts.o: ../src/config/Pic32mk_harmony/interrupts.c  .generated_files/flags/Pic32mk_harmony/cac935bbb792577f96da9be64b90c7dd75b4ba7 .generated_files/flags/Pic32mk_harmony/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1253356837" 
	@${RM} ${OBJECTDIR}/_ext/1253356837/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1253356837/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/Pic32mk_harmony" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1253356837/interrupts.o.d" -o ${OBJECTDIR}/_ext/1253356837/interrupts.o ../src/config/Pic32mk_harmony/interrupts.c    -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Pic32mk_harmony.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../src/config/Pic32mk_harmony/p32MK1024GPD064.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_SIMULATOR=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Pic32mk_harmony.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,--defsym=_min_heap_size=512,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/Pic32mk_harmony.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/config/Pic32mk_harmony/p32MK1024GPD064.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Pic32mk_harmony.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_Pic32mk_harmony=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=512,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/Pic32mk_harmony.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
