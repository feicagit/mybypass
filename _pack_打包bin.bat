@echo off
rem ����rar.exe����Ŀ¼
rem set path=%path%;c:\program files\winrar

rem ����rar���ļ�������ʽfilename_prefix + ����
rem �����ļ���ǰ׺
set filename_prefix=������ֱ��ϵͳ

rem ��ȡ�����ַ��������磺"2007-05-26"��date�����������˼��������Ҫ��ȡ���ڼ�������������set wday=%date:~-3%  ����-3��ʾ����3���ַ�
rem tasklist |find "123.exe" &&if errorlevel 1  (goto 1) else  goto 2
rem ver|find /i "5.1." >nul
rem if %errorlevel%==1 set curdate=%date:~6,8%
rem if %errorlevel%==0 set curdate=%date:~2,8%

rem XP:set curdate=%date:~2,8%
rem 2000:set curdate=%date:~6,8%

set curdate=%date:~,4%%date:~5,2%%date:~8,2%

rem �����ļ���
set rar_filename=%filename_prefix%%curdate%
rem set rar_filename=%filename_prefix%

rem �����rar�ļ��Ѵ��ڣ���ɾ��
if exist %cd%\%rar_filename%.rar del %cd%\%rar_filename%.rar

rem ִ��rar�Ĵ����һЩָ��Ϳ�������
rem a ָ�򿪣�û���򴴽���һ��rar�ĵ�
rem -r ���������Ŀ¼
rem -ed ����ӿ�Ŀ¼
rem -x �ų��ļ����ļ��У�֧��ͨ��������ļ� -x*.obj  Ŀ¼�磺 -x*\mydir\*
rem -p �����������123��������д��-p123
rem -t ��ɺ���в��ԣ�������������Ƿ��д���
rem rar a -r -ed -x*\bin\* -x*\lib\* -x*\bak\* -x*\Debug\* -x*\release\* -x*.ncb -x*.suo -x*.aps -x*.user -x*.bat -x*.rar -p123 -t %rar_filename%
rem set test=rar a -hp123456 -r -x*.zip -x*\x64_dlls\*
rem set test=rar a -r -ed  -x*.pdb -x*.lib -x*.exp -x*.ilk -x*_d.dll -x*_d.exe -x*.zip -x*\x64*\* %rar_filename% .\bin\*.* 
set test=rar a -r -ed  -pa123 -x*.log -x*.log -x*.sdf -x*120d.dll -x*_d.* -x*.pdb -x*.pch -x*.exp -x*.ilk -x*_d.dll -x*_d.exe -x*.zip -x*.rar -x*\x64*\* -x*\x86_dlls\* -x*.ipch -x*.obj %rar_filename%  .\bypass_live_demo\bin\*.* 
%test%
pause