################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bintree.c \
../src/bitmask.c \
../src/hashtable.c \
../src/list.c \
../src/queue.c \
../src/sjjg.c \
../src/sorting.c \
../src/stack.c 

OBJS += \
./src/bintree.o \
./src/bitmask.o \
./src/hashtable.o \
./src/list.o \
./src/queue.o \
./src/sjjg.o \
./src/sorting.o \
./src/stack.o 

C_DEPS += \
./src/bintree.d \
./src/bitmask.d \
./src/hashtable.d \
./src/list.d \
./src/queue.d \
./src/sjjg.d \
./src/sorting.d \
./src/stack.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


