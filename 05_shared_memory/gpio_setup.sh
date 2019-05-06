#!/bin/bash
export PRUN=0
export TARGET=gpio1
echo PRUN=$PRUN
echo TARGET=$TARGET

# Configure the PRU pins based on which Beagle is running
machine=$(awk '{print $NF}' /proc/device-tree/model)
echo -n $machine
if [ $machine = "Black" ]; then
    echo " Found"
    pins="P9_11"
elif [ $machine = "Wireless" ]; then
      echo " Found"
      declare -a pins=("P8_13" "P8_14" "P8_17" "P8_19" "P9_11" "P9_13" "P9_17" "P9_18" "P9_19" "P9_20" "P9_21" "P9_22" "P9_24" "P9_41" "P9_42")
elif [ $machine = "Blue" ]; then
    echo " Found"
    pins=""
elif [ $machine = "PocketBeagle" ]; then
    echo " Found"
    pins="P1_36"
else
    echo " Not Found"
    pins=""
fi

for pin in ""${pins[@]}""; do
    echo $pin
    config-pin $pin out
    config-pin -q $pin
done

#P8_31, P8_32, P8_33, P8_35