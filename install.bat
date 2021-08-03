@echo off
echo Compiling Tool...
g++ writepath.cpp -o writepath.exe
echo OK.
cd > info.txt
writepath.exe
echo Compiling dhelper...
g++ dhelper.cpp -o dhelper.exe -I .
echo OK.
echo Please add directory
type info.txt
echo to the PATH environment variable.
echo DO NOT delete anything in this directory.Doing so may break the tool!
echo Usage:
echo - dhelper parse:parse task(requires Competitive Companion extension)
echo - dhelper test:test program
echo - dhelper combine:combine into single file(to submit)
echo Good luck and high rating!
pause