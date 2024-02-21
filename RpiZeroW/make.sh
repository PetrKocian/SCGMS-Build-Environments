echo Building kernel
mkdir -p build >/dev/null 2>&1
cd build
cmake ..
make
objcopy --srec-forceS3 freertos -O srec freertos.srec
echo "G" >> freertos.srec
echo Build finished

