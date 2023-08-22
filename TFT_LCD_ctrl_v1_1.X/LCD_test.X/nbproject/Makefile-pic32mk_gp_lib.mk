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
ifeq "$(wildcard nbproject/Makefile-local-pic32mk_gp_lib.mk)" "nbproject/Makefile-local-pic32mk_gp_lib.mk"
include nbproject/Makefile-local-pic32mk_gp_lib.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=pic32mk_gp_lib
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/LCD_test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/LCD_test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../src/main.c ../src/config/pic32mk_gp_lib/initialization.c ../src/config/pic32mk_gp_lib/interrupts.c ../src/config/pic32mk_gp_lib/exceptions.c ../src/config/pic32mk_gp_lib/stdio/xc32_monitor.c ../src/config/pic32mk_gp_lib/peripheral/clk/plib_clk.c ../src/config/pic32mk_gp_lib/peripheral/gpio/plib_gpio.c ../src/config/pic32mk_gp_lib/peripheral/evic/plib_evic.c ../src/config/pic32mk_gp_lib/peripheral/spi/spi_master/plib_spi5_master.c ../src/app.c ../src/config/pic32mk_gp_lib/peripheral/coretimer/plib_coretimer.c ../src/config/pic32mk_gp_lib/peripheral/tmr/plib_tmr2.c ../src/cordic.c ../src/cube3d.c ../src/glcdfont.c ../src/ili9341.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/530576794/initialization.o ${OBJECTDIR}/_ext/530576794/interrupts.o ${OBJECTDIR}/_ext/530576794/exceptions.o ${OBJECTDIR}/_ext/743599572/xc32_monitor.o ${OBJECTDIR}/_ext/1415359268/plib_clk.o ${OBJECTDIR}/_ext/926587405/plib_gpio.o ${OBJECTDIR}/_ext/926533577/plib_evic.o ${OBJECTDIR}/_ext/241099094/plib_spi5_master.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/908944264/plib_coretimer.o ${OBJECTDIR}/_ext/1415375643/plib_tmr2.o ${OBJECTDIR}/_ext/1360937237/cordic.o ${OBJECTDIR}/_ext/1360937237/cube3d.o ${OBJECTDIR}/_ext/1360937237/glcdfont.o ${OBJECTDIR}/_ext/1360937237/ili9341.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/530576794/initialization.o.d ${OBJECTDIR}/_ext/530576794/interrupts.o.d ${OBJECTDIR}/_ext/530576794/exceptions.o.d ${OBJECTDIR}/_ext/743599572/xc32_monitor.o.d ${OBJECTDIR}/_ext/1415359268/plib_clk.o.d ${OBJECTDIR}/_ext/926587405/plib_gpio.o.d ${OBJECTDIR}/_ext/926533577/plib_evic.o.d ${OBJECTDIR}/_ext/241099094/plib_spi5_master.o.d ${OBJECTDIR}/_ext/1360937237/app.o.d ${OBJECTDIR}/_ext/908944264/plib_coretimer.o.d ${OBJECTDIR}/_ext/1415375643/plib_tmr2.o.d ${OBJECTDIR}/_ext/1360937237/cordic.o.d ${OBJECTDIR}/_ext/1360937237/cube3d.o.d ${OBJECTDIR}/_ext/1360937237/glcdfont.o.d ${OBJECTDIR}/_ext/1360937237/ili9341.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/530576794/initialization.o ${OBJECTDIR}/_ext/530576794/interrupts.o ${OBJECTDIR}/_ext/530576794/exceptions.o ${OBJECTDIR}/_ext/743599572/xc32_monitor.o ${OBJECTDIR}/_ext/1415359268/plib_clk.o ${OBJECTDIR}/_ext/926587405/plib_gpio.o ${OBJECTDIR}/_ext/926533577/plib_evic.o ${OBJECTDIR}/_ext/241099094/plib_spi5_master.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/908944264/plib_coretimer.o ${OBJECTDIR}/_ext/1415375643/plib_tmr2.o ${OBJECTDIR}/_ext/1360937237/cordic.o ${OBJECTDIR}/_ext/1360937237/cube3d.o ${OBJECTDIR}/_ext/1360937237/glcdfont.o ${OBJECTDIR}/_ext/1360937237/ili9341.o

# Source Files
SOURCEFILES=../src/main.c ../src/config/pic32mk_gp_lib/initialization.c ../src/config/pic32mk_gp_lib/interrupts.c ../src/config/pic32mk_gp_lib/exceptions.c ../src/config/pic32mk_gp_lib/stdio/xc32_monitor.c ../src/config/pic32mk_gp_lib/peripheral/clk/plib_clk.c ../src/config/pic32mk_gp_lib/peripheral/gpio/plib_gpio.c ../src/config/pic32mk_gp_lib/peripheral/evic/plib_evic.c ../src/config/pic32mk_gp_lib/peripheral/spi/spi_master/plib_spi5_master.c ../src/app.c ../src/config/pic32mk_gp_lib/peripheral/coretimer/plib_coretimer.c ../src/config/pic32mk_gp_lib/peripheral/tmr/plib_tmr2.c ../src/cordic.c ../src/cube3d.c ../src/glcdfont.c ../src/ili9341.c



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
	${MAKE}  -f nbproject/Makefile-pic32mk_gp_lib.mk ${DISTDIR}/LCD_test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MK1024GPD064
MP_LINKER_FILE_OPTION=,--script="..\src\config\pic32mk_gp_lib\p32MK1024GPD064.ld"
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
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/pic32mk_gp_lib/793ca977dc79e89a5c0a07343ae5a1b3946263b0 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/530576794/initialization.o: ../src/config/pic32mk_gp_lib/initialization.c  .generated_files/flags/pic32mk_gp_lib/9a8152c9d267dbf36ed51a5254311d9ca4cdad49 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/530576794" 
	@${RM} ${OBJECTDIR}/_ext/530576794/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/530576794/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/530576794/initialization.o.d" -o ${OBJECTDIR}/_ext/530576794/initialization.o ../src/config/pic32mk_gp_lib/initialization.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/530576794/interrupts.o: ../src/config/pic32mk_gp_lib/interrupts.c  .generated_files/flags/pic32mk_gp_lib/85b5ec6c41e493f892ed25deb0ce212f4d93fb74 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/530576794" 
	@${RM} ${OBJECTDIR}/_ext/530576794/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/530576794/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/530576794/interrupts.o.d" -o ${OBJECTDIR}/_ext/530576794/interrupts.o ../src/config/pic32mk_gp_lib/interrupts.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/530576794/exceptions.o: ../src/config/pic32mk_gp_lib/exceptions.c  .generated_files/flags/pic32mk_gp_lib/2f3c2eccd9a3a6beb167d3c28063d2410fe2916c .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/530576794" 
	@${RM} ${OBJECTDIR}/_ext/530576794/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/530576794/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/530576794/exceptions.o.d" -o ${OBJECTDIR}/_ext/530576794/exceptions.o ../src/config/pic32mk_gp_lib/exceptions.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/743599572/xc32_monitor.o: ../src/config/pic32mk_gp_lib/stdio/xc32_monitor.c  .generated_files/flags/pic32mk_gp_lib/acfc0ea76b49f92ea248be54b4cbdb8a02cf81eb .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/743599572" 
	@${RM} ${OBJECTDIR}/_ext/743599572/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/743599572/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/743599572/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/743599572/xc32_monitor.o ../src/config/pic32mk_gp_lib/stdio/xc32_monitor.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1415359268/plib_clk.o: ../src/config/pic32mk_gp_lib/peripheral/clk/plib_clk.c  .generated_files/flags/pic32mk_gp_lib/4ce2801facbd201b120e8afd4ba3a1341863176b .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1415359268" 
	@${RM} ${OBJECTDIR}/_ext/1415359268/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1415359268/plib_clk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1415359268/plib_clk.o.d" -o ${OBJECTDIR}/_ext/1415359268/plib_clk.o ../src/config/pic32mk_gp_lib/peripheral/clk/plib_clk.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/926587405/plib_gpio.o: ../src/config/pic32mk_gp_lib/peripheral/gpio/plib_gpio.c  .generated_files/flags/pic32mk_gp_lib/4ec3c24f7bfde5b556e39bb318da25109eddb38b .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/926587405" 
	@${RM} ${OBJECTDIR}/_ext/926587405/plib_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/926587405/plib_gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/926587405/plib_gpio.o.d" -o ${OBJECTDIR}/_ext/926587405/plib_gpio.o ../src/config/pic32mk_gp_lib/peripheral/gpio/plib_gpio.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/926533577/plib_evic.o: ../src/config/pic32mk_gp_lib/peripheral/evic/plib_evic.c  .generated_files/flags/pic32mk_gp_lib/3c003b157015b0eb5fabf7577de648d9cb4c9f75 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/926533577" 
	@${RM} ${OBJECTDIR}/_ext/926533577/plib_evic.o.d 
	@${RM} ${OBJECTDIR}/_ext/926533577/plib_evic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/926533577/plib_evic.o.d" -o ${OBJECTDIR}/_ext/926533577/plib_evic.o ../src/config/pic32mk_gp_lib/peripheral/evic/plib_evic.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/241099094/plib_spi5_master.o: ../src/config/pic32mk_gp_lib/peripheral/spi/spi_master/plib_spi5_master.c  .generated_files/flags/pic32mk_gp_lib/54bf3b785477155d6582ea8c11d7a867e6aa2c .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/241099094" 
	@${RM} ${OBJECTDIR}/_ext/241099094/plib_spi5_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/241099094/plib_spi5_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/241099094/plib_spi5_master.o.d" -o ${OBJECTDIR}/_ext/241099094/plib_spi5_master.o ../src/config/pic32mk_gp_lib/peripheral/spi/spi_master/plib_spi5_master.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/pic32mk_gp_lib/9c72057cd1898cc2f3a4620f5fbde02d000ced3 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/908944264/plib_coretimer.o: ../src/config/pic32mk_gp_lib/peripheral/coretimer/plib_coretimer.c  .generated_files/flags/pic32mk_gp_lib/9aa8a93ca9a4310166b27aaa6355252830e93900 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/908944264" 
	@${RM} ${OBJECTDIR}/_ext/908944264/plib_coretimer.o.d 
	@${RM} ${OBJECTDIR}/_ext/908944264/plib_coretimer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/908944264/plib_coretimer.o.d" -o ${OBJECTDIR}/_ext/908944264/plib_coretimer.o ../src/config/pic32mk_gp_lib/peripheral/coretimer/plib_coretimer.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1415375643/plib_tmr2.o: ../src/config/pic32mk_gp_lib/peripheral/tmr/plib_tmr2.c  .generated_files/flags/pic32mk_gp_lib/363cdb580f36d760c66207c6ce427cfc3db6de78 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1415375643" 
	@${RM} ${OBJECTDIR}/_ext/1415375643/plib_tmr2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1415375643/plib_tmr2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1415375643/plib_tmr2.o.d" -o ${OBJECTDIR}/_ext/1415375643/plib_tmr2.o ../src/config/pic32mk_gp_lib/peripheral/tmr/plib_tmr2.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/cordic.o: ../src/cordic.c  .generated_files/flags/pic32mk_gp_lib/4e486fb17e63da0cdad70c9912b5cc924bfd0e57 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/cordic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/cordic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/cordic.o.d" -o ${OBJECTDIR}/_ext/1360937237/cordic.o ../src/cordic.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/cube3d.o: ../src/cube3d.c  .generated_files/flags/pic32mk_gp_lib/9c56aa5d9819b92eb8ac9b90d969de266074285b .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/cube3d.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/cube3d.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/cube3d.o.d" -o ${OBJECTDIR}/_ext/1360937237/cube3d.o ../src/cube3d.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/glcdfont.o: ../src/glcdfont.c  .generated_files/flags/pic32mk_gp_lib/6e954e6ea1b461d506fb6283da2224835c8ee071 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/glcdfont.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/glcdfont.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/glcdfont.o.d" -o ${OBJECTDIR}/_ext/1360937237/glcdfont.o ../src/glcdfont.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/ili9341.o: ../src/ili9341.c  .generated_files/flags/pic32mk_gp_lib/95fca42522c91dbc790629a9d0e8c59033e1ad80 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ili9341.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ili9341.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ili9341.o.d" -o ${OBJECTDIR}/_ext/1360937237/ili9341.o ../src/ili9341.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/pic32mk_gp_lib/43ffb6c5ee4fb9fa3e4387d3de703d7ebd291a20 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/530576794/initialization.o: ../src/config/pic32mk_gp_lib/initialization.c  .generated_files/flags/pic32mk_gp_lib/9aeffb10ec8a9e80705961c2dbff9bd47ab5135c .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/530576794" 
	@${RM} ${OBJECTDIR}/_ext/530576794/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/530576794/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/530576794/initialization.o.d" -o ${OBJECTDIR}/_ext/530576794/initialization.o ../src/config/pic32mk_gp_lib/initialization.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/530576794/interrupts.o: ../src/config/pic32mk_gp_lib/interrupts.c  .generated_files/flags/pic32mk_gp_lib/d8ee7297b24f1b01188bed3cd693d51eb2a380db .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/530576794" 
	@${RM} ${OBJECTDIR}/_ext/530576794/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/530576794/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/530576794/interrupts.o.d" -o ${OBJECTDIR}/_ext/530576794/interrupts.o ../src/config/pic32mk_gp_lib/interrupts.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/530576794/exceptions.o: ../src/config/pic32mk_gp_lib/exceptions.c  .generated_files/flags/pic32mk_gp_lib/ea7da05ee471684b8113214e79afe336f7e02993 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/530576794" 
	@${RM} ${OBJECTDIR}/_ext/530576794/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/530576794/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/530576794/exceptions.o.d" -o ${OBJECTDIR}/_ext/530576794/exceptions.o ../src/config/pic32mk_gp_lib/exceptions.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/743599572/xc32_monitor.o: ../src/config/pic32mk_gp_lib/stdio/xc32_monitor.c  .generated_files/flags/pic32mk_gp_lib/37b913d9a43e21c7147733748582043654e1c108 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/743599572" 
	@${RM} ${OBJECTDIR}/_ext/743599572/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/743599572/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/743599572/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/743599572/xc32_monitor.o ../src/config/pic32mk_gp_lib/stdio/xc32_monitor.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1415359268/plib_clk.o: ../src/config/pic32mk_gp_lib/peripheral/clk/plib_clk.c  .generated_files/flags/pic32mk_gp_lib/2424f1c8b07c4857b910c8be85fe0a2351407d35 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1415359268" 
	@${RM} ${OBJECTDIR}/_ext/1415359268/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1415359268/plib_clk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1415359268/plib_clk.o.d" -o ${OBJECTDIR}/_ext/1415359268/plib_clk.o ../src/config/pic32mk_gp_lib/peripheral/clk/plib_clk.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/926587405/plib_gpio.o: ../src/config/pic32mk_gp_lib/peripheral/gpio/plib_gpio.c  .generated_files/flags/pic32mk_gp_lib/bc20912c3395688a1a44ed8049bb2df9642712d .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/926587405" 
	@${RM} ${OBJECTDIR}/_ext/926587405/plib_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/926587405/plib_gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/926587405/plib_gpio.o.d" -o ${OBJECTDIR}/_ext/926587405/plib_gpio.o ../src/config/pic32mk_gp_lib/peripheral/gpio/plib_gpio.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/926533577/plib_evic.o: ../src/config/pic32mk_gp_lib/peripheral/evic/plib_evic.c  .generated_files/flags/pic32mk_gp_lib/a000e93b01dae6b65c67f33dd740a487c8b9ce84 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/926533577" 
	@${RM} ${OBJECTDIR}/_ext/926533577/plib_evic.o.d 
	@${RM} ${OBJECTDIR}/_ext/926533577/plib_evic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/926533577/plib_evic.o.d" -o ${OBJECTDIR}/_ext/926533577/plib_evic.o ../src/config/pic32mk_gp_lib/peripheral/evic/plib_evic.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/241099094/plib_spi5_master.o: ../src/config/pic32mk_gp_lib/peripheral/spi/spi_master/plib_spi5_master.c  .generated_files/flags/pic32mk_gp_lib/f5f13d83be102091366363e2b981586d1f6318f5 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/241099094" 
	@${RM} ${OBJECTDIR}/_ext/241099094/plib_spi5_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/241099094/plib_spi5_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/241099094/plib_spi5_master.o.d" -o ${OBJECTDIR}/_ext/241099094/plib_spi5_master.o ../src/config/pic32mk_gp_lib/peripheral/spi/spi_master/plib_spi5_master.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/pic32mk_gp_lib/19c0ac6961d0288e8c8c2268f47c273c16ca376e .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/908944264/plib_coretimer.o: ../src/config/pic32mk_gp_lib/peripheral/coretimer/plib_coretimer.c  .generated_files/flags/pic32mk_gp_lib/e0cf259886da86daaf27acd74864181e0428551d .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/908944264" 
	@${RM} ${OBJECTDIR}/_ext/908944264/plib_coretimer.o.d 
	@${RM} ${OBJECTDIR}/_ext/908944264/plib_coretimer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/908944264/plib_coretimer.o.d" -o ${OBJECTDIR}/_ext/908944264/plib_coretimer.o ../src/config/pic32mk_gp_lib/peripheral/coretimer/plib_coretimer.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1415375643/plib_tmr2.o: ../src/config/pic32mk_gp_lib/peripheral/tmr/plib_tmr2.c  .generated_files/flags/pic32mk_gp_lib/ac15dfa38de40dcb709b21e08b87cef94195d048 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1415375643" 
	@${RM} ${OBJECTDIR}/_ext/1415375643/plib_tmr2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1415375643/plib_tmr2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1415375643/plib_tmr2.o.d" -o ${OBJECTDIR}/_ext/1415375643/plib_tmr2.o ../src/config/pic32mk_gp_lib/peripheral/tmr/plib_tmr2.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/cordic.o: ../src/cordic.c  .generated_files/flags/pic32mk_gp_lib/b863610d61c1c82287b899b7b08d6012cd4929c3 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/cordic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/cordic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/cordic.o.d" -o ${OBJECTDIR}/_ext/1360937237/cordic.o ../src/cordic.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/cube3d.o: ../src/cube3d.c  .generated_files/flags/pic32mk_gp_lib/cec9ff9c41c85cd8a69db3fa0fa15a7a88f72150 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/cube3d.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/cube3d.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/cube3d.o.d" -o ${OBJECTDIR}/_ext/1360937237/cube3d.o ../src/cube3d.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/glcdfont.o: ../src/glcdfont.c  .generated_files/flags/pic32mk_gp_lib/33b3924fdc4b13110c65a478b4a1a9b6075337e7 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/glcdfont.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/glcdfont.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/glcdfont.o.d" -o ${OBJECTDIR}/_ext/1360937237/glcdfont.o ../src/glcdfont.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/ili9341.o: ../src/ili9341.c  .generated_files/flags/pic32mk_gp_lib/29e01752b34c96382a50dcc5f4b60cd4850b6d32 .generated_files/flags/pic32mk_gp_lib/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ili9341.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ili9341.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -fno-common -I"../src" -I"../src/config/pic32mk_gp_lib" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ili9341.o.d" -o ${OBJECTDIR}/_ext/1360937237/ili9341.o ../src/ili9341.c    -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/LCD_test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../src/config/pic32mk_gp_lib/p32MK1024GPD064.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/LCD_test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x36F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=512,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/LCD_test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/config/pic32mk_gp_lib/p32MK1024GPD064.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/LCD_test.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_pic32mk_gp_lib=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=512,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/LCD_test.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}
