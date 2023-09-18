#include <mpu6050.h>

extern I2C_HandleTypeDef hi2c1;


void MPU6050_Init()
{
    uint8_t check,Data; 

    HAL_I2C_Mem_Read(&hi2c1, (MPU6050_Address<<1), WHO_AM_I, 1, &check, 1,1000);
    if(check == MPU6050_Address)
    {
        Data = 0;
        HAL_I2C_Mem_Write(&hi2c1, (MPU6050_Address<<1), PWR_MGMT_1, 1, &Data, 1, 1000);

        Data = 0x07;
        HAL_I2C_Mem_Write(&hi2c1, (MPU6050_Address<<1), SMPRT_DIV, 1, &Data, 1, 1000);

        Data = 0x0;
        HAL_I2C_Mem_Write(&hi2c1, (MPU6050_Address<<1), ACCEL_CONFIG, 1,&Data, 1, 1000);

        Data = 0x0;
        HAL_I2C_Mem_Write(&hi2c1, (MPU6050_Address<<1), GYRO_CONFIG, 1,&Data, 1, 1000);
    }
}


void MPU6050_Read(mpu6050_t *Data)
{
    uint8_t Accel_Data[6];
    HAL_I2C_Mem_Read(&hi2c1, (MPU6050_Address<<1), ACCEL_XOUT, 1, &Accel_Data, 6, 1000);
    Data->Ax_RAW =(int16_t) (Accel_Data[0] <<8 | Accel_Data[1]);
    Data->Ay_RAW =(int16_t) (Accel_Data[2] <<8 | Accel_Data[3]);
    Data->Az_RAW =(int16_t) (Accel_Data[4] <<8 | Accel_Data[5]);
 
     uint8_t Gyro_Data[6];
    HAL_I2C_Mem_Read(&hi2c1, (MPU6050_Address<<1), ACCEL_XOUT, 1, &Gyro_Data, 6, 1000);
    Data->Gx_RAW =(int16_t) (Gyro_Data[0] << 8 | Gyro_Data[1]);
    Data->Gy_RAW =(int16_t) (Gyro_Data[2] << 8 | Gyro_Data[3]);
    Data->Gz_RAW =(int16_t) (Gyro_Data[4] << 8 | Gyro_Data[5]);

    Data->Gx = Data->Gx_RAW/65.5;
    Data->Gy = Data->Gy_RAW/65.5;
    Data->Gz = Data->Gz_RAW/65.5;

    Data->Ax = Data->Ax_RAW/4096.0;
    Data->Ay = Data->Ay_RAW/4096.0;
    Data->Az = Data->Az_RAW/4096.0;

    Data->Roll = atan(Data->Ax/(sqrt(pow(Data->Ay,2)+pow(Data->Az,2))))*RAD2DEG;
    Data->Pitch = atan((-1*Data->Ay)/(sqrt( pow(Data->Ax,2) + pow(Data->Az,2) )))*RAD2DEG;
}