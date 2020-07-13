mkdir -p -- build
cd build
conan remote add conan-center https://conan.bintray.com
conan install ..
cmake ../
make 

