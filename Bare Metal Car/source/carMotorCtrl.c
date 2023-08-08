#include <carMotorCtrl.h>
#include <gpio.h>
#include <rcc.h>

#define MOTOR_ENABLE_ALL_1_2_4_3 0x00000C00 // EA & EB
#define MOTOR_ENABLE_LEFT_1_2 0x00000800	// EA
#define MOTOR_ENABLE_RIGHT_4_3 0x00000400	// EB

// L293d CONTORL
//  IN1		IN2		Spinning Direction
//  Low(0)	Low(0)	Motor OFF
//  High(1)	Low(0)	Forward
//  Low(0)	High(1)	Backward
//  High(1)	High(1)	Motor OFF
#define CAR_FORWARD_LEFT_1_2 0x00001000	 // IN1
#define CAR_BACKWARD_LEFT_1_2 0x00002000 // IN2
#define CAR_OFF_LOW_LEFT_1_2 0x00000000	 // ~CAR_OFF_HIGH_LEFT_1_2
#define CAR_OFF_HIGH_LEFT_1_2 0x00003000 // IN1 & IN2

#define CAR_FORWARD_RIGHT_4_3 0x00004000  // IN4
#define CAR_BACKWARD_RIGHT_4_3 0x00008000 // IN3
#define CAR_OFF_LOW_RIGHT_4_3 0x00000000  // ~CAR_OFF_HIGH_RIGHT_4_3
#define CAR_OFF_HIGH_RIGHT_4_3 0x0000C000 // IN4 & IN3

// L293D motor driver IC
void motorCtrlInit()
{
	// Enable clock on port B
	_RCCRA(RCC)->APB2ENR |= RCC_APB2ENR_IOPBEN;

	// Reset MODE for pins 10-15 -> 00: Input mode (reset state)
	_GPIOPRA(GPIO_P_B)->CRH &= ~GPIO_CRH_MODE10; // ENB
	_GPIOPRA(GPIO_P_B)->CRH &= ~GPIO_CRH_MODE11; // ENA
	_GPIOPRA(GPIO_P_B)->CRH &= ~GPIO_CRH_MODE12; // IN1
	_GPIOPRA(GPIO_P_B)->CRH &= ~GPIO_CRH_MODE13; // IN2
	_GPIOPRA(GPIO_P_B)->CRH &= ~GPIO_CRH_MODE14; // IN4
	_GPIOPRA(GPIO_P_B)->CRH &= ~GPIO_CRH_MODE15; // IN3

	// Setup MODE for pins 10-15 -> 11: Output mode, max speed 50 MHz
	_GPIOPRA(GPIO_P_B)->CRH |= GPIO_CRH_MODE10; // ENB
	_GPIOPRA(GPIO_P_B)->CRH |= GPIO_CRH_MODE11; // ENA
	_GPIOPRA(GPIO_P_B)->CRH |= GPIO_CRH_MODE12; // IN1
	_GPIOPRA(GPIO_P_B)->CRH |= GPIO_CRH_MODE13; // IN2
	_GPIOPRA(GPIO_P_B)->CRH |= GPIO_CRH_MODE14; // IN4
	_GPIOPRA(GPIO_P_B)->CRH |= GPIO_CRH_MODE15; // IN3

	// Reset CNF for pins 10-15 -> 00: General purpose output push-pull
	_GPIOPRA(GPIO_P_B)->CRH &= ~GPIO_CRH_CNF10; // ENB
	_GPIOPRA(GPIO_P_B)->CRH &= ~GPIO_CRH_CNF11; // ENA
	_GPIOPRA(GPIO_P_B)->CRH &= ~GPIO_CRH_CNF12; // IN1
	_GPIOPRA(GPIO_P_B)->CRH &= ~GPIO_CRH_CNF13; // IN2
	_GPIOPRA(GPIO_P_B)->CRH &= ~GPIO_CRH_CNF14; // IN4
	_GPIOPRA(GPIO_P_B)->CRH &= ~GPIO_CRH_CNF15; // IN3
}

void motorEnable()
{
	_GPIOPRA(GPIO_P_B)->ODR |= MOTOR_ENABLE_ALL_1_2_4_3;
}

void motorDisable()
{
	_GPIOPRA(GPIO_P_B)->ODR &= ~MOTOR_ENABLE_ALL_1_2_4_3;
	_GPIOPRA(GPIO_P_B)->ODR &= ~CAR_OFF_HIGH_LEFT_1_2;
	_GPIOPRA(GPIO_P_B)->ODR &= ~CAR_OFF_HIGH_RIGHT_4_3;
}

void carForward()
{
	motorEnable();

	_GPIOPRA(GPIO_P_B)->ODR |= CAR_FORWARD_LEFT_1_2;
	_GPIOPRA(GPIO_P_B)->ODR |= CAR_FORWARD_RIGHT_4_3;
}

void carBackward()
{
	motorEnable();

	_GPIOPRA(GPIO_P_B)->ODR |= CAR_BACKWARD_LEFT_1_2;
	_GPIOPRA(GPIO_P_B)->ODR |= CAR_BACKWARD_RIGHT_4_3;
}
void carTurnLeft()
{
	_GPIOPRA(GPIO_P_B)->ODR &= ~MOTOR_ENABLE_LEFT_1_2;
}

void carTurnRight()
{
	_GPIOPRA(GPIO_P_B)->ODR &= ~MOTOR_ENABLE_RIGHT_4_3;
}
