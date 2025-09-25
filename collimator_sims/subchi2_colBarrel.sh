#!/bin/bash
colIdx=1
WORK_DIR=/data2/kneale/hk-software/collimator_sims

condor_qsub $WORK_DIR/chi2calc_colBarrel_col${colIdx}.sh -e chi2calc_colBarrel_col${colIdx}.err -o chi2calc_colBarrel_col${colIdx}.out

