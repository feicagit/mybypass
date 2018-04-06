@echo off
rem 加入rar.exe所在目录
rem set path=%path%;c:\program files\winrar

rem 建立rar的文件名，格式filename_prefix + 日期
rem 建立文件名前缀
set filename_prefix=今来网直播系统

rem 获取日期字符串，型如："2007-05-26"，date的命令很有意思，比如你要获取星期几，可以这样：set wday=%date:~-3%  其中-3表示后面3个字符
rem tasklist |find "123.exe" &&if errorlevel 1  (goto 1) else  goto 2
rem ver|find /i "5.1." >nul
rem if %errorlevel%==1 set curdate=%date:~6,8%
rem if %errorlevel%==0 set curdate=%date:~2,8%

rem XP:set curdate=%date:~2,8%
rem 2000:set curdate=%date:~6,8%

set curdate=%date:~,4%%date:~5,2%%date:~8,2%

rem 保存文件名
set rar_filename=%filename_prefix%%curdate%
rem set rar_filename=%filename_prefix%

rem 如果该rar文件已存在，则删除
if exist %cd%\%rar_filename%.rar del %cd%\%rar_filename%.rar

rem 执行rar的打包，一些指令和开关如下
rem a 指打开（没有则创建）一个rar文档
rem -r 针对所有子目录
rem -ed 不添加空目录
rem -x 排除文件或文件夹，支持通配符，如文件 -x*.obj  目录如： -x*\mydir\*
rem -p 加入口令，如口令123可以这样写：-p123
rem -t 完成后进行测试，看看打包过程是否有错误
rem rar a -r -ed -x*\bin\* -x*\lib\* -x*\bak\* -x*\Debug\* -x*\release\* -x*.ncb -x*.suo -x*.aps -x*.user -x*.bat -x*.rar -p123 -t %rar_filename%
rem set test=rar a -hp123456 -r -x*.zip -x*\x64_dlls\*
rem set test=rar a -r -ed  -x*.pdb -x*.lib -x*.exp -x*.ilk -x*_d.dll -x*_d.exe -x*.zip -x*\x64*\* %rar_filename% .\bin\*.* 
set test=rar a -r -ed  -pa123 -x*.log -x*.log -x*.sdf -x*120d.dll -x*_d.* -x*.pdb -x*.pch -x*.exp -x*.ilk -x*_d.dll -x*_d.exe -x*.zip -x*.rar -x*\x64*\* -x*\x86_dlls\* -x*.ipch -x*.obj %rar_filename%  .\bypass_live_demo\bin\*.* 
%test%
pause