#include <Library/BaseLib.h>
#include <Library/DeviceMemoryMapLib.h>

STATIC
ARM_MEMORY_REGION_DESCRIPTOR_EX
gDeviceMemoryDescriptorEx[] = {
  //Name                 Address     Length      HobOption  ResourceAttribute   ArmAttributes     ResourceType    MemoryType
  {"NOMAP",              0x80000000, 0x016e0000, NoHob,     MEM_RES,            UNCACHEABLE,      Reserv,         UNCACHED_UNBUFFERED_XN},
  {"RSRV0",              0x816e0000, 0x00320000, AddMem,    SYS_MEM,            SYS_MEM_CAP,      Reserv,         WRITE_BACK_XN},
  {"XBL DT",             0x81a00000, 0x00040000, AddMem,    SYS_MEM,            SYS_MEM_CAP,      Reserv,         WRITE_BACK_XN},
  {"XBL Ramdump",        0x81a40000, 0x001c0000, AddMem,    MEM_RES,            UNCACHEABLE,      Reserv,         UNCACHED_UNBUFFERED_XN},
  {"AOP",                0x81c00000, 0x000a0000, AddMem,    MEM_RES,            UNCACHEABLE,      Reserv,         UNCACHED_UNBUFFERED_XN},
  {"UEFI Log",           0x81ce4000, 0x00010000, AddMem,    MEM_RES,            UNCACHEABLE,      Reserv,         UNCACHED_UNBUFFERED_XN},
  {"SMEM",               0x81d00000, 0x00200000, AddMem,    MEM_RES,            UNCACHEABLE,      Reserv,         UNCACHED_UNBUFFERED_XN},
  {"PvmFw",              0x824a0000, 0x00100000, AddMem,    SYS_MEM,            SYS_MEM_CAP,      Reserv,         WRITE_BACK_XN},
  {"PIL Reserved",       0x8bc00000, 0x16e00000, AddMem,    MEM_RES,            UNCACHEABLE,      Reserv,         UNCACHED_UNBUFFERED_XN},
  {"DBI Dump",           0xa2a00000, 0x00f00000, NoHob,     MMAP_IO,            INITIALIZED,      Reserv,         UNCACHED_UNBUFFERED_XN},
  {"UEFI FD",            0xa7000000, 0x00400000, AddMem,    SYS_MEM,            SYS_MEM_CAP,      BsData,         WRITE_BACK},
  {"UEFI FD Reserved",   0xa7400000, 0x00200000, AddMem,    SYS_MEM,            SYS_MEM_CAP,      BsData,         WRITE_BACK},
  {"CPU Vectors",        0xa7600000, 0x00001000, AddMem,    SYS_MEM,            SYS_MEM_CAP,      BsData,         WRITE_BACK},
  {"Info Blk",           0xa7601000, 0x00001000, AddMem,    SYS_MEM,            SYS_MEM_CAP,      RtData,         WRITE_BACK_XN},
  {"MMU PageTables",     0xa7602000, 0x00003000, AddMem,    SYS_MEM,            SYS_MEM_CAP,      BsData,         WRITE_BACK_XN},
  {"Log Buffer",         0xa7605000, 0x00008000, AddMem,    SYS_MEM,            SYS_MEM_CAP,      RtData,         WRITE_BACK_XN},
  {"UEFI Stack",         0xa760d000, 0x00040000, AddMem,    SYS_MEM,            SYS_MEM_CAP,      BsData,         WRITE_BACK_XN},
  {"SEC Heap",           0xa764d000, 0x0008c000, AddMem,    SYS_MEM,            SYS_MEM_CAP,      BsData,         WRITE_BACK},
  {"Sched Heap",         0xa76d9000, 0x00400000, AddMem,    SYS_MEM,            SYS_MEM_CAP,      BsData,         WRITE_BACK_XN},
  {"FV Region",          0xa7ad9000, 0x00400000, AddMem,    SYS_MEM,            SYS_MEM_CAP,      BsData,         WRITE_BACK_XN},
  {"UEFI RESV",          0xa7ed9000, 0x00127000, AddMem,    SYS_MEM,            SYS_MEM_CAP,      BsData,         WRITE_BACK_XN},
  {"Kernel",             0xa8000000, 0x10000000, AddMem,    SYS_MEM,            SYS_MEM_CAP,      Reserv,         WRITE_BACK_XN},
  {"DXE Heap",           0xb8000000, 0x1ba00000, AddMem,    SYS_MEM,            SYS_MEM_CAP,      Conv,           WRITE_BACK_XN},
  {"Display Demura",     0xd3a00000, 0x02b00000, AddMem,    MEM_RES,            SYS_MEM_CAP,      Reserv,         WRITE_THROUGH_XN},          
  {"TZApps Reserved",    0xd8800000, 0x093b0000, AddMem,    MEM_RES,            UNCACHEABLE,      Reserv,         UNCACHED_UNBUFFERED_XN},
  {"Display Reserved",   0xe3940000, 0x02b00000, AddMem,    MEM_RES,            SYS_MEM_CAP,      Reserv,         WRITE_THROUGH_XN},
  {"DXE Heap1",          0xe6440000, 0x0cdc0000, AddMem,    SYS_MEM,            SYS_MEM_CAP,      Conv,           WRITE_BACK_XN},

  {"IMEM Base",          0x14680000, 0x0002a000, NoHob,     MMAP_IO,            INITIALIZED,      Conv,           NS_DEVICE},
  {"IMEM Cookie Base",   0x146aa000, 0x00016000, AddDev,    MMAP_IO,            UNCACHEABLE,      MmIO,           NS_DEVICE},
  {"IPC ROUTER TOP",     0x00400000, 0x00100000, AddDev,    MMAP_IO,            UNCACHEABLE,      MmIO,           NS_DEVICE},
  {"SECURITY CONTROL",   0x00780000, 0x00007000, AddDev,    MMAP_IO,            UNCACHEABLE,      MmIO,           NS_DEVICE},
  {"QUP",                0x00800000, 0x00300000, AddDev,    MMAP_IO,            UNCACHEABLE,      MmIO,           NS_DEVICE},
  {"PRNG CFG PRNG",      0x010c0000, 0x0000C000, AddDev,    MMAP_IO,            UNCACHEABLE,      MmIO,           NS_DEVICE},
  {"CRYPTO0 CRYPTO",     0x01dc0000, 0x00040000, AddDev,    MMAP_IO,            UNCACHEABLE,      MmIO,           NS_DEVICE},
  {"CLK TCSR TCSR REGS", 0x01f00000, 0x00100000, AddDev,    MMAP_IO,            UNCACHEABLE,      MmIO,           NS_DEVICE},
  {"PERIPH SS",          0x08800000, 0x00100000, AddDev,    MMAP_IO,            UNCACHEABLE,      MmIO,           NS_DEVICE},
  {"USB",                0x0a600000, 0x00200000, AddDev,    MMAP_IO,            UNCACHEABLE,      MmIO,           NS_DEVICE},
  {"AOSS",               0x0b000000, 0x04000000, AddDev,    MMAP_IO,            UNCACHEABLE,      MmIO,           NS_DEVICE},
  {"TLMM",               0x0f000000, 0x01000000, AddDev,    MMAP_IO,            UNCACHEABLE,      MmIO,           NS_DEVICE},
  {"SMMU",               0x15000000, 0x00200000, AddDev,    MMAP_IO,            UNCACHEABLE,      MmIO,           NS_DEVICE},
  {"APSS_HM",            0x17000000, 0x02000000, AddDev,    MMAP_IO,            UNCACHEABLE,      MmIO,           NS_DEVICE},

  // Terminator for MMU
  {"Terminator",                  0,          0,      0,          0,                      0,         0,                   0}
};

ARM_MEMORY_REGION_DESCRIPTOR_EX*
GetDeviceMemoryMap()
{
  return gDeviceMemoryDescriptorEx;
}
