#!/bin/bash
JOB_DIR=/data2/kneale/hk-software/LI_simulations/collimator_process
BASE_DATA_DIR=/data2/kneale/hk-software/collimator_sims

for i in colIdx

condor_qsub $JOB_DIR/chi2plot_colBarrel_col${colIdx}.sh -e chi2plot_colBarrel_col${colIdx}.err -o chi2plot_colBarrel_col${colIdx}.out

