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

typedef struct
{

    /* Reading raw values variables*/
    int16_t Gx_RAW;
    int16_t Gy_RAW;
    int16_t Gz_RAW;

    int16_t Ax_RAW;
    int16_t Ay_RAW;
    int16_t Az_RAW;

    /* Convert true values variables*/
    double Cali_Gx;
    double Cali_Gy;
    double Cali_Gz;
    
    double Gx;
    double Gy;
    double Gz;

    double Ax;
    double Ay;
    double Az;

    float Roll_Angle;
    float Pitch_Angle;
    float Total_Acc_Vector;
    float Roll_Angle_Acc;
    float Pitch_Angle_Acc;
    float Roll_Output;
    float Pitch_Output;


}mpu6050_t; 

void MPU6050_Init();
void MPU6050_Read();