#!/bin/bash
colIdx=1
WORK_DIR=/data2/kneale/hk-software/collimator_analysis

condor_qsub $WORK_DIR/chi2plot_colBarrel_col${colIdx}.sh -e chi2plot_colBarrel_col${colIdx}.err -o chi2plot_colBarrel_col${colIdx}.out

