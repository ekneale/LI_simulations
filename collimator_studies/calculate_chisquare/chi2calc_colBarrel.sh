source /data2/kneale/hk-software/wcsim_od_calib/env-WCSim.sh
col=2.00
colIdx=1

SIMDIR=/data2/kneale/hk-data/August2023/collimator_${colIdx}


FILE=chisquare_collimator_${colIdx}.root

if test -f "$FILE"; then
    mv $FILE saved_$FILE
fi

for jobfile in $SIMDIR/jobs_col*;

  do 
  echo $jobfile

  root -x -b -q 'calculate_chi_squared_errors_PMTdist.C("'${jobfile}'","'${SIMDIR}'/jobs_col_'${col}'_baseline.root","'${colIdx}'")';

done
