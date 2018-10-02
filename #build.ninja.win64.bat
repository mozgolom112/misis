if NOT EXIST build.ninja.win64 mkdir build.ninja.win64

pushd build.ninja.win64

call "%VS140COMNTOOLS%..\..\VC\vcvarsall.bat" x64
cmake .. -G"Ninja" -D"CMAKE_CXX_CPPLINT=cpplint;--linelength=79"
cmake --build . --config Debug
@rem cmake --build . --config Release

popd