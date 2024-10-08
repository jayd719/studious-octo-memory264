################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/A8-finalPractice.c \
../src/avl.c 

C_DEPS += \
./src/A8-finalPractice.d \
./src/avl.d 

OBJS += \
./src/A8-finalPractice.o \
./src/avl.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/A8-finalPractice.d ./src/A8-finalPractice.o ./src/avl.d ./src/avl.o

.PHONY: clean-src

