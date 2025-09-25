#!/bin/sh

source $WCSIMDIR/env-WCSim.sh

SCRATCH_DIR=/scratch/$USER/ # essentially whatever temp/scratch area you want your jobs to run in
if [ ! -e $SCRATCH_DIR ]; then mkdir $SCRATCH_DIR; fi

BASE_DATA_DIR=$WCSIMDIR/../collimator_sims # wherever you want to save your OD work
if [ ! -e $BASE_DATA_DIR ]; then mkdir $BASE_DATA_DIR; fi

DATA_DIR=$BASE_DATA_DIR/collimator_1
if [ ! -e $DATA_DIR ]; then mkdir $DATA_DIR; fi

LOG_DIR=$DATA_DIR/logs/
if [ ! -e $LOG_DIR ]; then mkdir $LOG_DIR; fi

JOB_DIR=$SCRATCH_DIR
if [ ! -e $JOB_DIR ]; then mkdir $JOB_DIR; fi

(>&2 echo `hostname`)
cd $WCSIMDIR

WCSim $DATA_DIR/macro_collimator_1_0.9_0.75_1.30.mac  $DATA_DIR/params_0.9_0.75_1.30.mac

root -l -x -b -q 'ReduceODOutput.C("/scratch/$USER/collimator_1_0.9_0.75_1.30.root","/scratch/$USER/reduced_collimator_1_0.9_0.75_1.30.root")'

mv /scratch/$USER/collimator_1_0.9_0.75_1.30.root $DATA_DIR
mv /scratch/$USER/reduced_collimator_1_0.9_0.75_1.30.root $DATA_DIR
