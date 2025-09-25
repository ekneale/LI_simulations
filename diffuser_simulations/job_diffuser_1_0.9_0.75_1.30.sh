#!/bin/sh

source $WCSIMDIR/env.sh

SCRATCH_DIR=/scratch/$USER/ # essentially whatever temp/scratch area you want your jobs to run in
if [ ! -e $SCRATCH_DIR ]; then mkdir $SCRATCH_DIR; fi

BASE_DATA_DIR=/data2/kneale/hk-software/diffuser_sims # wherever you want to save your OD work
if [ ! -e $BASE_DATA_DIR ]; then mkdir $BASE_DATA_DIR; fi

DATA_DIR=$BASE_DATA_DIR/diffuser_1
if [ ! -e $DATA_DIR ]; then mkdir $DATA_DIR; fi

LOG_DIR=$DATA_DIR/logs/
if [ ! -e $LOG_DIR ]; then mkdir $LOG_DIR; fi

JOB_DIR=$SCRATCH_DIR
if [ ! -e $JOB_DIR ]; then mkdir $JOB_DIR; fi

(>&2 echo `hostname`)
cd $WCSIMDIR
original_macro=macro_diffuser_1_0.9_0.75_1.30.mac

# change the seed, wcsim output filename and generator parameters in the macro
cp $DATA_DIR/../$original_macro $DATA_DIR/macro_diffuser_1_0.9_0.75_1.30.mac

sed -i "s/wcsim_output.root/\/scratch\/kneale\/diffuser_1_0.9_0.75_1.30.root/" $DATA_DIR/macro_diffuser_1_0.9_0.75_1.30.mac
sed -i "s/seed 3254/seed 3254${CONDOR_JOB_NUM}/" $DATA_DIR/macro_diffuser_1_0.9_0.75_1.30.mac

sed -i "s/injectorPulseWidth 999/injectorPulseWidth 2/g" $DATA_DIR/macro_diffuser_1_0.9_0.75_1.30.mac
sed -i "s/injectorWavelength 999/injectorWavelength 400/g" $DATA_DIR/macro_diffuser_1_0.9_0.75_1.30.mac
sed -i "s/injectorIdx 999/injectorIdx 1/g" $DATA_DIR/macro_diffuser_1_0.9_0.75_1.30.mac
sed -i "s/nphotons 999/nphotons 2/g" $DATA_DIR/macro_diffuser_1_0.9_0.75_1.30.mac
sed -i "s/beamOn 999/beamOn 2/g" $DATA_DIR/macro_diffuser_1_0.9_0.75_1.30.mac

sed -i "s/wcsim_output.root/\/scratch\/kneale\/diffuser_1_0.9_0.75_1.30.root/" $DATA_DIR/macro_diffuser_1_0.9_0.75_1.30.mac
sed -i "s/seed 3254/seed 3254${CONDOR_JOB_NUM}/" $DATA_DIR/macro_diffuser_1_0.9_0.75_1.30.mac

WCSim $DATA_DIR/macro_diffuser_1_0.9_0.75_1.30.mac  $DATA_DIR/params_0.9_0.75_1.30.mac

root -l -x -b -q 'sample-root-scripts/read_LIGen_output_per_pulse.C("/scratch/kneale/diffuser_1_0.9_0.75_1.30.root","/scratch/kneale/reduced_diffuser_1_0.9_0.75_1.30.root")'

mv /scratch/${USER}/reduced_diffuser_1_0.9_0.75_1.30.root $DATA_DIR && rm /scratch/${USER}/diffuser_1_0.9_0.75_1.30.root .
