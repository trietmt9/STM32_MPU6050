#include <stm32f4xx.h>
<<<<<<< HEAD

extern I2C_HandleTypeDef hi2c1;
#define MPU6050_Address         0xD0
=======
#include <math.h>
#include <stdint.h>
#define MPU6050_Address         0x68
>>>>>>> 45d5a5918c0c82d06af1aa756b8ba5175a7b412e
#define WHO_AM_I                0x75
#define SMPRT_DIV               0x19
#define GYRO_CONFIG             0x1B
#define GYRO_XOUT               0x43
#define ACCEL_CONFIG            0x1C
#define ACCEL_XOUT              0x3B
#define PWR_MGMT_1              0x6B
<<<<<<< HEAD

typedef struct 
{
    float Gx_Callib;
    float Gy_Callib;
    float Gz_Callib;

=======
typedef struct 
{
>>>>>>> 45d5a5918c0c82d06af1aa756b8ba5175a7b412e
    float Gx;
    float Gy;
    float Gz;

    float Ax;
    float Ay;
    float Az;

    int16_t Gx_RAW;
    int16_t Gy_RAW;
    int16_t Gz_RAW;

    int16_t Ax_RAW;
    int16_t Ay_RAW;
    int16_t Az_RAW;
<<<<<<< HEAD


}mpu6050_t;

void MPU6050_Init();
void MPU6050_Read_Acc(mpu6050_t *Data);
void MPU6050_Read_Gyro(mpu6050_t *Data);
=======
}mpu6050_t;
void MPU6050_Init();
void MPU6050_Read_Acc(mpu6050_t *Data);
void MPU6050_Read_Gyro(mpu6050_t *Data);
>>>>>>> 45d5a5918c0c82d06af1aa756b8ba5175a7b412e
