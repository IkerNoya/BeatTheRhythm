@echo off
echo copying files...
copy "%1\lib\raylib-2.6.0-Win32-msvc15-actualizado\bin\Debug\raylib.dll" "%2"
cd "%2"
mkdir "res"
cd "res"
mkdir "assets"
cd "assets"
xcopy "%1\res\assets" "%2\res\assets" /S /Y
echo files copied...