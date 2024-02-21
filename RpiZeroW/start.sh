date "+%H:%M:%S"
echo Copying kernel.srec to /dev/ttyUSB0
cat build/freertos.srec > /dev/ttyUSB0
date "+%H:%M:%S"
echo Finished, listening
while :
do
cat /dev/ttyUSB0
done
