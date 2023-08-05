/*
 * Si5351B Rev B Configuration Register Export Header File
 *
 * This file represents a series of Skyworks Si5351B Rev B 
 * register writes that can be performed to load a single configuration 
 * on a device. It was created by a Skyworks ClockBuilder Pro
 * export tool.
 *
 * Part:		                                       Si5351B Rev B
 * Design ID:                                          
 * Includes Pre/Post Download Control Register Writes: Yes
 * Created By:                                         ClockBuilder Pro v4.4 [2022-03-30]
 * Timestamp:                                          2022-08-16 18:14:16 GMT+05:30
 *
 * A complete design report corresponding to this export is included at the end 
 * of this header file.
 *
 */

#ifndef SI5351B_REVB_REG_CONFIG_HEADER
#define SI5351B_REVB_REG_CONFIG_HEADER
#include "i2c6.h"
#include <android/log.h>
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "some-tag", __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "some-tag", __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, "some-tag", __VA_ARGS__))
#define SI5351B_ADDRESS  0x60   // slave address A0 is not avaible for Si5351B

#define SI5351B_REVB_REG_CONFIG_NUM_REGS				88

uint8_t ON=0x0F;

typedef struct
{
    unsigned int address; /* 8-bit register address */
    unsigned char value; /* 8-bit register data */

} si5351b_revb_register_t;

si5351b_revb_register_t const si5351b_revb_registers[SI5351B_REVB_REG_CONFIG_NUM_REGS] =
        {
                { 0x0002, 0x53 }, // this IC dosn't have any page selection option , bcoz the registers are limited to 0 to 187; It is 8bit address no need to concider the extra 00 at the begining
                { 0x0003, 0xFF },
                { 0x0004, 0x20 },
                { 0x0007, 0x01 },
                { 0x000F, 0x00 },
                { 0x0010, 0x0F },
                { 0x0011, 0x0F },
                { 0x0012, 0x0F },
                { 0x0013, 0x0F },
                { 0x0014, 0x0F },
                { 0x0015, 0x0F },
                { 0x0016, 0x0F },
                { 0x0017, 0x0F },
                { 0x001A, 0x00 },
                { 0x001B, 0x01 },
                { 0x001C, 0x00 },
                { 0x001D, 0x10 },
                { 0x001E, 0x00 },
                { 0x001F, 0x00 },
                { 0x0020, 0x00 },
                { 0x0021, 0x00 },
                { 0x002A, 0x00 },
                { 0x002B, 0x01 },
                { 0x002C, 0x00 },
                { 0x002D, 0x10 },
                { 0x002E, 0x00 },
                { 0x002F, 0x00 },
                { 0x0030, 0x00 },
                { 0x0031, 0x00 },
                { 0x0032, 0x00 },
                { 0x0033, 0x01 },
                { 0x0034, 0x00 },
                { 0x0035, 0x10 },
                { 0x0036, 0x00 },
                { 0x0037, 0x00 },
                { 0x0038, 0x00 },
                { 0x0039, 0x00 },
                { 0x003A, 0x00 },
                { 0x003B, 0x01 },
                { 0x003C, 0x00 },
                { 0x003D, 0x10 },
                { 0x003E, 0x00 },
                { 0x003F, 0x00 },
                { 0x0040, 0x00 },
                { 0x0041, 0x00 },
                { 0x0042, 0x00 },
                { 0x0043, 0x01 },
                { 0x0044, 0x00 },
                { 0x0045, 0x10 },
                { 0x0046, 0x00 },
                { 0x0047, 0x00 },
                { 0x0048, 0x00 },
                { 0x0049, 0x00 },
                { 0x004A, 0x00 },
                { 0x004B, 0x01 },
                { 0x004C, 0x00 },
                { 0x004D, 0x10 },
                { 0x004E, 0x00 },
                { 0x004F, 0x00 },
                { 0x0050, 0x00 },
                { 0x0051, 0x00 },
                { 0x0052, 0x00 },
                { 0x0053, 0x01 },
                { 0x0054, 0x00 },
                { 0x0055, 0x10 },
                { 0x0056, 0x00 },
                { 0x0057, 0x00 },
                { 0x0058, 0x00 },
                { 0x0059, 0x00 },
                { 0x005A, 0x24 },
                { 0x005B, 0x24 },
                { 0x0095, 0x00 },
                { 0x0096, 0x00 },
                { 0x0097, 0x00 },
                { 0x0098, 0x00 },
                { 0x0099, 0x00 },
                { 0x009A, 0x00 },
                { 0x009B, 0x00 },
                { 0x00A2, 0x00 },
                { 0x00A3, 0x00 },
                { 0x00A4, 0x00 },
                { 0x00A5, 0x00 },
                { 0x00A6, 0x00 },
                { 0x00A7, 0x00 },
                { 0x00A8, 0x00 },
                { 0x00A9, 0x00 },
                { 0x00AA, 0x00 },
                { 0x00B7, 0x92 },
        };

void si5351_write(uint8_t i, u_int8_t i1);

/*
 * Design Report
 *
 * Overview
 * ========
 * Part:               Si5351B
 * Created By:         ClockBuilder Pro v4.4 [2022-03-30]
 * Timestamp:          2022-08-16 18:14:16 GMT+05:30
 * 
 * Design Rule Check
 * =================
 * Errors:
 * - No errors
 * 
 * Warnings:
 * - No warnings
 * 
 * Design
 * ======
 * I2C Address: 0x60
 * 
 * Inputs:
 *     IN0: 25 MHz
 * 
 * Outputs:
 *    OUT0: 25 MHz
 *          Disabled LVCMOS 8 mA
 *          Offset 0.000 s 
 *    OUT1: 25 MHz
 *          Disabled LVCMOS 8 mA
 *          Offset 0.000 s 
 *    OUT2: 25 MHz
 *          Disabled LVCMOS 8 mA
 *          Offset 0.000 s 
 *    OUT3: 25 MHz
 *          Disabled LVCMOS 8 mA
 *          Offset 0.000 s 
 *    OUT4: 25 MHz
 *          Disabled LVCMOS 8 mA
 *          Offset 0.000 s 
 *    OUT5: 25 MHz
 *          Disabled LVCMOS 8 mA
 *          Offset 0.000 s 
 *    OUT6: 25 MHz
 *          Disabled LVCMOS 8 mA
 *          Offset 0.000 s 
 *    OUT7: 25 MHz
 *          Disabled LVCMOS 8 mA
 *          Offset 0.000 s 
 * 
 * Frequency Plan
 * ==============
 * PLL_A:
 *    Enabled Features = None
 *    Fvco             = 900 MHz
 *    M                = 36
 *    Input0:
 *       Source           = Crystal
 *       Source Frequency = 25 MHz
 *       Fpfd             = 25 MHz
 *       Load Capacitance = Load_08pF
 *    Output0:
 *       Features       = None
 *       Disabled State = StopLow
 *       R              = 1  (2^0)
 *       Fout           = 25 MHz
 *       N              = 36
 *    Output1:
 *       Features       = None
 *       Disabled State = StopLow
 *       R              = 1  (2^0)
 *       Fout           = 25 MHz
 *       N              = 36
 *    Output2:
 *       Features       = None
 *       Disabled State = StopLow
 *       R              = 1  (2^0)
 *       Fout           = 25 MHz
 *       N              = 36
 *    Output3:
 *       Features       = None
 *       Disabled State = StopLow
 *       R              = 1  (2^0)
 *       Fout           = 25 MHz
 *       N              = 36
 *    Output4:
 *       Features       = None
 *       Disabled State = StopLow
 *       R              = 1  (2^0)
 *       Fout           = 25 MHz
 *       N              = 36
 *    Output5:
 *       Features       = None
 *       Disabled State = StopLow
 *       R              = 1  (2^0)
 *       Fout           = 25 MHz
 *       N              = 36
 *    Output6:
 *       Features       = None
 *       Disabled State = StopLow
 *       R              = 1  (2^0)
 *       Fout           = 25 MHz
 *       N              = 36
 *    Output7:
 *       Features       = None
 *       Disabled State = StopLow
 *       R              = 1  (2^0)
 *       Fout           = 25 MHz
 *       N              = 36
 * 
 * Settings
 * ========
 * 
 * Location      Setting Name    Decimal Value      Hex Value        
 * ------------  --------------  -----------------  -----------------
 * 0x0002[3]     XO_LOS_MASK     0                  0x0              
 * 0x0002[4]     CLK_LOS_MASK    1                  0x1              
 * 0x0002[5]     LOL_A_MASK      0                  0x0              
 * 0x0002[6]     LOL_B_MASK      1                  0x1              
 * 0x0002[7]     SYS_INIT_MASK   0                  0x0              
 * 0x0003[7:0]   CLK_OEB         255                0xFF             
 * 0x0004[4]     DIS_RESET_LOLA  0                  0x0              
 * 0x0004[5]     DIS_RESET_LOLB  1                  0x1              
 * 0x0007[7:4]   I2C_ADDR_CTRL   0                  0x0              
 * 0x000F[2]     PLLA_SRC        0                  0x0              
 * 0x000F[3]     PLLB_SRC        0                  0x0              
 * 0x000F[4]     PLLA_INSELB     0                  0x0              
 * 0x000F[5]     PLLB_INSELB     0                  0x0              
 * 0x000F[7:6]   CLKIN_DIV       0                  0x0              
 * 0x0010[1:0]   CLK0_IDRV       3                  0x3              
 * 0x0010[3:2]   CLK0_SRC        3                  0x3              
 * 0x0010[4]     CLK0_INV        0                  0x0              
 * 0x0010[5]     MS0_SRC         0                  0x0              
 * 0x0010[6]     MS0_INT         0                  0x0              
 * 0x0010[7]     CLK0_PDN        0                  0x0              
 * 0x0011[1:0]   CLK1_IDRV       3                  0x3              
 * 0x0011[3:2]   CLK1_SRC        3                  0x3              
 * 0x0011[4]     CLK1_INV        0                  0x0              
 * 0x0011[5]     MS1_SRC         0                  0x0              
 * 0x0011[6]     MS1_INT         0                  0x0              
 * 0x0011[7]     CLK1_PDN        0                  0x0              
 * 0x0012[1:0]   CLK2_IDRV       3                  0x3              
 * 0x0012[3:2]   CLK2_SRC        3                  0x3              
 * 0x0012[4]     CLK2_INV        0                  0x0              
 * 0x0012[5]     MS2_SRC         0                  0x0              
 * 0x0012[6]     MS2_INT         0                  0x0              
 * 0x0012[7]     CLK2_PDN        0                  0x0              
 * 0x0013[1:0]   CLK3_IDRV       3                  0x3              
 * 0x0013[3:2]   CLK3_SRC        3                  0x3              
 * 0x0013[4]     CLK3_INV        0                  0x0              
 * 0x0013[5]     MS3_SRC         0                  0x0              
 * 0x0013[6]     MS3_INT         0                  0x0              
 * 0x0013[7]     CLK3_PDN        0                  0x0              
 * 0x0014[1:0]   CLK4_IDRV       3                  0x3              
 * 0x0014[3:2]   CLK4_SRC        3                  0x3              
 * 0x0014[4]     CLK4_INV        0                  0x0              
 * 0x0014[5]     MS4_SRC         0                  0x0              
 * 0x0014[6]     MS4_INT         0                  0x0              
 * 0x0014[7]     CLK4_PDN        0                  0x0              
 * 0x0015[1:0]   CLK5_IDRV       3                  0x3              
 * 0x0015[3:2]   CLK5_SRC        3                  0x3              
 * 0x0015[4]     CLK5_INV        0                  0x0              
 * 0x0015[5]     MS5_SRC         0                  0x0              
 * 0x0015[6]     MS5_INT         0                  0x0              
 * 0x0015[7]     CLK5_PDN        0                  0x0              
 * 0x0016[1:0]   CLK6_IDRV       3                  0x3              
 * 0x0016[3:2]   CLK6_SRC        3                  0x3              
 * 0x0016[4]     CLK6_INV        0                  0x0              
 * 0x0016[5]     MS6_SRC         0                  0x0              
 * 0x0016[6]     FBA_INT         0                  0x0              
 * 0x0016[7]     CLK6_PDN        0                  0x0              
 * 0x0017[1:0]   CLK7_IDRV       3                  0x3              
 * 0x0017[3:2]   CLK7_SRC        3                  0x3              
 * 0x0017[4]     CLK7_INV        0                  0x0              
 * 0x0017[5]     MS7_SRC         0                  0x0              
 * 0x0017[6]     FBB_INT         0                  0x0              
 * 0x0017[7]     CLK7_PDN        0                  0x0              
 * 0x001C[17:0]  MSNA_P1         4096               0x01000          
 * 0x001F[19:0]  MSNA_P2         0                  0x00000          
 * 0x001F[23:4]  MSNA_P3         1                  0x00001          
 * 0x002C[17:0]  MS0_P1          4096               0x01000          
 * 0x002F[19:0]  MS0_P2          0                  0x00000          
 * 0x002F[23:4]  MS0_P3          1                  0x00001          
 * 0x0034[17:0]  MS1_P1          4096               0x01000          
 * 0x0037[19:0]  MS1_P2          0                  0x00000          
 * 0x0037[23:4]  MS1_P3          1                  0x00001          
 * 0x003C[17:0]  MS2_P1          4096               0x01000          
 * 0x003F[19:0]  MS2_P2          0                  0x00000          
 * 0x003F[23:4]  MS2_P3          1                  0x00001          
 * 0x0044[17:0]  MS3_P1          4096               0x01000          
 * 0x0047[19:0]  MS3_P2          0                  0x00000          
 * 0x0047[23:4]  MS3_P3          1                  0x00001          
 * 0x004C[17:0]  MS4_P1          4096               0x01000          
 * 0x004F[19:0]  MS4_P2          0                  0x00000          
 * 0x004F[23:4]  MS4_P3          1                  0x00001          
 * 0x0054[17:0]  MS5_P1          4096               0x01000          
 * 0x0057[19:0]  MS5_P2          0                  0x00000          
 * 0x0057[23:4]  MS5_P3          1                  0x00001          
 * 0x005A[7:0]   MS6_P1          36                 0x24             
 * 0x005B[7:0]   MS7_P1          36                 0x24             
 * 0x0095[14:0]  SSDN_P2         0                  0x0000           
 * 0x0095[7]     SSC_EN          0                  0x0              
 * 0x0097[14:0]  SSDN_P3         0                  0x0000           
 * 0x0097[7]     SSC_MODE        0                  0x0              
 * 0x0099[11:0]  SSDN_P1         0                  0x000            
 * 0x009A[15:4]  SSUDP           0                  0x000            
 * 0x00A2[21:0]  VCXO_PARAM      0                  0x000000         
 * 0x00A5[7:0]   CLK0_PHOFF      0                  0x00             
 * 0x00A6[7:0]   CLK1_PHOFF      0                  0x00             
 * 0x00A7[7:0]   CLK2_PHOFF      0                  0x00             
 * 0x00A8[7:0]   CLK3_PHOFF      0                  0x00             
 * 0x00A9[7:0]   CLK4_PHOFF      0                  0x00             
 * 0x00AA[7:0]   CLK5_PHOFF      0                  0x00             
 * 0x00B7[7:6]   XTAL_CL         2                  0x2
 * 
 *
 */

uint8_t clk0[]={0x10,0x00};
uint8_t clk1[]={0x04,0x00};
uint8_t clk2[]={0x01,0x00};
uint8_t clk3[]={0x40,0x00};
uint8_t clk4[]={0x00,0x01};
uint8_t clk5[]={0x00,0x04};
uint8_t clk6[]={0x00,0x10};
uint8_t clk7[]={0x00,0x40};

void si5351_init() {
    LOGE("si5351b INIT");

    si5351_write(0x03, 0xFF); //Disable Outputs Set CLKx_DIS HIGH
    si5351_write(0x10, 0x80); //0x10 is register 16; 0x80 is used to POWER DOWN for clock 0; MS 0 - fractional division mode; Select PLLA as the source for MS 0; Output Clock 0 is not inverted;Output
    // Clock 0 Input Source; CLK0 Output Rise and Fall time(2mA)
    si5351_write(0x11, 0x80); //0x11 is register 17; 0x80 is used to POWER DOWN for clock 1; MS 1 - fractional division mode; Select PLLA as the source for MS 1; Output Clock 1 is not inverted;
    // OutputClock 1 Input Source; CLK1 Output Rise and Fall time(2mA)
    si5351_write(0x12, 0x80); //0x12 is register 18; 0x80 is used to POWER DOWN for clock 2; MS 2 - fractional division mode; Select PLLA as the source for MS 2; Output Clock 2 is not inverted;
    // OutputClock 2 Input Source; CLK2 Output Rise and Fall time(2mA)
    si5351_write(0x13, 0x80); //0x13 is register 19; 0x80 is used to POWER DOWN for clock 3; MS 3 - fractional division mode; Select PLLA as the source for MS 3; Output Clock 3 is not inverted;OutputClock 3 Input Source; CLK3 Output Rise and Fall time(2mA)
    si5351_write(0x14, 0x80); //0x14 is register 20; 0x80 is used to POWER DOWN for clock 4; MS 4 - fractional division mode; Select PLLA as the source for MS 4; Output Clock 4 is not inverted;Output Clock 4 Input Source; CLK4 Output Rise and Fall time(2mA)
    si5351_write(0x15, 0x80); //0x15 is register 21; 0x80 is used to POWER DOWN for clock 5; MS 5 - fractional division mode; Select PLLA as the source for MS 5; Output Clock 5 is not inverted;Output Clock 5 Input Source; CLK5 Output Rise and Fall time(2mA)
    si5351_write(0x16, 0x80); //0x16 is register 22; 0x80 is used to POWER DOWN for clock 6; MS 6 - fractional division mode; Select PLLA as the source for MS 6; Output Clock 6 is not inverted;Output Clock 6 Input Source; CLK6 Output Rise and Fall time(2mA)
    si5351_write(0x17, 0x80); //0x17 is register 23; 0x80 is used to POWER DOWN for clock 7; MS 7 - fractional division mode; Select PLLA as the source for MS 7; Output Clock 7 is not inverted;Output Clock 7 Input Source; CLK7 Output Rise and Fall time(2mA)
    si5351_write(0x02, 0xF8); //Enabling Interrupt status mask - may be only for si5351C 'need to confirm'
    for (int i=0;i< ARRAY_SIZE(si5351b_revb_registers);i++){
        if((si5351b_revb_registers[i].address>=0x000F)&&(si5351b_revb_registers[i].address<=0x005C)){  //x>15 and  x<92
            si5351_write(si5351b_revb_registers[i].address, si5351b_revb_registers[i].value);
        }else if((si5351b_revb_registers[i].address>=0x0095)&&(si5351b_revb_registers[i].address<=0x00AA)){ //x<149 x>170
            si5351_write(si5351b_revb_registers[i].address, si5351b_revb_registers[i].value);
        }

    }
    si5351_write(0xB1, 0xAC); // soft reset for PLLA and PLLB
    si5351_write(0x03, 0xFF);
    si5351_write(0x18, 0x00); // Reg24
//    si5351_write(0x19, 0x00); // Reg25
    LOGE("si5351b INIT END");
    LOGE("si5351b INIT EXPERIMENTAL START");
    si5351_write(0x10, 0x00); //0x10 is register 16; 0x80 is used to POWER DOWN for clock 0; MS 0 - fractional division mode; Select PLLA as the source for MS 0; Output Clock 0 is not inverted;Output
    // Clock 0 Input Source; CLK0 Output Rise and Fall time(2mA)
    si5351_write(0x11, 0x00); //0x11 is register 17; 0x80 is used to POWER DOWN for clock 1; MS 1 - fractional division mode; Select PLLA as the source for MS 1; Output Clock 1 is not inverted;
    // OutputClock 1 Input Source; CLK1 Output Rise and Fall time(2mA)
    si5351_write(0x12, 0x00); //0x12 is register 18; 0x80 is used to POWER DOWN for clock 2; MS 2 - fractional division mode; Select PLLA as the source for MS 2; Output Clock 2 is not inverted;
    // OutputClock 2 Input Source; CLK2 Output Rise and Fall time(2mA)
    si5351_write(0x13, 0x00); //0x13 is register 19; 0x80 is used to POWER DOWN for clock 3; MS 3 - fractional division mode; Select PLLA as the source for MS 3; Output Clock 3 is not inverted;
    // OutputClock 3 Input Source; CLK3 Output Rise and Fall time(2mA)
    si5351_write(0x14, 0x00); //0x14 is register 20; 0x80 is used to POWER DOWN for clock 4; MS 4 - fractional division mode; Select PLLA as the source for MS 4; Output Clock 4 is not inverted;
    // Output Clock 4 Input Source; CLK4 Output Rise and Fall time(2mA)
    si5351_write(0x15, 0x00); //0x15 is register 21; 0x80 is used to POWER DOWN for clock 5; MS 5 - fractional division mode; Select PLLA as the source for MS 5; Output Clock 5 is not inverted;
    // Output Clock 5 Input Source; CLK5 Output Rise and Fall time(2mA)
    si5351_write(0x16, 0x00); //0x16 is register 22; 0x80 is used to POWER DOWN for clock 6; MS 6 - fractional division mode; Select PLLA as the source for MS 6; Output Clock 6 is not inverted;
    // Output Clock 6 Input Source; CLK6 Output Rise and Fall time(2mA)
    si5351_write(0x17, 0x00); //0x17 is register 23; 0x80 is used to POWER DOWN for clock 7; MS 7 - fractional division mode; Select PLLA as the source for MS 7; Output Clock 7 is not inverted;
    // Output Clock 7 Input Source; CLK7 Output Rise and Fall time(2mA)
    LOGE("si5351b INIT EXPERIMENTAL END");

}

void si5351_write(uint8_t reg_addr, u_int8_t buf) {
    opendevice();
    write_i2c_device_8(SI5351B_ADDRESS, reg_addr, &buf);
    closedevice();

}


// REGISTER 25 AN619
// IF ALL OUTPUTS ARE DISABLED THROUGH REG3 or OEB pin
// THEN VALUE OF OUTPUT WILL BE DETERMINED BY REG25(0x19) and REG24(0x18)

void turnOn395Nm() {
    LOGE("si5351b 395NM LED PULLUP START");
    si5351_write(0x09, 0xff);
    si5351_write(0x18, 0x10);
    si5351_write(0x19, 0x40);
}


void turnOn395SNm() {
    LOGE("si5351b 395NM LED PULLUP START");
    si5351_write(0x09, 0xff);
    si5351_write(0x18, 0x40);
    si5351_write(0x19, 0x00);
}


void turnOn365Nm() {
    LOGE("si5351b 365 PULLUP START");
    uint8_t LED_365 = 0x02;
    si5351_write(0x09, 0xff);
    si5351_write(0x18, 0x04);
    si5351_write(0x19, 0x01);
    LOGE("si5351b 365 PULLUP END");
}

void turnOn450Nm() {
    LOGE("si5351b 365 PULLUP START");
    si5351_write(0x09, 0xff);
    si5351_write(0x18, 0x00);
    si5351_write(0x19, 0x10);
    LOGE("si5351b 365 PULLUP END");
}
void turnOnClk0NM() {
    LOGE("si5351b Clk0 LED PULLUP START");
    si5351_write(0x18, 0x10);
    si5351_write(0x19, 0x00);
    LOGE("si5351b Clk0 PULLUP END");
};


void turnOnClk1NM() {
    LOGE("si5351b Clk1 PULLUP START");
    si5351_write(0x18, 0x04);
    si5351_write(0x19, 0x00);
    LOGE("si5351b Clk1 PULLUP END");
};


void turnOnClk2NM() {
    LOGE("si5351b 850NM LED PULLUP START");
    si5351_write(0x18, 0x01);
    si5351_write(0x19, 0x00);
    LOGE("si5351b 850NM PULLUP END");
};


void turnOnClk3NM() {
    LOGE("si5351b CLK3 PULLUP START");
    si5351_write(0x18, 0x40);
    si5351_write(0x19, 0x00);
    LOGE("si5351b CLK3 PULLUP END");
};

void turnOnClk4NM() {
    LOGE("si5351b CLK4 LED PULLUP START");
    si5351_write(0x18, 0x00);
    si5351_write(0x19, 0x01);
    LOGE("si5351b CLK4 PULLUP END");
};


void turnOnClk5NM() {
    LOGE("si5351b CLK5 PULLUP START");
    si5351_write(0x18, 0x00);
    si5351_write(0x19, 0x04);
    LOGE("si5351b CLK5 PULLUP END");
};


void turnOnClk6NM() {
    LOGE("si5351b CLK6 PULLUP START");
    si5351_write(0x18, 0x00);
    si5351_write(0x19, 0x10);
    LOGE("si5351b CLK6 PULLUP END");
};

void turnOnClk7NM() {
    LOGE("si5351b CLK7 PULLUP START");
    si5351_write(0x18, 0x00);
    si5351_write(0x19, 0x40);
    LOGE("si5351b CLK7 PULLUP END");
};


void groupTurnONLed(JNIEnv *env,jintArray clks){
    int i, sum = 0;
    int finalclkW[]={0x00,0x00};
    jsize len = (*env).GetArrayLength(clks);
    jint *body = (*env).GetIntArrayElements( clks, 0);
    for (i=0; i<len; i++) {
        if(body[i]==(jint) 0){
            finalclkW[0]+=clk0[0];
            finalclkW[1]+=clk0[1];
        }
        if(body[i]==1){
            finalclkW[0]+=clk1[0];
            finalclkW[1]+=clk1[1];
        }
        if(body[i]==2){
            finalclkW[0]+=clk2[0];
            finalclkW[1]+=clk2[1];
        }
        if(body[i]==3){
            finalclkW[0]+=clk3[0];
            finalclkW[1]+=clk3[1];
        }
        if(body[i]==4){
            finalclkW[0]+=clk4[0];
            finalclkW[1]+=clk4[1];
        }
        if(body[i]==5){
            finalclkW[0]+=clk5[0];
            finalclkW[1]+=clk5[1];
        }
        if(body[i]==6){
            finalclkW[0]+=clk6[0];
            finalclkW[1]+=clk6[1];
        }
        if(body[i]==7){
            finalclkW[0]+=clk7[0];
            finalclkW[1]+=clk7[1];
        }
    }
    si5351_write(0x09, 0xff);
    si5351_write(0x18, finalclkW[0]);
    si5351_write(0x19, finalclkW[1]);
}

void turnOff(){
    LOGE("si5351b KILL ALL START");
    si5351_write(0x18, 0x00);
    si5351_write(0x19, 0x00);
    LOGE("si5351b KILL ALL  END");
}

#endif