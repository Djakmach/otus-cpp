rem Static

dumpbin /SYMBOLS lib/sumLib.dir/Debug/sum.obj
dumpbin /SYMBOLS lib/Debug/sumLib.lib
dumpbin /SYMBOLS static_library_usage.dir/Debug/main.obj

rem Dynamic

dumpbin /EXPORTS lib/Debug/sumLib.lib
dumpbin /EXPORTS lib/Debug/sumLib.dll

dumpbin /DEPENDENTS Debug/dynamic_library_usage.exe
dumpbin /DEPENDENTS lib/Debug/sumLib.dll