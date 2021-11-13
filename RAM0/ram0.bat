SET PATH=c:\z88dk199c;c:\z88dk199c\bin;c:\z88dk199c\lib\;c:\z88dk199c\lib\clibs;c:\z88dk199c\lib\config

cd codemaps
	del ram0.o
cd ..

@rem this creates an object file
zcc +zx -vn -SO3 -c -clib=new -pragma-include:zpragma.inc -o RAM0.o --fsigned-char @ram0.lst

if not exist "RAM0.o" (
call error.bat
)

copy "ram0.o" "..\"
move "ram0.o" "codemaps\"

@REM Cleanup
del zcc_opt.def


rem attention new
del hotrod1.zx0
del hotrod2.zx0
del hotrod3.zx0

REM a nice map view
cd codemaps
	echo on
	@REM all these objects match up
	z80nm ram0.o
	z80nm ram0.o > ram0.txt
	copy "ram0.txt" "..\"
	echo off
cd ..

@call beep.bat
