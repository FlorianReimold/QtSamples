@echo off

pushd %~dp0

if not exist "_build" mkdir "_build"

set "Qt5_DIR=C:/Qt/5.15.2/msvc2015_64"

cd _build
cmake .. -A x64 -T v140

popd 
pause