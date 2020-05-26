################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./Driver/Source/F2837xD_Adc.obj" \
"./Driver/Source/F2837xD_CodeStartBranch.obj" \
"./Driver/Source/F2837xD_CpuTimers.obj" \
"./Driver/Source/F2837xD_DefaultISR.obj" \
"./Driver/Source/F2837xD_EPwm.obj" \
"./Driver/Source/F2837xD_GlobalVariableDefs.obj" \
"./Driver/Source/F2837xD_Gpio.obj" \
"./Driver/Source/F2837xD_Ipc.obj" \
"./Driver/Source/F2837xD_PieCtrl.obj" \
"./Driver/Source/F2837xD_PieVect.obj" \
"./Driver/Source/F2837xD_SysCtrl.obj" \
"./Driver/Source/F2837xD_usDelay.obj" \
"./Driver/Source/SPLL_1ph_SOGI_F.obj" \
"./Driver/Source/sin_tab.obj" \
"../2837x_FLASH_lnk_cpu1.cmd" \
"../Cmd/F2837xD_Headers_nonBIOS_cpu1.cmd" \
$(GEN_CMDS__FLAG) \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Cmd/subdir_vars.mk
-include Driver/Source/subdir_vars.mk
-include subdir_rules.mk
-include Cmd/subdir_rules.mk
-include Driver/Source/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
PLL-TEST1.out \

EXE_OUTPUTS__QUOTED += \
"PLL-TEST1.out" \

BIN_OUTPUTS += \
PLL-TEST1.hex \

BIN_OUTPUTS__QUOTED += \
"PLL-TEST1.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "PLL-TEST1.out"

# Tool invocations
PLL-TEST1.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number -z -m"PLL-TEST1.map" --stack_size=0x200 --warn_sections -i"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/lib" -i"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/include" --reread_libs --diag_wrap=off --display_error_number --xml_link_info="PLL-TEST1_linkInfo.xml" --rom_model -o "PLL-TEST1.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

PLL-TEST1.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C2000 Hex Utility'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.1.LTS/bin/hex2000"  -o "PLL-TEST1.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "Driver\Source\F2837xD_Adc.obj" "Driver\Source\F2837xD_CodeStartBranch.obj" "Driver\Source\F2837xD_CpuTimers.obj" "Driver\Source\F2837xD_DefaultISR.obj" "Driver\Source\F2837xD_EPwm.obj" "Driver\Source\F2837xD_GlobalVariableDefs.obj" "Driver\Source\F2837xD_Gpio.obj" "Driver\Source\F2837xD_Ipc.obj" "Driver\Source\F2837xD_PieCtrl.obj" "Driver\Source\F2837xD_PieVect.obj" "Driver\Source\F2837xD_SysCtrl.obj" "Driver\Source\F2837xD_usDelay.obj" "Driver\Source\SPLL_1ph_SOGI_F.obj" "Driver\Source\sin_tab.obj" 
	-$(RM) "main.d" "Driver\Source\F2837xD_Adc.d" "Driver\Source\F2837xD_CpuTimers.d" "Driver\Source\F2837xD_DefaultISR.d" "Driver\Source\F2837xD_EPwm.d" "Driver\Source\F2837xD_GlobalVariableDefs.d" "Driver\Source\F2837xD_Gpio.d" "Driver\Source\F2837xD_Ipc.d" "Driver\Source\F2837xD_PieCtrl.d" "Driver\Source\F2837xD_PieVect.d" "Driver\Source\F2837xD_SysCtrl.d" "Driver\Source\SPLL_1ph_SOGI_F.d" "Driver\Source\sin_tab.d" 
	-$(RM) "Driver\Source\F2837xD_CodeStartBranch.d" "Driver\Source\F2837xD_usDelay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

