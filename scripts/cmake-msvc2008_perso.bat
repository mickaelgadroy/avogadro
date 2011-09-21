@echo off

REM SET build_system="NMake Makefiles"
SET build_system="Visual Studio 9 2008"
SET build_type="Debug"

REM requires NSIS (http://nsis.sourceforge.net)!
SET cpack_options=-DCPACK_BINARY_NSIS:=ON -DCPACK_BINARY_ZIP:=OFF

REM General
SET with_wmavo=-DENABLE_WMAVO=false

SET qt_bin_dir=C:\Qt\4.7.2\bin
SET PATH=%PATH%;%qt_bin_dir%

SET openbabel_dir=C:\src\openbabeld-2.3.0\
SET openbabel_install_dir=%openbabel_dir%windows-vc2008\install
SET openbabel_version=2.3.0
SET openbabel_include_dir=%openbabel_install_dir%\include\openbabel-2.0
SET openbabel_lib=%openbabel_install_dir%\bin\openbabel-2.lib
SET openbabel_dll_dir=%openbabel_install_dir%%\bin\
SET ob_opt=-DOPENBABEL2_DIR=%openbabel_dir% -DOPENBABEL2_INCLUDE_DIR=%openbabel_include_dir% -DOPENBABEL2_LIBRARIES=%openbabel_lib% -DOPENBABEL2_DLL_DIR=%openbabel_dll_dir% -DOPENBABEL2_VERSION=%openbabel_version%

REM libxml_dir has "libxml-2.0.pc.in"
SET libxml_dir=C:\src\libxml2d-2.7.3
REM libxml_dll_dir has "libxml2.dll"
SET libxml_dll_dir=%libxml_dir%\win32\libxml2_debug\lib
SET libxml_opt=-DLIBXML_DIR=%libxml_dir% -DLIBXML_DLL_DIR=%libxml_dll_dir%

SET zlib_dir=C:\src\zlib-1.2.5
REM where is "zlib1.dll" :
SET zlib_dll_dir=%zlib_dir%\old\msvc2008\Win32_DLL_Debug
SET zlib_lib=%zlib_dll_dir%\zlib1d.lib
SET zlib_opt=-DZLIB_INCLUDE_DIR=%zlib_dir% -DZLIB_LIBRARY=%zlib_lib% -DZLIB_DLL_DIR=%zlib_dll_dir%

SET eigen2_dir=C:\src\eigen-2.0.15
SET eigen_opt=-DEIGEN2_INCLUDE_DIR=%eigen2_dir%


REM GLSL Support
SET glsl_options=-DENABLE_GLSL:=ON

SET glew_dir_root=C:\src\glewd-1.5.8
SET glew_dir=%glew_dir_root%\include
SET glew_lib=%glew_dir_root%\lib\glew32d.lib
REM where is "glew32.dll" :
SET glew_dll_dir=%glew_dir_root%\bin
SET glew_opt=-DGLEW_INCLUDE_DIR=%glew_dir% -DGLEW_LIBRARY=%glew_lib% -DGLEW_DLL_DIR=%glew_dll_dir%


REM Run cmake with GLSL (no python)
cmake.exe .. %with_wmavo% %ob_opt% %libxml_opt% %zlib_opt% %eigen_opt% %glew_opt% %glsl_options% -DCMAKE_BUILD_TYPE=%build_type% -G %build_system% 
