################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/graph.c \
../src/graph_ptest.c \
../src/queue_stack.c 

C_DEPS += \
./src/graph.d \
./src/graph_ptest.d \
./src/queue_stack.d 

OBJS += \
./src/graph.o \
./src/graph_ptest.o \
./src/queue_stack.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/graph.d ./src/graph.o ./src/graph_ptest.d ./src/graph_ptest.o ./src/queue_stack.d ./src/queue_stack.o

.PHONY: clean-src

