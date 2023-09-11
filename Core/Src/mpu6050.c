#include <mpu6050.h>
extern I2C_HandleTypeDef hi2c1;

void MPU6050_Init()
{
    uint8_t check; 
    uint8_t Data;

    HAL_I2C_Mem_Read(&hi2c1, (MPU6050_Address<<1), WHO_AM_I, 1, &check, 1,100);
    if(check == MPU6050_Address)
    {
        Data = 0;
        HAL_I2C_Mem_Write(&hi2c1, (MPU6050_Address<<1), PWR_MGMT_1, 1, &Data, 1, 100);

        Data = 0x07;
        HAL_I2C_Mem_Write(&hi2c1, (MPU6050_Address<<1), SMPRT_DIV, 1, &Data, 1, 100);

        Data = 0;
        HAL_I2C_Mem_Write(&hi2c1, (MPU6050_Address<<1), ACCEL_CONFIG, 1,&Data, 1, 100);

        Data = 0;
        HAL_I2C_Mem_Write(&hi2c1, (MPU6050_Address<<1), GYRO_CONFIG, 1,&Data, 1, 100);
    }
}

void MPU6050_Read(mpu6050_t *Data)
{
    uint16_t Accel_Data[6];
    HAL_I2C_Mem_Read(&hi2c1, (MPU6050_Address<<1), ACCEL_XOUT, 1, &Accel_Data, 6, 100);
    Data->Ax_RAW = ((Accel_Data[0]<<8)|Accel_Data[1]);
    Data->Ay_RAW = ((Accel_Data[2]<<8)|Accel_Data[3]);
    Data->Az_RAW = ((Accel_Data[4]<<8)|Accel_Data[5]);

    Data->Ax = Data->Ax_RAW/16384.0;
    Data->Ay = Data->Ay_RAW/16384.0;
    Data->Az = Data->Az_RAW/16384.0;

    uint16_t Gyro_Data[6];
    HAL_I2C_Mem_Read(&hi2c1, (MPU6050_Address<<1), ACCEL_XOUT, 1, &Gyro_Data, 6, 100);
    Data->Gx_RAW = ((Gyro_Data[0]<<8)|Gyro_Data[1]);
    Data->Gy_RAW = ((Gyro_Data[2]<<8)|Gyro_Data[3]);
    Data->Gz_RAW = ((Gyro_Data[4]<<8)|Gyro_Data[5]);

    Data->Gx = Data->Gx_RAW/131.0;
    Data->Gy = Data->Gy_RAW/131.0;
    Data->Gz = Data->Gz_RAW/131.0;

}