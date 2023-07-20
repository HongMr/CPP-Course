@echo off
::title设置标题
title CMake build


::#放CMake编译生成文件的地方
set dirCompile=build

::#Initial directory

del /q build\*.*
rd /s /q build


mkdir %dirCompile%

cd %dirCompile%

::#Run cmake
cmake ..

cmake --build . --config Release
cd ..
pause