/*volatile常用于寄存器的寄存器的定义 
volatile是C语言中的一个关键字。
将变量定义为volatile就表示告诉编译器这个变量可能会自动改变，
优化器在用到这个变量是必须每次重新读取他的值而不是使用它的临时值。
*/

/*下面是core_cm3.h中对寄存器的定义*/
//先是宏定义
#ifdef __cplusplus
  #define     __I     volatile                /*!< defines 'read only' permissions      */
#else
  #define     __I     volatile const          /*!< defines 'read only' permissions      */
#endif
//上面说的是没有使用C++则_I替换的是volatile const类型表示ROM
#define     __O     volatile                  /*!< defines 'write only' permissions     */
#define     __IO    volatile                  /*!< defines 'read / write' permissions   */
/*C中_O和_IO替代的都是volatile因为这两者确实是RAM类型，_O和_IO的不同只是给人看的，增强可读性
C中volatile const类型是一个表示会自动更改的const类型，const（恒定的）指的是不可修改其值只能读
*/

//再是定义一个RAM（SRAM和DRAM不同没啥好说，只要SRAM只要通电状态就可以一直保持而DRAM是动态的会不停刷新因为多半是电容的需要补电啥的）
extern __IO uint16_t ADC_ConvertedValue;//这就是定义了一个全局的长度为16位无符号整型的RAM
