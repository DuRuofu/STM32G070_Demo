SET PATH=C:\Keil_v5\ARM\ARMCLANG\Bin;C:\Python34;C:\NXP\GUI-Guider-1.6.1-GA\environment\tools\unixTools;C:\NXP\GUI-Guider-1.6.1-GA\environment\mingw\bin;C:\Program Files (x86)\VMware\VMware Workstation\bin\;C:\Program Files\Common Files\Oracle\Java\javapath;C:\Program Files\Python311\Scripts\;C:\Program Files\Python311\;C:\Program Files\Python37;C:\Program Files\Python38\Scripts;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Program Files\MySQL\MySQL Server 8.0\bin;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\NVIDIA Corporation\NVIDIA NvDLISR;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files\Git\cmd;C:\Program Files (x86)\Tencent\微信web开发者工具\dll;C:\Users\duruofu\AppData\Roaming\Python\Python311\Scripts;C:\Users\duruofu\AppData\Roaming\Python\Python311\site-packages;C:\Users\duruofu\.platformio\penv\Scripts;C:\Users\duruofu\AppData\Roaming\nvm;C:\Program Files\nodejs;C:\Program Files\MATLAB\R2021b\runtime\win64;C:\Program Files\MATLAB\R2021b\bin;C:\Program Files\PuTTY\;C:\Program Files\Pandoc\;C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility;D:\Program Files\mingw64\bin;C:\ProgramData\Anaconda3\Scripts\tensorboard.exe;C:\Program Files\dotnet\;C:\Program Files (x86)\Snapde;C:\Xilinx\Vivado\2018.3\bin;C:\Xilinx\Vivado\2018.3\bin\unwrapped\win64.o;C:\Program Files\usbipd-win\;C:\Program Files\im-select;C:\Users\duruofu\AppData\Local\Microsoft\WindowsApps;C:\Users\duruofu\AppData\Local\Programs\Microsoft VS Code\bin;C:\Program Files\JetBrains\PyCharm Community Edition 2022.2.4\bin;;C:\Users\duruofu\AppData\Roaming\nvm;C:\Program Files\nodejs;C:\Program Files\JetBrains\CLion 2023.3.3\bin;;C:\modeltech64_10.4\win64;C:\iverilog\bin;C:\iverilog\gtkwave\bin;C:\Program Files\JetBrains\PyCharm 2023.2.1\bin;;C:\modelsim_dlx64_10.6c\win64pe
SET ARMCC6_ASMOPT=--diag_suppress=9931
SET ARMCC6_CCOPT=--diag_suppress=9931
SET ARMCC6_LINKOPT=--diag_suppress=9931
SET CPU_TYPE=STM32G070RBTx
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=GPIO
SET CPU_CLOCK=0x00B71B00
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\startup_stm32g070xx._ac"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\main.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\gpio.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\stm32g0xx_it.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\stm32g0xx_hal_msp.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\stm32g0xx_hal_tim.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\stm32g0xx_hal_tim_ex.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\stm32g0xx_hal_rcc.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\stm32g0xx_hal_rcc_ex.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\stm32g0xx_ll_rcc.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\stm32g0xx_hal_flash.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\stm32g0xx_hal_flash_ex.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\stm32g0xx_hal_gpio.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\stm32g0xx_hal_dma.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\stm32g0xx_hal_dma_ex.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\stm32g0xx_ll_dma.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\stm32g0xx_hal_pwr.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\stm32g0xx_hal_pwr_ex.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\stm32g0xx_hal_cortex.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\stm32g0xx_hal.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\stm32g0xx_hal_exti.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"..\output\system_stm32g0xx.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmLink" --Via "..\Output\GPIO.lnp"
"C:\Keil_v5\ARM\ARMCLANG\Bin\fromelf.exe" "..\Output\GPIO.axf" --i32combined --output "..\Output\GPIO.hex"
