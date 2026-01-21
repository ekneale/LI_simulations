#!/bin/sh
WCSIMDIR=/data2/kneale/hk-software/WCSim
source $WCSIMDIR/env.sh

photonsperpulse=(1000000 1000000)
wavelengths=(365.0 365.0)
pulsewidths=(10.0 10.0)
pulses=(10 10)
collimators=(10 13)

for laserIdx in {0..1}
do

    collimatorIdx=${collimators[laserIdx]}
    wl=${wavelengths[laserIdx]}
    ppp=${photonsperpulse[laserIdx]}
    pw=${pulsewidths[laserIdx]}
    npulse=${pulses[laserIdx]}

    BASE_DATA_DIR=/data2/kneale/hk-software/collimator_sims/collimator_${collimatorIdx}
    RESULTS_DIR=${BASE_DATA_DIR}/results

    FILE=chisquare_collimator_${collimatorIdx}.root

    if test -f "$FILE"; then
        mv $FILE saved_$FILE
    fi

    for reduced_root_file in ${RESULTS_DIR}/reduced_*;

      do 
      echo ${reduced_root_file}

      root -x -b -q 'calculate_chi_squared_errors_PMTdist.C("'${reduced_root_file}'","'${RESULTS_DIR}'/reduced_collimator_'${collimatorIdx}'_'${wl}'_nm_'${pw}'_ns_'${ppp}'_ppp_baseline.root","'${collimatorIdx}'")';

    done

done
