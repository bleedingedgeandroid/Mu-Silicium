##
#
#  Copyright (c) 2011 - 2022, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2020, Intel Corporation. All rights reserved.
#  Copyright (c) 2018, Bingxing Wang. All rights reserved.
#  Copyright (c) Microsoft Corporation.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#
##

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  PLATFORM_NAME                  = peridot
  PLATFORM_GUID                  = f40612fc-1778-4a06-8b16-8d38b7a16800
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build/peridotPkg
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = RELEASE|DEBUG
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = peridotPkg/peridot.fdf
  USE_DISPLAYDXE                 = 0
  AB_SLOT_SUPPORT                = 0

[LibraryClasses]
  DeviceMemoryMapLib|peridotPkg/Library/DeviceMemoryMapLib/DeviceMemoryMapLib.inf
  DeviceConfigurationMapLib|peridotPkg/Library/DeviceConfigurationMapLib/DeviceConfigurationMapLib.inf

[PcdsFixedAtBuild]
  # DDR Start Address
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x80000000

  # Device Maintainer
  gEfiMdeModulePkgTokenSpaceGuid.PcdFirmwareVendor|L"PugzAreCute"

  # CPU Vector Address
  gArmTokenSpaceGuid.PcdCpuVectorBaseAddress|0xa7600000

  # UEFI Stack Addresses
  gEmbeddedTokenSpaceGuid.PcdPrePiStackBase|0xa760d000
  gEmbeddedTokenSpaceGuid.PcdPrePiStackSize|0x40000

  # SmBios
  gQcomPkgTokenSpaceGuid.PcdSmbiosSystemVendor|"Xiaomi"
  gQcomPkgTokenSpaceGuid.PcdSmbiosSystemModel|"Poco F6"
  gQcomPkgTokenSpaceGuid.PcdSmbiosSystemRetailModel|"peridot"
  gQcomPkgTokenSpaceGuid.PcdSmbiosSystemRetailSku|"Poco_F6_peridot"
  gQcomPkgTokenSpaceGuid.PcdSmbiosBoardModel|"Poco F6"

  # Simple FrameBuffer
  gQcomPkgTokenSpaceGuid.PcdMipiFrameBufferWidth|1220
  gQcomPkgTokenSpaceGuid.PcdMipiFrameBufferHeight|2712
  gQcomPkgTokenSpaceGuid.PcdMipiFrameBufferColorDepth|30

  # Dynamic RAM Start Address
  gQcomPkgTokenSpaceGuid.PcdRamPartitionBase|0x19000000

  # SD Card Slot
  gQcomPkgTokenSpaceGuid.PcdSDCardSlotPresent|FALSE
  
  # USB Controller
  gQcomPkgTokenSpaceGuid.PcdStartUsbController|TRUE            # This should be TRUE unless your UsbConfigDxe is Patched to be Dual Role.

[PcdsDynamicDefault]
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoHorizontalResolution|1220
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoVerticalResolution|2712
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoHorizontalResolution|1220
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoVerticalResolution|2712
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutColumn|153
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutRow|143
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutColumn|153
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutRow|143

!include SM8635Pkg/SM8635.dsc.inc