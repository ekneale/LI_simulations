#!/bin/sh

source $WCSIMDIR/env.sh

SCRATCH_DIR=/scratch/$USER/ # essentially whatever temp/scratch area you want your jobs to run in
if [ ! -e $SCRATCH_DIR ]; then mkdir $SCRATCH_DIR; fi

BASE_DATA_DIR=$WCSIMDIR/../collimator_sims # wherever you want to save your OD work
if [ ! -e $BASE_DATA_DIR ]; then mkdir $BASE_DATA_DIR; fi

JOB_GENERATION_DIR=/data2/kneale/hk-software/LI_simulations/collimator_simulations

DATA_DIR=$BASE_DATA_DIR/collimator_1
if [ ! -e $DATA_DIR ]; then mkdir $DATA_DIR; fi

LOG_DIR=$DATA_DIR/logs/
if [ ! -e $LOG_DIR ]; then mkdir $LOG_DIR; fi

JOB_DIR=$SCRATCH_DIR
if [ ! -e $JOB_DIR ]; then mkdir $JOB_DIR; fi

(>&2 echo `hostname`)

cd $WCSIMDIR
original_macro=macro_collimator_1_0.9_0.75_1.30.mac

# change the seed, wcsim output filename and generator parameters in the macro
cp $JOB_GENERATION_DIR/$original_macro $DATA_DIR/macro_collimator_1_0.9_0.75_1.30.mac

sed -i "s/wcsim_output.root/\/scratch\/kneale\/collimator_1_0.9_0.75_1.30.root/" $DATA_DIR/macro_collimator_1_0.9_0.75_1.30.mac
sed -i "s/seed 3254/seed 3254${CONDOR_JOB_NUM}/" $DATA_DIR/macro_collimator_1_0.9_0.75_1.30.mac
sed -i "s/injectorPulseWidth 999/injectorPulseWidth 2/g" $DATA_DIR/macro_collimator_1_0.9_0.75_1.30.mac
sed -i "s/injectorWavelength 999/injectorWavelength 400/g" $DATA_DIR/macro_collimator_1_0.9_0.75_1.30.mac
sed -i "s/injectorIdx 999/injectorIdx 1/g" $DATA_DIR/macro_collimator_1_0.9_0.75_1.30.mac
sed -i "s/injectorDetector 999/injectorDetector OD/g" $DATA_DIR/macro_collimator_1_0.9_0.75_1.30.mac
sed -i "s/nphotons 999/nphotons 2/g" $DATA_DIR/macro_collimator_1_0.9_0.75_1.30.mac
sed -i "s/beamOn 999/beamOn 2/g" $DATA_DIR/macro_collimator_1_0.9_0.75_1.30.mac

WCSim $DATA_DIR/macro_collimator_1_0.9_0.75_1.30.mac  $DATA_DIR/params_0.9_0.75_1.30.mac

root -l -x -b -q '${WCSIMDIR}/sample-root-scripts/read_LIGen_collimator_output.C("/scratch/kneale/collimator_1_0.9_0.75_1.30.root","/scratch/kneale/reduced_collimator_1_0.9_0.75_1.30.root")'

mv /scratch/${USER}/reduced_collimator_1_0.9_0.75_1.30.root $DATA_DIR && rm /scratch/${USER}/collimator_1_0.9_0.75_1.30.root
