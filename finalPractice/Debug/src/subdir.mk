################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Strings1.c \
../src/finalPractice.c 

C_DEPS += \
./src/Strings1.d \
./src/finalPractice.d 

OBJS += \
./src/Strings1.o \
./src/finalPractice.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Strings1.d ./src/Strings1.o ./src/finalPractice.d ./src/finalPractice.o

.PHONY: clean-src

