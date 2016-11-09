######################################
# Makefile by CubeMX2Makefile.py
######################################

######################################
# target
######################################
TARGET = thumbinator-i2c-oled

######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -O0

#######################################
# pathes
#######################################
# Build path
BUILD_DIR = build

######################################
# source
######################################
C_SOURCES = \
  Src/usb_device.c \
  Src/usbd_conf.c \
  Src/usbd_desc.c \
  Src/usbd_cdc_if.c \
  Src/stm32f0xx_it.c \
  Src/stm32f0xx_hal_msp.c \
  Src/main.c \
  Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pcd.c \
  Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pcd_ex.c \
  Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c.c \
  Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c_ex.c \
  Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim.c \
  Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim_ex.c \
  Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_usart.c \
  Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc.c \
  Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc_ex.c \
  Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.c \
  Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_gpio.c \
  Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_dma.c \
  Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_cortex.c \
  Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr.c \
  Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr_ex.c \
  Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash.c \
  Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash_ex.c \
  Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/system_stm32f0xx.c \
  Drivers/u8glib/src/u8g_arm.c \
  Drivers/u8glib/src/u8g_bitmap.c \
  Drivers/u8glib/src/u8g_circle.c \
  Drivers/u8glib/src/u8g_clip.c \
  Drivers/u8glib/src/u8g_com_api.c \
  Drivers/u8glib/src/u8g_com_api_16gr.c \
  Drivers/u8glib/src/u8g_com_i2c.c \
  Drivers/u8glib/src/u8g_com_io.c \
  Drivers/u8glib/src/u8g_com_msp430_hw_spi.c \
  Drivers/u8glib/src/u8g_com_null.c \
  Drivers/u8glib/src/u8g_com_raspberrypi_hw_spi.c \
  Drivers/u8glib/src/u8g_com_raspberrypi_ssd_i2c.c \
  Drivers/u8glib/src/u8g_com_std_sw_spi.c \
  Drivers/u8glib/src/u8g_cursor.c \
  Drivers/u8glib/src/u8g_delay.c \
  Drivers/u8glib/src/u8g_dev_a2_micro_printer.c \
  Drivers/u8glib/src/u8g_dev_flipdisc_2x7.c \
  Drivers/u8glib/src/u8g_dev_gprof.c \
  Drivers/u8glib/src/u8g_dev_ht1632.c \
  Drivers/u8glib/src/u8g_dev_ili9325d_320x240.c \
  Drivers/u8glib/src/u8g_dev_ks0108_128x64.c \
  Drivers/u8glib/src/u8g_dev_lc7981_160x80.c \
  Drivers/u8glib/src/u8g_dev_lc7981_240x128.c \
  Drivers/u8glib/src/u8g_dev_lc7981_240x64.c \
  Drivers/u8glib/src/u8g_dev_lc7981_320x64.c \
  Drivers/u8glib/src/u8g_dev_ld7032_60x32.c \
  Drivers/u8glib/src/u8g_dev_null.c \
  Drivers/u8glib/src/u8g_dev_pcd8544_84x48.c \
  Drivers/u8glib/src/u8g_dev_pcf8812_96x65.c \
  Drivers/u8glib/src/u8g_dev_sbn1661_122x32.c \
  Drivers/u8glib/src/u8g_dev_ssd1306_128x32.c \
  Drivers/u8glib/src/u8g_dev_ssd1306_128x64.c \
  Drivers/u8glib/src/u8g_dev_ssd1306_64x48.c \
  Drivers/u8glib/src/u8g_dev_ssd1309_128x64.c \
  Drivers/u8glib/src/u8g_dev_ssd1322_nhd31oled_bw.c \
  Drivers/u8glib/src/u8g_dev_ssd1322_nhd31oled_gr.c \
  Drivers/u8glib/src/u8g_dev_ssd1325_nhd27oled_bw.c \
  Drivers/u8glib/src/u8g_dev_ssd1325_nhd27oled_bw_new.c \
  Drivers/u8glib/src/u8g_dev_ssd1325_nhd27oled_gr.c \
  Drivers/u8glib/src/u8g_dev_ssd1325_nhd27oled_gr_new.c \
  Drivers/u8glib/src/u8g_dev_ssd1327_96x96_gr.c \
  Drivers/u8glib/src/u8g_dev_ssd1351_128x128.c \
  Drivers/u8glib/src/u8g_dev_ssd1353_160x128.c \
  Drivers/u8glib/src/u8g_dev_st7565_64128n.c \
  Drivers/u8glib/src/u8g_dev_st7565_dogm128.c \
  Drivers/u8glib/src/u8g_dev_st7565_dogm132.c \
  Drivers/u8glib/src/u8g_dev_st7565_lm6059.c \
  Drivers/u8glib/src/u8g_dev_st7565_lm6063.c \
  Drivers/u8glib/src/u8g_dev_st7565_nhd_c12832.c \
  Drivers/u8glib/src/u8g_dev_st7565_nhd_c12864.c \
  Drivers/u8glib/src/u8g_dev_st7687_c144mvgd.c \
  Drivers/u8glib/src/u8g_dev_st7920_128x64.c \
  Drivers/u8glib/src/u8g_dev_st7920_192x32.c \
  Drivers/u8glib/src/u8g_dev_st7920_202x32.c \
  Drivers/u8glib/src/u8g_dev_t6963_128x128.c \
  Drivers/u8glib/src/u8g_dev_t6963_128x64.c \
  Drivers/u8glib/src/u8g_dev_t6963_240x128.c \
  Drivers/u8glib/src/u8g_dev_t6963_240x64.c \
  Drivers/u8glib/src/u8g_dev_tls8204_84x48.c \
  Drivers/u8glib/src/u8g_dev_uc1601_c128032.c \
  Drivers/u8glib/src/u8g_dev_uc1608_240x128.c \
  Drivers/u8glib/src/u8g_dev_uc1608_240x64.c \
  Drivers/u8glib/src/u8g_dev_uc1610_dogxl160.c \
  Drivers/u8glib/src/u8g_dev_uc1611_dogm240.c \
  Drivers/u8glib/src/u8g_dev_uc1611_dogxl240.c \
  Drivers/u8glib/src/u8g_dev_uc1701_dogs102.c \
  Drivers/u8glib/src/u8g_dev_uc1701_mini12864.c \
  Drivers/u8glib/src/u8g_ellipse.c \
  Drivers/u8glib/src/u8g_font.c \
  Drivers/u8glib/src/u8g_font_data.c \
  Drivers/u8glib/src/u8g_line.c \
  Drivers/u8glib/src/u8g_ll_api.c \
  Drivers/u8glib/src/u8g_page.c \
  Drivers/u8glib/src/u8g_pb.c \
  Drivers/u8glib/src/u8g_pb14v1.c \
  Drivers/u8glib/src/u8g_pb16h1.c \
  Drivers/u8glib/src/u8g_pb16h2.c \
  Drivers/u8glib/src/u8g_pb16v1.c \
  Drivers/u8glib/src/u8g_pb16v2.c \
  Drivers/u8glib/src/u8g_pb32h1.c \
  Drivers/u8glib/src/u8g_pb8h1.c \
  Drivers/u8glib/src/u8g_pb8h1f.c \
  Drivers/u8glib/src/u8g_pb8h2.c \
  Drivers/u8glib/src/u8g_pb8h8.c \
  Drivers/u8glib/src/u8g_pb8v1.c \
  Drivers/u8glib/src/u8g_pb8v2.c \
  Drivers/u8glib/src/u8g_pbxh16.c \
  Drivers/u8glib/src/u8g_pbxh24.c \
  Drivers/u8glib/src/u8g_polygon.c \
  Drivers/u8glib/src/u8g_rect.c \
  Drivers/u8glib/src/u8g_rot.c \
  Drivers/u8glib/src/u8g_scale.c \
  Drivers/u8glib/src/u8g_state.c \
  Drivers/u8glib/src/u8g_u16toa.c \
  Drivers/u8glib/src/u8g_u8toa.c \
  Drivers/u8glib/src/u8g_virtual_screen.c \
  Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c \
  Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c \
  Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c \
  Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.c  
ASM_SOURCES = \
  Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/gcc/startup_stm32f072xb.s

#######################################
# binaries
#######################################
CC = arm-none-eabi-gcc
AS = arm-none-eabi-gcc -x assembler-with-cpp
CP = arm-none-eabi-objcopy
AR = arm-none-eabi-ar
SZ = arm-none-eabi-size
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
 
#######################################
# CFLAGS
#######################################
# macros for gcc
AS_DEFS =
C_DEFS = -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F072xB
# includes for gcc
AS_INCLUDES =
C_INCLUDES = -IInc
C_INCLUDES += -IDrivers/STM32F0xx_HAL_Driver/Inc
C_INCLUDES += -IDrivers/STM32F0xx_HAL_Driver/Inc/Legacy
C_INCLUDES += -IDrivers/CMSIS/Device/ST/STM32F0xx/Include
C_INCLUDES += -IDrivers/CMSIS/Include
C_INCLUDES += -IDrivers/u8glib/inc
C_INCLUDES += -IMiddlewares/ST/STM32_USB_Device_Library/Core/Inc
C_INCLUDES += -IMiddlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc
# compile gcc flags
ASFLAGS = -mthumb -mcpu=cortex-m0 $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections
CFLAGS = -mthumb -mcpu=cortex-m0 $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections
ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif
# Generate dependency information
CFLAGS += -std=c99 -MD -MP -MF .dep/$(@F).d

#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = STM32F072CBTx_FLASH.ld
# libraries
LIBS = -lc -lm -lnosys
LIBDIR =
LDFLAGS = -mthumb -mcpu=cortex-m0 -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin

#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir -p $@		

#######################################
# clean up
#######################################
clean:
	-rm -fR .dep $(BUILD_DIR)
  
#######################################
# dependencies
#######################################
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)

.PHONY: clean all

# *** EOF ***
