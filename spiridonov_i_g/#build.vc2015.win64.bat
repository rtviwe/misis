if NOT EXIST build.vc2015.win64 mkdir build.vc2015.win64
pushd build.vc2015.win64
call "%VS140COMNTOOLS%..\..\VC\vcvarsall.bat" x64
cmake -G"Visual Studio 14 2015 Win64" ..
msbuild spiridonov_i_g.sln /property:Configuration=Debug /m
msbuild spiridonov_i_g.sln /property:Configuration=Release /m
popd