@echo off
mkdir ..\build
pushd ..\build
cl /std:clatest gdi32.lib kernel32.lib msvcrt.lib opengl32.lib raylib.lib shell32.lib user32.lib winmm.lib ..\src\PurpleRain.c -I..\include /link /libpath:..\lib 
popd


