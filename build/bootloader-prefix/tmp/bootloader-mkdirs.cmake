# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/Espressif/frameworks/esp-idf-v5.0/components/bootloader/subproject"
  "E:/Surbhi/sample_project/build/bootloader"
  "E:/Surbhi/sample_project/build/bootloader-prefix"
  "E:/Surbhi/sample_project/build/bootloader-prefix/tmp"
  "E:/Surbhi/sample_project/build/bootloader-prefix/src/bootloader-stamp"
  "E:/Surbhi/sample_project/build/bootloader-prefix/src"
  "E:/Surbhi/sample_project/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/Surbhi/sample_project/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/Surbhi/sample_project/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
