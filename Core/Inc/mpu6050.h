#ifndef MPU6050_H
#define MPU6050_H
#include <stm32f4xx.h>
#include <math.h>
#include <stdint.h>
#define MPU6050_Address         0x68
#define WHO_AM_I                0x75
#define SMPRT_DIV               0x19
#define GYRO_CONFIG             0x1B
#define GYRO_XOUT               0x43
#define ACCEL_CONFIG            0x1C
#define ACCEL_XOUT              0x3B
#define PWR_MGMT_1              0x6B
#define RAD2DEG                 57.2957795131

typedef struct 
{
    float Gx;
    float Gy;
    float Gz;
    
    float Gx_Callib;
    float Gy_Callib;
    float Gz_Callib;

    float Ax;
    float Ay;
    float Az;
    int16_t Gx_RAW;
    int16_t Gy_RAW;
    int16_t Gz_RAW;
    int16_t Ax_RAW;
    int16_t Ay_RAW;
    int16_t Az_RAW;
    float Roll;
    float Pitch;

    float KalmanRoll;
    float KalmanPitch;
}mpu6050_t;

void MPU6050_Init();
void MPU6050_Read(mpu6050_t *Data);

#endif


